# Simulate a sports tournament

import csv
import sys
import random

# Number of simluations to run
N = 1000


def main():

    # Ensure correct usage
    if len(sys.argv) != 2:
        sys.exit("Usage: python tournament.py FILENAME")

    teams = []
    # TODO: Read teams into memory from file
    file = open(sys.argv[1], 'r')
    reader = csv.DictReader(file)
    for row in reader:
        current_team = row['team']
        current_rating = row['rating']

        temporary_dict = {'team': str(current_team), 'rating': int(current_rating)}
        teams.append(temporary_dict)

    tuple(teams)

    counts = {}

    # TODO: Simulate N tournaments and keep track of win count
    for i in range(N):
        winning_team = simulate_tournament(teams)

        if winning_team in counts.keys():
            counts[winning_team] += 1
        else:
            counts[winning_team] = 1

    # Check for missing teams
    if (len(counts) < len(teams)):
        for team in (teams):
            if team['team'] not in counts.keys():
                counts[team['team']] = 0

    # Print each team's chances of winning, according to simulation
    for team in sorted(counts, key=lambda team: counts[team], reverse=True):
        print(f"{team}: {counts[team] * 100 / N:.1f}% chance of winning")


def simulate_game(team1, team2):
    """Simulate a game. Return True if team1 wins, False otherwise."""
    rating1 = team1["rating"]
    rating2 = team2["rating"]
    probability = 1 / (1 + 10 ** ((rating2 - rating1) / 600))
    return random.random() < probability


def simulate_round(teams):
    """Simulate a round. Return a list of winning teams."""
    winners = []

    # Simulate games for all pairs of teams
    for i in range(0, len(teams), 2):
        if simulate_game(teams[i], teams[i + 1]):
            winners.append(teams[i])
        else:
            winners.append(teams[i + 1])

    return winners


def simulate_tournament(teams):
    """Simulate a tournament. Return name of winning team."""
    # TODO
    teams_simulation = []

    for team in (teams):
        teams_simulation.append(team)

    # Run tournament simulation.
    while (len(teams_simulation) > 1):
        teams_simulation = simulate_round(teams_simulation)

    return teams_simulation[0]['team']


if __name__ == "__main__":
    main()