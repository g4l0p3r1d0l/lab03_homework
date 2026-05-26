# Отчёт по лабораторной работе №3. Домашнее задание

**Репозиторий:** https://github.com/g4l0p3r1d0l/lab03_homework

## Задание 1. Статическая библиотека `formatter`

**`formatter_lib/CMakeLists.txt`**
```cmake
cmake_minimum_required(VERSION 3.10)
project(formatter_lib)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(formatter STATIC formatter.cpp)
target_include_directories(formatter PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
```

## Задание 2. Библиотека `formatter_ex` (расширение)

**`formatter_ex_lib/CMakeLists.txt`**
```cmake
cmake_minimum_required(VERSION 3.10)
project(formatter_ex_lib)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(formatter_ex STATIC formatter_ex.cpp)
target_include_directories(formatter_ex PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(formatter_ex formatter)
```

## Задание 3. Приложения

### Приложение `hello_world`
**`hello_world_app/CMakeLists.txt`**
```cmake
cmake_minimum_required(VERSION 3.10)
project(hello_world_app)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(hello_world main.cpp)
target_link_libraries(hello_world formatter_ex)
```

### Приложение `solver`
**`solver_app/CMakeLists.txt`**
```cmake
cmake_minimum_required(VERSION 3.10)
project(solver_app)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(solver main.cpp)
target_link_libraries(solver formatter_ex solver_lib)
```

### Библиотека `solver_lib`
**`solver_lib/CMakeLists.txt`**
```cmake
cmake_minimum_required(VERSION 3.10)
project(solver_lib)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(solver_lib STATIC solver.cpp)
target_include_directories(solver_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
```

### Корневой `CMakeLists.txt`
```cmake
cmake_minimum_required(VERSION 3.10)
project(FormatterProject)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(formatter_lib)
add_subdirectory(formatter_ex_lib)
add_subdirectory(solver_lib)
add_subdirectory(hello_world_app)
add_subdirectory(solver_app)
```

## Сборка и запуск

```bash
mkdir build && cd build
cmake ..
cmake --build .
```

### Результаты

**hello_world:**
```bash
$ ./hello_world_app/hello_world
Formatted: Hello, World! [EXTRA]
```

**solver (дискриминант < 0):**
```bash
$ ./solver_app/solver
Enter a, b, c: 1 2 3
Formatted: Roots:  [EXTRA]
```

**solver (корни 2 и 1):**
```bash
$ ./solver_app/solver
Enter a, b, c: 1 -3 2
Formatted: Roots: 2.000000 1.000000  [EXTRA]
```

## Выводы

- Созданы статические библиотеки `formatter`, `formatter_ex`, `solver_lib`.
- Написаны приложения `hello_world` и `solver`, использующие эти библиотеки.
- Проект собран с помощью CMake без ошибок.
- Изучены основные команды CMake: `add_library`, `target_link_libraries`, `target_include_directories`, `add_subdirectory`.
