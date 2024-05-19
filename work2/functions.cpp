#include <iostream>
#define ZERO 0
#define ONE 1
#define TWO 2
#define FOUR 4
#define FIVE 5
#define EIGHT 8
#define TEN 10
#define TWELVE 12
#define TWENTY_SIX 26
#define HUNDRED 100

using namespace std ;

void orthogonal_Matrix (int [][FIVE]) ;
void number (int) ;
void right (int) ;                       // Part of a number function
void left (int) ;                        // Part of a number function
void twice (int) ;                       // Part of a number function
void pascal_Triangle (int) ;
int factorial (int) ;                    // Part of a pascal_Triangle function
void triangle_Of_Letters (int) ;
void contain (int [], int []) ;
void matrix_Statistics (int [][FIVE]) ;
float square_root_approx (float, float ) ;
typedef enum {Orthogonal_Matrix = 1, Number, Pascal_Triangle, Triangle_Of_Letters, Contain, Matrix_Statistics, Exit, Bonus } menu;

int main() {
                                                // Variable definition for:
    int matrix [FIVE][FIVE] ;                         // option 1 (Orthogonal matrix) and option 6 (Matrix_Statistics)
    int choice, num1 ;                                // option 2 (Number)
    int line ;                                        // option 3 (Pascal_Triangle)
    int letters ;                                     // option 4 (Triangle_Of_Letters)
    int vector1 [TWELVE], vector2 [FIVE] ;            // option 5 (Contain)
    float num_x, epsilon ;                            // option 5 (Bonus)
    do {
        cout << "-----------------------------\n"
                "Please enter your choice:\n"          // Print the menu
                "1 Orthogonal matrix\n"
                "2 Number\n"
                "3 Pascal triangle\n"
                "4 Triangle of letters\n"
                "5 Contain\n"
                "6 Matrix statistics\n"
                "7 Exit\n"
                "8 Bonus\n " ;
        cin >> choice;                              // Accepting the user's choice
        switch (choice) {
            case Orthogonal_Matrix:
                cout << "Please enter 5*5 matrix: \n" ;          // Requests a matrix from the user
                orthogonal_Matrix (matrix) ;
                break;
            case Number:
                cout << "Enter number (less than 20,000): " << endl ;         // Requests a number from the user
                cin >> num1 ;
                number (num1);
                break;
            case Pascal_Triangle:
                cout << "Please enter number of lines (no more than 12): \n" ;        // Requests a number of lines from the user
                cin >> line ;
                pascal_Triangle(line) ;
                break;
            case Triangle_Of_Letters:
                cout << "Enter number between 1 - 26: \n" ;            // Requests a number of letters from the user
                cin >> letters ;
                triangle_Of_Letters(letters) ;
                break;
            case Contain:
                cout << "Enter 12 numbers vector: \n" ;              // Requests an array from the user
                contain(vector1, vector2) ;
                break;
            case Matrix_Statistics:
                cout << "Please enter 5*5 matrix: \n" ;              // Requests a matrix from the user
                matrix_Statistics(matrix) ;
                break;
            case Exit:
                cout << "Exit\n" ;
                break;
            case Bonus:
                cout << "Please enter num x: \n" ;
                cin >> num_x ;
                cout << "Please enter epsilon: \n" ;                 // Requests a number x and epsilon from the user
                cin >> epsilon ;
                square_root_approx(num_x, epsilon) ;
                break ;
            default:
                cout << "Wrong number, try again\n";
        }
    }
    while (choice != Exit) ;
    return ZERO;
}
void orthogonal_Matrix (int matrix[][FIVE]) {
    /* This function accepts a matrix of 5x5 integers, checks if all rows of
     the matrix are perpendicular to each other and prints appropriate notice. */
    int check, sum = ZERO, row = ZERO, column ;
    for (int i = 0; i < FIVE; ++i) {
        for (int j = 0; j < FIVE; ++j) {                     // The user enter a matrix
            cin >> matrix[i][j];
        }
    }
    while (row < FOUR && sum == 0) {                    // For each line from zero to 3 and just if sum still 0
        check = 1;
        while ((check + row) < FIVE && sum == 0) {              // Fits each row the rows after it (the test row) up to the fourth and last row
            column = ZERO ;                                     // Start from column zero
            while (column < FIVE) {                             // to column four
                sum = sum + (matrix[row][column] * matrix[row + check][column]);  // check if the lines of the matrix are orthogonal
                ++column ;
            }
            ++check ;
    }
        ++row ;
    }
    if (sum == ZERO) {
        cout << "The lines of the matrix are orthogonal\n" ;
    }                                                                 // Prints an appropriate message to the user
    else
        cout << "The lines of the matrix are not orthogonal\n" ;
}



