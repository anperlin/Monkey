Monkey Library for Arduino – A Macro Library to Simplify Arduino Programming

Monkey is a C++ library for Arduino designed to make programming easier, especially for beginners. It provides commands that allow you to write code in a way that closely resembles natural language, significantly reducing the need to write in C, which can be challenging for those without prior programming experience.

The commands in Monkey are implemented as C macros and functions, and can be used within any C/C++ Arduino sketch. They help simplify tasks such as changing the state of multiple pins with a single command or using non-blocking timers to perform periodic actions without stopping program execution (unlike delay()).

The library is mainly composed of C preprocessor macros, a timer management class, a class to handle buttons and switches, and several helper functions to initialize and configure Arduino pins.

Disclaimer: This library was developed for educational purposes. The author assumes no responsibility for its use in critical applications. If you choose to use it to control a nuclear reactor’s cooling system… you do so at your own risk.

Installation
To install the Monkey library:

Create a folder named monkey inside your Arduino\libraries directory.

Download and copy the following files into it: monkey.h, monkey.cpp, keywords.txt, and COPYING.LESSER.

Open the Arduino IDE and go to Sketch > Include Library > Manage Libraries.

In the search bar, type monkey. The library should appear.

Select it and click the button in the bottom-right corner to install it.

For a complete list of available commands and usage examples, check the project wiki.
