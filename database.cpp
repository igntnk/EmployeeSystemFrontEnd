#include "database.h"
#include "employee.h"

DataBase::DataBase()
{
    ranks.push_back(Rank(0,"Admin"));
    ranks.push_back(Rank(1,"Boss"));
    ranks.push_back(Rank(2,"Manager"));
    ranks.push_back(Rank(3,"Worker"));

    tasks.push_back(Task(0,"Cleaning",0,QDate(2023,8,12),QDate(2022,8,23)));
    tasks.push_back(Task(1,"Cleaning",0,QDate(2024,1,1),QDate(2021,1,12)));
    tasks.push_back(Task(2,"Cleaning",2,QDate(2023,11,1),QDate(2021,5,22)));
    tasks.push_back(Task(3,"Cleaning",4,QDate(2023,11,1),QDate(2022,11,30)));
    tasks.push_back(Task(4,"Cleaning",0,QDate(2025,10,1),QDate(2022,6,3)));
    tasks.push_back(Task(5,"Cleaning",1,QDate(2023,12,1),QDate(2022,1,1)));

    employeers.push_back(Employee(0,"Ignat","Ilyenko",tasks[0],ranks[0],
                                  "admin","admin",QDate(2022,1,1),false));
    employeers.push_back(Employee(1,"Kabub","Danilenko",tasks[2],ranks[1],
                                  "admin","admin",QDate(2022,1,1),false));
    employeers.push_back(Employee(2,"Svin","Uhov",tasks[0],ranks[1],
                                  "admin","admin",QDate(2022,1,1),false));
    employeers.push_back(Employee(3,"Semen","Gachimuchivich",tasks[3],ranks[2],
                                  "admin","admin",QDate(2022,1,1),false));
    employeers.push_back(Employee(4,"Lapyh","Dubovich",tasks[2],ranks[2],
                                  "admin","admin",QDate(2022,1,1),false));
    employeers.push_back(Employee(5,"Deinekyn","Irinenko",tasks[5],ranks[2],
                                  "admin","admin",QDate(2022,1,1),false));
    employeers.push_back(Employee(6,"Zuzenko","Konstant",tasks[4],ranks[3],
                                  "admin","admin",QDate(2022,1,1),false));
    employeers.push_back(Employee(7,"Bezugl","Kyryllyi",tasks[5],ranks[3],
                                  "admin","admin",QDate(2022,1,1),false));
}

int DataBase::employeeNumbers()
{
    return employeers.size();
}

Employee DataBase::getEmployee(int number)
{
    return employeers[number];
}