void number (int num1) {
    // This function sends to three functions that calculate different values
    right(num1);
    left(num1);
    twice(num1);
}
void right(int num1) {
    // This function accepts a number and prints the number after shifting each digit one place to the right.
    int first_digit, new_num ;
    first_digit = (num1 % TEN) ;               // Saving the last digit in a variable
    new_num = num1 / TEN ;                     // The new number is the original number without the last digit
    while (num1 / TEN != ZERO) {
        first_digit *= TEN ;                   //Transferring the last digit to the first digit by multiplying by ten according to the number of digits
        num1 = num1 / TEN ;
    }
    new_num = (first_digit + new_num) ;
    cout << "right rotate: " <<  new_num << endl ;
}

void left (int num1) {
    // This function accepts a number and prints the number after shifting each digit one place to the left.
    int new_num, counter = ZERO, last_digit, first_digit;
    last_digit = num1 ;
    while ((last_digit / TEN) != ZERO) {
        ++counter ;                                  // Saving the first digit in a variable
        last_digit /= TEN;
    }
    first_digit = last_digit ;
    for (int i = 0; i < counter; ++i) {                      // Calculates the value of the first digit
        first_digit *= TEN;
    }
    new_num = ((num1 - first_digit) * TEN) + last_digit  ;      // The new number is the original number minus the value of the first digit times ten plus the last digit
    cout << "left rotate: " <<  new_num << endl;
}

void twice ( int num1) {
    // This function takes a number and prints a number that contains every digit of the original number twice
    int new_num, modulo, counter = ZERO ;
    long long done_num = ZERO;
    while ((num1 % TEN) != ZERO) {
        modulo = (num1 % TEN);                             // Digit duplication
        new_num = (modulo * TEN) + modulo;
        for (int i = 0; i < counter; ++i) {
            new_num *= HUNDRED ;                          // The position of the digits in the final number
        }
        ++counter;
        done_num = done_num + new_num;                     // Connecting the current pair of digits with the previous pairs
        num1 /= TEN ;                                       // Move to the next digit
    }
    cout << "Twice: " << done_num << endl;
}

int factorial (int line) {
    // This function accepts a number and calculates its factorial
    long factorial = ONE ;
    for (int i = line ; i >= ONE ; --i ) {
        factorial = factorial * i ;                      // Multiplying the number by all the numbers from one up to it
    }
    return factorial;
}

void pascal_Triangle(int line) {
    /* This function accepts an integer, and prints the first rows of a triangle
    Pascal from line number 0 to the entered number */
    int number ;
    for (int n = 0; n <= line; ++n) {                 // The rows
        for (int m = 0; m <= n; ++m) {                               // The position of the number in the line
            number = factorial(n) / (factorial(m) * factorial(n - m)) ;         // Printing the number according to the formula for finding a term in Pascal's triangle
            cout << number << " ";
        }
        cout << endl;
    }
}

void triangle_Of_Letters (int letters){
    /* This function accepts a number between 1 and 26 and a print a triangle of letters
    consisting of a number of lines according to the entered number.
     In line number i in the triangle appear the Latin letters from a up to the letter number i, and then in descending order up to a */
    int j ;
    char alpha ;
    while (letters < ONE || letters > TWENTY_SIX){
        cout << "the number is not in the range, enter number between 1 - 26: \n" ;      // Checking that the entered number is within the requested range
        cin >> letters ;
    }
    for (int i = 0 ; i < letters ; ++i) {                // The rows
        for  (j = 0, alpha = 'a'; j <= i; ++j) {                     // The position of the letter in the line
            cout << alpha;
            ++alpha;                                      // print the letters from a to i (the asking letter)
        }
        alpha -= TWO ;
        for (int k = j ; k > ONE ; --k ) {                // print the letters from i (the asking letter) to a
            cout << alpha ;
            --alpha ;
        }
        cout << endl;
    }
}

void contain (int vector1[], int vector2[]) {
    /* This function accepts two arrays of integers: the first of size 12, and the second of size 5.
    It prints the index the first in the large array where the small array begins.
    If no such index exists, 1.- will be printed */
    int n = ZERO, j ;
    int check = ZERO, output_number;
    for (int i = 0; i < TWELVE; ++i) {
        cin >> vector1[i];                      // Reception of the large array
    }
    cout << "enter 5 numbers vector: \n";
    for (int i = 0; i < FIVE; ++i) {             // Reception of the small array
        cin >> vector2[i];
    }
    while ((n <= EIGHT) && (check != ONE)) {         // For each number in the large array from zero to 8 and just if check still 0
        j = ZERO ;
        while ((vector1[n+j] == vector2[j]) && (j < FIVE)) {    // For each number in the small array from zero to 4 and just if it equal to large array [n]
            j += ONE ;
            if (j == FIVE) {                       // If a match is found
                output_number = vector2[ZERO] ;
                check = ONE ;                            // change the check to stop function running
                while (output_number / TEN != ZERO)
                    output_number = output_number / TEN ;          // print the first digit of the first number in small array
                cout << output_number << endl ;
            }
        }
        ++n  ;
    }

    if (n >= EIGHT) {                       // If a match is not founded
        cout << "-1\n" ;
    }
}

