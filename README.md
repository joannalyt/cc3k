# CC3K — Please Do Not Feed the Dragons

```text
************************************************************
*                                                          *
*          C C 3 K :  D U N G E O N  A W A I T S           *
*                                                          *
*      Five floors. Four races. Questionable potions.      *
*              Your entire body is an @ sign.              *
*                                                          *
************************************************************
```

CC3K is a turn-based, terminal roguelike dungeon game written in **C++14**. Explore rooms, fight monsters, collect gold, and find the stairs through five increasingly inconvenient floors of dungeon life.

Built around **object-oriented design, inheritance, and polymorphism**, the game separates characters, enemies, items, and rooms into modular components that work together to implement combat mechanics and character interactions.

Originally hand-written before AI coding agents were a thing. Human-made code. Human-made bugs. Dragon-made problems.

## Enter at your own risk

Bring a C++14-capable compiler, `make`, and a terminal with ANSI color support. No graphics engine required. Your imagination handles the rendering budget.

```bash
git clone https://github.com/joannalyt/cc3k.git
cd cc3k
make -B
./cc3k
```

Run from the repository directory so the game can find its map and text files. `make -B` rebuilds everything locally, including the compiled files bundled with this old repository. After source changes, plain `make` is enough.

## Choose your tiny ASCII destiny

At the welcome screen, type a **lowercase** race letter and press **Enter**:

| Input | Race | HP | Attack | Defense | Fine print |
| --- | --- | ---: | ---: | ---: | --- |
| `h` | Human | 140 | 20 | 20 | Final gold score gets a 1.5× multiplier. Management material. |
| `d` | Dwarf | 100 | 20 | 30 | Double gold from pickups. Very serious about accounting. |
| `e` | Elf | 140 | 30 | 10 | Negative potion effects become positive. Suspiciously good metabolism. |
| `o` | Orc | 180 | 30 | 25 | Half gold from pickups, rounded up. Here for the fighting. |

## How to avoid becoming the next floor decoration

Type a command, then press **Enter**. Directions refer to the tile immediately beside you, including diagonals.

```text
                  nw     no     ne
                    ↖    ↑    ↗
                  we ←   @   → ea
                    ↙    ↓    ↘
                  sw     so     se
```

| Command | Action |
| --- | --- |
| `no`, `so`, `ea`, `we` | Move north, south, east, or west |
| `ne`, `se`, `sw`, `nw` | Move diagonally |
| `a <direction>` | Attack an adjacent enemy; e.g. `a ea` |
| `u <direction>` | Use an adjacent potion; e.g. `u no` |
| `r` | Restart and choose a new character |
| `q` | Quit once you have entered the dungeon |

**Your mission:** reach the stairs on each floor, survive all five floors, and leave with as much gold as possible. Reach zero HP and the dungeon wins. Your final score is based on collected gold, with the Human bonus applied if relevant.

Successful moves and attacks give enemies a turn to move or attack. Read the `Action` line below the map to see what just happened to your carefully considered plan.

## A field guide to things that may bite

| Symbol | Meaning |
| --- | --- |
| `@` | You. Looking good. |
| `.`, `#`, `+` | Room floor, corridor, and doorway |
| `-`, `\|` | Walls. Persistently uncooperative. |
| `\` | Stairs to the next floor, or victory on floor five |
| `P` | Potion: health, attack, or defense effects, helpful or harmful |
| `G` | Gold; walk onto an unguarded pile to collect it |
| `B` | Barrier Suit, a dragon-guarded item that reduces incoming damage |
| `W`, `V`, `T`, `N`, `X` | Werewolf, vampire, troll, goblin, and phoenix |
| `M` | Merchant. Peaceful until you make a terrible business decision. |
| `D` | Dragon. The treasure is not complimentary. |

A few survival tips, generously provided by previous occupants:

- Defeat the guarding dragon before collecting its treasure or Barrier Suit.
- Attack a merchant and the other merchants on that floor become hostile. Customer service has limits.
- Potion changes to attack and defense reset on the next floor.
- All potions look like `P`. The dungeon does not believe in informative packaging.

## Behind the dungeon walls

The default game uses a fixed room-and-corridor layout with randomly placed characters, stairs, potions, and gold. It also supports loading preset floors with `./cc3k <map-file>`.

| Component | Responsibility |
| --- | --- |
| `main.cc` | Character selection, command loop, floor progression, and win/loss handling |
| `Floor` | Map state, spawning, rendering, movement, and interaction coordination |
| `Chamber` | Room boundaries and random placement positions |
| `Character` → `Player`, `Enemy` | Shared character attributes, specialized races, and combat behavior |
| `Item` → `Potion`, `Gold` | Item properties, potion effects, and collectible treasure |

Inheritance provides common character and item interfaces; virtual methods allow specialized behavior such as a dragon exposing its guarded hoard. Objects are connected using `std::shared_ptr`, while the map is rendered as a two-dimensional character grid with terminal colors.

## The humans responsible

Created by **Jingwen Min, Yuxuan Li, and Yingtong Liu**.

```text
************************************************************
*                                                          *
*                       B Y E  B Y E                       *
*                                                          *
*       Thanks for visiting. Please take your gold.        *
*            Leave the dragons where they are.             *
*                                                          *
************************************************************
```
