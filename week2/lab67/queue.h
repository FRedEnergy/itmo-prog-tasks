#include <exception>

#ifndef ITMO_PROG_TASKS_QUEUE_H
#define ITMO_PROG_TASKS_QUEUE_H

class queue_exception: std::exception{};

class queue_limit_reached: queue_exception{
    virtual const char *what() const throw(){
        return "Queue limit reached";
    }
};

class queue_is_empty: queue_exception{
    virtual const char *what() const throw() {
        return "Queue is empty";
    }
};

template <class T, int N> class queue{

    T data[N];
    int head = 0;
    int tail = 0;
    int size = 0;

public:

    void offer(T a){
        if(size >= N)
            throw new queue_limit_reached();

        data[++head % N] = a;
        size++;
    }

    T poll(){
        if(size == 0)
            throw new queue_is_empty();

        T result = data[++tail % N];
        --size;
        return result;
    }
};



#endif //ITMO_PROG_TASKS_QUEUE_H
