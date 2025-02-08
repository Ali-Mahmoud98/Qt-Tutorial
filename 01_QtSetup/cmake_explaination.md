# CMakeLists Setup:

To build and run your Qt C++ application using **CMake**, you'll need a `CMakeLists.txt` file that:  
- Specifies the required **CMake version**.  
- Finds the **Qt** libraries (`Qt6` or `Qt5`).  
- Creates an **executable**.  
- Links the **Qt libraries** properly.  

---

## Specifies the **CMake version**, project name, header, and source files.
```CMake
cmake_minimum_required(VERSION 3.22.1)

project("01_QtSetup")

# List of header files (if any)
set(HEADER_FILES
    # Add your header files here, e.g., mainwindow.h
)

# List of source files
set(SOURCE_FILES
    main.cpp
    # Add other source files here, e.g., mainwindow.cpp
)
```

---
## Finds the **Qt** libraries (`Qt6` or `Qt5`).
You may need to tell CMake where to find Qt (or other dependencies) when it’s not installed in a standard location by using the following command:
```CMake
set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} "/path/to/Qt6")
```
* `set(...)`: This sets a CMake variable.
* `CMAKE_PREFIX_PATH`: A CMake search path variable that tells CMake where to look for installed packages (like Qt).
* `${CMAKE_PREFIX_PATH}`: The existing value of `CMAKE_PREFIX_PATH` (if any).
* `"/path/to/Qt6"`: The directory where Qt is installed.
* The full line appends `"/path/to/Qt6"` to the existing `CMAKE_PREFIX_PATH` value.

### 🔹 Why is This Needed?

By default, CMake searches **standard system paths** for installed libraries.
However, if Qt is installed in a **non-standard location** (e.g., manually installed or custom Qt versions), CMake **won’t find it** automatically.

👉 **This line tells CMake explicitly where to look for Qt.**

### 🔹 Alternative: Set It in the Terminal
Instead of modifying `CMakeLists.txt`, you can set `CMAKE_PREFIX_PATH` in the shell before running CMake:
```sh
export CMAKE_PREFIX_PATH="/path/to/Qt6"
```
This method is useful if you don’t want to hardcode the path in `CMakeLists.txt`.


### The second part of cmake:
```cmake
find_package(Qt6 COMPONENTS Core Gui Widgets REQUIRED)

# Moc header files (if you have headers with Q_OBJECT macros)
qt6_wrap_cpp(HEADER_MOC ${HEADER_FILES})
```
####  **🔹 What Does `find_package(Qt6 ...)` Do?**
This line **searches for Qt6** in the system and makes the specified Qt6 components **available for linking**.

##### **📌 Breaking it Down**
```cmake
find_package(Qt6 COMPONENTS Core Gui Widgets REQUIRED)
```
- **`find_package(Qt6 ...)`**  
  - This tells CMake to search for the **Qt6 package**.
- **`COMPONENTS Core Gui Widgets`**  
  - Specifies that we need the following **Qt6 modules**:
    1. **Core** → Essential non-GUI functionality (event loop, file handling, etc.).
    2. **Gui** → Basic GUI-related functionality (2D graphics, fonts, colors).
    3. **Widgets** → Provides traditional widget-based UI elements (`QWidget`, `QPushButton`, etc.).
- **`REQUIRED`**  
  - If Qt6 **is not found**, CMake **will generate an error** and stop processing.

##### **🔹 Where Does CMake Look for Qt?**
CMake checks:
1. **System paths** (e.g., `/usr/lib`, `/usr/local/lib`).
2. **Custom paths set by `CMAKE_PREFIX_PATH`** (if Qt is in a non-standard location).
3. **CMake package registry** (if previously configured).

#### **🔹 What is MOC (Meta-Object Compiler)?**
- In Qt, `Q_OBJECT` macros **enable signals, slots, and reflection** in C++ classes.
- The **Meta-Object Compiler (MOC)** processes header files containing `Q_OBJECT` to generate **additional C++ source files**.
- These generated files are **required** for proper compilation.

#### **📌 What Does `qt6_wrap_cpp(...)` Do?**
```cmake
qt6_wrap_cpp(HEADER_MOC ${HEADER_FILES})
```
- **`qt6_wrap_cpp(...)`**  
  - This is a Qt-specific **CMake function** that:
    1. Detects which header files need MOC processing (files with `Q_OBJECT`).
    2. Runs MOC on these headers.
    3. Generates new C++ files containing the necessary **meta-object code**.
- **`HEADER_MOC`**  
  - This is a variable that stores the **generated source files**.
- **`${HEADER_FILES}`**  
  - This is a list of **header files** that might contain `Q_OBJECT`.

#### **🔹 When Do You Need This?**
You **must use `qt6_wrap_cpp(...)`** if you have **custom C++ classes** that:
1. **Inherit from `QObject`**.
2. **Use the `Q_OBJECT` macro**.
3. **Define signals, slots, or properties**.

----

## Create an **executable** and link the **Qt libraries**.
```cmake
add_executable(${PROJECT_NAME}
    ${SOURCE_FILES}
    ${HEADER_FILES}
    ${HEADER_MOC}
)

# Include the Qt libraries
set(QT_LIBS
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
)

# Link the executable target with Qt libraries
target_link_libraries(${PROJECT_NAME} PRIVATE ${QT_LIBS})

# Include directories (optional, depends on your project's needs)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Enable C++17 without compiler-specific extensions
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)
set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_EXTENSIONS OFF
)
```

GOOD to READ: [compile-features.md](./comile-features.md)
