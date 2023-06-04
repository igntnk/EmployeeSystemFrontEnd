#include "database.h"

DataBase::DataBase()
{
    SFProDisplay = QFont("SF Pro Display", 22);
    SFProDisplay.setStyleStrategy(QFont::PreferAntialias);
    SFProDisplay.setWeight(QFont::Bold);

    Task* referTask = new Task();
    referTask->setId(tasksAmount());
    referTask->setName("Create DataBase");
    referTask->setDescription("Create data base using PostgreSQL and Qt");
    referTask->setDeadline(QDate(2023,8,22));
    referTask->setStartline(QDate(2023,1,12));
    referTask->setResponceId(1);
    referTask->setCompleteStage(0);

    m_tasks.push_back(referTask);

    referTask = new Task();
    referTask->setId(tasksAmount());
    referTask->setName("Create OpenGl cube");
    referTask->setDescription("Create textured cube model using OpenGl 1998 year version");
    referTask->setDeadline(QDate(2023,12,12));
    referTask->setStartline(QDate(2021,5,12));
    referTask->setResponceId(2);
    referTask->setCompleteStage(1);

    m_tasks.push_back(referTask);

    referTask = new Task();
    referTask->setId(tasksAmount());
    referTask->setName("Create Refer DB Video");
    referTask->setDescription("Create simple video with data base programm using After Effects");
    referTask->setDeadline(QDate(2023,5,12));
    referTask->setStartline(QDate(2023,1,12));
    referTask->setResponceId(1);
    referTask->setCompleteStage(2);

    m_tasks.push_back(referTask);

    referTask = new Task();
    referTask->setId(tasksAmount());
    referTask->setName("Task to check the line");
    referTask->setDescription("Task to checke working of the date line");
    referTask->setDeadline(QDate(2024,2,12));
    referTask->setStartline(QDate(2023,1,12));
    referTask->setResponceId(3);
    referTask->setCompleteStage(0);

    m_tasks.push_back(referTask);

    referTask = new Task();
    referTask->setId(tasksAmount());
    referTask->setName("Trash");
    referTask->setDescription("trash task to make a size");
    referTask->setDeadline(QDate(2023,9,22));
    referTask->setStartline(QDate(2023,1,12));
    referTask->setResponceId(3);
    referTask->setCompleteStage(1);

    m_tasks.push_back(referTask);

    referTask = new Task();
    referTask->setId(tasksAmount());
    referTask->setName("Trash");
    referTask->setDescription("trash task to make a size");
    referTask->setDeadline(QDate(2024,2,22));
    referTask->setStartline(QDate(2023,1,12));
    referTask->setResponceId(0);
    referTask->setCompleteStage(3);

    m_tasks.push_back(referTask);

    referTask = new Task();
    referTask->setId(tasksAmount());
    referTask->setName("Trash");
    referTask->setDescription("trash task to make a size");
    referTask->setDeadline(QDate(2024,2,22));
    referTask->setStartline(QDate(2023,1,12));
    referTask->setResponceId(0);
    referTask->setCompleteStage(3);

    m_tasks.push_back(referTask);

    referTask = new Task();
    referTask->setId(tasksAmount());
    referTask->setName("Trash");
    referTask->setDescription("trash task to make a size");
    referTask->setDeadline(QDate(2032,2,22));
    referTask->setStartline(QDate(2000,1,12));
    referTask->setResponceId(3);
    referTask->setCompleteStage(1);

    m_tasks.push_back(referTask);

    referTask = new Task();
    referTask->setId(tasksAmount());
    referTask->setName("Trash");
    referTask->setDescription("trash task to make a size");
    referTask->setDeadline(QDate(2024,2,22));
    referTask->setStartline(QDate(2023,1,12));
    referTask->setResponceId(3);
    referTask->setCompleteStage(0);

    m_tasks.push_back(referTask);

    referTask = new Task();
    referTask->setId(tasksAmount());
    referTask->setName("Task to check lost task");
    referTask->setDescription("This task should be red colored");
    referTask->setDeadline(QDate(2023,4,22));
    referTask->setStartline(QDate(2023,1,12));
    referTask->setResponceId(2);
    referTask->setCompleteStage(1);

    m_tasks.push_back(referTask);

    referTask = new Task();
    referTask->setId(tasksAmount());
    referTask->setName("Trash");
    referTask->setDescription("trash task to make a size");
    referTask->setDeadline(QDate(2024,2,22));
    referTask->setStartline(QDate(2023,1,12));
    referTask->setResponceId(0);
    referTask->setCompleteStage(3);

    m_tasks.push_back(referTask);

    Rank* referRank = new Rank();
    referRank->setId(ranksAmount());
    referRank->setName("Admin");

    m_ranks.push_back(referRank);

    referRank = new Rank();
    referRank->setId(ranksAmount());
    referRank->setName("Director");

    m_ranks.push_back(referRank);

    referRank = new Rank();
    referRank->setId(ranksAmount());
    referRank->setName("Assistant");

    m_ranks.push_back(referRank);

    referRank = new Rank();
    referRank->setId(ranksAmount());
    referRank->setName("Manager");

    m_ranks.push_back(referRank);

    referRank = new Rank();
    referRank->setId(ranksAmount());
    referRank->setName("Instructor");

    m_ranks.push_back(referRank);

    referRank = new Rank();
    referRank->setId(ranksAmount());
    referRank->setName("Worker");

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

Employee *DataBase::employee(int id)
{
    for(int c=0;c<m_employeers.size();c++)
    {
        if(m_employeers[c]->id() == id)
        {
            return m_employeers[c];
        }
    }
    return nullptr;
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

Employee *DataBase::employeeByIndex(int index)
{
    return m_employeers[index];
}

std::vector<Employee *> DataBase::employees()
{
    return m_employeers;
}

void DataBase::addEmployee(Employee *employee)
{
    if(employee != nullptr)
        m_requester.createEmployee(*employee);

    m_employeers.push_back(employee);

    QObject::connect(&m_requester, &Requester::requestFailed, [](const QString& error) {
        std::cout << "Request failed:" << error.toStdString();
    });
}

void DataBase::removeEmployee(int number)
{
    int pos = -1;
    for(int c = 0;c<employeesAmount();c++)
    {
        if(m_employeers[c]->id() == number)
        {
            pos = c;
            for(int a =0;a<vacationsAmount();a++)
            {
                if(m_vacations[a]->employee()->id() == m_employeers[c]->id())
                {
                    delete m_vacations[a];
                    m_vacations.erase(m_vacations.begin()+a);
                }
            }
        }
    }
    m_requester.deleteEmployee(number);
    delete this->employee(number);
    m_employeers.erase(m_employeers.begin()+pos);
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
    for(int c=0;c<m_tasks.size();c++)
    {
        if(m_tasks[c]->id() == number)
        {
            return m_tasks[c];
        }
    }
    return nullptr;
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

std::vector<Task *> DataBase::tasks()
{
    return m_tasks;
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

void DataBase::setLoggindeId(int logginedId)
{
    m_logginedId = logginedId;
}

int DataBase::loggindeId()
{
    return m_logginedId;
}

QFont DataBase::font()
{
    return SFProDisplay;
}

void DataBase::setFontPixelSize(int size)
{
    SFProDisplay.setPixelSize(size);
}


