# So_long

A small 2D game written in C using MiniLibX.

The player controls a character on a map, collects all the items and reaches the exit. Maps are loaded from `.ber` files and validated before starting the game.

The project also includes custom graphics and several maps.

## Main features

* `.ber` map parsing
* Map validation
* Wall and character checks
* Flood-fill validation to verify that the map is playable
* Keyboard controls
* Move counter
* 2D graphics using MiniLibX
* Custom XPM textures
* Error handling and resource cleanup

## Build

```bash
make
```

Then run:

```bash
./so_long maps/map.ber
```

## Technologies

* C
* MiniLibX
* Make
* Unix/Linux
