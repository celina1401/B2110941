# Project Documentation

## Overview

This repository contains two small programs:

- `bai6.c`: A simple fixed-size list (array-backed) Abstract Data Type (ADT) in C with basic operations such as initialize, locate, delete, and erase-by-value. Includes a small demo in `main`.
- `BMI.cpp`: A small C++ program that computes Body Mass Index (BMI) from user input and prints a textual category.

Both are console programs, each with its own `main` function.

## Build and Run

Requirements:
- GCC for C (`gcc`) and G++ for C++ (`g++`).

Build commands:

```bash
# Build the C list program
gcc -std=c11 -O2 -Wall -Wextra -o bai6 bai6.c

# Build the C++ BMI program
g++ -std=c++17 -O2 -Wall -Wextra -o BMI BMI.cpp
```

Run commands and example outputs:

```bash
# Run the list demo
./bai6
# Example output
0 4 6 8 2
```

```bash
# Run the BMI program with sample input
printf "Nguyen Van A\n60\n1.7\n" | ./BMI
# Example output (line breaks and spacing may vary)

 Ten cua ban la:
 Can nang cua ban la:
 Chieu cao cua ban la:Ket qua BMI cua ban Nguyen Van A la: 20.7612
 Nguoi can doi!! Good! Congratulation!!
```

---

## API Reference: `bai6.c`

### Types

```c
#define Maxlenght 300

typedef int ElementType;  // Value type stored in the list

typedef int Position;     // Index position

typedef struct {
    ElementType Elements[Maxlenght]; // Storage
    Position Last;                   // Number of elements currently in the list
} List;
```

- **Capacity**: `Maxlenght` elements (300).
- **Size**: `L.Last` holds the current number of elements.
- **Valid zero-based indices**: `0 .. L.Last - 1`.

Important: The current implementation mixes zero-based and one-based indexing across functions (see notes below). Use care when calling functions that accept a `Position`.

### Functions

- **makenullList**

  ```c
  void makenullList(List *L);
  ```

  - **Description**: Initializes the list to empty state.
  - **Parameters**: `L` — pointer to list.
  - **Postcondition**: `L->Last == 0`.

- **endList**

  ```c
  Position endList(List L);
  ```

  - **Description**: Returns `L.Last + 1`.
  - **Notes**: Useful in one-based index conventions; not required for zero-based usage.

- **next**

  ```c
  Position next(Position p, List L);
  ```

  - **Description**: Returns `p + 1`.
  - **Notes**: `L` is unused in this implementation.

- **retrieve**

  ```c
  ElementType retrieve(Position p, List L);
  ```

  - **Description**: Retrieves the element at one-based position `p`.
  - **Parameters**: `p` — one-based position (1..`L.Last`).
  - **Returns**: `L.Elements[p - 1]`.
  - **Preconditions**: `1 <= p && p <= L.Last`.

- **locate**

  ```c
  Position locate(ElementType x, List L);
  ```

  - **Description**: Finds the first occurrence of `x`.
  - **Returns**: The zero-based index `i` where `L.Elements[i] == x`, if found; otherwise returns `L.Last + 1` as a sentinel.
  - **Notes**: This mixes zero-based valid positions with a one-based-style sentinel. Prefer checking `pos < L.Last` to confirm presence.

- **deleteList**

  ```c
  void deleteList(Position p, List *pL);
  ```

  - **Description**: Deletes the element at zero-based index `p` and shifts subsequent elements left by one.
  - **Preconditions**: `0 <= p && p < pL->Last`.
  - **Postcondition**: `pL->Last` is decremented by 1.

- **erase**

  ```c
  void erase(ElementType x, List *pL);
  ```

  - **Description**: Removes the first occurrence of `x` if present.
  - **Behavior**: Internally calls `locate(x, *pL)` to get position `p`. If `p < pL->Last`, calls `deleteList(p, pL)`.

### Example Usage

