# So Long

## Objectives

It’s time for you to create a basic computer graphics project!<br><br>
so long will help you improve your skills in the following areas: window management, event handling, colors, textures, and so forth.<br><br>
You are going to use the school graphical library: the MiniLibX! This library was developed internally and includes basic necessary tools to open a window, create images and deal with keyboard and mouse events.<br><br>
The other goals are similar to every other goal for this first year: being rigorous, level up in C programming, use basic algorithms, do some information research, and so forth.<br><br>

## Rules

+ The use the `MiniLibX` library is mandatory
+ `Makefile` must not relink
+ The program has to take as a parameter a map description file ending with the `.ber` extension

### Game

+ The player's goal is to collect every collectible present on the map, then escape the shortest possible route
+ You can choose to use `W, A, S, D` || `ZQSD` || `arrow` keys to move the main character
+ The player should be able to move `UP, DOWN, LEFT, RIGHT`
+ The player should not be able move into walls
+ At every move, the current number of movements must be displayed in the shell
+ You have to use a `2D view` (top-down or profile)
+ The game doesn't have to be real time

### Graphic management

+ The program has to display the image in a window
+ The management of your window must remain smooth (changing to another window, minimizing, and so forth)
+ Pressing `ESC` must close the window and quit the program in a clean way

### Links
+ [MiniLibX Basic intro](https://gontjarow.github.io/MiniLibX/mlx-tutorial-draw-line.html)
+ [Getting started with the MiniLibX](https://gontjarow.github.io/MiniLibX/)
+ [Getting started with the MiniLibX github](https://github.com/Gontjarow/MiniLibX)
+ [42 Docs](https://harm-smits.github.io/42docs/)

## Guide

### Part 1 : Check files
+ Verify that there is no errors in main arguments
	. tot number or arguments
	. File extension of map file
	. map size : make sure that main window size adapt to map size
	. map does not contain any errors
	. in case of any error, program must exit correctly

+ Questions:

### Part 2 : Parsing
+ Parse map file
	. Check with backtracking or idealy flood fill that map.ber is functional
	. GNL to fetch each map.ber line
	. Convert each line: Replace/convert each number in the map with the appropriate sprite
	. 

+ Questions:

### Part 3 : Move
	. Either intervert sprites based on character movements
	. Either rewrite sprite based on character movements




## Ressources

* Telechargement de la MLX: https://github.com/42Paris/minilibx-linux

* Bibliotheque de png: https://www.vhv.rs/

* Resize un png: https://onlinepngtools.com/resize-png

* Convertion en xpm: https://anyconv.com/fr/convertisseur-de-png-en-xpm/

* Guide pour l'utilisation de la minilib: https://aurelienbrabant.fr/blog

* Man des prototypes de fonctions de la MLX: https://qst0.github.io/ft_libgfx/man_mlx_new_image.html
