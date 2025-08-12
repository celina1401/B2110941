# Consolidated API Reference

This document provides a quick reference to all public APIs, functions, and components available in this project.

## Table of Contents
- [List Data Structure API](#list-data-structure-api)
- [BMI Calculator API](#bmi-calculator-api)
- [Quick Reference Tables](#quick-reference-tables)
- [Code Examples](#code-examples)

---

## List Data Structure API

### Data Types
```c
typedef int ElementType;    // Type of list elements
typedef int Position;       // Position/index type
typedef struct {
    ElementType Elements[Maxlenght];
    Position Last;
} List;                     // Main list structure
```

### Constants
```c
#define Maxlenght 300      // Maximum list capacity
```

### Functions

#### `void makenullList(List *L)`
**Purpose:** Initialize empty list  
**Parameters:** `L` - Pointer to list  
**Complexity:** O(1)  
**Example:**
```c
List myList;
makenullList(&myList);
```

#### `Position endList(List L)`
**Purpose:** Get position after last element  
**Parameters:** `L` - List to query  
**Returns:** Position after last element  
**Complexity:** O(1)

#### `Position next(Position p, List L)`
**Purpose:** Get next position  
**Parameters:** `p` - Current position, `L` - List  
**Returns:** Next position (p + 1)  
**Complexity:** O(1)

#### `ElementType retrieve(Position p, List L)`
**Purpose:** Get element at position  
**Parameters:** `p` - Position (1-based), `L` - List  
**Returns:** Element at position  
**Complexity:** O(1)  
**Note:** No bounds checking

#### `Position locate(ElementType x, List L)`
**Purpose:** Find element position  
**Parameters:** `x` - Element to find, `L` - List  
**Returns:** Position if found, else `L.Last + 1`  
**Complexity:** O(n)  
**Note:** Returns 0-based position

#### `void deleteList(Position p, List *pL)`
**Purpose:** Delete element at position  
**Parameters:** `p` - Position (0-based), `pL` - Pointer to list  
**Complexity:** O(n)  
**Note:** No bounds checking

#### `void erase(ElementType x, List *pL)`
**Purpose:** Remove first occurrence of element  
**Parameters:** `x` - Element to remove, `pL` - Pointer to list  
**Complexity:** O(n)

---

## BMI Calculator API

### Data Structures
```cpp
struct ThongTin {
    string Hoten;        // Full name
    float Can_nang;      // Weight in kg  
    float Chieu_cao;     // Height in meters
};
```

### Functions

#### `void Cong_thuc_BMI(ThongTin tt)`
**Purpose:** Calculate BMI and display health recommendation  
**Parameters:** `tt` - Personal information structure  
**Formula:** BMI = weight / (height²)  
**Complexity:** O(1)  

**BMI Categories:**
- `< 18.5`: Underweight
- `18.5 - 25.0`: Normal weight  
- `> 25.0`: Overweight

**Example:**
```cpp
ThongTin person;
person.Hoten = "John Doe";
person.Can_nang = 70.0;
person.Chieu_cao = 1.75;
Cong_thuc_BMI(person);
```

---

## Quick Reference Tables

### List Operations Summary
| Operation | Function | Time | Notes |
|-----------|----------|------|-------|
| Initialize | `makenullList()` | O(1) | Required before use |
| Access | `retrieve()` | O(1) | 1-based indexing |
| Search | `locate()` | O(n) | Returns 0-based position |
| Delete | `deleteList()` | O(n) | 0-based position |
| Remove | `erase()` | O(n) | By element value |
| End check | `endList()` | O(1) | For traversal |
| Next pos | `next()` | O(1) | Position increment |

### BMI Categories Reference
| BMI Range | Category | Vietnamese Message |
|-----------|----------|-------------------|
| < 18.5 | Underweight | "Om qua an nhieu do di @@ Co da thit chut moi xinh" |
| 18.5 - 25.0 | Normal | "Nguoi can doi!! Good! Congratulation!!" |
| > 25.0 | Overweight | "Ulatr beo phi roi ma oi :(( TAP THE DUC DI" |

---

## Code Examples

### Complete List Usage
```c
#include <stdio.h>

int main() {
    List myList;
    makenullList(&myList);
    
    // Manual population (no insert function)
    myList.Elements[0] = 10;
    myList.Elements[1] = 20;
    myList.Elements[2] = 30;
    myList.Last = 3;
    
    // Traverse and display
    printf("List contents: ");
    for (Position p = 1; p <= myList.Last; p++) {
        printf("%d ", retrieve(p, myList));
    }
    printf("\n");
    
    // Search for element
    Position pos = locate(20, myList);
    if (pos < myList.Last) {
        printf("Found 20 at position %d\n", pos);
    }
    
    // Remove element
    erase(20, &myList);
    printf("After removing 20, size: %d\n", myList.Last);
    
    return 0;
}
```

### Complete BMI Calculator Usage
```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    ThongTin person;
    
    // Get input
    cout << "Ten cua ban la: ";
    getline(cin, person.Hoten);
    
    cout << "Can nang cua ban la: ";
    cin >> person.Can_nang;
    
    cout << "Chieu cao cua ban la: ";
    cin >> person.Chieu_cao;
    
    // Calculate and display BMI
    Cong_thuc_BMI(person);
    
    return 0;
}
```

### Error-Safe List Operations
```c
// Safe element retrieval
ElementType safeRetrieve(Position p, List L) {
    if (p >= 1 && p <= L.Last) {
        return retrieve(p, L);
    }
    printf("Error: Invalid position %d\n", p);
    return -1; // Error value
}

// Safe element search
Position safeLocate(ElementType x, List L) {
    Position pos = locate(x, L);
    if (pos <= L.Last) {
        return pos + 1; // Convert to 1-based
    }
    return -1; // Not found
}
```

### Enhanced BMI Calculator with Validation
```cpp
bool validateInput(const ThongTin& tt) {
    if (tt.Hoten.empty()) {
        cout << "Error: Name cannot be empty!" << endl;
        return false;
    }
    if (tt.Can_nang <= 0 || tt.Can_nang > 500) {
        cout << "Error: Invalid weight!" << endl;
        return false;
    }
    if (tt.Chieu_cao <= 0 || tt.Chieu_cao > 3.0) {
        cout << "Error: Invalid height!" << endl;
        return false;
    }
    return true;
}

void safeBMICalculation(ThongTin tt) {
    if (validateInput(tt)) {
        Cong_thuc_BMI(tt);
    }
}
```

---

## Compilation Commands

```bash
# List Data Structure
gcc -std=c99 -Wall -Wextra -o list_program bai6.c

# BMI Calculator
g++ -std=c++11 -Wall -Wextra -o bmi_program BMI.cpp

# With debug information
gcc -g -std=c99 -Wall -Wextra -o list_debug bai6.c
g++ -g -std=c++11 -Wall -Wextra -o bmi_debug BMI.cpp
```

---

## Common Pitfalls

### List Data Structure
1. **Indexing Inconsistency:** `retrieve()` uses 1-based, `locate()` returns 0-based
2. **No Bounds Checking:** Manual validation required
3. **No Insert Function:** Must manually populate array
4. **Fixed Size:** Maximum 300 elements

### BMI Calculator  
1. **No Input Validation:** Division by zero possible
2. **Mixed Languages:** Vietnamese-English messages
3. **No Error Handling:** Invalid inputs not checked
4. **Limited Precision:** Using float for medical calculations

---

*For detailed documentation, see [LIST_API_DOCUMENTATION.md](LIST_API_DOCUMENTATION.md) and [BMI_CALCULATOR_DOCUMENTATION.md](BMI_CALCULATOR_DOCUMENTATION.md)*