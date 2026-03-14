import random

N = 8
POPULATION_SIZE = 100
MUTATION_RATE = 0.05
MAX_GENERATIONS = 10000


def random_individual():
    """A permutation: individual[col] = row of queen in that column."""
    ind = list(range(N))
    random.shuffle(ind)
    return ind


def fitness(individual):
    """Count non-attacking queen pairs (higher is better, max = N*(N-1)/2)."""
    non_attacking = 0
    for i in range(N):
        for j in range(i + 1, N):
            if abs(individual[i] - individual[j]) != abs(i - j):
                non_attacking += 1
    return non_attacking


MAX_FITNESS = N * (N - 1) // 2


def selection(population, fitnesses):
    """Roulette wheel selection."""
    total = sum(fitnesses)
    pick = random.uniform(0, total)
    current = 0
    for ind, fit in zip(population, fitnesses):
        current += fit
        if current >= pick:
            return ind
    return population[-1]


def crossover(parent1, parent2):
    """Order crossover (OX): preserves relative order from parent2."""
    start, end = sorted(random.sample(range(N), 2))
    child = [None] * N
    child[start:end + 1] = parent1[start:end + 1]
    fill = [g for g in parent2 if g not in child]
    idx = 0
    for i in range(N):
        if child[i] is None:
            child[i] = fill[idx]
            idx += 1
    return child


def mutate(individual):
    """Swap mutation: swap two random genes."""
    if random.random() < MUTATION_RATE:
        i, j = random.sample(range(N), 2)
        individual[i], individual[j] = individual[j], individual[i]
    return individual


def print_board(individual):
    """Print the chessboard with queens (Q) and empty squares (.)."""
    for row in range(N):
        line = ""
        for col in range(N):
            line += "Q " if individual[col] == row else ". "
        print(line)
    print()


def solve():
    population = [random_individual() for _ in range(POPULATION_SIZE)]

    for generation in range(MAX_GENERATIONS):
        fitnesses = [fitness(ind) for ind in population]
        best_fitness = max(fitnesses)
        best = population[fitnesses.index(best_fitness)]

        if best_fitness == MAX_FITNESS:
            print(f"Solution found in generation {generation}!")
            print_board(best)
            print(f"Queen positions (col -> row): {best}")
            return

        # Elitism: carry the best individual forward
        new_population = [best[:]]

        while len(new_population) < POPULATION_SIZE:
            p1 = selection(population, fitnesses)
            p2 = selection(population, fitnesses)
            child = crossover(p1, p2)
            child = mutate(child)
            new_population.append(child)

        population = new_population

    # Print the best found even if no perfect solution
    fitnesses = [fitness(ind) for ind in population]
    best = population[fitnesses.index(max(fitnesses))]
    print(f"Best solution after {MAX_GENERATIONS} generations (fitness {max(fitnesses)}/{MAX_FITNESS}):")
    print_board(best)
    print(f"Queen positions (col -> row): {best}")


if __name__ == "__main__":
    solve()
