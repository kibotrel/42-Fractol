# 42-Libft
The very first school project at 42. This repository contains most of the project **libft** and all the function that I thought useful at some point in the cursus.

## Install
This project works on any **macOS X** and **Debian Stretch 9.8** for sure and should everywhere else (not sure). To compile the library, simply run :
```
$> make
```

You'll get a static library called **libft.a** at repository's root. In order to use it afterwards you may have to include it to the compilation when you call any function of the library in another project.
```
$> gcc -I./LIB_FOLDER/incs -L./LIB_FOLDER/ -lft [...]
```

## Breakdown
All functions in this repository is organised in different categories.

Category | Number of functions
:---: | :---:
Display | 9
Control | 22
String manipulation | 11
Conversion | 7
Memory manipulation | 8
File manipulation | 1
Total | 57

Every function is documented in the [**wiki**](https://github.com/kibotrel/42-Libft/wiki), check it out for more informations !
