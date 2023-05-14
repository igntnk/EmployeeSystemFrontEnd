#ifndef DATABASE_H
#define DATABASE_H

#include <QMessageBox>
#include "employee.h"
#include "task.h"
#include "rank.h"
#include <vector>

class DataBase
{
public:
    DataBase();

    int employeeNumbers();
    Employee* getEmployee(int number);
    std::vector<Employee> getEmployeers();

    Task* getTask(int number);
    Task getTask(QString name);
    int taskNumbers();

    Rank getRank(int number);

    void addEmployee(const Employee& refer);
    void deleteEmployee(int number);

private:

    std::vector<Employee> employeers;
    std::vector<Task> tasks;
    std::vector<Rank> ranks;

};

#endif // DATABASE_H
