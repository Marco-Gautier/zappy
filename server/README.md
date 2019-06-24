# Server API protocole

The **client** must be **authenticated** by joining a **team** (default team1/team2/team3/team4).


| Action                       | Command        | time limit | Response                                |
|------------------------------|----------------|------------|-----------------------------------------|
| move up one tile             | Forward        | 7/f        | ok                                      |
| turn 90° right               | Right          | 7/f        | ok                                      |
| turn 90° left                | Left           | 7/f        | ok                                      |
| -----------------------------| ---------------| -----------| ----------------------------------------|
| look around                  | Look           | 7/f        | [tile1, tile2,. . . ]                   |
| inventory                    | Inventory      | 1/f        | [linemate n, sibur n,. . . ]            |
| broadcast text               | Broadcast text | 7/f        | ok                                      |
| -----------------------------| ---------------| -----------| ----------------------------------------|
| number of team unused slots  | Connect_nbr    | -          | value                                   |
| fork a player                | Fork           | 42/f       |                                         |
| eject players from this tile | Eject          | 7/f        | ok/ko                                   |
| death of a player            | -              | -          | dead                                    |
| -----------------------------| ---------------| -----------| ----------------------------------------|
| take object                  | Take object    | 7/f        | ok/ko                                   |
| set object down              | Set object     | 7/f        | ok/ko                                   |
| start incantation            | Incantation    | 300/f      | Elevation underway <br> Current level: *k* <br>/ko |
