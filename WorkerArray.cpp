//
// Created by Student on 8/2/2023.
//
#include <iostream>
#include "WorkerArray.h"

using namespace std;

WorkerArray::WorkerArray(){
    // This function is an empty constructor that allocates an array of employees of length 0
    size = 0;
    array = nullptr ;
}
WorkerArray::WorkerArray(Worker* arr, int _size){
    // This function is a constructor, it receives size and worker array and allocates an array of workers of length size
    this-> size = _size;
    this->array = new Worker[size];
    for(int i = 0; i<size; ++i){
        array[i] = arr[i];
    }
}
WorkerArray::WorkerArray(const WorkerArray& arr){
    /* This function is a copy constructor, it receives worker array by reference
    and allocates a new array of workers of same size and initializes it with the values of the received array*/
    this->size = arr.size;
    this->array = new Worker[size];
    for(int i = 0;i<size;++i){
        this->array[i] = arr.array[i];
    }
}
WorkerArray::~WorkerArray(){
    // This function is destructor
    delete [] array;
}
Worker*  WorkerArray::getArray(){
    // This function return worker's array
    return array;
}
void WorkerArray::addWorker(Worker worker){
    // This function receives worker's details and add the worker to array
    ++this->size;
    Worker* newArray = new Worker [size];
    for(int i = 0; i < size-1; ++i){
        newArray[i] = this->array[i];
    }
    newArray[size-1] = worker;
    delete[]this->array;
    this->array = newArray;
}
void WorkerArray::tenPercMore(){
    // This function adds ten percent to the salary of all the workers
    for (int i = 0; i < size; ++i) {
        array[i].setSalary(array[i].getSalary()*1.1);
    }
}
bool WorkerArray::returnMember(int index, Worker& item){
    /* This function receives a variable of type worker by reference and index,
    if the index exists in the array it returns true and the value of the index in the reference, otherwise it returns false*/
    if(size <= index)
        return false;
    item = array[index];
    return true;
}
double WorkerArray::maxMonthSalary(){
    // This function return the  highest salary
    double max = array[0].getSalary();
    for (int i = 1; i < this->size; ++i) {
        if(array[i].monthlySalary()> max){
            max = array[i].monthlySalary();
        }
    }
    return max;
}
int WorkerArray::sizeOfArray() {
    // This function return the length of the array
    return size;
}
void WorkerArray::printArray(){
    // This function print the array
    for (int i = 0; i < size; ++i) {
        cout<<"Worker number "<< i+1 << " is: \n" ;
        array[i].showDetails();
        cout<< endl;
    }
    cout <<"End of WorkerArray\n-------------------------------------------------------\n";
}