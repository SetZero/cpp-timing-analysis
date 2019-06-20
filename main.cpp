#include <iostream>
#include <memory>
#include "src/StateMachine/FiniteStateMachine.h"
#include "src/StateMachine/BaseState.h"
#include "src/StateMachine/States/Demo.h"
#include "src/StateMachine/States/Demo2.h"

int main() {
    const auto& d1 = std::make_unique<Demo>();
    const auto& d2 = std::make_unique<Demo2>();

    FiniteStateMachine<BaseState*> machine{d1.get()};
    machine.add(d1.get(), d2.get());
    machine.add(d2.get(), d1.get());

    for(;;) {
        machine.process();
        machine.get()->execute();
    }
}