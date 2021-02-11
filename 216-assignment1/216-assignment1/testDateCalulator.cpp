// อาดีนัน อับดุลลี
// 6209650719

#include <iostream>
#include "DateCalculator2019.h"
using namespace std;

int main(){
    
    int d,m,doy;
    
    cin >>m >>d >>doy;
    
    DateCalculator2019 D(d, m);
    D.setdate(d, m);
    D.plusday(doy);
    D.print();
}
