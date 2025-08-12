# C++ Lab Programs

This document contains the C++ source code for a series of lab experiments, covering fundamental to intermediate concepts of the C++ programming language. Each program is presented with comments to explain the logic.

---

## Experiment 1: Program to illustrate the use of class and object
This program defines a Student class to encapsulate student data and functions, and then creates an object of this class to demonstrate its usage.
```cpp
#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    int rollNo;
    string name;

public:
    void getData() {
        cout << "Enter Roll Number: ";
        cin >> rollNo;
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
    }
    void putData() {
        cout << "\n--- Student Details ---\n";
        cout << "Name: " << name << "\n";
        cout << "Roll Number: " << rollNo << "\n";
    }
};

int main() {
    Student s1;
    s1.getData();
    s1.putData();
    return 0;
}
```

---

## Experiment 2: Program to use decision control statements

### 2.1 if statement
```cpp
#include <iostream>
using namespace std;

class Checker {
private:
    int num;
public:
    void checkPositive() {
        cout << "Enter a number: ";
        cin >> num;
        if (num > 0) {
            cout << num << " is a positive number.\n";
        }
    }
};

int main() {
    Checker obj;
    obj.checkPositive();
    return 0;
}
```

### 2.2 if-else statement
```cpp
#include <iostream>
using namespace std;

class EvenOdd {
private:
    int num;
public:
    void check() {
        cout << "Enter an integer: ";
        cin >> num;
        if (num % 2 == 0) {
            cout << num << " is an even number.\n";
        } else {
            cout << num << " is an odd number.\n";
        }
    }
};

int main() {
    EvenOdd obj;
    obj.check();
    return 0;
}
```

### 2.3 else-if ladder
```cpp
#include <iostream>
using namespace std;

class Grader {
private:
    float percentage;
public:
    void assignGrade() {
        cout << "Enter percentage: ";
        cin >> percentage;
        if (percentage >= 90) cout << "Grade: A+\n";
        else if (percentage >= 80) cout << "Grade: A\n";
        else if (percentage >= 70) cout << "Grade: B\n";
        else if (percentage >= 60) cout << "Grade: C\n";
        else if (percentage >= 50) cout << "Grade: D\n";
        else cout << "Grade: F (Fail)\n";
    }
};

int main() {
    Grader obj;
    obj.assignGrade();
    return 0;
}
```

### 2.4 nested if-else statement
```cpp
#include <iostream>
using namespace std;

class LargestNumber {
private:
    int a, b, c;
public:
    void findLargest() {
        cout << "Enter three numbers: ";
        cin >> a >> b >> c;
        if (a >= b) {
            if (a >= c) cout << "Largest number is: " << a << "\n";
            else cout << "Largest number is: " << c << "\n";
        } else {
            if (b >= c) cout << "Largest number is: " << b << "\n";
            else cout << "Largest number is: " << c << "\n";
        }
    }
};

int main() {
    LargestNumber obj;
    obj.findLargest();
    return 0;
}
```

### 2.5 switch-case statement
```cpp
#include <iostream>
using namespace std;

class Calculator {
private:
    char op;
    float num1, num2;
public:
    void performOperation() {
        cout << "Enter an operator (+, -, *, /): ";
        cin >> op;
        cout << "Enter two numbers: ";
        cin >> num1 >> num2;

        switch (op) {
            case '+': cout << num1 + num2 << "\n"; break;
            case '-': cout << num1 - num2 << "\n"; break;
            case '*': cout << num1 * num2 << "\n"; break;
            case '/':
                if (num2 != 0) cout << num1 / num2 << "\n";
                else cout << "Error! Division by zero.\n";
                break;
            default: cout << "Invalid operator.\n"; break;
        }
    }
};

int main() {
    Calculator calc;
    calc.performOperation();
    return 0;
}
```

---

## Experiment 3: Loop control statements

### 3.1 for loop
```cpp
#include <iostream>
using namespace std;

class NaturalNumbers {
private:
    int n;
public:
    void printSeries() {
        cout << "Enter the limit (n): ";
        cin >> n;
        for (int i = 1; i <= n; ++i) cout << i << " ";
        cout << "\n";
    }
};

int main() {
    NaturalNumbers obj;
    obj.printSeries();
    return 0;
}
```

