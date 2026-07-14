#ifndef DB_H
#define DB_H

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>

class Db
{
public:
    Db();
    ~Db();
    QSqlDatabase& conDb();

private:
    QSqlDatabase db;
    static bool db_open;
    void initTables();
};

#endif
