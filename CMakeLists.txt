cmake_minimum_required(VERSION 3.14)
project(OOP_2nd_Course_1Lab)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)

add_subdirectory(lib/googletest)

include_directories(Lists)
include_directories(Test)
include_directories(GUI)
include_directories(Books/headers)
include_directories(Books/sources)
include_directories(lib/googletest/googletest/include)

set(PYTHON_EXECUTABLE C:/Users/vetal/AppData/Local/Programs/Python/Python37-32)

add_executable(OOP_2nd_Course_1Lab Lists/Lists.cpp Lists/Lists.h main.cpp Books/sources/Book.cpp Books/headers/Book.h Books/sources/Literature.cpp Books/headers/Literature.h Test/test.cpp Books/sources/Date.cpp Books/headers/Date.h Books/sources/Character.cpp Books/headers/Character.h Books/sources/Global_Character.cpp Books/headers/Global_Character.h demo.cpp Test/gtest.cpp GUI/mainwindow.cpp GUI/mainwindow.h GUI/mainwindow.ui GUI/addbook.cpp GUI/addbook.h GUI/addbook.ui GUI/addvalue.cpp GUI/addvalue.h GUI/addvalue.ui)

target_link_libraries(OOP_2nd_Course_1Lab gtest Qt5::Core Qt5::Quick Qt5::Sql)

find_package(Qt5Widgets)

find_package(Qt5 REQUIRED COMPONENTS Core Quick Sql)

qt5_use_modules(OOP_2nd_Course_1Lab Widgets)
