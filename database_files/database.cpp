#include "database.h"

DataBase::DataBase()
{
    Task* referTask = new Task();
    referTask->setId(tasksAmount());
    referTask->setName("Create DataBase");
    referTask->setDescription("Create data base using PostgreSQL and Qt");
    referTask->setDeadline(QDate(2023,5,22));
    referTask->setStartline(QDate(2023,1,12));

    m_tasks.push_back(referTask);

    referTask = new Task();
    referTask->setId(tasksAmount());
    referTask->setName("Create OpenGl cube");
    referTask->setDescription("Create textured cube model using OpenGl 1998 year version");
    referTask->setDeadline(QDate(2023,6,12));
    referTask->setStartline(QDate(2021,5,12));

    m_tasks.push_back(referTask);

    referTask = new Task();
    referTask->setId(tasksAmount());
    referTask->setName("Create Refer DB Video");
    referTask->setDescription("Create simple video with data base programm using After Effects");
    referTask->setDeadline(QDate(2023,5,12));
    referTask->setStartline(QDate(2023,1,12));

    m_tasks.push_back(referTask);

    referTask = new Task();
    referTask->setId(tasksAmount());
    referTask->setName("Trash");
    referTask->setDescription("trash task to make a size");
    referTask->setDeadline(QDate(2000,2,22));
    referTask->setStartline(QDate(2023,1,12));

    m_tasks.push_back(referTask);

    referTask = new Task();
    referTask->setId(tasksAmount());
    referTask->setName("Trash");
    referTask->setDescription("trash task to make a size");
    referTask->setDeadline(QDate(2000,2,22));
    referTask->setStartline(QDate(2023,1,12));

    m_tasks.push_back(referTask);

    referTask = new Task();
    referTask->setId(tasksAmount());
    referTask->setName("Trash");
    referTask->setDescription("trash task to make a size");
    referTask->setDeadline(QDate(2000,2,22));
    referTask->setStartline(QDate(2023,1,12));

    m_tasks.push_back(referTask);

    referTask = new Task();
    referTask->setId(tasksAmount());
    referTask->setName("Trash");
    referTask->setDescription("trash task to make a size");
    referTask->setDeadline(QDate(2000,2,22));
    referTask->setStartline(QDate(2023,1,12));

    m_tasks.push_back(referTask);

    referTask = new Task();
    referTask->setId(tasksAmount());
    referTask->setName("Trash");
    referTask->setDescription("trash task to make a size");
    referTask->setDeadline(QDate(2000,2,22));
    referTask->setStartline(QDate(2023,1,12));

    m_tasks.push_back(referTask);

    referTask = new Task();
    referTask->setId(tasksAmount());
    referTask->setName("Trash");
    referTask->setDescription("trash task to make a size");
    referTask->setDeadline(QDate(2000,2,22));
    referTask->setStartline(QDate(2023,1,12));

    m_tasks.push_back(referTask);

    referTask = new Task();
    referTask->setId(tasksAmount());
    referTask->setName("Trash");
    referTask->setDescription("trash task to make a size");
    referTask->setDeadline(QDate(2000,2,22));
    referTask->setStartline(QDate(2023,1,12));

    m_tasks.push_back(referTask);

    Department* referDep = new Department();
    referDep->setId(departmentsAmount());
    referDep->setName("Programming");

    m_departments.push_back(referDep);

    referDep = new Department();
    referDep->setId(departmentsAmount());
    referDep->setName("Video Editor");

    m_departments.push_back(referDep);

    referDep = new Department();
    referDep->setId(departmentsAmount());
    referDep->setName("Text editor");

    m_departments.push_back(referDep);

    Rank* referRank = new Rank();
    referRank->setId(ranksAmount());
    referRank->setName("Admin");
    referRank->setDepartment(department(1));

    m_ranks.push_back(referRank);

    referRank = new Rank();
    referRank->setId(ranksAmount());
    referRank->setName("Director");
    referRank->setDepartment(department(0));

    m_ranks.push_back(referRank);

    referRank = new Rank();
    referRank->setId(ranksAmount());
    referRank->setName("Assistant");
    referRank->setDepartment(department(1));

    m_ranks.push_back(referRank);

    referRank = new Rank();
    referRank->setId(ranksAmount());
    referRank->setName("Manager");
    referRank->setDepartment(department(0));

    m_ranks.push_back(referRank);

    referRank = new Rank();
    referRank->setId(ranksAmount());
    referRank->setName("Instructor");
    referRank->setDepartment(department(2));

    m_ranks.push_back(referRank);

    referRank = new Rank();
    referRank->setId(ranksAmount());
    referRank->setName("Worker");
    referRank->setDepartment(department(2));

    m_ranks.push_back(referRank);

    Document* referDoc = new Document();
    referDoc->setCode("2017122374");
    referDoc->setId(documentsAmount());
    referDoc->setName("Passport");

    m_documents.push_back(referDoc);

    referDoc = new Document();
    referDoc->setCode("48095351208");
    referDoc->setId(documentsAmount());
    referDoc->setName("SNILS");

    m_documents.push_back(referDoc);

    referDoc = new Document();
    referDoc->setCode("82763692");
    referDoc->setId(documentsAmount());
    referDoc->setName("Medical book");

    m_documents.push_back(referDoc);

    referDoc = new Document();
    referDoc->setCode("2018122374");
    referDoc->setId(documentsAmount());
    referDoc->setName("Passport");

    m_documents.push_back(referDoc);

    referDoc = new Document();
    referDoc->setCode("56245967124");
    referDoc->setId(documentsAmount());
    referDoc->setName("SNILS");

    m_documents.push_back(referDoc);

    referDoc = new Document();
    referDoc->setCode("73855262");
    referDoc->setId(documentsAmount());
    referDoc->setName("Medical book");

    m_documents.push_back(referDoc);

    referDoc = new Document();
    referDoc->setCode("2003256666");
    referDoc->setId(documentsAmount());
    referDoc->setName("Passport");

    m_documents.push_back(referDoc);

    referDoc = new Document();
    referDoc->setCode("82653719752");
    referDoc->setId(documentsAmount());
    referDoc->setName("SNILS");

    m_documents.push_back(referDoc);

    referDoc = new Document();
    referDoc->setCode("28165735");
    referDoc->setId(documentsAmount());
    referDoc->setName("Medical book");

    m_documents.push_back(referDoc);

    Payment* referPay = new Payment();
    referPay->setId(paymentsAmount());
    referPay->setName("Ilya Salary");
    referPay->setAmount(40000);

    m_payments.push_back(referPay);

    referPay = new Payment();
    referPay->setId(paymentsAmount());
    referPay->setName("Danil Salary");
    referPay->setAmount(30000);

    m_payments.push_back(referPay);

    referPay = new Payment();
    referPay->setId(paymentsAmount());
    referPay->setName("Andrey Salary");
    referPay->setAmount(280000);

    m_payments.push_back(referPay);

    referPay = new Payment();
    referPay->setId(paymentsAmount());
    referPay->setName("Zuzev Salary");
    referPay->setAmount(500000);

    m_payments.push_back(referPay);

    Employee* referEmployee = new Employee();
    referEmployee->setId(employeesAmount());
    referEmployee->setName("Ilya");
    referEmployee->setSurname("Ignatenko");
    referEmployee->setUsername("Ilya");
    referEmployee->setPassword("123");
    referEmployee->setHireDate(QDate::currentDate());
    referEmployee->addTask(m_tasks[0]);
    referEmployee->addTask(m_tasks[1]);
    referEmployee->addTask(m_tasks[2]);
    referEmployee->setRank(m_ranks[ranksAmount()-3]);
    referEmployee->addDocument(m_documents[0]);
    referEmployee->addDocument(m_documents[1]);
    referEmployee->addDocument(m_documents[2]);
    referEmployee->addPayment(m_payments[0]);

    m_employeers.push_back(referEmployee);

    referEmployee = new Employee();
    referEmployee->setId(employeesAmount());
    referEmployee->setName("Danil");
    referEmployee->setSurname("Svinoukhov");
    referEmployee->setUsername("Danil");
    referEmployee->setPassword("234");
    referEmployee->setHireDate(QDate(2022,12,2));
    referEmployee->addTask(m_tasks[1]);
    referEmployee->setRank(m_ranks[ranksAmount()-1]);
    referEmployee->addDocument(m_documents[3]);
    referEmployee->addDocument(m_documents[1]);
    referEmployee->addDocument(m_documents[4]);
    referEmployee->addPayment(m_payments[1]);

    m_employeers.push_back(referEmployee);

    referEmployee = new Employee();
    referEmployee->setId(employeesAmount());
    referEmployee->setName("Danil");
    referEmployee->setSurname("Kabirov");
    referEmployee->setUsername("Danil");
    referEmployee->setPassword("345");
    referEmployee->setHireDate(QDate(2021,2,12));
    referEmployee->addTask(m_tasks[2]);
    referEmployee->setRank(m_ranks[0]);
    referEmployee->addDocument(m_documents[3]);
    referEmployee->addDocument(m_documents[1]);
    referEmployee->addDocument(m_documents[4]);
    referEmployee->addPayment(m_payments[1]);

    m_employeers.push_back(referEmployee);

    referEmployee = new Employee();
    referEmployee->setId(employeesAmount());
    referEmployee->setName("Andrew");
    referEmployee->setSurname("Abramov");
    referEmployee->setUsername("Andrey");
    referEmployee->setPassword("567");
    referEmployee->setHireDate(QDate(1272,8,27));
    referEmployee->addTask(m_tasks[3]);
    referEmployee->setRank(m_ranks[ranksAmount()-1]);
    referEmployee->addDocument(m_documents[3]);
    referEmployee->addDocument(m_documents[1]);
    referEmployee->addDocument(m_documents[4]);
    referEmployee->addPayment(m_payments[1]);

    m_employeers.push_back(referEmployee);

    referEmployee = new Employee();
    referEmployee->setId(employeesAmount());
    referEmployee->setName("Kirill");
    referEmployee->setSurname("Bezuglyi");
    referEmployee->setUsername("Kirill");
    referEmployee->setPassword("678");
    referEmployee->setHireDate(QDate(2009,12,3));
    referEmployee->addTask(m_tasks[3]);
    referEmployee->setRank(m_ranks[ranksAmount()-3]);
    referEmployee->addDocument(m_documents[3]);
    referEmployee->addDocument(m_documents[1]);
    referEmployee->addDocument(m_documents[4]);
    referEmployee->addPayment(m_payments[3]);

    m_employeers.push_back(referEmployee);

    Vacation* referVac = new Vacation();
    referVac->setId(vacationsAmount());
    referVac->setBeginDate(QDate(2021,12,22));
    referVac->setEndDate(QDate(2022,1,22));
    referVac->setEmployee(m_employeers[1]);

    m_vacations.push_back(referVac);

    referVac = new Vacation();
    referVac->setId(vacationsAmount());
    referVac->setBeginDate(QDate(2023,5,12));
    referVac->setEndDate(QDate(2023,5,30));
    referVac->setEmployee(m_employeers[2]);

    m_vacations.push_back(referVac);

}

