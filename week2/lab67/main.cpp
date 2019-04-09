#include <iostream>
#include "queue.h"

using namespace std;

template <class T>
void swap(T* a, T* b){
    T t = *a;
    *a = *b;
    *b = t;
}

int main(){

    int a = 2;
    int g = 10;

    swap(&a, &g);

    cout << a << ", " << g << endl;

    queue<int, 3> q;

    try {
        q.offer(3);
        q.offer(5);
        q.offer(5);
        q.offer(2);
    } catch(queue_exception* e){
        cout << e->what() << endl;
    }

    try {
        for(int i = 0; i < 5; i++)
            q.poll();
    } catch(queue_is_empty* e){
        cout << e->what() << endl;
    }


    return 0;
}