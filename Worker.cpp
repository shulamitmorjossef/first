//
// Created by Student on 8/1/2023.
//
#include <iostream>
#include "Worker.h"
#include <iomanip>


using namespace std;

Worker::Worker(){
    // This function is an empty constructor
}

Worker::Worker(const char _name[15], const long _id, const double salary, const int rHours, const int eHours){
    // This function is a constructor, it receives parameters and initializes the object accordingly
    for(int i = 0; i<15; ++i)
        this->name[i] = _name[i];
    this->id = _id;
    this->salaryPerHour = salary;
    this->regularHours = rHours;
    this->extraHours = eHours;
}

char* Worker::getName(){
    // This function return name of worker
    return name;
}

long Worker::getId() {
    // This function return ID of worker
    return id;
}

double Worker::getSalary() {
    // This function return salary per hour of worker
    return salaryPerHour;
}

int Worker::getRegularHours() {
    // This function return number of regular hours of worker
    return regularHours;
}

int Worker::getExtraHours() {
    // This function return number of extra hours of worker
    return extraHours;
}

void Worker::setSalary(const double salary){
    // This function accepts a double number and updates the worker's hourly wage
    salaryPerHour = salary;
}

void Worker::setRegularHours(const int rHours){
    // This function accepts an int number and updates the worker's number of regular hours
    regularHours = rHours;
}

void Worker::setExtraHours(const int eHours){
    // This function accepts an int number and updates the worker's number of extra hours
    extraHours = eHours;
}

double Worker::monthlySalary() {
    // This function calculates the worker's monthly salary and return it
    double monthlySal = regularHours*salaryPerHour + extraHours*1.5*salaryPerHour;
    return (monthlySal);
}

void Worker::showDetails() {
    // This function print worker's details
    cout<< "name: " <<name<< endl
    <<"id: "<< id<<endl
    <<"salary per hour: "<<fixed << setprecision(2)<<salaryPerHour<<endl
    <<"regularHours: "<<regularHours<<endl
    <<"extraHours: "<<extraHours<<endl;
    //<< setprecision(3);
    //cout <<"monthly salary: "<< monthlySalary() << endl;
    cout<<"monthly salary: "<<fixed << setprecision(2)<<monthlySalary()<<endl;   // Print the salary with exactly 2 digits after the decimal point
}