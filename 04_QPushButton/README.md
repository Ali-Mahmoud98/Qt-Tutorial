# QPushButton, Signals, Slots

## **Signals and Slots**
You Can Read:
* [Signals and slots - Wikipedia](https://en.wikipedia.org/wiki/Signals_and_slots)
* [Signals and Slots - MIT](https://web.mit.edu/~firebird/arch/sun4x_58/doc/html/signalsandslots.html)
* [Signals and Slots - Qt Docs](https://doc.qt.io/qt-6/signalsandslots.html)

Qt uses a signal and slot mechanism to enable communication between objects in a safe and flexible way. This is one of the core features of Qt and allows loose coupling between UI components and logic.

**NOTE:** We use signals and slots for communication between objects in the Qt GUI. We use then many times for example with buttons, and text boxs.

### 📌 What are Signals and Slots?
1. **Signal** → A message emitted by an object when something happens (e.g., button clicked).
2. **Slot** → A function that reacts to the signal (e.g., function that runs when a button is clicked).

### 🔄 How It Works?
- A signal is emitted from an object.
- A slot receives the signal and executes some action.
- Qt automatically connects the signal to the slot, ensuring the function runs when needed.
