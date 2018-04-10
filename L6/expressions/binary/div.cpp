//
// Created by Tooster on 10.04.2018.
//

#include "div.h"

Div::Div(const Expression *e1, const Expression *e2) : Binary(e1, e2) {}

double Div::eval() const {
    return e1->eval() / e2->eval();
}

std::string Div::toString() const {
    return std::string("(" + e1->toString() + ")/(" + e2->toString() + ")");

}
