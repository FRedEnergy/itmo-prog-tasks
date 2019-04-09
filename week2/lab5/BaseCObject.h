#ifndef ITMO_PROG_TASKS_BASECOBJECT_H
#define ITMO_PROG_TASKS_BASECOBJECT_H

class BaseCObject {
public:
// Имя класса (типа данных).
    virtual const char* classname() = 0;
// Размер занимаемой памяти.
    virtual unsigned int size() = 0;
};

#endif //ITMO_PROG_TASKS_BASECOBJECT_H
