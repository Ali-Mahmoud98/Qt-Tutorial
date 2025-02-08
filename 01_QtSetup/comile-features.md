# `target_compile_features` and `set_target_properties`
### **1️⃣ `target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)`**
### **2️⃣ `set_target_properties(${PROJECT_NAME} PROPERTIES CXX_EXTENSIONS OFF)`**

---

## **1️⃣ `target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)`**

### **🔹 What Does This Do?**
This command **enables C++17** (or a newer compatible standard) for your project.

### **📌 Breaking it Down**
```cmake
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)
```
- **`target_compile_features(...)`**  
  - Specifies **which C++ features** (like C++17 or C++20) should be used.
- **`${PROJECT_NAME}`**  
  - Refers to the name of the executable or library target defined earlier using `add_executable(...)` or `add_library(...)`.
- **`PUBLIC`**  
  - The **visibility** of this feature:
    - `PRIVATE`: Only applies to this target.
    - `PUBLIC`: Applies to this target **and** any dependent targets.
    - `INTERFACE`: Only applies to targets that depend on this one.
- **`cxx_std_17`**  
  - Enables **C++17** (or newer if the compiler supports it).

### **🔹 Why Use `target_compile_features(...)` Instead of `set(CMAKE_CXX_STANDARD 17)`?**
- `target_compile_features(...)` applies **only to a specific target**, making it more modular.
- `set(CMAKE_CXX_STANDARD 17)` applies **globally** to the entire project, which might not be desirable if different parts need different standards.

---

## **2️⃣ `set_target_properties(${PROJECT_NAME} PROPERTIES CXX_EXTENSIONS OFF)`**

### **🔹 What Does This Do?**
This **disables compiler-specific extensions** and ensures **strict C++ standard compliance**.

### **📌 Breaking it Down**
```cmake
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_EXTENSIONS OFF)
```
- **`set_target_properties(...)`**  
  - Sets special properties for a target.
- **`${PROJECT_NAME}`**  
  - The target (executable or library) being configured.
- **`PROPERTIES`**  
  - Specifies that we are modifying the project's properties.
- **`CXX_EXTENSIONS OFF`**  
  - Disables compiler-specific extensions.

### **🔹 Why Disable Extensions?**
Most compilers (like GCC and Clang) enable **non-standard C++ extensions** by default, which can cause:
1. **Portability Issues**: Code might work with one compiler but fail on another.
2. **Unexpected Behavior**: The compiler may allow non-standard features that break strict C++ compliance.
3. **Build Issues with Different Qt Versions**: Qt5 and Qt6 expect **strict C++ compliance** for better compatibility.

Disabling extensions ensures that the compiler **only allows standard C++** features.
