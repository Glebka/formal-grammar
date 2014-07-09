#ifndef COMMON_H
#define COMMON_H

#include <QString>

#define MSG_INVALID_NAME "������������ ��� �����������."
#define MSG_REDEFINITION "���������� '%1' ��� ��������� �����."
#define MSG_NOT_RULE "������ �� �������� �������� ����������."
#define MSG_UNCLOSED_TERM "����������� ����������� ������� ������� � ����� ���������."
#define MSG_WRONG_SYMBOL "������������ ������ � ������� ����������."
#define MSG_UNUSED_SYMBOL "������������ ������ '%1'."
#define MSG_UNDEFINED_SYMBOL "�������������� ������ '%1'."
#define MSG_INFINITE_RECURSION "�������� ����������� �������� ��� ������ ������� �� ������� '%1'"

namespace MessageType
{
    enum mType{Error,Warning};
}
namespace ErrorClass
{
    enum errcls{None,Syntax,Grammar};
}
namespace SyntaxError
{
    enum synErr{None,NotRule,WrongSymbol,Redefinition,UnclosedTerminal,InvalidName};
}

namespace GrammarError
{
    enum grmErr{None,UnusedNonTerm,UndefinedNonTerm,InfiniteRecursion};
}
namespace SimpleRelationType
{
    enum rltType{None,Last,First,Equal};
}
namespace RelationType
{
    enum resRltType{None=0,LT=1,GT=2,EQ=4,LTEQ=5,GTEQ=6,LTGTEQ=7,LTGT=3};
}

struct NonTerminal
{
    bool noLoop;
    bool defined;
    bool used;
};

struct Position
{
    unsigned int line;
    unsigned int col;
    unsigned int length;
    bool definedHere;
};

struct Message
{
    QString text;
    Position pos;
    unsigned int cls;
    unsigned int id;
    unsigned int type;
};

struct SimpleRelationPair
{
    int element1;
    int relation;
    int element2;
};

struct Conflict{
    int row;
    int col;
    int relation;
    Conflict(int row,int col,int relation)
    {
        this->row=row;
        this->col=col;
        this->relation=relation;
    }
};

#endif // COMMON_H
