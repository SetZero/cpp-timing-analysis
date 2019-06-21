#pragma once

#include "DataHolder/ProcessDatabase.h"

class BaseState {
public:
    explicit BaseState(ProcessDatabase& pd) : mProcessDatabase{pd} {};

    virtual ~BaseState() = default;

    virtual void execute() noexcept = 0;

protected:
    ProcessDatabase& mProcessDatabase;
};
