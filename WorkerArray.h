//
// Created by Student on 8/2/2023.
//

#ifndef PART3_WORKERARRAY_H
#define PART3_WORKERARRAY_H
#include "Worker.h"

class WorkerArray {
public:
    WorkerArray();
    WorkerArray(Worker*, int );
    WorkerArray(const WorkerArray&);
    ~WorkerArray();
    Worker* getArray();
    void addWorker(Worker);                         // Statement on the functions of the "WorkerArray" department
    void tenPercMore();
    bool returnMember(int, Worker&);
    double maxMonthSalary();
    int sizeOfArray() ;
    void printArray();

private:
    Worker* array;                        // Statement on the members of the "WorkerArray" department
    int size;
};


#endif //PART3_WORKERARRAY_H