////////////////////////////
/// DataBase::vacation
///
///

int DataBase::vacationsAmount()
{
    return m_vacations.size();
}

Vacation *DataBase::vacation(int number)
{
    return m_vacations[number];
}

void DataBase::addVacation(Vacation *vacation)
{
    m_vacations.push_back(vacation);
}

void DataBase::removeVacation(int number)
{
    delete m_vacations[number];
    m_vacations.erase(m_vacations.begin()+number);
}

void DataBase::changeVacation(Vacation *vacation, int number)
{
    delete m_vacations[number];
    m_vacations[number] = vacation;
}

////////////////////////////
/// DataBase::employee
///
///


int DataBase::employeesAmount()
{
    return m_employeers.size();
}

Employee *DataBase::employee(int number)
{
    return m_employeers[number];
}

Employee *DataBase::employee(QString name)
{
    for(int c=0;c<m_employeers.size();c++)
    {
        if(m_employeers[c]->name() == name)
        {
            return m_employeers[c];
        }
    }
    return nullptr;
}

void DataBase::addEmployee(Employee *employee)
{
    m_employeers.push_back(employee);
}

void DataBase::removeEmployee(int number)
{
    delete m_employeers[number];
    m_employeers.erase(m_employeers.begin()+number);
}

void DataBase::changeEmployee(Employee *employee, int number)
{
    delete m_employeers[number];
    m_employeers[number] = employee;
}

