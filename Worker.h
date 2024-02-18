//
// Created by Student on 8/1/2023.
//

#ifndef PART3_WORKER_H
#define PART3_WORKER_H


class Worker {
public:
    Worker();
    Worker(const char[15], long, double, int, int);
    char* getName ();
    long getId() ;
    double getSalary() ;
    int getRegularHours() ;
    int getExtraHours() ;                  // Statement on the functions of the "Worker" department
    void setSalary(double);
    void setRegularHours(int);
    void setExtraHours(int);
    double monthlySalary() ;
    void showDetails() ;
private:
    char name [15] ;
    long id;
    double salaryPerHour;                               // Statement on the members of the "Worker" department
    int regularHours;
    int extraHours;

};


#endif //PART3_WORKER_H
