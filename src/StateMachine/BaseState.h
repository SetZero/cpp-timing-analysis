#pragma once

class BaseState {
    virtual ~BaseState() = default;

    virtual BaseState next() noexcept = 0;

    [[nodicard]] virtual const BaseState& current() const noexcept = 0;
};