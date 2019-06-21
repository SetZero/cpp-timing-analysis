#pragma once
#include <memory>
#include "BaseState.h"

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

    template<typename F>
    void addChain(T startState, F condition) {

    }

    BaseState& next() noexcept {

    }

    [[nodiscard]] const BaseState& current() const noexcept {

    }

    [[nodiscard]] BaseState& current() noexcept {

    }

private:
    T mCurrent = nullptr;
};