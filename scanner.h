#ifndef SCANNER_H
#define SCANNER_H

#include <QObject>
#include <QString>
#include <QStringList>
#include <QList>
#include <QMultiMap>
#include <QSet>
#include <QRegExp>

#include "common.h"
#include "dependencytree.h"

class GramScanner : public QObject
{
    Q_OBJECT
public:
    explicit GramScanner(QObject *parent = 0);

    void clear();
    void process(QString text, class DependencyTree * depTree);

    const QStringList * getTerms();
    const QStringList * getNonTerms();
    const QSet<QString> getInfRecNonTerms();
    const QSet<QString> getNonRecNonTerms();
    const QList<NonTerminal *> * getNonTermAttrs();
    const QMultiMap<QString,Position> * getLocations();
    const QList<SimpleRelationPair> getSimpleRelationPairs();
    const QList<SimpleRelationPair> * getSimpleRelationPairs2();
    const QStringList * getFullDictionary();


signals:
    void message(int type, QString text, Position pos, unsigned int cls, unsigned int id);
public slots:

    bool markNonTermAsNonRec(QVariant name);
    QString getInfRecNonTermsString();

protected:

    QStringList terminals; //������� ���������� � ��������� contains!
    QStringList nonTerminals; //������� ������������ � ��������� contains!
    QSet<QString> infRecNonTerm; //��������� ������������, ������� ����� ���� ���������� ������������
    QSet<QString> nonRecNonTerm; //��������� ������������, � ������� ����� ��� ����������� ��������, �������� � ������� ���� �� ���� �������, ��������� ������ �� ����������
    QList <NonTerminal *> nonTeriminalAttr; //������� ��������� ������������, ������� ������������� ������� ������������
    QMultiMap<QString,Position> locations; // ������� ������������
    QList<SimpleRelationPair> simpleRelations;

    QStringList fullDictionary;

    int registerNonTerm(unsigned int line,unsigned int col,QString name, bool define=true, bool use=false);
    int registerTerm(unsigned int line,unsigned int col,QString name);
    void clearNonTerms();
    void clearTerms();
    void registerFirstLastRelation(int &leftPartIndex,int &first, int &last);
    void registeEqualRelation(int &element1, int &element2);
};

#endif // SCANNER_H
