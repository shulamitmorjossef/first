#include <iostream>
#include "MyMatrix.h"
#include "Worker.h"
#include "WorkerArray.h"
#include <cstring>
#include <iomanip>
using namespace std;

void testMyMatrix();
void testWorkers();
void testWorkerArray();

int main(){

    //testMyMatrix();
    //testWorkers();
    //testWorkerArray();

    return 0;
}



void testMyMatrix(){
    float num1, num2, num3, num4 ;
    cout << "Enter first matrix:\n";
    cin >> num1 >> num2 >> num3 >> num4;             // Creates and initializes matrix A
    MyMatrix A (num1,num2,num3,num4);

    MyMatrix A_copy(A);                               // Copy matrix A to another MyMatrix

    cout << "Enter second matrix:\n";
    cin >> num1 >> num2 >> num3 >> num4;             // Creates and initializes matrix B
    MyMatrix B (num1,num2,num3,num4);

    cout << "Enter third matrix:\n";
    cin >> num1 >> num2 >> num3 >> num4;              // Creates and initializes matrix C
    MyMatrix C (num1,num2,num3,num4);

    cout << "-------------------------------------------\n";

    if(A.isEqual(B))
        cout<<"The matrices A and B is equal\n";
    else
        cout<<"The matrices A and B is not equal\n";
    //cout << "-------------------------------------------\n";
    if(A.isEqual(C))
        cout<<"The matrices A and C is equal\n";
    else                                                                         // Check and print if the matrices is equal
        cout<<"The matrices A and C is not equal\n";
    //cout << "-------------------------------------------\n";
    if(B.isEqual(C))
        cout<<"The matrices B and C is equal\n";
    else
        cout<<"The matrices B and C is not equal\n";
    cout << "-------------------------------------------\n";


    cout << "The determinant of the A matrix is " << A.det() << endl ;
    //cout << "-------------------------------------------\n";

    cout << "The determinant of the B matrix is " << B.det() << endl ;            // Print determinants of the matrices
    //cout << "-------------------------------------------\n";

    cout << "The determinant of the C matrix is " << C.det() << endl ;
    cout << "-------------------------------------------\n";


    A_copy.multi(B);
    A_copy.add(C);
    cout << "The matrix A*B+C is: \n" ;                                        // Calculates and prints the matrix A*B+C using A_copy
    A_copy.print();
    cout << "-------------------------------------------\n";

    cout << "Enter second matrix again:\n";
    cin >> num1 >> num2 >> num3 >> num4;                                       // Updates matrix B values
    B.set(num1, num2, num3, num4) ;

    A.multi(B);
    A.add(C);
    cout << "The new matrix A*B+C is: \n" ;
    A.print();                                                               // Calculates and prints the new matrix A*B+C

}

void testWorkers() {
//    cout <<"---------------------------------\n";
//    cout << "test Worker: \n";
//    cout <<"---------------------------------\n";
//    Worker sec("shulamit", 206576977, 95, 100, 20);
//    if (strcmp(sec.getName(), "shulamit") == 0) {
//        cout << "test pass\n";
//    } else
//        cout << "--------test fail---------\n";
//    if (sec.getId() == 206576977) {
//        cout << "test pass\n";
//    } else
//        cout << "--------test fail---------\n";
//    if (sec.getSalary() == 95) {
//        cout << "test pass\n";
//    } else
//        cout << "--------test fail---------\n";                     // Testing Worker methods
//    if (sec.getRegularHours() == 100) {
//        cout << "test pass\n";
//    } else
//        cout << "--------test fail---------\n";
//    if (sec.getExtraHours() == 20) {
//        cout << "test pass\n";
//    } else
//        cout << "--------test fail---------\n";
//    if (sec.monthlySalary() == 95 * 100 + 95 * 20 * 1.5) {
//        cout << "test pass\n";
//    } else
//        cout << "--------test fail---------\n";

    char name[15];
    long id;
    double salary;
    int regH, extH;
    cout <<"---------------------------------\n";
    cout << "test Worker: \n";
    cout <<"---------------------------------\n";
    cout << "Enter name: \n";
    cin>> name;
    cout << "Enter id: \n";
    cin>> id;
    cout << "Enter salary per hour: \n";
    cin>> salary;                                                    // An example of running the program
    cout << "Enter number of regular hours: \n";
    cin>> regH;
    cout << "Enter number of extra hours: \n";
    cin>> extH;
    Worker first{name, id,salary,regH,extH};
    cout<<"salary is: "<<fixed << setprecision(2)<<first.monthlySalary()<< endl;
    first.showDetails();
}

void testWorkerArray() {
    cout <<"---------------------------------\n";
    cout << "test Worker Array: \n";
    cout <<"---------------------------------\n";
    Worker first("name", 000000000, 0, 0, 0);                      // Creating "empty" Worker
    Worker sec("shulamit", 206576977, 95.6671, 100, 20);
    Worker third("chana", 123456789, 46.92, 80, 40);               // Creating 2 Workers

    WorkerArray arr1;                                              // Creating Worker array with an empty constructor

    arr1.addWorker(sec);                                           // Initialize the array using the add function
    arr1.addWorker(third);

    WorkerArray arr2(arr1.getArray(),arr1.sizeOfArray());         //  Creating and initialize Worker array with a another constructor

    WorkerArray arr3 = arr1;                                      //  Creating and initialize Worker array with a copy constructor

// arr1, arr2, arr3 with the same values

    cout << "Arr values:\n";                       // print arr1
    arr1.printArray();

    arr2.tenPercMore();                          // update salary of workers in arr2  - add 10 percent

    cout << "Arr values after update:\n";
    arr2.printArray();                              // print arr2  - arr1 after updating

    int index;
    cout <<"Enter index to check: \n";
    cin >> index;
    if (arr1.returnMember(index, first)){
        cout << "test pass\nthere is worker in index "<< index <<"\n\n";
        cout << "The worker in index " << index<< " is: \n\n";
        first.showDetails();                                                        // Check if there is Worker in a certain index and print it
    }
    else
        cout<< "--------test fail---------\n there is no worker in index "<<index<<"\n";

    cout<< "\nThe highest monthly salary is:\n" << arr2.maxMonthSalary() << endl;         // print the highest monthly salary

}
