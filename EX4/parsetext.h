#ifndef PARSETEXT_H
#define PARSETEXT_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>

class ParseText
{
public:
    ParseText();
    QString getText(QString);
private:
    int n = 5;
    QString *symbolsNames;
    QString *symbols;
};
#endif // PARSETEXT_H
