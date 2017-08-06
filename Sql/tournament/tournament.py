#!/usr/bin/env python
#
# tournament.py -- implementation of a Swiss-system tournament
#

import psycopg2


def connect():
    """Connect to the PostgreSQL database.  Returns a database connection."""
    return(psycopg2.connect("dbname=tournament"))


def deleteMatches():
    """Remove all the match records from the database."""
    db = connect()
    p = db.cursor()
    p.execute("delete from matches;")
    db.commit()


def deletePlayers():
    """Remove all the player records from the database."""
    db = connect()
    p = db.cursor()
    p.execute("delete from players;")
    db.commit()


def countPlayers():
    """Returns the number of players currently registered."""
    db = connect()
    p = db.cursor()
    p.execute("select count(*) as num from players;")
    num = p.fetchone()
    return(num[0])


def registerPlayer(name):
    """Adds a player to the tournament database.

    The database assigns a unique serial id number for the player.  (This
    should be handled by your SQL database schema, not in your Python code.)

    Args:
      name: the player's full name (need not be unique).
    """
    db = connect()
    p = db.cursor()
    p.execute("insert into players (name) values (%s);",(name,))
    db.commit()


def playerStandings():
    """Returns a list of the players and their win records, sorted by wins.

    The first entry in the list should be the player in first place, or a player
    tied for first place if there is currently a tie.

    Returns:
      A list of tuples, each of which contains (id, name, wins, matches):
        id: the player's unique id (assigned by the database)
        name: the player's full name (as registered)
        wins: the number of matches the player has won
        matches: the number of matches the player has played
    """
    db = connect()
    p = db.cursor()
    p.execute("select * from playerStatistics")
    players = p.fetchall()
    return(players)




def reportMatch(winner, loser):
    """Records the outcome of a single match between two players.

    Args:
      winner:  the id number of the player who won
      loser:  the id number of the player who lost
    """
    db = connect()
    p = db.cursor()
    p.execute("insert into matches (winner, loser) values (%s,%s)",(winner, loser,))
    db.commit()

def swissPairings():
    """Returns a list of pairs of players for the next round of a match.

    Assuming that there are an even number of players registered, each player
    appears exactly once in the pairings.  Each player is paired with another
    player with an equal or nearly-equal win record, that is, a player adjacent
    to him or her in the standings.

    Returns:
      A list of tuples, each of which contains (id1, name1, id2, name2)
        id1: the first player's unique id
        name1: the first player's name
        id2: the second player's unique id
        name2: the second player's name
    """
    db = connect()
    p = db.cursor()
    pairs = []

    # returns player1.id, player1.name, player2.id, player2.name sorted
    # by number of wins - swiss pairing system
    p.execute("""
    select a.id, a.name from
    (select array_agg(players.id) as id, array_agg(players.name) as name
    from playerStatistics as players) as a;
    """)

    pair = p.fetchone()
    ids = pair[0]
    names = pair[1]

    pairs = []
    # create pairs of two players from arrays returned from db
    for i in xrange(0,len(ids) - 1, 2):
        if ids[i] != None:
            pair = (ids[i], names[i], ids[i+1], names[i+1])
            pairs.append(pair)
    return(pairs)