/*
 * Copyright 2016 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
 
#ifndef SKSL_IFSTATEMENT
#define SKSL_IFSTATEMENT

#include "SkSLExpression.h"
#include "SkSLStatement.h"

namespace SkSL {

/**
 * An 'if' statement.
 */
struct IfStatement : public Statement {
    IfStatement(Position position, std::unique_ptr<Expression> test, 
                std::unique_ptr<Statement> ifTrue, std::unique_ptr<Statement> ifFalse)
    : INHERITED(position, kIf_Kind)
    , fTest(std::move(test))
    , fIfTrue(std::move(ifTrue))
    , fIfFalse(std::move(ifFalse)) {}

    SkString description() const override {
        SkString result = "if (" + fTest->description() + ") " + fIfTrue->description();
        if (fIfFalse) {
            result += " else " + fIfFalse->description();
        }
        return result;
    }

    const std::unique_ptr<Expression> fTest;
    const std::unique_ptr<Statement> fIfTrue;
    const std::unique_ptr<Statement> fIfFalse;

    typedef Statement INHERITED;
};

} // namespace

#endif
