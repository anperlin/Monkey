# Monkey Library for Arduino

## Introduction

Monkey is a C++ library for Arduino designed to make programming easier, especially for beginners. It allows you to write code in a way that closely resembles natural language, significantly reducing the need to use C, which can be hard to learn for non-programmers.

## Features

Monkey provides commands as C macros and functions that can be easily used in any C/C++ Arduino sketch.  
Examples:
- Control multiple pins with a single instruction.
- Use non-blocking timers instead of `delay()` to avoid halting the main loop.

## Structure

The library includes:
- C preprocessor macros.
- A class for managing timers.
- A class for handling buttons and switches.
- Functions to initialize and configure Arduino pins.

## Disclaimer

This library was created for educational purposes. The author assumes no responsibility for its use in critical applications.  
**If you choose to use it to control a nuclear reactor, you do so at your own risk.**

## Installation

1. Create a folder named `monkey` inside `Arduino/libraries`.
2. Copy the following files into it: `monkey.h`, `monkey.cpp`, `keywords.txt`, `COPYING.LESSER`.
3. Open the Arduino IDE and go to **Sketch > Include Library > Manage Libraries**.
4. Type `monkey` in the search bar, select the library, and click **Install**.

## Documentation

Check the project wiki for the list of available commands and practical examples.
