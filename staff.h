#ifndef STAFF_H
#define STAFF_H
#include <QString>


class Staff
{
private:
    QString name;
    QString job_title;


public:

     virtual QString get_name() = 0;
     virtual QString set_name(QString name) = 0;
     virtual QString set_job_title(QString job_title) = 0;

};

#endif // STAFF_H

