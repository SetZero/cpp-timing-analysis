#pragma once
#include <memory>
#include <map>
#include <vector>
#include <functional>
#include <optional>
#include "BaseState.h"

namespace {
    template<typename T>
    struct StateInfo{
        std::optional<T> state;
        std::optional<std::function<bool()>> condition;
    };
}

template<typename T>
class StateChain {
public:
    StateChain(T startState) : mCurrent{std::move(startState)}  {
        
    }

    void addChain(T startState, T endState) {
        mStates[startState].emplace_back( endState, std::nullopt );
    }

    template<typename F>
    void addChain(T startState, T endState, F condition) {
        mStates[startState].emplace_back( endState, condition );
    }

    template<typename F>
    void addChain(T startState, F condition) {
        mStates[startState].emplace_back( std::nullopt, condition );
    }

    std::optional<T> next() noexcept {
        std::optional<T> nextState;
        const std::vector<StateInfo<T>>& nextOptions = mStates[mCurrent];
        for (const StateInfo<T>& nextOption : nextOptions) {
            if (nextOption.condition == std::nullopt) {
                nextState = nextOption.state;
                break;
            }

            if ((*(nextOption.condition))()) {
                nextState = nextOption.state;
                break;
            }
        }
        if (nextState) {
            mCurrent = *nextState;
        }
        return nextState;
    }

    [[nodiscard]] const T current() const noexcept {
        return mCurrent;
    }

    [[nodiscard]] T current() noexcept {
        return mCurrent;
    }

private:
    T mCurrent;
    std::map<T, std::vector<StateInfo<T>>> mStates;
};