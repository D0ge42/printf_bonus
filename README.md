# ft_printf - 42 Project (125/100)

This project is a **custom implementation of printf** in C, developed as part of the **42 School** curriculum. It fully replicates the behavior of the standard `printf` function while handling various format specifiers efficiently. With **bonus features** implemented, this project scored **125/100** in Moulinette tests. 🚀

---

## 🌟 Features
- **Handles all standard conversions**: `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, `%%`
- **Bonus Implementations**:
  - **Flag handling**: `-`, `0`, `+`, ` ` (space), `#`
  - **Field width & precision**
- **Optimized for performance & minimal memory usage**
- **No memory leaks, robust error handling**
- **Fully functional and tested implementation**

---

## 🛠️ Compilation & Usage
### 🔧 Build
```bash
make
```

### 📌 Include ft_printf in Your Project
```c
#include "ft_printf.h"
```

### 🚀 Example Usage
```c
#include "ft_printf.h"

int main()
{
    ft_printf("Hello, %s! Your score is %d.\n", "User", 125);
    return 0;
}
```
Output:
```
Hello, User! Your score is 125.
```

---

## 📖 How It Works
1. **Parsing & Formatting:** The input format string is scanned for specifiers and flags.
2. **Conversion Handling:** Each format specifier is processed and printed accordingly.
3. **Memory Management:** The function ensures no leaks or unnecessary allocations.
4. **Bonus Features:** Advanced formatting options are applied for a more complete `printf` behavior.

---

## 🏆 Why This ft_printf?
✅ **Fully functional & tested** - Passed Moulinette with **125/100** score!  
✅ **Handles all required format specifiers & flags**  
✅ **Optimized & leak-free**  
✅ **Supports width, precision, and advanced formatting**  
✅ **Robust & efficient implementation**

---

## 📜 License
This project is open-source and free to use for educational purposes.

---

A deep dive into formatted output, optimization, and C internals! 🖥️✨

