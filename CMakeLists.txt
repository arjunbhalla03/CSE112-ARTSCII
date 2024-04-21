CMAKE_MINIMUM_REQUIRED(VERSION 3.2)
project(ArtScii)


add_compile_options(-Wall -Wextra -pedantic -ansi -O3 -std=c++11)

ADD_EXECUTABLE(ArtScii
    main.cpp
    src/Picture.cpp
    src/Settings.cpp
    lodepng/lodepng.cpp
)


