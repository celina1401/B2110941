# BMI Calculator API Documentation

## Overview

This document provides comprehensive documentation for the BMI (Body Mass Index) calculator implementation in `BMI.cpp`. The program calculates BMI based on user input and provides health recommendations in Vietnamese.

## Data Structures

### ThongTin (Information Structure)
```cpp
struct ThongTin {
    string Hoten;        // Full name
    float Can_nang;      // Weight in kg
    float Chieu_cao;     // Height in meters
};
```

**Description:** Structure to store personal information required for BMI calculation.

**Fields:**
- `Hoten` (string): Person's full name
- `Can_nang` (float): Person's weight in kilograms
- `Chieu_cao` (float): Person's height in meters

**Usage Example:**
```cpp
ThongTin person;
person.Hoten = "Nguyen Van A";
person.Can_nang = 70.5;
person.Chieu_cao = 1.75;
```

## Public API Functions

### Cong_thuc_BMI
```cpp
void Cong_thuc_BMI(ThongTin tt)
```

**Description:** Calculates BMI using the standard formula and provides health assessment based on the result.

**Formula:** BMI = weight (kg) / (height (m))²

**Parameters:**
- `tt`: ThongTin structure containing person's information

**BMI Categories and Responses:**
- **Normal Weight (18.5 ≤ BMI ≤ 25):** "Nguoi can doi!! Good! Congratulation!!"
- **Overweight (25 < BMI ≤ 30):** "Ulatr beo phi roi ma oi :(( TAP THE DUC DI"
- **Underweight (BMI < 18.5):** "Om qua an nhieu do di @@ Co da thit chut moi xinh"

**Usage Example:**
```cpp
ThongTin person;
person.Hoten = "John Doe";
person.Can_nang = 70.0;    // 70 kg
person.Chieu_cao = 1.75;   // 1.75 m
Cong_thuc_BMI(person);
// Output: BMI calculation and health recommendation
```

**Output Format:**
```
Ket qua BMI cua ban [Name] la: [BMI_Value] [Health_Message]
```

**Time Complexity:** O(1)

## Complete Usage Example

```cpp
#include <iostream>
#include <string>
using namespace std;

// Include the BMI calculator implementation
#include "BMI.cpp"

int main() {
    ThongTin person;
    
    // Get user input
    cout << "\n Ten cua ban la: ";
    getline(cin, person.Hoten);
    
    cout << "\n Can nang cua ban la: ";
    cin >> person.Can_nang;
    
    cout << "\n Chieu cao cua ban la: ";
    cin >> person.Chieu_cao;
    
    // Calculate and display BMI
    Cong_thuc_BMI(person);
    
    return 0;
}
```

## Sample Program Execution

### Example 1: Normal Weight
```
Input:
Ten cua ban la: Nguyen Van A
Can nang cua ban la: 70
Chieu cao cua ban la: 1.75

Output:
Ket qua BMI cua ban Nguyen Van A la: 22.8571
Nguoi can doi!! Good! Congratulation!!
```

### Example 2: Overweight
```
Input:
Ten cua ban la: Le Thi B
Can nang cua ban la: 80
Chieu cao cua ban la: 1.60

Output:
Ket qua BMI cua ban Le Thi B la: 31.25
Ulatr beo phi roi ma oi :(( TAP THE DUC DI
```

### Example 3: Underweight
```
Input:
Ten cua ban la: Tran Van C
Can nang cua ban la: 50
Chieu cao cua ban la: 1.80

Output:
Ket qua BMI cua ban Tran Van C la: 15.4321
Om qua an nhieu do di @@ Co da thit chut moi xinh
```

## BMI Reference Chart

| BMI Range | Category | Health Status | Vietnamese Message |
|-----------|----------|---------------|-------------------|
| < 18.5 | Underweight | Needs to gain weight | "Om qua an nhieu do di @@ Co da thit chut moi xinh" |
| 18.5 - 24.9 | Normal | Healthy weight | "Nguoi can doi!! Good! Congratulation!!" |
| 25.0 - 29.9 | Overweight | Should lose weight | "Ulatr beo phi roi ma oi :(( TAP THE DUC DI" |
| ≥ 30.0 | Obese | Should lose weight | "Ulatr beo phi roi ma oi :(( TAP THE DUC DI" |

**Note:** The current implementation treats BMI ≥ 25 as overweight without distinguishing between overweight and obese categories.

## Input Validation and Error Handling

### Current Limitations
The current implementation has minimal input validation:
- No validation for negative weight or height values
- No validation for unrealistic values (e.g., height > 3m, weight > 500kg)
- No handling of division by zero (height = 0)
- No validation for empty name input

### Recommended Improvements
```cpp
bool validateInput(const ThongTin& tt) {
    if (tt.Hoten.empty()) {
        cout << "Error: Name cannot be empty!" << endl;
        return false;
    }
    if (tt.Can_nang <= 0 || tt.Can_nang > 500) {
        cout << "Error: Weight must be between 0 and 500 kg!" << endl;
        return false;
    }
    if (tt.Chieu_cao <= 0 || tt.Chieu_cao > 3.0) {
        cout << "Error: Height must be between 0 and 3.0 meters!" << endl;
        return false;
    }
    return true;
}
```

## Localization and Language Support

The current implementation uses Vietnamese language for:
- User prompts
- Health recommendations
- Mixed Vietnamese-English messages

### Text Messages Reference
- `"Ten cua ban la:"` - "Your name is:"
- `"Can nang cua ban la:"` - "Your weight is:"
- `"Chieu cao cua ban la:"` - "Your height is:"
- `"Ket qua BMI cua ban"` - "Your BMI result"

## Memory Management

- Uses stack allocation for the `ThongTin` structure
- No dynamic memory allocation required
- Minimal memory footprint
- Safe for embedded systems with limited memory

## Thread Safety

This implementation is **not thread-safe** due to:
- Use of global `cout` object
- No synchronization mechanisms
- Shared state through console I/O

For multi-threaded applications, consider:
- Synchronizing console output
- Using thread-local storage for calculations
- Implementing proper locking mechanisms

## Performance Characteristics

- **Time Complexity:** O(1) for BMI calculation
- **Space Complexity:** O(1) additional space
- **I/O Bound:** Performance limited by console input/output operations

## Compilation Instructions

```bash
# Compile with g++
g++ -o bmi_calculator BMI.cpp

# Run the program
./bmi_calculator
```

**Compiler Requirements:**
- C++11 or later (for string operations)
- Standard library support for iostream and string

## Best Practices for Usage

1. **Input Validation:** Always validate user input before processing
2. **Error Handling:** Implement proper error handling for edge cases
3. **Localization:** Consider supporting multiple languages
4. **Precision:** Use appropriate data types for medical calculations
5. **User Experience:** Provide clear instructions and feedback

## Medical Disclaimer

**Important:** This BMI calculator is for educational purposes only. BMI is a general indicator and may not be accurate for:
- Athletes with high muscle mass
- Elderly individuals
- Pregnant women
- Children and adolescents

Always consult healthcare professionals for medical advice and accurate health assessments.

## Future Enhancements

Potential improvements for the BMI calculator:
1. **Input validation** with error messages
2. **Multiple language support**
3. **Age and gender-specific BMI categories**
4. **BMI history tracking**
5. **Graphical user interface**
6. **Export results to file**
7. **Integration with health tracking systems**