//
// Created by sebastian on 21.06.19.
//

#pragma once


class BaseState {
public:
    virtual void execute() = 0;

    virtual ~BaseState() = default;
};



