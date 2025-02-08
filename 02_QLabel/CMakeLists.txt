cmake_minimum_required(VERSION 3.22.1)

project("02_QLabel")

# List of header files (if any)
set(HEADER_FILES
    # Add your header files here, e.g., mainwindow.h
)

# List of source files
set(SOURCE_FILES
    main.cpp
    # Add other source files here, e.g., mainwindow.cpp
)

# you may want to include the following line 
set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} /home/ali-mahmoud/Qt/6.7.3/gcc_64/lib/cmake/Qt6)

message(STATUS "CMAKE_PREFIX_PATH: ${CMAKE_PREFIX_PATH}")

# Find the Qt6 packages you need
find_package(Qt6 COMPONENTS Core Gui Widgets REQUIRED)

# Find the Qt5 packages needed
# find_package(Qt6Core CONFIG REQUIRED)
# find_package(Qt6Widgets CONFIG REQUIRED)
# find_package(Qt6Gui CONFIG REQUIRED)

# Moc header files (if you have headers with Q_OBJECT macros)
qt6_wrap_cpp(HEADER_MOC ${HEADER_FILES})

# Add the executable target
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
