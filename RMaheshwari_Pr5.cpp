/*
 * Class: CMSC140 CRN 22556
 * Instructor: Farnaz Eivazi
 * Project 5
 * Description: (Give a brief description for Project)
 * Due Date: 12/10/23
 * I pledge that I have completed the programming assignment independently.
   I have not copied the code from a student or any source.
   I have not given my code to any student.
   Print your Name here: RAUNAK MAHESHWARI
*/
#include <iostream>
using namespace std;
const int ROWS = 3, COLS = 3, MIN = 1, MAX = 9;
bool isMagicSquare(int[], int[], int[], int);
bool checkUnique(int[], int[], int[], int);
bool checkRange(int[], int[], int[], int, int, int);
bool checkRowSum(int[], int[], int[], int);
bool checkColSum(int[], int[], int[], int);
bool checkDiagSum(int[], int[], int[], int);
void fillArray(int[], int[], int[], int);
void showArray(int[], int[], int[], int);
int main() {
    int magicArray1[COLS], magicArray2[COLS], magicArray3[COLS];
    fillArray(magicArray1, magicArray2, magicArray3, ROWS);
    showArray(magicArray1, magicArray2, magicArray3, ROWS);
    char answer;
    if (isMagicSquare(magicArray1, magicArray2, magicArray3, ROWS)) {
        cout << "This is a Lo Shu magic square." << endl;
    } else {
        cout << "This is not a Lo Shu magic square." << endl;
        cout << " " << endl;
    }
    cout << "Do you want to try again?";
    cin >> answer;
    while (answer != 'n') {
        fillArray(magicArray1, magicArray2, magicArray3, ROWS);
        showArray(magicArray1, magicArray2, magicArray3, ROWS);
        if (isMagicSquare(magicArray1, magicArray2, magicArray3, ROWS)) {
            cout << "This is a Lo Shu magic square." << endl;
        } else {
            cout << "This is not a Lo Shu magic square." << endl;
            cout << " " << endl;
        }
        cout << "Do you want to try again?";
        cin >> answer;
    }
    return 0;
}

void fillArray(int arr1[], int arr2[], int arr3[], int size) {
    int number;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << "Enter the number for row " << i << " and column " << j << ": ";
            if (i == 0) {
                cin >> number;
                arr1[j] = number;
            } else if (i == 1) {
                cin >> number;
                arr2[j] = number;
            } else {
                cin >> number;
                arr3[j] = number;
            }
        }
    }
}

void showArray(int arr1[], int arr2[], int arr3[], int size) {
    for (int i = 0; i < ROWS; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < ROWS; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < ROWS; i++) {
        cout << arr3[i] << " ";
    }
    cout << endl;
}

bool checkRowSum(int arr1[], int arr2[], int arr3[], int size) {
    int total1 = 0, total2 = 0, total3 = 0;
    for (int i = 0; i < size; i++) {
        total1 += arr1[i];
    }
    for (int i = 0; i < size; i++) {
        total2 += arr2[i];
    }
    for (int i = 0; i < size; i++) {
        total3 += arr3[i];
    }
    if ((total1 == total2) && (total2 == total3)) {
        return true;
    }
    return false;
}

bool checkColSum(int arr1[], int arr2[], int arr3[], int size) {
    int colSum1 = 0, colSum2 = 0, colSum3 = 0;
    for (int i = 0; i < size; i++) {
        if (i == 0) {
            colSum1 += (arr1[i] + arr2[i] + arr3[i]);
        } else if (i == 1) {
            colSum2 += (arr1[i] + arr2[i] + arr3[i]);
        } else {
            colSum3 += (arr1[i] + arr2[i] + arr3[i]);
        }
    }
    if ((colSum1 == colSum2) && (colSum2 == colSum3)) {
        return true;
    }
    return false;
}
bool checkDiagSum(int arr1[], int arr2[], int arr3[], int size) {
    for (int i = 0; i < size; i++) {
        if (i == 0) {
            if (arr1[i] + arr2[i+1] + arr3[i+2] == arr3[i] + arr2[i+1] + arr1[i+2]) {
                return true;
            }
        }
    }
    return false;
}
bool checkRange(int arr1[], int arr2[], int arr3[], int size, int min, int max) {
    for (int i = 0; i < size; i++) {
        if ((arr1[i] < min || arr1[i] > max) || (arr2[i] < min || arr2[i] > max) || (arr3[i] < min || arr3[i] > max)) {
            return false;
        }
    }
    return true;
}
bool checkUnique(int arr1[], int arr2[], int arr3[], int size) {

     for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr1[i] == arr1[j] || arr2[i] == arr2[j] || arr3[i] == arr3[j]) {
                return false;
            }
        }
     }
     return true;
}
bool isMagicSquare(int arr1[], int arr2[], int arr3[], int size) {
    if ((checkUnique(arr1, arr2, arr3, size)) && (checkRange(arr1, arr2, arr3, size, MIN, MAX)) && checkRowSum(arr1, arr2, arr3, size) && checkColSum(arr1, arr2, arr3, size) && checkDiagSum(arr1, arr2, arr3, size)) {
        return true;
    }
    return false;
}
