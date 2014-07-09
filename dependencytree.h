#ifndef DEPENDENCYTREE_H
#define DEPENDENCYTREE_H

#include <QObject>
#include <QFile>
#include <QString>
#include <QDebug>
#include <QtWebKit/QWebView>
#include <QtWebKit/QWebFrame>
#include <QFileInfo>
#include <QEventLoop>
#include "common.h"
#include "scanner.h"

class DependencyTree : public QObject
{
    Q_OBJECT
public:
    explicit DependencyTree(QObject *parent = 0);
    ~DependencyTree();
    void append(QString parent, QString child);
    void createRule(QString parent);
    void process(class GramScanner * );
    void clear();
signals:
    void message(int type, QString text, Position pos, unsigned int cls, unsigned int id);
    //void notify();
public slots:
    //void notifyMe(QString);
protected:
    //QDomDocument dependencyTree;
    QWebView * webview;
    QWebFrame * xmlprocessor;
};

class Stringer : public QObject
{
    Q_OBJECT
public:
    explicit Stringer(QString str,QObject *parent = 0);
public slots:
    QString getString();
private:
    QString str;
};

#endif // DEPENDENCYTREE_H
