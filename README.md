![julia_0](/screenshots/julia_0.png)
# 42-Fractol

This project's goal is to make a fractal visualizer.

## Install

Only works on **42-Paris Dumps** at the moment but should be portable on any **macOS X** in the near future.

Simply type command bellow in your shell :
```
$> brew install pidof && make
```

## Usage
### Run the program

Once the program is compiled, run it with the following command line :
```
$> ./fractol 'Desired Fractal'
```
To get more informations on how the program works and how you can interact with it type :
```
$> ./fractol
```
To set everything up before running the visualizer with a graphic interface do :
```
$> ./fractol menu
```

### Fractal list

Every fractal bellow are handled by the program.

Name | Type | Multithread
:---: | :---: | :---:
Mandelbrot | Complex | :heavy_check_mark:
Julia | Complex | :heavy_check_mark:
Burning Ship | Complex | :heavy_check_mark:
Burning Julia | Complex | :heavy_check_mark:
Sierpinski triangle | Space filling curve | :heavy_multiplication_x:
Van Koch's snowfake | Auto-similar | :heavy_multiplication_x:
Barnsley's fern | Random generation | :heavy_multiplication_x:
Flower (Original) | Space filling and auto-similar | :heavy_multiplication_x:

### Controls

Keyboard :
* **W / A / S / D** Shift the displayed fractal by a fixed length in the desired direction
* **1 / 2 / 3 / 4 / 5 / 6 / 7 / 8** Change the displayed fractal in the visualizer
* **M** Update the used coloring process between **Gradient mode** and **Areas mode**
* **V / B / N** Modify the color used in **Gradient mode**
* **Z / X / C** Modify the color used in **Areas mode**
* **Page_Up / Page_Down** Update the amount of details in the displayed fractal
* **P** Trigger **Psychedelic mode**
* **J / K / L** Modify the audiofile used in **Psychedelic mode**
* **~** Toggle the variation of **Julia** and **Burning Julia** using mouse cursor position
* **R** Reset everything to the default point of view
* **ESC** Quit the visualizer

Mouse:
* **Mouse Wheel** Update the **zoom level** depending on the scroll direction
* **Cursor** Update **preset complex** in both **Julia** and **Burning Julia** fractals

## Error management

Each following error is handled by the program leading to a complete memory free and program exit :
* Invalid fractal name (*ERROR-CODE 1*)
* Failed memory allocation (*ERROR-CODE 2*)
* Failed to fork the process (*ERROR-CODE 3*)
* Failed to create a thread (*ERROR-CODE 4*)
* Failed to play an audio file (*ERROR-CODE 5*)
* Audio file unavailable (*ERROR-CODE 6*)

Whenever one of these error occurs, the correct error message is displayed on the **standard output** and the whole program return an error code that you can retrieve by running :
```
$> echo $?
```

## Screenshots
![mandelbrot_0](/screenshots/mandelbrot_0.png)
![mandelbrot_1](/screenshots/mandelbrot_1.png)
![julia_1](/screenshots/julia_1.png)
![julia_2](/screenshots/julia_2.png)
![julia_3](/screenshots/julia_3.png)
![burning_ship](/screenshots/burning_ship.png)
![burning_julia_0](/screenshots/burning_julia_0.png)
![burning_julia_1](/screenshots/burning_julia_1.png)
![sierpinski](/screenshots/sierpinski.png)
![koch](/screenshots/koch.png)
![barnsley](/screenshots/barnsley.png)
![flower](/screenshots/flower.png)
![menu_0](/screenshots/menu_0.png)
![menu_11](/screenshots/menu_1.png)
![menu_2](/screenshots/menu_2.png)
