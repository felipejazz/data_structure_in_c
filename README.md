# Data Structures in C++

This repository is intended for studying and implementing data structures in C++ using `assert`-based tests for validation. Currently, the following data structures are implemented:

- **Queue**
- **Stack**
- **Linked Queue**
- **Linked Stack**
- **Hash Table**
- **Tree**
- **AVL Tree**
- **Graph**



In the future, other data structures (e.g., `List`, `Tree`, `Graph`, etc.) will be added following the exact same folder organization—only the data-structure-specific names will change.

---

## Project Structure

Below is a simplified view of the directory structure (omitting build artifacts and other automatically generated files):

```bash 
.
├── HashTable
│   ├── CMakeLists.txt
│   ├── include
│   │   ├── BaseObject.hpp
│   │   ├── CMakeLists.txt
│   │   └── HashTable.hpp
│   ├── src
│   │   ├── BaseObject.cpp
│   │   ├── CMakeLists.txt
│   │   └── HashTable.cpp
│   └── tests
│       ├── CMakeLists.txt
│       └── TestHashTable.cpp
.
.
.


```

Each data structure has:

- A `build` folder (where build and compilation files are generated).
- An `include` folder (where header files reside).
- A `src` folder (where the implementation `.cpp` files live).
- A `tests` folder (with test files that use `assert` to verify correctness).

---

## How to Build and Test

For each data structure, you can compile and run tests by following these steps:

1. **Navigate** to the specific data structure’s directory (e.g., `queue/` or `stack/`).
2. **Enter** the `build` directory within that data structure, for example:
   ```bash
   cd queue
   mkdir build
   cd build
    ```
Run CMake to generate the build files:
   ```bash
    cmake ..
```
Compile the project:
```bash
    make
 ```
Run the tests inside the build directory. Tests are located in ./tests/:
```bash
    ./tests/test_queue
```

    (For the stack data structure, you would run ./tests/test_stack, etc.)

Repeat similar steps for any other data structure you want to build and test.
Navigational Guide

    Root Directory: Contains general files like hello_world.cpp.
    <data_structure>/include: Headers for the specified data structure.
    <data_structure>/src: Source files for the specified data structure.
    <data_structure>/tests: Test files using assert statements.
    <data_structure>/build: Compiled artifacts are generated here after running cmake .. && make.


To build and run this project, you need:

    CMake (version >= 3.x)
    Make (or a compatible build system)
    A C++ compiler that supports C++11 (or higher)
