#include <iostream>
#include <memory>
#include "src/StateMachine/StateChain.h"
#include "src/StateMachine/BaseState.h"

int main() {

    ProcessDatabase database;

    LoadAssembly loadAssembly{ database };
    SplitAssembly splitAssembly{ database };
    CleanupAssembly cleanupAssembly{ database };
    ParseAssembly parseAssembly{ database };
    TimingCalculation timingCalculation{ database };
    TimingInsertion timingInsertion{ database };

    StateChain<BaseState> stateChain{ loadAssembly };
    stateChain.addChain(loadAssembly, splitAssembly);
    stateChain.addChain(splitAssembly, cleanupAssembly);
    stateChain.addChain(cleanupAssembly, parseAssembly);
    stateChain.addChain(parseAssembly, timingCalculation);
    stateChain.addChain(timingCalculation, timingInsertion);
    stateChain.addChain(timingInsertion, cleanupAssembly, [&] { return dynamic_cast<LoadAssembly>(splitAssembly).remainingSplits() > 0; });
    stateChain.addChain(timingInsertion, [&] { return dynamic_cast<LoadAssembly>(splitAssembly).remainingSplits() <= 0; );

    /*const auto& d1 = std::shared_ptr<Demo>();
    const auto& d2 = std::shared_ptr<Demo2>();

    FiniteStateMachine<BaseState*> machine{d1};
    machine.add(d1, d2);
    machine.add(d2, d1);*/

    for(;;) {
        stateChain.current()->execute();
        stateChain.next();
    }
}