////////////////////////////
/// DataBase::task
///
///

int DataBase::tasksAmount()
{
    return m_tasks.size();
}

Task *DataBase::task(int number)
{
    return m_tasks[number];
}

Task *DataBase::task(QString name)
{
    for(int c=0;c<m_tasks.size();c++)
    {
        if(m_tasks[c]->name() == name)
        {
            return m_tasks[c];
        }
    }
    return nullptr;
}

void DataBase::addTask(Task *task)
{
    m_tasks.push_back(task);
}

void DataBase::removeTask(int number)
{
    delete m_tasks[number];
    m_tasks.erase(m_tasks.begin()+number);
}

void DataBase::changeTask(Task *task, int number)
{
    delete m_tasks[number];
    m_tasks[number] = task;
}

////////////////////////////
/// DataBase::rank
///
///

int DataBase::ranksAmount()
{
    return m_ranks.size();
}

Rank *DataBase::rank(int number)
{
    return m_ranks[number];
}

Rank *DataBase::rank(QString name)
{
    for(int c=0;c<m_ranks.size();c++)
    {
        if(m_ranks[c]->name() == name)
        {
            return m_ranks[c];
        }
    }
    return nullptr;
}

void DataBase::addRank(Rank *rank)
{
    m_ranks.push_back(rank);
}

