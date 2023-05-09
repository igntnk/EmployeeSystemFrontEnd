#include "database.h"
#include "employee.h"

DataBase::DataBase()
{
    ranks.push_back(Rank(0,"Admin"));
    ranks.push_back(Rank(1,"Boss"));
    ranks.push_back(Rank(2,"Manager"));
    ranks.push_back(Rank(3,"Worker"));

    QString taskDesc = "Now there is nothing but later there will be something useful,"
                       " for example word or two about your mommy";

    tasks.push_back(Task(0,"Cleaning",taskDesc,0,QDate(2023,8,12),QDate(2022,8,23)));
    tasks.push_back(Task(1,"Shopping",taskDesc,0,QDate(2024,1,1),QDate(2021,1,12)));
    tasks.push_back(Task(2,"Climbing",taskDesc,2,QDate(2023,11,1),QDate(2021,5,22)));
    tasks.push_back(Task(3,"Writing",taskDesc,4,QDate(2023,11,1),QDate(2022,11,30)));
    tasks.push_back(Task(4,"Celebrating",taskDesc,0,QDate(2025,10,1),QDate(2022,6,3)));
    tasks.push_back(Task(5,"Codding",taskDesc,1,QDate(2023,12,1),QDate(2022,1,1)));

    employeers.push_back(Employee(0,"Ignat","Ilyenko","Batkovich",tasks[0],ranks[0],
                                  "Ignat","123",QDate(2022,1,1),false));
    employeers.push_back(Employee(1,"Kabub","Danilenko","Batkovich",tasks[2],ranks[1],
                                  "Kabub","234",QDate(2022,3,11),false));
    employeers.push_back(Employee(2,"Svin","Uhov","Batkovich",tasks[0],ranks[1],
                                  "Svin","345",QDate(1965,2,2),false));
    employeers.push_back(Employee(3,"Semen","Gachimuchivich","Batkovich",tasks[3],ranks[2],
                                  "Semen","456",QDate(1900,2,31),true));
    employeers.push_back(Employee(4,"Lapyh","Dubovich","Batkovich",tasks[2],ranks[2],
                                  "Lapyh","567",QDate(2022,1,1),false));
    employeers.push_back(Employee(5,"Deinekyn","Irinenko","Batkovich",tasks[5],ranks[2],
                                  "Deinekyn","678",QDate(658,12,12),false));
    employeers.push_back(Employee(6,"Zuzenko","Konstant","Batkovich",tasks[4],ranks[3],
                                  "Zuzenko","789",QDate(2023,7,24),true));
    employeers.push_back(Employee(7,"Bezugl","Kyryllyi","Batkovich",tasks[5],ranks[3],
                                  "Bezugl","890",QDate(2021,12,25),false));
}

int DataBase::employeeNumbers()
{
    return employeers.size();
}

Employee DataBase::getEmployee(int number)
{
    return employeers[number];
}

std::vector<Employee> DataBase::getEmployeers()
{
    return employeers;
}
