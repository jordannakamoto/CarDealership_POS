# Car Dealership App - 355 Databases Project

![GitHub contributors](https://img.shields.io/github/contributers/jordannakamoto/355CarDealership/)

Simple app with a UI that demonstrates a cpp program that interacts local mysql database.

## Table of Contents
- [Car Dealership App - 355 Databases Project](#car-dealership-app---355-databases-project)
  - [Table of Contents](#table-of-contents)
  - [Getting Started / Installation](#getting-started--installation)
  - [Running the App](#running-the-app)
  - [Development](#development)
  - [Authors](#authors)
      - [Jordan Nakamoto](#jordan-nakamoto)
  - [License](#license)
  - [Acknowledgments](#acknowledgments)

## Getting Started / Installation

If you haven't installed mysql locally, please do so. Additionally, I am using mycli as my interface in iTerm2 to interact with mysql from a Mac Terminal.

Clone GitHub project and install dependency libraries on your computer.

For mysql-cpp data interface:
1. Setup Oracle mysqlcppconnector
https://github.com/mysql/mysql-connector-cpp

2. Connect the CPP linker to the library locations in the makefile. Current setup is for M1 Macbook Air filesystem
   - using lmysqlcppconn8 - version 8 of the connector
   - two source directories must be linked by their path from download location to the compiler

3. Download http://wxwidgets.org, the GUI library.
  - on MacOSX this is most easily done through Homebrew Package Manager
  - once again, this library has been linked in the Makefile for building on M1 Mac filesystem as documented here:
  - https://wiki.wxwidgets.org/Wx-Config

Note: Makefile is also using clang c++ compiler which is default on M1 Mac.

```
	355CARDEALERSHIP
	├── Assets     - png logo image
	└── Functions  - CRUD mysql functions
  └── SQLCode    - Plain .sql files to copy and paste into mysql cli in order to setup initial data
  app            - compiled program
  main.cpp       - main program, setup and draw UI, connect to mysql
  Makefile       - for compiling and building
```

## Running the App

* Commands from VSCode integrated terminal:
  ```
    make
    ./app
  ```

## Development

Intended basic functionality is implemented for the sale data type. For other data types, only read is implemented so the project can be extended.

TODO:
- move authentication to a settings panel
- make a panel for creating a new sale
- better UI for information based on its application value. I.E. make the employee name more accessible throughout the UX than their ID or Address.


## Authors

#### Jordan Nakamoto
* [GitHub]

## License

`Project Title` is open source software [licensed as MIT][license].

## Acknowledgments

Professor Vysala - Sonoma State University

* Team Members
  
[//]: # (HyperLinks)

[GitHub]: https://github.com/jordannakamoto

[license]: https://github.com/madhur-taneja/README-template/blob/master/LICENSE.md
