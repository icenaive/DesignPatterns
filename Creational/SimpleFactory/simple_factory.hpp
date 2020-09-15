#ifndef design_patterns_factory_method_operation_factory_h
#define design_patterns_factory_method_operation_factory_h

#include <string>
#include "operation_add.hpp"
#include "operation_div.hpp"
#include "operation_mul.hpp"
#include "operation_sub.hpp"

using std::string;

class OperationFactory {
public:
        Operation* CreateOperation(const string& operate) const
        {
                if (operate == "+")
                        return new OperationAdd;
                else if (operate == "-")
                        return new OperationSub;
                else if (operate == "*")
                        return new OperationMul;
                else if (operate == "/")
                        return new OperationDiv;
                else
                        throw std::logic_error("not find operate");
        }
};

#endif