void DataBase::removeRank(int number)
{

    m_ranks.erase(m_ranks.begin()+number);
}

void DataBase::changeRank(Rank *rank, int number)
{
    delete m_ranks[number];
    m_ranks[number] = rank;
}

////////////////////////////
/// DataBase::department
///
///

int DataBase::departmentsAmount()
{
    return m_departments.size();
}

Department *DataBase::department(int number)
{
    return m_departments[number];
}

Department *DataBase::department(QString name)
{
    for(int c=0;c<m_departments.size();c++)
    {
        if(m_departments[c]->name() == name)
        {
            return m_departments[c];
        }
    }
    return nullptr;
}

void DataBase::addDepartment(Department *department)
{
    m_departments.push_back(department);
}

void DataBase::removeDepartment(int number)
{
    delete m_departments[number];
    m_departments.erase(m_departments.begin()+number);
}

void DataBase::changeDepartment(Department *department, int number)
{
    delete m_departments[number];
    m_departments[number] = department;
}

////////////////////////////
/// DataBase::document
///
///

int DataBase::documentsAmount()
{
    return m_documents.size();
}

Document *DataBase::document(int number)
{
    return m_documents[number];
}

Document *DataBase::document(QString name)
{
    for(int c=0;c<m_documents.size();c++)
    {
        if(m_documents[c]->name() == name)
        {
            return m_documents[c];
        }
    }
    return nullptr;
}

void DataBase::addDocument(Document *document)
{
    m_documents.push_back(document);
}

void DataBase::removeDocument(int number)
{
    delete m_documents[number];
    m_documents.erase(m_documents.begin()+number);
}

void DataBase::changeDocument(Document *document, int number)
{
    delete m_documents[number];
    m_documents[number] = document;
}

////////////////////////////
/// DataBase::payment
///
///

int DataBase::paymentsAmount()
{
    return m_payments.size();
}

Payment *DataBase::payment(int number)
{
    return m_payments[number];
}

Payment *DataBase::payment(QString name)
{
    for(int c=0;c<m_payments.size();c++)
    {
        if(m_payments[c]->name() == name)
        {
            return m_payments[c];
        }
    }
    return nullptr;
}

