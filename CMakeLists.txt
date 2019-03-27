cmake_minimum_required(VERSION 3.10)
project(itmo_prog_tasks)

set(CMAKE_CXX_STANDARD 11)

add_executable(w1task2 week1/task2.c)
add_executable(w1task3 week1/task3.c)
add_executable(w1task4 week1/task4.c)
add_executable(w1task5 week1/task5.c)
add_executable(w1task6 week1/task6.c)
add_executable(w1task7 week1/task7.c)
add_executable(w1task8 week1/task8.c)
add_executable(w1task9 week1/task9.c)
add_executable(w1task10 week1/task10.c)
add_executable(w1task11 week1/task11.c week1/circle.h week1/circle.c )
add_executable(w1task12 week1/task12.c)
add_executable(w1task13p week1/tag_parser.c)

add_executable(w2task1 week2/lab1/task1.cpp week2/lab1/task1.h)
add_executable(w2task2 week2/lab2/task2.cpp week2/lab2/task2.h)
add_executable(w2task3 week2/lab3/vector3.cpp week2/lab3/vector3.h week2/lab3/polynom.cpp week2/lab3/polynom.h)
add_executable(w2task4 week2/lab4/ellipse.cpp week2/lab4/ellipse.h week2/lab4/circle.cpp week2/lab4/circle.h)