void matrix_Statistics (int matrix [][FIVE]) {
    /* This function accepts a matrix of 5*5 integers, and prints:
    the sum of the largest elements in each row, the sum of the largest members in each column,
     and the number of pairs of equal neighbors. Neighborhoods can be too diagonally. */
    int max = ZERO, sum = ZERO, counter = ZERO ;
    for (int i = 0; i < FIVE; ++i) {
        for (int j = 0; j < FIVE; ++j) {                     // The user enter a matrix
            cin >> matrix[i][j];
        }
    }

    // The sum of the largest elements in each row
    for (int i = 0 ; i < FIVE ; ++i){
        for (int j = 0; j < FIVE; ++j){
            if (matrix [i][j] > max) {              // Finding the largest term in each row
                max = matrix[i][j] ;
            }
        }
        sum = sum + max ;                           // sum of the largest elements
        max = ZERO ;
    }
    cout << "The sum of the largest terms in each row is: " << sum << endl ;
    sum = ZERO ;

    // The sum of the largest members in each column
    for (int i = 0 ; i < FIVE ; ++i){
        for (int j = 0 ; j < FIVE; ++j){
            if (matrix [j][i] > max) {                // Finding the largest term in each column
                max = matrix[j][i] ;
            }
        }
        sum = sum + max ;                                // sum of the largest elements
        max = ZERO ;
    }
    cout << "The sum of the largest terms in each column is:" << sum << endl ;

    // The number of pairs of equal neighbors
    for (int i = 0 ; i < FIVE ; ++i) {
        for (int j = 0; j < FIVE; ++j) {                       // For each element in the matrix
            if(i != FOUR && j != ZERO &&  j != FOUR) {                // Case 1 - four neighbors to check
                if (matrix[i][j] == matrix[i][j + ONE]) {
                    ++counter;
                    cout << "(" << matrix[i][j] << "," << matrix[i][j + ONE] << ") ";
                }
                if (matrix[i][j] == matrix[i + ONE][j]) {
                    ++counter;
                    cout << "(" << matrix[i][j] << "," << matrix[i + ONE][j] << ") ";
                }
                if (matrix[i][j] == matrix[i + ONE][j + ONE]) {
                    ++counter;
                    cout << "(" << matrix[i][j] << "," << matrix[i + ONE][j + ONE] << ") ";
                }
                if (matrix[i][j] == matrix[i + ONE][j - ONE]) {
                    ++counter;
                    cout << "(" << matrix[i][j] << "," << matrix[i + ONE][j - ONE] << ") ";
                }
            }
            else if(i != FOUR && j == ZERO){                        // Case 2 - three neighbors to check
                if (matrix[i][j] == matrix[i][j + ONE]) {
                    ++counter;
                    cout << "(" << matrix[i][j] << "," << matrix[i][j + ONE] << ") ";
                }
                if (matrix[i][j] == matrix[i + ONE][j]) {
                    ++counter;
                    cout << "(" << matrix[i][j] << "," << matrix[i + ONE][j] << ") ";
                }
                if (matrix[i][j] == matrix[i + ONE][j + ONE]) {
                    ++counter;
                    cout << "(" << matrix[i][j] << "," << matrix[i + ONE][j + ONE] << ") ";
                }
            }
            else if( i != FOUR) {                                   // Case 3 - two neighbors to check
                if (matrix[i][j] == matrix[i + ONE][j]) {
                    ++counter;
                    cout << "(" << matrix[i][j] << "," << matrix[i + ONE][j] << ") ";
                }
                if (matrix[i][j] == matrix[i + ONE][j - ONE]) {
                    ++counter;
                    cout << "(" << matrix[i][j] << "," << matrix[i + ONE][j - ONE] << ") ";
                }
            }
            else if(j != FOUR){                                    // Case 4 - one neighbor to check
                if (matrix[i][j] == matrix[i][j + ONE]) {
                    ++counter;
                    cout << "(" << matrix[i][j] << "," << matrix[i][j + ONE] << ") ";
                }
            }
        }
        }
    cout << endl << "The number of neighbors: " << counter << endl ;

    }

float square_root_approx (float num_x, float epsilon) {
    /* This function finds an approximation of a square root. She gets two real numbers,x and epsilon.
    The return value of the function is an approximation of the square root of x with an accuracy of epsilon */
    int check = ZERO ;
    float left = ZERO, right, middle, middle_squared  ;
    right = num_x + ONE ;
    while ((right - left) > epsilon && check == ZERO) {             // Checks the accuracy of the square root approximation
        middle = (right + left) / TWO ;                             // Average calculation
        middle_squared = middle*middle ;                            // Average squared calculation
        cout << "left = " << left << ",    right = " << right << ",    middle = " << middle << ",    middle^2 = " << middle_squared << endl ;
        if (middle_squared == num_x ) {
            cout << "The square root is " << middle << endl ;       // Find the square root of x
            check = ONE ;                                           // stop running
        }
        else if (middle_squared > num_x) {                          // Changing the border on the right
            right = middle ;
        }
        else if (middle_squared < num_x){                           // Changing the border on the left
            left = middle ;
        }

    }
    cout << "The square root approximation is: " << middle << ". \n" ;
    return middle ;
}