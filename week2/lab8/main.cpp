#include <vector>
#include <iostream>
#include <cmath>
#include <sstream>

using namespace std;

class Vector2D{

private:
    double x,y;

public:
    Vector2D(double _x, double _y): x(_x), y(_y){}

    double len(){
        return sqrt(x * x + y * y);
    }

    bool operator==(const Vector2D& b){
        return x == b.x && y == b.y;
    }

    string to_string(){
        ostringstream ss;
        ss << "Vector2d[" << x << ", " << y << "]";
        return ss.str();
    }

};

template<class C>
class Predicate {
public:
    bool operator()(C &collection, typename C::iterator it) = 0;
};

template<class C>
class Comparator{
public:
    int operator()(C &collection, typename C::iterator a, typename C::iteratorb) = 0;
};

template <class T, class Condition>
bool none_of(T &collection, Condition test){
    for(typename T::iterator it = collection.begin(); it != collection.end(); it++){
        if(test(*it))
            return false;
    }

    return true;
}

template <class T, class Comparator>
bool is_sorted(T &collection, Comparator comparator){
    for(typename T::iterator it = collection.begin(); it + 1 != collection.end(); it++){
        if(comparator(*it, *(it + 1)) > 0)
            return false;
    }

    return true;
}


template <class T>
typename T::iterator find_not(T &collection, typename T::value_type val){
    for(typename T::iterator it = collection.begin(); it != collection.end(); it++){
        if(!(*it == val))
            return it;
    }

    return collection.end();
}

int main(){
    vector<int> v;

    v.push_back(3);
    v.push_back(5);
    v.push_back(7);

    cout << "On primitive vector: " << endl;
    cout << none_of(v, [](int i){ return i % 2 == 0; }) << endl;
    cout << is_sorted(v, [](int a, int b){ return a - b; }) << endl;
    cout << *find_not(v, 5) << endl;

    vector<Vector2D> p;

    p.push_back(Vector2D(0, 0));
    p.push_back(Vector2D(100, 100));
    p.push_back(Vector2D(20, 20));

    cout << "On custom vector: " << endl;
    cout << none_of(p, [](Vector2D vec){ return vec.len() == 0.0; }) << endl;
    cout << is_sorted(p, [](Vector2D a, Vector2D b){ return a.len() - b.len(); }) << endl;
    cout << find_not(p, Vector2D(0, 0))->to_string() << endl;

    return 0;
}
