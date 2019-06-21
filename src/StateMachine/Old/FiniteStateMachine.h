//
// Created by sebastian on 21.06.19.
// From: https://rosettacode.org/wiki/Finite_state_machine#C.2B.2B
//

#pragma once
#include <map>

template<typename State, typename Transition = State>
class FiniteStateMachine {
private:
    State mCurrent;
    std::map<State, std::map<Transition, State>> mDatabase;
public:
    FiniteStateMachine(const State& state) {
        set(state);
    }

    FiniteStateMachine() {
        set(State());
    }

    void set(const State& state) noexcept(std::is_nothrow_move_assignable_v<State>) {
        mCurrent = state;
    }

    [[nodiscard]] const State& get() const noexcept {
        return mCurrent;
    }

    void clear() noexcept(noexcept(mDatabase.clear())) {
        mDatabase.clear();
    }

    void add(const State& state, const Transition& transition, const State& next)
    noexcept(std::is_nothrow_move_assignable_v<State> && std::is_nothrow_move_assignable_v<Transition>) {
        mDatabase[state][transition] = next;
    }

    void add(const State& transitionAndState, const State& next) {
        add(transitionAndState, transitionAndState, next);
    }

    [[nodiscard]] bool process(Transition transition) {
        const auto& transitions = mDatabase[mCurrent];
        const auto& found = transitions.find(transition);
        if(found == transitions.end()) {
            return false;
        }
        set(found->second);
        return true;
    }

    [[nodiscard]] bool process() {
        return process(get());
    }

    template <typename Container>
    [[nodiscard]] bool get_valid_transitions(State const& state, Container& container)
    {
        container.clear();
        const auto& found = mDatabase.find(state);
        if(found == mDatabase.end())
            return false;
        const auto& transitions = found->second;
        if(transitions.size() == 0)
            return false;
        for(auto const& iterator : transitions)
        {
            const auto& transition = iterator.first;
            container.push_back(transition);
        }
        return true;
    }
    template <typename Container>
    bool get_valid_transitions(Container& container)
    {
        return get_valid_transitions(get(), container);
    }
};



