#include "Interpreter.h"

string Context::GetText() {
    return text_;
}

void Context::SetText(string text) {
  text_ = text;
}

void Expression::Interprete(Context *context) {
    stringstream ss;
    string key;
    double value;
    string remain_text = context->GetText();
    ss << remain_text;
    ss >> key >> value;
    remain_text = remain_text.substr(remain_text.find(" ")+1);
    remain_text = remain_text.substr(remain_text.find(" ")+1);
    if(remain_text.length() < 3){
        remain_text = "";
    }
    context->SetText(remain_text);
    Excute(key, value);
}
void Scale::Excute(string key, double value) {
    switch ((int)value)
    {
    case 1:
        cout << "boss\n";
        break;
    case 2:
        cout << "alto\n";
        break;
    case 3:
        cout << "treble\n";
        break;
    default:
        break;
    }
}

void Note::Excute(string key, double value) {
    cout << key[0] << endl;
}

Expression* ExpressionFactory::CreateExpression(Context *context) {
    char key = context->GetText()[0];
    if(key == 'O') return new Scale();
    else return new Note();
}