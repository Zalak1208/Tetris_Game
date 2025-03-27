# Tetrimania
Tetrimania is a game, in C++, in which the player controls the Tetrimino — a geometric shape made of four blocks . The terimino continuously descends towards the ground. The player can rotate it or shift it in left and right direction. The objective of the player is to maximize the score by creating horizontal rows of tetrimino blocks, which clears the row, giving more space and increases the score. With increase in Score, falling speed also increases. The game ends when no space remains for a newly generated Tetrimino to appear at the top-center of the playing field.

## Table of Contents
 - [Dependencies](#dependencies)
 - [Installation](#installation)
 - [Usage](#usage)
 - [Features](#features)
 - [Conclusion](#conclusion)

 ## Dependencies
 The following are the system requirements:
 -Windows 10 Operating System
 -Cpp  compiler
 - 13th Gen Intel(R) Core(TM) i5-13420H   2.10 GHz or Higher
 - 4.0 GB RAM

## Installation
 1) Clone this repository.
 2) Open Command prompt.
 3) Compile this code using the command: "g++ main.cpp intro.cpp map.cpp pieces.cpp".
 4) Run a.exe file to play the game.
 5) Read the instruction and play the game.

## Usage
 Just run a.exe file.

## Features 
 1) The game is played on a fixed-sized grid, containing walls(boundaries), the teriminos.
 2) The tetrimino gradually descends towards the ground, the player can influence its movement by rotating it and shifting it to left and right.
 3) Left and right movement is accomplished by left and right arrow keys, upward arrow for rotating the tetrimino. Space Bar is used for hard drop and downward key for soft drop.
 4) Teriminos are generated randomly on the top-centre of the grid. The player can maximise its score by forming horizontal rows of tetrimino.
 5) With the increase in score, the speed of tetrimino increases.
 6) The game ends if no space remains for a newly generated Tetrimino to appear at the top-center of the playing field.

## Conclusion 
The project is done with the concept of Object-Oriented Programming. There could more updates in the future based on the liking by the public.