```c
#include <stdio.h>

int main(void) {
    List L;
    makenullList(&L);

    // Append some even numbers manually for demo
    for (int i = 0; i < 5; i++) {
        L.Elements[i] = 2 * i;  // 0,2,4,6,8
    }
    L.Elements[5] = 2;  // duplicate 2 at index 5
    L.Last = 6;         // size is 6

    // Remove first occurrence of 2
    erase(2, &L); // L becomes [0,4,6,8,2]

    for (int i = 0; i < L.Last; i++) {
        printf("%d ", L.Elements[i]);
    }
    return 0;
}
```

### Indexing Notes and Recommended Conventions

- The implementation currently has a mix of one-based (`retrieve`) and zero-based (`locate`, `deleteList`) semantics.
- To avoid off-by-one errors:
  - Treat stored elements as zero-based in the underlying array.
  - Prefer zero-based throughout. If you use `retrieve`, pass `p = i + 1` for a zero-based index `i`.
  - When checking the result from `locate`, use `if (pos < L.Last)` to confirm that a value was found.

### Complexity

- `locate`: O(n)
- `deleteList`: O(n) due to shifting
- `erase`: O(n) average/worst-case due to `locate` and possible shift

### Constraints and Error Handling

- There is no bounds checking for insertions in this demo. Ensure `L.Last < Maxlenght` before adding elements.
- Functions do not guard against invalid indices. Validate `Position` arguments before calling.

---

## API Reference: `BMI.cpp`

### Types

```cpp
struct ThongTin {
    std::string Hoten;      // Full name
    float Can_nang;         // Weight in kilograms
    float Chieu_cao;        // Height in meters
};
```

### Functions

- **Cong_thuc_BMI**

  ```cpp
  void Cong_thuc_BMI(ThongTin tt);
  ```

  - **Description**: Computes BMI = weight / (height^2) and prints the result along with a coarse category.
  - **Parameters**: `tt` — personal info with `Hoten`, `Can_nang` (kg), `Chieu_cao` (m).
  - **Output**: Writes to `std::cout`:
    - "Ket qua BMI cua ban <Hoten> la: <BMI>"
    - Category:
      - 18.5 ≤ BMI ≤ 25: "Nguoi can doi"
      - 25 < BMI ≤ 30: Overweight/obese message
      - Otherwise: Underweight message

### Example Usage

```cpp
#include <iostream>
#include <string>

int main() {
    ThongTin tt;
    tt.Hoten = "Nguyen Van A";
    tt.Can_nang = 60.0f;  // kg
    tt.Chieu_cao = 1.70f; // m

    Cong_thuc_BMI(tt);
    return 0;
}
```

Example I/O when running the provided interactive `main`:

Input
```text
Nguyen Van A
60
1.7
```

Output
```text
 Ten cua ban la:
 Can nang cua ban la:
 Chieu cao cua ban la:Ket qua BMI cua ban Nguyen Van A la: 20.7612
 Nguoi can doi!! Good! Congratulation!!
```

### Notes and Recommendations

- `ThongTin::Chieu_cao` should be in meters; `Can_nang` in kilograms.
- The current code declares a `std::string KQ;` that is printed but never assigned; it can be removed or set to a meaningful message.
- Consider formatting BMI to a fixed number of decimals for cleaner output, e.g., `std::fixed << std::setprecision(2)`.
- For robust UX, validate inputs (non-empty name, positive weight/height).

---

## Known Issues and Improvements

- `bai6.c` indexing is inconsistent between functions:
  - Prefer standardizing on zero-based indices across all functions and adjusting `retrieve` accordingly.
  - Add bounds checks and insertion helpers (e.g., `insertAt`, `pushBack`) that maintain `Last` safely.
- `BMI.cpp` prints an uninitialized string `KQ` and could improve output formatting and input validation.

## License

Not specified. Add a license if you intend to distribute or open-source this code.