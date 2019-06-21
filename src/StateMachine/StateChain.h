#pragma once
#include <memory>

template<typename T>
class StateChain {
public:
    StateChain(T startState) : mCurrent{std::move(startState)}  {

    }

    void addChain(T startState, T endState) {

    }

    template<typename F>
    void addChain(T startState, T endState, F condition) {

    }
private:
    std::shared_ptr<T> mCurrent = nullptr;
};