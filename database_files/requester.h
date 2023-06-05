//
// Created by nedonil on 04.06.23.
//

#ifndef TEST_REST_REQUESTER_H
#define TEST_REST_REQUESTER_H

#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QObject>
#include <QFile>
#include <QJsonArray>
#include <vector>
#include "employee.h"

class Requester : public QObject
{
Q_OBJECT

public:
    explicit Requester(QObject *parent = nullptr) : QObject(parent)
    {
        manager = new QNetworkAccessManager();
	    readSettingsFromFile(QString("settings.txt"));
    }

    void readSettingsFromFile(const QString &filename);

    void makePostRequest(const QString& path, const QByteArray& data);
    void makeDeleteRequest(const QString& path);

    void createEmployee(Employee& employee);
    void deleteEmployee(int employeeId);

private:
    QString protocol;
    QString host;
    int port;
    QNetworkAccessManager* manager;
public:
signals:
    void requestFailed(const QString& error);
};

#endif //TEST_REST_REQUESTER_H
