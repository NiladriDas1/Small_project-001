# 🧠 Auto Data Type Detector (C Language)

This project is a lightweight C module that helps you **automatically detect datatypes** from given input strings. It's easy to use, header-only, and can be embedded in any C project.

> 🔧 No need to include `stdio.h` or any other standard libraries manually — the single header file handles everything for you.

---

## 🚀 Features

- Auto-detects common datatypes (int, float, string, etc.)
- Supports direct and interactive input
- Fully self-contained (no external dependencies)
- Single-file integration

---

## 📥 Installation

```bash
git clone "repo link"
```

1. Clone the repository.
2. Place the folder in your C project directory.
3. Include the header in your `.c` file:
   ```c
   #include "data_controller.h"
   ```

---

## ⚙️ Usage

### 1. Define a `DATASET` pointer
```c
DATASET *DATA;
```

### 2. Input Functions

#### `input(char *arg)`
- Detects and stores data automatically.
- If `arg == NULL`, enables terminal input.
```c
DATA = input(NULL);               // User provides input via console
DATA = input("2838hELLO");        // Direct string input
```

#### `processInput(const char *input)`
- Accepts direct input string and processes it.
```c
processInput("123.45");
```

### 3. Print Data

#### `printAllocatedData(DATASET *result)`
- Displays all data stored in the `DATASET`.
```c
printAllocatedData(DATA);
```

---

## 🧪 Example

```c
#include "data_controller.h"

int main() {
    DATASET *DATA = input("2838hELLO"); // Auto-detect datatype
    printAllocatedData(DATA);          // Print the result
    free(DATA);                        // Free memory
    return 0;
}
```

---

# 🔤 ASCII Converter

This utility converts a given string to its ASCII values and then back to the original string. It's a simple way to see character encodings in action.

---

## 📁 Header File

Include the ASCII converter in your project:

```c
#include "asccitochar.h"
```

---

## ⚙️ Function Usage

### `Converter("string or character")`
- Converts each character to its ASCII value and prints the result.
- Then retrieves the original string from the ASCII values.

---

## 🧪 Example

```c
#include "asccitochar.h"

int main() {
    Converter("Hello world is not real program");
    printf("\n");
    Converter("Hey i'm bee");

    return 0;
}
```

### 💡 Sample Output

```
Stored ASCII values: 72 101 121 32 105 39 109 32 98 101 101
Retrieved string: Hey i'm bee
```

---

## 📄 License

MIT License – use freely in your own projects.

---

## 🙋‍♂️ Contributing

Found a bug or want to suggest a feature? Open an issue or submit a pull request!


---

# 🗂️ Terminal File Explorer (C++)

A C++ project that scans and explores the file system via a terminal interface. It can:
- List all files and folders
- Filter only files
- Filter by file extension
- Search files by name (case-insensitive)

---

## 🧩 Features

- Cross-platform support (Windows and Linux)
- Uses C++20 features and `<filesystem>`
- Modern CLI menu-based interface
- Case-insensitive file searching

---

## 📁 Requirements

- C++20 compatible compiler (e.g., g++ 10+, MSVC 2019+)
- For Windows: `<windows.h>` (auto-handled)
- For Linux/macOS: `/` is the root path

---

## 🧪 Example Code

```cpp
#include <iostream>
#include <filesystem>
#include <vector>
#include <string>
#include <ranges>
#include <algorithm>

// Include FileSystemScanner and CLI classes

int main() {
    CLI cli;
    cli.run();  // Starts the terminal interface
    return 0;
}
```

---

## 🖥️ User Options

```
🧭 Terminal File Explorer Options:
1. List all files and folders
2. List only files
3. List files with specific extension
4. Search for a specific file by name
0. Exit
Choose an option:
```

---

## 📄 License

MIT License – use freely in your own projects.

---

## 🙋‍♂️ Contributing

Found a bug or want to suggest a feature? Open an issue or submit a pull request!
