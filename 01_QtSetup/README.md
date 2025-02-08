# 01_QtSetup

## **main.cppCode Explanation**
#### **1. Including Necessary Headers**
```cpp
#include <QApplication>
#include <QWidget>
```
- `#include <QApplication>`:  
  - This header is required to create a Qt application.  
  - `QApplication` is responsible for handling application-wide resources such as event handling and GUI management.
  
- `#include <QWidget>`:  
  - This header is needed to create a basic window.  
  - `QWidget` is the base class for all UI objects in Qt.  
  - It represents a generic window or UI element.

---

#### **2. The `main` Function (Entry Point)**
```cpp
int main(int argc, char* argv[])
```
- Every C++ program starts execution from `main()`.
- `argc`: Represents the number of command-line arguments.
- `argv`: An array of character pointers representing command-line arguments.
- These arguments are passed to `QApplication` for handling command-line options.

---

#### **3. Creating a Qt Application**
```cpp
QApplication app(argc, argv);
```
- `QApplication` object is created with `argc` and `argv`.
- This object:
  - Initializes the application.
  - Handles event processing.
  - Manages GUI elements.

⚠️ **Important:** Every Qt GUI application **must** create a `QApplication` instance before creating any widgets.

---

#### **4. Creating a Widget (Window)**
```cpp
QWidget* widget = new QWidget();
```
- `QWidget` is a base class for all graphical elements in Qt.
- `new QWidget()` creates a new **window** dynamically (on the heap).
- The pointer `widget` stores the address of the newly created window.

---

#### **5. Setting Window Properties**
```cpp
widget->setWindowTitle("Hello Qt visual C++");
```
- `setWindowTitle("Hello Qt visual C++")` sets the title of the window.

```cpp
widget->setGeometry(0, 0, 2000, 1080);
```
- `setGeometry(x, y, width, height)` defines the **position** and **size** of the window.
  - `(0, 0)`: Position of the window (top-left corner).
  - `2000`: Width of the window.
  - `1080`: Height of the window.

---

#### **6. Displaying the Window**
```cpp
widget->show();
```
- `show()` makes the window **visible** on the screen.
- If `show()` is **not** called, the window will be created but remain hidden.

---

#### **7. Running the Event Loop**
```cpp
return app.exec();
```
- `app.exec()` starts the **event loop**.
- The event loop:
  - Waits for user interactions (mouse clicks, keyboard inputs, etc.).
  - Processes system events (window resizing, closing, etc.).
  - Keeps the application running until the user closes it.

---

### **Summary of the Code**
1. **QApplication** manages the application lifecycle.
2. **QWidget** creates a window.
3. **setWindowTitle()** sets the title.
4. **setGeometry()** sets the size and position.
5. **show()** makes the window visible.
6. **app.exec()** starts the event loop.

---

### **Possible Improvements**
✅ **Avoid Using Raw Pointers**  
Instead of:
```cpp
QWidget* widget = new QWidget();
```
Use:
```cpp
QWidget widget;
widget.setWindowTitle("Hello Qt visual C++");
widget.setGeometry(0, 0, 2000, 1080);
widget.show();
```
- This avoids **manual memory management**.
- The object is automatically destroyed when it goes out of scope.

----

### **What Does `QApplication` Support?**  
The `QApplication` class is the **core application manager** in Qt. It **manages application-wide resources** and is necessary for any Qt GUI application.  

#### **Main Features of `QApplication`:**
- **Event Handling**:  
  - Captures and processes user inputs (mouse clicks, key presses, etc.).
  - Uses an **event loop** to keep the GUI responsive.
- **Window Management**:  
  - Ensures correct rendering and behavior of all Qt widgets.
- **Clipboard and Drag & Drop**:  
  - Provides access to system clipboard and drag-and-drop functionality.
- **Global Settings**:  
  - Stores application-wide settings (e.g., fonts, styles, themes).
- **Translators and Localization**:  
  - Supports multilingual applications.
- **Command-Line Argument Processing**:  
  - Can parse command-line options passed to the application.

#### **Header File:**
```cpp
#include <QApplication>
```
Located in **QtCore** and **QtGui** modules.

---

### **What Does `QWidget` Support?**  
`QWidget` is the **base class** for all graphical user interface (GUI) elements in Qt.  

#### **Main Features of `QWidget`:**
- **Window & UI Component**:
  - It can be a **window** or a **UI component** inside another widget.
- **Parent-Child Relationship**:
  - Widgets can be nested to create complex layouts.
- **Geometry Management**:
  - Supports positioning, resizing, and automatic layout handling.
- **Custom Painting**:
  - Can be customized using `QPainter` for custom graphics.
- **Event Handling**:
  - Handles keyboard/mouse input, focus events, and paint events.
- **Styling & Theming**:
  - Supports **Qt Style Sheets (QSS)** for custom appearance.
  
#### **Header File:**
```cpp
#include <QWidget>
```
Located in **QtWidgets** module.

---

### **What is a `QWidget` (Conceptually)?**  
A `QWidget` is a **visual element** in Qt. It can be:
- A **window** (`QWidget` with no parent).
- A **container** (holding other widgets inside).
- A **component** (e.g., button, label, text field).

#### **Examples of Widgets in Qt:**
| Widget Class | Description |
|-------------|-------------|
| `QWidget` | Generic UI element (can be a window or container). |
| `QMainWindow` | Main application window with menus, toolbars. |
| `QPushButton` | A clickable button. |
| `QLabel` | Displays text or images. |
| `QLineEdit` | Editable text field. |
| `QTextEdit` | Multi-line text editor. |
| `QCheckBox` | Checkbox for toggling options. |

---

### **Example: Different Uses of `QWidget`**
#### **1️⃣ `QWidget` as a Window**
```cpp
#include <QApplication>
#include <QWidget>

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("Standalone QWidget");
    window.resize(400, 300); // Set width = 400, height = 300
    window.show();

    return app.exec();
}
```
👉 `window` acts as a standalone **window**.

---

#### **2️⃣ `QWidget` as a Container**
```cpp
#include <QApplication>
#include <QWidget>
#include <QPushButton>

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("Container Widget");
    window.resize(400, 300);

    QPushButton button("Click Me", &window); // Button inside the window
    button.setGeometry(100, 100, 200, 50);   // x=100, y=100, width=200, height=50

    window.show();
    return app.exec();
}
```
👉 `window` **contains** a button.

---

### **Summary about `QApplication` and `QWidget`**
1. `QApplication` → Manages the **entire** application.
2. `QWidget` → The **base class** for all UI elements.
3. A `QWidget` can be a **window**, **container**, or **UI component**.

---

### **GOOD To READ:**
* [cmake_explaination.md](./cmake_explaination.md)
