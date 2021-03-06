#ifndef HIGHLIGHTER_H
#define HIGHLIGHTER_H

 #include <QSyntaxHighlighter>

 #include <QHash>
 #include <QTextCharFormat>

 class QTextDocument;

 class Highlighter : public QSyntaxHighlighter
 {
     Q_OBJECT

 public:
     Highlighter(QTextDocument *parent = 0);

 protected:
     void highlightBlock(const QString &text);

 private:
     struct HighlightingRule
     {
         QRegExp pattern;
         QTextCharFormat format;
     };
     QVector<HighlightingRule> highlightingRules;

     QTextCharFormat nonTermFormat;
     QTextCharFormat singleLineCommentFormat;
     QTextCharFormat termFormat;
     QTextCharFormat definedNonTermFormat;
 };

#endif // HIGHLIGHTER_H
