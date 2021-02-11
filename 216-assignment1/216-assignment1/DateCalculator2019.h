// อาดีนัน อับดุลลี
// 6209650719

#ifndef DateCalculator2019_h
#define DateCalculator2019_h

class DateCalculator2019
{
public:
    DateCalculator2019();
    DateCalculator2019(int doy);
    DateCalculator2019(int dd , int mm);
    
    void setdate(int dd ,int mm);
    void print();
    void plusday(int days);
    
private:
    int d,m;
};
#endif
