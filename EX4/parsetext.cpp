#include "parsetext.h"
ParseText::ParseText()
{
    symbolsNames = new QString[n]{"RUB","COPY","PROM","R", "EURO"};
    symbols = new QString[n]{"₽","©","‰","®","€"};
}

QString ParseText::getText(QString txt) {
    QString answer;
    for(int i = 0; i < n;i++)
    {
        if(symbolsNames[i] == txt)
        {
            answer = symbols[i];
            break;
        }
    }
    return answer;
}
