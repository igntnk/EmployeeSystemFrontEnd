#include "requester.h"
#include <iostream>

void Requester::readSettingsFromFile(const QString &filename)
{
    QFile file(filename);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            if (line.startsWith("Protocol:")) {
                protocol = line.mid(QString("Protocol:").length()).trimmed();
            } else if (line.startsWith("Host:")) {
                host = line.mid(QString("Host:").length()).trimmed();
            } else if (line.startsWith("PORT:")) {
                port = line.mid(QString("PORT:").length()).trimmed();
            }
        }
        file.close();
    }
}

void Requester::createEmployee(Employee& employee)
{
    QString path = "/api/v1/employees";
    QJsonObject jsonObject;
    
    jsonObject["username"] = employee.username();
    jsonObject["firstname"] = employee.name();
    jsonObject["lastname"] = employee.surname();
    jsonObject["password"] = employee.password();

    QJsonDocument jsonDocument(jsonObject);
    QByteArray requestData = jsonDocument.toJson();

    makePostRequest(path, requestData);
}

void Requester::deleteEmployee(int employeeId)
{
    QString path = "/api/v1/employees/" + QString::number(employeeId);
    makeDeleteRequest(path);
}

void Requester::makePostRequest(const QString& path, const QByteArray& data)
{
    QUrl url;
    url.setScheme(protocol);
    url.setHost(host);
    url.setPort(port);
    url.setPath(path);

    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QNetworkReply* reply = manager->post(request, data);

    connect(reply, &QNetworkReply::finished, this, [this, reply]() {
        if (reply->error() == QNetworkReply::NoError) {
            // Log success request
        } else {
            QString errorString = reply->errorString();
            emit requestFailed(errorString);
        }

        reply->deleteLater();
    });
}

void Requester::makeDeleteRequest(const QString& path)
{
    QUrl url;
    url.setScheme(protocol);
    url.setHost(host);
    url.setPort(port);
    url.setPath(path);

    QNetworkRequest request(url);
    QNetworkReply* reply = manager->deleteResource(request);

    connect(reply, &QNetworkReply::finished, this, [this, reply]() {
        if (reply->error() == QNetworkReply::NoError) {
            // Log success request
        } else {
            QString errorString = reply->errorString();
            emit requestFailed(errorString);
        }

        reply->deleteLater();
    });
}

