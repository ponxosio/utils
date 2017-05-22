#ifndef MEMENTO_H
#define MEMENTO_H

template <class T> class Memento {
public:
    Memento(const T & state) : state(state){}
    virtual ~Memento(){}

    inline const T & getState() const {
        return state;
    }
protected:
    T state;
};

#endif // MEMENTO_H
