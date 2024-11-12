#ifndef JSONUTILS_H
#define JSONUTILS_H

#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>
#include <QDir>
#include <QTextStream>

class JsonUtils
{

public:
    JsonUtils();

    bool convertJsonFileToCSV(const QString& dbgFilePath, QFile& csvFile);
    bool convertJsonFileDirToCSV(const QString& dbgDirPath, QFile& csvFile);
    int maxTestDuration = 0;
    void addheaderlist(const QString &header, QStringList &values);
    void addRows(QJsonObject &jsonObject,const QString &test, QStringList &values);

private:
    void flattenJson(const QJsonObject& jsonObject, QStringList& values);

    bool convertJsonToCSV(QTextStream& in, QTextStream& out, QString fileName = "");
};

#endif // JSONUTILS_H
