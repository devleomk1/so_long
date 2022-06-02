# so_long
[![jisokang's 42 so_long Score](https://badge42.vercel.app/api/v2/cl3wfqiem000609jsr6tci7fi/project/2193781)](https://github.com/JaeSeoKim/badge42)
![so long play screen shot](so_long_play_screen_shot.png)
This is a small game project from 42school implemented using MiniLibX. This project is inspired by Game Freak's Pokemon Firered.

## Goals
This project is a very small 2D game. It is built to make you work with textures, sprites. And some very basic gameplay elements.

## Getting Started
>🚨 Please check the issue/#1 before start.

### Install
```bash
$ make bonus
```

### Usage
```bash
$ ./so_long_bonus [MAP_FILE.ber]
```
Only map files with extension `.ber` are available. Map file examples are available in the `map/` directory.

```bash
$ ./so_long_bonus map/map_sl.ber
```
Run the code to use all the features of the game.

### HOW TO PLAY
The player’s goal is to collect all collectibles present on the map then escape with minimal movement.

|KEYBOARD|ACTION|
|---|---|
|`W`, `↑`|Move up|
|`S`, `↓`|Move down|
|`A`, `←`|Move left|
|`D`, `→`|Move right|
|`return ⏎`| Start game|
|`R`|Retry game|
|`ESC ⎋`|Close the game window|

## Reference
 * [42Paris/minilibx-linux](https://github.com/42Paris/minilibx-linux)
 * [42Docs/minilibx](https://harm-smits.github.io/42docs/libs/minilibx)
 * [taelee42/mlx_example](https://github.com/taelee42/mlx_example)
 * [pret/Disassembly of Pokémon FireRed and LeafGreen](https://github.com/pret/pokefirered)
