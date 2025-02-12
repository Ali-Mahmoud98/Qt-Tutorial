cmake_minimum_required(VERSION 3.22.1)

project("My_Text_Editor")

# Enable automatic processing of Q_OBJECT classes
# set(CMAKE_AUTOMOC ON)

option(USE_QOBJECT_MACRO "Use Q_OBJECT macro" OFF)
if(USE_QOBJECT_MACRO)
    set(CMAKE_AUTOMOC ON)
    add_compile_definitions(USE_QOBJECT_MACRO)
endif()


# List of header files (if any)
set(HEADER_FILES
    # Add your header files here, e.g., mainwindow.h
    main_window/inc/mainWindow.hpp
)

# List of source files
set(SOURCE_FILES
    main.cpp
    # Add other source files here, e.g., mainwindow.cpp
    main_window/src/mainWin.cpp
    main_window/src/menuBar.cpp
    main_window/src/statusBar.cpp
    main_window/src/toolbar.cpp
    main_window/src/open.cpp
    main_window/src/new.cpp
    main_window/src/save.cpp
    main_window/src/helperFunctions.cpp
)

option(ADD_PAGE_SETUP "Compile and link page_setup.cpp" OFF)

if(ADD_PAGE_SETUP)
    add_compile_definitions(ADD_PAGE_SETUP)
    list(APPEND SOURCE_FILES main_window/src/myPageSetup.cpp)
endif()


set(RESOURCES_FILES
	resources/resources.qrc
)

# you may want to include the following line 
set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} /home/ali-mahmoud/Qt/6.7.3/gcc_64/lib/cmake/Qt6)

message(STATUS "CMAKE_PREFIX_PATH: ${CMAKE_PREFIX_PATH}")

# Find the Qt6 packages you need
find_package(Qt6 COMPONENTS Core Gui Widgets REQUIRED)

# Moc header files (if you have headers with Q_OBJECT macros)
qt6_wrap_cpp(HEADER_MOC ${HEADER_FILES})
qt6_add_resources(RESOURCE_ADDED ${RESOURCES_FILES})

# Add the executable target
add_executable(${PROJECT_NAME}
    ${SOURCE_FILES}
    ${HEADER_FILES}
    ${HEADER_MOC}
    ${RESOURCE_ADDED}
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
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/main_window/inc)

# Enable C++17 without compiler-specific extensions
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)
set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_EXTENSIONS OFF
)
