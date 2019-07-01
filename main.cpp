#include <iostream>
#include <memory>
#include <clara.hpp>
#include "src/StateMachine/DataHolder/ProcessDatabase.h"
#include "src/StateMachine/StateChain.h"
#include "src/StateMachine/BaseState.h"
#include "src/StateMachine/DataHolder/ProcessDatabase.h"
#include "src/StateMachine/States/includes/LoadAssembly.h"
#include "src/StateMachine/States/includes/SplitAssembly.h"
#include "src/StateMachine/States/includes/CleanupAssembly.h"
#include "src/StateMachine/States/includes/ParseAssembly.h"
#include "src/StateMachine/States/includes/TimingCalculation.h"
#include "src/StateMachine/States/includes/TimingInsertion.h"
#include "src/commandline/parse.h"

[[nodiscard]] int pgmEnd() {
#if defined(DEBUG_BUILD) && defined(_MSC_VER)
    std::this_thread::sleep_until(std::chrono::system_clock::now() + std::chrono::hours(std::numeric_limits<int>::max()));
#endif
    return 0;
}

int main(int argc, const char* argv[]) {

    Parse clParser{argc, argv};
    if(!clParser) {
        std::cout << clParser;
        return pgmEnd();
    }

    ProcessDatabase database;
    database.fileLocation(clParser.asmLocation());

    LoadAssembly loadAssembly{ database };
    SplitAssembly splitAssembly{ database };
    CleanupAssembly cleanupAssembly{ database };
    ParseAssembly parseAssembly{ database };
    TimingCalculation timingCalculation{ database };
    TimingInsertion timingInsertion{ database };

    StateChain<BaseState*> stateChain{ &loadAssembly };
    stateChain.addChain(&loadAssembly, &splitAssembly);
    stateChain.addChain(&splitAssembly, &cleanupAssembly);
    stateChain.addChain(&cleanupAssembly, &parseAssembly);
    stateChain.addChain(&parseAssembly, &timingCalculation);
    stateChain.addChain(&timingCalculation, &timingInsertion);
    stateChain.addChain(&timingInsertion, &cleanupAssembly, [&] { return (splitAssembly).remainingSplits() > 0; });
    stateChain.addChain(&timingInsertion, [&] { return splitAssembly.remainingSplits() <= 0;} );

    do {
        stateChain.current()->execute();
    } while (stateChain.next());

    //std::cout << database.fileContents() << std::endl;
}