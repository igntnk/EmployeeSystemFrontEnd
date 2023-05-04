#ifndef DATABASE_H
#define DATABASE_H

#include "employee.h"
#include "task.h"
#include "rank.h"
#include <vector>

class DataBase
{
public:
    DataBase();

    int employeeNumbers();
    Employee getEmployee(int number);
    std::vector<Employee> getEmployeers();

private:

    std::vector<Employee> employeers;
    std::vector<Task> tasks;
    std::vector<Rank> ranks;

};

#endif // DATABASE_H
