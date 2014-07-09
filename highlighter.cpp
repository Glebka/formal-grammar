#include <QtGui>

 #include "highlighter.h"

 Highlighter::Highlighter(QTextDocument *parent)
     : QSyntaxHighlighter(parent)
 {
     HighlightingRule rule;

     nonTermFormat.setFontWeight(QFont::Bold);
     nonTermFormat.setForeground(Qt::blue);
     //rule.pattern = QRegExp("\\bQ[A-Za-z]+\\b");
     rule.pattern = QRegExp("\\b[\\w][\\w\\d]*\\b");
     //[\\w][\\w\\d]*
     rule.format = nonTermFormat;
     highlightingRules.append(rule);

     definedNonTermFormat.setFontWeight(QFont::Bold);
     definedNonTermFormat.setForeground(Qt::darkMagenta);
     rule.pattern = QRegExp("^[\\w][\\w\\d]*\\b");
     //[\\w][\\w\\d]*
     rule.format = definedNonTermFormat;
     highlightingRules.append(rule);

     termFormat.setForeground(Qt::darkGreen);
     rule.pattern = QRegExp("\"[^\"]*\"");
     rule.format = termFormat;
     highlightingRules.append(rule);


     singleLineCommentFormat.setForeground(Qt::red);
     rule.pattern = QRegExp("^//[^\n]*");
     rule.format = singleLineCommentFormat;
     highlightingRules.append(rule);

 }

 void Highlighter::highlightBlock(const QString &text)
 {
     foreach (const HighlightingRule &rule, highlightingRules) {
         QRegExp expression(rule.pattern);
         int index = expression.indexIn(text);
         while (index >= 0) {
             int length = expression.matchedLength();
             setFormat(index, length, rule.format);
             index = expression.indexIn(text, index + length);
         }
     }
     setCurrentBlockState(0);
     /*int startIndex = 0;
     if (previousBlockState() != 1)
         startIndex = commentStartExpression.indexIn(text);

     while (startIndex >= 0) {
         int endIndex = commentEndExpression.indexIn(text, startIndex);
         int commentLength;
         if (endIndex == -1) {
             setCurrentBlockState(1);
             commentLength = text.length() - startIndex;
         } else {
             commentLength = endIndex - startIndex
                             + commentEndExpression.matchedLength();
         }
         setFormat(startIndex, commentLength, multiLineCommentFormat);
         startIndex = commentStartExpression.indexIn(text, startIndex + commentLength);
     }*/
 }
