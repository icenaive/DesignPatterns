#include "Interpreter.h"

int main() {
    ExpressionFactory *expression_factory_ = new ExpressionFactory();
    Context *context_ = new Context();
    context_->SetText("O 2 E 0.5 G 0.5 A 3");
    while(context_->GetText().length()) {
      Expression  *expression_ = expression_factory_->CreateExpression(context_);
      expression_->Interprete(context_);
      delete expression_;
    }
    return 0;
}