#ifndef ITMO_PROG_TASKS_IDIALOGINIT_H
#define ITMO_PROG_TASKS_IDIALOGINIT_H

class IDialogInitiable {

public:

    // Задать параметры объекта с помощью диалога с пользователем.
    virtual void initFromDialog() = 0;
};

#endif //ITMO_PROG_TASKS_IDIALOGINIT_H
