# 42_fdf

## Description

All programs that you wrote until now were executed in text mode on your terminal. Now, let’s discover something more exciting: how to open a graphics window and draw inside? To start your journey in graphic programming, FdF offers to represent “iron wire” meshing in 3D.

## Keywords
* Simple graphic library
* Segment layout
* Events
* 3D projection to 2D

## Skills
* Imperative programming
* Rigor
* Graphics
* Algorithms & AI


# FDF
Wireframe model

Summary: This project is about representing a landscape as a 3D object in which all surfaces are outlined in lines.

Version: 2

## Introduction

The representation in 3D of a landscape is a critical aspect of modern mapping. For example, in these times of spatial exploration, to have a 3D representation of Mars is a prerequisite condition to its conquest. As another example, comparing various 3D representations of an area of high tectonic activity will allow you to better understand these phenomena and their evolution, and as a result, be better prepared. It’s your turn today to modelize some 3D magnificent landscapes, imaginary or not.

> FDF is short for ’fil de fer’ in French which means ’wireframe model’.


## Objectives

It’s time for you to create a basic computer graphics project!
You are going to use the school graphical library: the MiniLibX! This library was developed internally and includes basic necessary tools to open a window, create images and deal with keyboard and mouse events. This will be the opportunity for you to get familiar with the MiniLibX, to discover the basics of graphics programming, especially how to place points in space, join them and, most important, how to see the scene from a specific viewpoint.

## Common Instructions
* Your project must be written in C.
* Your project must be written in accordance with the Norm. If you have bonus files/functions, they are included in the norm check and you will receive a 0 if there is a norm error inside.
* Your functions should not quit unexpectedly (segmentation fault, bus error, double free, etc) apart from undefined behaviors. If this happens, your project will be considered non functional and will receive a 0 during the evaluation.
* All heap allocated memory space must be properly freed when necessary. No leaks will be tolerated.
* If the subject requires it, you must submit a Makefile which will compile your source files to the required output with the flags -Wall, -Wextra and -Werror, use cc, and your Makefile must not relink.
* Your Makefile must at least contain the rules $(NAME), all, clean, fclean and re.
* To turn in bonuses to your project, you must include a rule bonus to your Makefile, which will add all the various headers, librairies or functions that are forbidden on the main part of the project. Bonuses must be in a different file _bonus.{c/h} if the subject does not specify anything else. Mandatory and bonus part evaluation is done separately.
* If your project allows you to use your libft, you must copy its sources and its associated Makefile in a libft folder with its associated Makefile. Your project’s Makefile must compile the library by using its Makefile, then compile the project.
* We encourage you to create test programs for your project even though this work won’t have to be submitted and won’t be graded. It will give you a chance to easily test your work and your peers’ work. You will find those tests especially useful during your defence. Indeed, during defence, you are free to use your tests and/or the tests of the peer you are evaluating.
* Submit your work to your assigned git repository. Only the work in the git repository will be graded. If Deepthought is assigned to grade your work, it will be done after your peer-evaluations. If an error happens in any section of your work during Deepthought’s grading, the evaluation will stop.

## Mandatory part
| | |
 :--- | :--- 
Program name | fdf
Turn in files | Makefile, *.h, *.c
Makefile | NAME, all, clean, fclean, re
Arguments | A file in format *.fdf
External functs. | * open, close, read, write, malloc, free, perror, strerror, exit<br>* All functions of the math library (-lm compiler option, man man 3 math)<br>* All functions of the MiniLibX<br>* ft_printf and any equivalent YOU coded
Libft authorized | Yes
Description | This project is about creating a simple wireframe model of a landscape.

This project is about creating a simple wireframe model representation of a 3D landscape by linking various points (x, y, z) thanks to line segments (edges).
Your project must comply with the following rules:
* You must use the MiniLibX. Either the version available on the school machines, or installing it using its sources.
* You have to turn in a Makefile which will compile your source files. It must not relink.
* Global variables are forbidden.

## Rendering
Your program has to represent the model in isometric projection. The coordinates of the landscape are stored in a .fdf file passed as a parameter to your program. Here is an example:

Each number represents a point in space:
* The horizontal position corresponds to its axis.
* The vertical position corresponds to its ordinate.
* The value corresponds to its altitude.
Should render a landscape similar to:

Remember to use of your libft the best way you can! Using get_next_line(), ft_split() and other functions will allow you to read data from the file in a quick and simple way.
Keep in mind that the goal of this project is not to parse maps! However, this doesn’t mean that your program should crash when run. It means that we assume the map contained in the file is properly formatted. Executing your fdf program using the example file 42.fdf:

## Graphic management
* Your program has to display the image in a window.
* The management of your window must remain smooth (changing to another window, minimizing, and so forth).
* Pressing ESC must close the window and quit the program in a clean way.
* Clicking on the cross on the window’s frame must close the window and quit the program in a clean way.
* The use of the images of the MiniLibX is mandatory.

> On the intranet project page, a binary file called fdf as well as the example file 42.fdf inside a fdf.zip are available to download.

# Bonus part
Usually, you would be encouraged to develop your own original extra features. However, there will be much more interesting graphic projects later. They are waiting for you!! Don’t lose too much time on this assignment! You are allowed to use other functions to complete the bonus part as long as their use is justified during your evaluation. Be smart!

You will get some extra points if you can:
* Include one extra projection (such as parallel or conic)!
* Zoom in and out.
* Translate your model.
* Rotate your model.
* Add one more bonus of your choice.

> The bonus part will only be assessed if the mandatory part is PERFECT. Perfect means the mandatory part has been integrally done and works without malfunctioning. If you have not passed ALL the mandatory requirements, your bonus part will not be evaluated at all.

# Submission and peer-evaluation
Turn in your assignment in your Git repository as usual. Only the work inside your repository will be evaluated during the defense. Don’t hesitate to double check the names of your files to ensure they are correct. As these assignments are not verified by a program, feel free to organize your files as you wish, as long as you turn in the mandatory files and comply with the requirements.
