-- Table definitions for the tournament project.
--
-- Put your SQL 'create table' statements in this file; also 'create view'
-- statements if you choose to use it.
--
-- You can write comments in this file by starting them with two dashes, like
-- these lines here.

-- creating table for players
create table players (
                       id serial primary key,
                       name text
                     );


-- creating table for matches
create table matches (
                        match_id serial,
                        winner integer references players(id),
                        loser integer references players(id)
                    );


-- call view to display player statistics (id, player name, won, number of matches)
create view playerStatistics as select players.id, players.name, count(matches.winner) as winner, (select count(*) as matches from matches where players.id = matches.winner or players.id = matches.loser)
                                from players left join matches
                                on players.id = matches.winner
                                group by players.id
                                order by players.winner desc;