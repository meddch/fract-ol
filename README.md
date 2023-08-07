# fract-ol

Fract-ol is a project at 42 that involves creating a graphical representation of various fractals. The goal of this project is to implement an interactive program that allows users to explore and visualize fractal patterns in real-time.

## Project Overview

The Fract-ol project focuses on the generation and rendering of fractal images. Fractals are complex mathematical patterns that exhibit self-similarity at different scales. In this project, you'll implement algorithms to generate popular fractals such as the Mandelbrot set, the Julia set, and the Tricorn fractal.

The main objectives of the project include:

1. Implementing fractal generation algorithms.
2. Rendering fractal images using pixel manipulation techniques.
3. Interactively exploring and navigating the fractal space.
4. Implementing zooming and color manipulation features.
5. Optimizing the rendering process for real-time visualization.

## How to Use Fract-ol

To compile the Fract-ol program, run the following command:

```
make
```

This will generate an executable named `fractol`.

To execute Fract-ol, use the following syntax:

```
./fractol fractal_name
```

- `fractal_name` is the name of the fractal to be rendered. It can be one of the following: `mandelbrot`, `julia`, or `tricorn`.

Here's an example usage of Fract-ol:

```
./fractol tricorn
```

This will launch the Fract-ol program and render the Tricorn fractal.

## Controls

Once the Fract-ol program is running, you can use the following controls to interact with the fractal:

- Zoom: Scroll up or down to zoom in or out.
- Move: Click and drag the fractal to move it around.
- Change Parameters (Julia Set and Tricorn only): Move the mouse to change the parameters of the fractal.

## Learning Objectives

The Fract-ol project provides an opportunity to learn and practice various concepts, including:

- Understanding and implementing fractal generation algorithms.
- Rendering graphics using pixel manipulation techniques.
- Interacting with graphical user interfaces (GUIs).
- Implementing zooming and panning functionality.
- Working with complex numbers and mathematical calculations.
- Optimizing rendering processes for real-time visualization.

## Resources

Here are some resources that can be helpful for completing the Fract-ol project:

- [Fractals](https://en.wikipedia.org/wiki/Fractal)
- [Mandelbrot Set](https://en.wikipedia.org/wiki/Mandelbrot_set)
- [Julia Set](https://en.wikipedia.org/wiki/Julia_set)
- [Tricorn Fractal](https://en.wikipedia.org/wiki/Tricorn_(mathematics))
- [Pixel Manipulation](https://www.geeksforgeeks.org/pixel-manipulation-in-c-c/)
- [GUI Programming in C](https://www.geeksforgeeks.org/gui-programming-in-c-language/)
- [Complex Numbers in C](https://www.geeksforgeeks.org/complex-number-arithmetic-in-c/)
- [Optimizing Graphics Rendering](https://developer.nvidia.com/blog/parallelforall/optimizing-opengl-es-2-0-based-2d-3d-graphics-applications/)
- [MiniLibX](https://github.com/42Paris/minilibx-linux) - A simple graphics library used for the Fract-ol project.

To add MiniLibX to your Fract-ol project, follow these steps:

1. Download MiniLibX from the [official GitHub repository](https://github.com/42Paris/minilibx-linux).
2. Extract the MiniLibX source code to a directory of your choice.
3. Configure MiniLibX by running `make` inside the MiniLibX directory.
4. Copy the generated `libmlx.a` library file to your Fract-ol project directory.
5. Add `-lmlx -L. -lXext -lX11 -lm` to the `LIBS` variable in your project's Makefile.
6. Include the MiniLibX headers in your Fract-ol source files using `#include "mlx.h"`.

Good luck with your Fract-ol project! Enjoy exploring the mesmerizing world of fractals and have fun implementing interactive visualizations!
