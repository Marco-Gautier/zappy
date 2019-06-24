# Zappy GUI

The **client** must be **authenticated** by joining the "**GRAPHIC**" **team**.


| Server                                     | Client    | Details                            |
|--------------------------------------------|-----------|------------------------------------|
| msz X Y\n                                  | msz\n     | map size                           |
| bct X Y q0 q1 q2 q3 q4 q5 q6\n             | bct X Y\n | content of a tile                  |
| bct X Y q0 q1 q2 q3 q4 q5 q6\n * nbr_tiles | mct\n     | content of the map (all the tiles) |
| tna N\n * nbr_teams                        | tna\n     | name of all the teams              |
| ppo n X Y O\n                              | ppo #n\n  | player’s position                  |
| plv n L\n                                  | plv #n\n  | player’s level                     |
| pin n X Y q0 q1 q2 q3 q4 q5 q6\n           | pin #n\n  | player’s inventory                 |
| sgt T\n                                    | sgt\n     | time unit request                  |
| sst T\n                                    | sst T\n   | time unit modification             |
