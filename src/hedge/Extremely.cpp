/*
fuzzylite (R), a fuzzy logic control library in C++.

Copyright (C) 2010-2024 FuzzyLite Limited. All rights reserved.
Author: Juan Rada-Vilela, PhD <jcrada@fuzzylite.com>.

This file is part of fuzzylite.

fuzzylite is free software: you can redistribute it and/or modify it under
the terms of the FuzzyLite License included with the software.

You should have received a copy of the FuzzyLite License along with
fuzzylite. If not, see <https://github.com/fuzzylite/fuzzylite/>.

fuzzylite is a registered trademark of FuzzyLite Limited.
*/

#include "fuzzylite/hedge/Extremely.h"

#include "fuzzylite/Operation.h"

namespace fuzzylite {

    std::string Extremely::name() const {
        return "extremely";
    }

    Complexity Extremely::complexity() const {
        return Complexity().comparison(1).arithmetic(5);
    }

    scalar Extremely::hedge(scalar x) const {
        return Op::isLE(x, 0.5) ? 2.0 * x * x : (1.0 - 2.0 * (1.0 - x) * (1.0 - x));
    }

    Extremely* Extremely::clone() const {
        return new Extremely(*this);
    }

    Hedge* Extremely::constructor() {
        return new Extremely;
    }

}