### 3.2 while loop
```cpp
#include <iostream>
using namespace std;

class Factorial {
private:
    int n;
    long long fact = 1;
public:
    void calculate() {
        cout << "Enter a non-negative integer: ";
        cin >> n;
        int i = n;
        while (i > 1) {
            fact *= i;
            i--;
        }
        cout << "Factorial of " << n << " is " << fact << "\n";
    }
};

int main() {
    Factorial obj;
    obj.calculate();
    return 0;
}
```

### 3.3 do-while loop
```cpp
#include <iostream>
using namespace std;

class NumberReverser {
private:
    int num, reversedNum = 0, remainder;
public:
    void reverse() {
        cout << "Enter an integer: ";
        cin >> num;
        int originalNum = num;
        do {
            remainder = num % 10;
            reversedNum = reversedNum * 10 + remainder;
            num /= 10;
        } while (num != 0);
        cout << "Reverse of " << originalNum << " is " << reversedNum << "\n";
    }
};

int main() {
    NumberReverser obj;
    obj.reverse();
    return 0;
}
```

### 3.4 nested for loop
```cpp
#include <iostream>
using namespace std;

class Pattern {
private:
    int rows;
public:
    void print() {
        cout << "Enter number of rows: ";
        cin >> rows;
        for (int i = 1; i <= rows; ++i) {
            for (int j = 1; j <= i; ++j) cout << "* ";
            cout << "\n";
        }
    }
};

int main() {
    Pattern obj;
    obj.print();
    return 0;
}
```

---

## Experiment 4: Nesting of member functions
```cpp
#include <iostream>
using namespace std;

class Numbers {
private:
    int a, b;
    int compare() { return (a > b) ? a : b; }
public:
    void findLargest() {
        cout << "Enter two numbers: ";
        cin >> a >> b;
        cout << "The largest number is: " << compare() << "\n";
    }
};

int main() {
    Numbers obj;
    obj.findLargest();
    return 0;
}
```

---

## Experiment 5: Default parameters
```cpp
#include <iostream>
using namespace std;

class InterestCalculator {
public:
    void calculateInterest(float principal, int time, float rate = 5.0) {
        float interest = (principal * rate * time) / 100.0;
        cout << "Principal: $" << principal;
        cout << "\nTime: " << time << " years";
        cout << "\nRate: " << rate << "%";
        cout << "\nSimple Interest: $" << interest << "\n";
    }
};

int main() {
    InterestCalculator ic;
    ic.calculateInterest(1000, 2);
    ic.calculateInterest(1000, 2, 7.5);
    return 0;
}
```

---

## Experiment 6: Local class
```cpp
#include <iostream>
#include <string>
using namespace std;

void manageStudent() {
    class Student {
    private:
        string name;
        int rollNo;
    public:
        void getData() {
            cout << "Enter student name: ";
            getline(cin, name);
            cout << "Enter roll number: ";
            cin >> rollNo;
        }
        void displayData() {
            cout << "Name: " << name << "\n";
            cout << "Roll No: " << rollNo << "\n";
        }
    };

    Student localStudent;
    localStudent.getData();
    localStudent.displayData();
}

int main() {
    manageStudent();
    return 0;
}
```

---

## Experiment 7: Nested class
```cpp
#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    string name;
public:
    class Address {
    private:
        string street, city;
    public:
        void setAddress() {
            cout << "Enter street: ";
            getline(cin, street);
            cout << "Enter city: ";
            getline(cin, city);
        }
        void displayAddress() {
            cout << "Street: " << street << "\n";
            cout << "City: " << city << "\n";
        }
    };

    void setName() {
        cout << "Enter person's name: ";
        getline(cin, name);
    }
    void displayName() {
        cout << "Name: " << name << "\n";
    }
};

int main() {
    Person p;
    p.setName();
    Person::Address addr;
    addr.setAddress();
    p.displayName();
    addr.displayAddress();
    return 0;
}
```

---

## Experiment 8: Inline function
```cpp
#include <iostream>
using namespace std;

class MathOperations {
public:
    inline int cube(int s) { return s * s * s; }
};

int main() {
    MathOperations op;
    int num;
    cout << "Enter a number to find its cube: ";
    cin >> num;
    cout << "The cube of " << num << " is: " << op.cube(num) << "\n";
    return 0;
}
```