void DataBase::addPayment(Payment *payment)
{
    m_payments.push_back(payment);
}

void DataBase::removePayment(int number)
{
    delete m_payments[number];
    m_payments.erase(m_payments.begin()+number);
}

void DataBase::changePayment(Payment *payment, int number)
{
    delete m_payments[number];
    m_payments[number] = payment;
}

////////////////////////////
/// DataBase::event
///
///

int DataBase::eventsAmount()
{
    return m_events.size();
}

Event *DataBase::event(int number)
{
    return m_events[number];
}

Event *DataBase::event(QString name)
{
    for(int c=0;c<m_events.size();c++)
    {
        if(m_events[c]->name() == name)
        {
            return m_events[c];
        }
    }
    return nullptr;
}

void DataBase::addEvent(Event *event)
{
    m_events.push_back(event);
}

void DataBase::removeEvent(int number)
{
    delete m_events[number];
    m_events.erase(m_events.begin()+number);
}

void DataBase::changeEvent(Event *event, int number)
{
    delete m_events[number];
    m_events[number] = event;
}

////////////////////////////
/// DataBase::employeeRole
///
///

int DataBase::employeeRoleAmount()
{
    return m_employee_role.size();
}

EmployeeRole *DataBase::employeeRole(int number)
{
    return m_employee_role[number];
}


void DataBase::addEmployeeRole(EmployeeRole *employeeRole)
{
    m_employee_role.push_back(employeeRole);
}

void DataBase::removeEmployeeRole(int number)
{
    delete m_employee_role[number];
    m_employee_role.erase(m_employee_role.begin()+number);
}

void DataBase::changeEmployeeRole(EmployeeRole *employeeRole, int number)
{
    delete m_employee_role[number];
    m_employee_role[number] = employeeRole;
}

////////////////////////////
/// DataBase::role
///
///

int DataBase::rolesAmount()
{
    return m_roles.size();
}

Role *DataBase::role(int number)
{
    return m_roles[number];
}

Role *DataBase::role(QString name)
{
    for(int c=0;c<m_roles.size();c++)
    {
        if(m_roles[c]->name() == name)
        {
            return m_roles[c];
        }
    }
    return nullptr;
}

void DataBase::addRole(Role *role)
{
    m_roles.push_back(role);
}

void DataBase::removeRole(int number)
{
    delete m_roles[number];
    m_roles.erase(m_roles.begin()+number);
}

void DataBase::changeRole(Role *role, int number)
{
    delete m_roles[number];
    m_roles[number] = role;
}

////////////////////////////
/// DataBase::roleAuthority
///
///

int DataBase::roleAuthorityAmount()
{
    return m_role_authority.size();
}

RoleAuthority *DataBase::roleAuthority(int number)
{
    return m_role_authority[number];
}

void DataBase::addRoleAuthority(RoleAuthority *roleAuthority)
{
    m_role_authority.push_back(roleAuthority);
}

void DataBase::removeRoleAuthority(int number)
{
    delete m_role_authority[number];
    m_role_authority.erase(m_role_authority.begin()+number);
}

void DataBase::changeRoleAuthority(RoleAuthority *roleAuthority, int number)
{
    delete m_role_authority[number];
    m_role_authority[number] = roleAuthority;
}

////////////////////////////
/// DataBase::authoritie
///
///

int DataBase::authoritiesAmount()
{
    return m_authorities.size();
}

Authority *DataBase::authority(int number)
{
    return m_authorities[number];
}

Authority *DataBase::authority(QString name)
{
    for(int c=0;c<m_authorities.size();c++)
    {
        if(m_authorities[c]->name() == name)
        {
            return m_authorities[c];
        }
    }
    return nullptr;
}

void DataBase::addAuthority(Authority *authority)
{
    m_authorities.push_back(authority);
}

void DataBase::removeAuthority(int number)
{
    delete m_authorities[number];
    m_authorities.erase(m_authorities.begin()+number);
}

void DataBase::changeAuthority(Authority *authority, int number)
{
    delete m_authorities[number];
    m_authorities[number] = authority;
}


