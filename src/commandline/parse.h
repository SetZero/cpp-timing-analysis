//
// Created by sebastian on 30.05.19.
//

#pragma once
#include <clara.hpp>
#include <optional>
#include <iostream>

class Parse {
private:
    std::string assemblyLocation;
    std::string mArch;
    bool showHelp = false;
    clara::Parser cli;
public:
    Parse(int argc, const char* argv[]) noexcept {
        cli = clara::Help( showHelp )
                  | clara::Opt(assemblyLocation, "config" )
                  ["-a"]["--asm"]
                          ("Assembly Location")
                  | clara::Opt(mArch, "config" )
                  ["-i"]["--arch"]
                          ("CPU Architecture / Instruction Set");

        auto result = cli.parse( clara::Args( argc, argv ) );
        if(!result) {
            std::cout << result.errorMessage();
            showHelp = true;
        } else {
            if(assemblyLocation.empty()) {
                showHelp = true;
            }
        }
    }

    [[nodiscard]] std::string asmLocation() const noexcept {
        return assemblyLocation;
    }

    [[nodiscard]] std::string arch() const noexcept {
        return mArch;
    }

    explicit operator bool() const {
        return !showHelp;
    }

    friend auto operator<<( std::ostream &os, Parse const &parse ) -> std::ostream& {
        if(parse.showHelp) {
            os << parse.cli;
        }
        return os;
    }
};



