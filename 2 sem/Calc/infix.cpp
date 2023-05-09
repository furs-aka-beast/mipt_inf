#include <iostream>
#include <vector>
#include <string>
#include "infix.h"
#include <stack>

enum struct TokenType {
  TT_NUMBER,
  TT_OPERATION,
  TT_END
};

enum struct Operation {
  OP_ADD,
  OP_SUB,
  OP_MUL,
  OP_DIV
};

struct Token {
  TokenType type;
  union {
    Int number;
    Operation operation;
  } value;
};

void SkipWhitespace(std::istream& istrm) {
  while (isspace(istrm.peek())) {
    istrm.get();
  }
}

TokenType GetNextTokenType(std::istream& istrm) {
  SkipWhitespace(istrm);

  if (istrm.eof()){
    return TokenType::TT_END;
  }

  switch(istrm.peek()) {
  case '+':
  case '-':
  case '*':
  case '/':
    return TokenType::TT_OPERATION;

  case '0': case '1': case '2': case '3':
  case '4': case '5': case '6': case '7':
  case '8': case '9':
    return TokenType::TT_NUMBER;

  default:
    throw std::logic_error("Bad token in stream, failed to detect type");
  }
}

Operation GetOperation(std::istream& istrm) {
  switch(istrm.get()) {
  case '+': return Operation::OP_ADD;
  case '-': return Operation::OP_SUB;
  case '*': return Operation::OP_MUL;
  case '/': return Operation::OP_DIV;
  default: throw std::logic_error("Bad operation in stream");
  }
}

Int GetNumber(std::istream& istrm) {
  Int value = 0;
  char c = istrm.peek();
  while(isdigit(c)) {               
    c = istrm.get();
    value = value * 10 + (c - '0');
    c = istrm.peek();
  }

  return value;
}
Int EvalOperation(Operation op, Int l, Int r) {
  switch(op) {
  case Operation::OP_ADD: return l + r;
  case Operation::OP_SUB: return l - r;
  case Operation::OP_MUL: return l * r;
  case Operation::OP_DIV: return l / r;
  default: throw std::logic_error("Enum switch reached default, how come?");
  }
}
bool GetPriority(Operation op){
    switch (op){
    case Operation::OP_ADD:
    case Operation::OP_SUB:
    return 0;
    case Operation::OP_MUL:
    case Operation::OP_DIV:
    return 1;
    
    default:
        throw std::logic_error("GetPriority err");
    }
}
void Reduce(std::stack<Operation>& oper,
    Operation op, std::stack<Int>& value){
    while(!oper.empty() && (GetPriority(oper.top()) >= GetPriority(op))){
        if(value.size()<2)   throw std::logic_error("Reduce err");
        Int r=value.top();
        value.pop();
        Int l=value.top();
        value.pop();
        value.push(EvalOperation(oper.top(),l,r));
        oper.pop();
    }   
    oper.push(op); 
}
Int InfixNotation(std::istream& istrm) {
    std::stack<Operation> oper;
    std::stack<Int> value;
    while (true){
        TokenType next;
        next = GetNextTokenType(istrm);

        if(next == TokenType::TT_OPERATION){
            if(oper.size() == value.size())
                throw std::logic_error("Two operators in a row");
            auto op=GetOperation(istrm);
            Reduce(oper,op,value);

        }
        else if(next == TokenType::TT_NUMBER){
            if(oper.size()<value.size())
                throw std::logic_error("Two numbers in a row");
            value.push(GetNumber(istrm));

        }
        else if(next == TokenType::TT_END){
            Reduce(oper, Operation::OP_ADD, value);
            return value.top();
        }
        else    throw std::logic_error("Default case triggered in enum switch");
    }
}
/*
int main(){
  std::string s = "10 / 5 - 2 * 2 * 2 - 1";
  std::istringstream iss(s);
  std::cout << InfixNotationExpr(iss) << std::endl;
}
*/