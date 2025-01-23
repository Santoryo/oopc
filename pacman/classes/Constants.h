#pragma once

// Drawing constants
#define PACMAN 9
#define BLINKY 8
#define PINKY 7
#define INKY 6
#define CLYDE 5
#define POWERUP 3
#define COIN 2
#define WALL 1
#define PATH 0

// Direction constants
#define NONE -999
#define UP 1
#define DOWN -1
#define LEFT 2
#define RIGHT -2

#define DIRECTIONS {UP, DOWN, LEFT, RIGHT}

// Other constants
#define TILE_SIZE 30
#define PACMAN_SPEED 2
#define GHOST_SPEED 1
#define GHOST_SPEED_SCARED 1.5

// COLORS
#define MAZE_COLOR "#1e26c8"
#define PACMAN_COLOR "#eeea04"
#define POINTS_COLOR "#f0bec8"
#define BLINKY_COLOR "#ff0000"
#define INKY_COLOR "#00FFFF"
#define PINKY_COLOR "#FFB8FF"
#define CLYDE_COLOR "#6320ee"