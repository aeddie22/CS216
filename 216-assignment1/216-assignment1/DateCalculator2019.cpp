// อาดีนัน อับดุลลี
// 6209650719
#include "DateCalculator2019.h"
#include <iostream>
#include <string>
using namespace std;

int sum = 0;
int months;
int dof = 0;
int month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
//string nday[7] = {"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
//string nmonth[12] = { "January","February","March","April","May","June","July","August","September","October","November","December" };


DateCalculator2019 ::  DateCalculator2019 ()
{
    d = 1;
    m = 1;
}

DateCalculator2019 :: DateCalculator2019 (int doy)
{
    if(doy > 1 && doy < 365){
        if (doy >= 1 && doy <= 31) {
            m = 1;
            d = doy;
        }else if(doy >= 32 && doy <= 59) {
            m = 2;
            d = doy-31;
        }else if(doy >= 60 && doy <= 90) {
            m = 3;
            d = doy-59;
        }else if(doy >= 91 && doy <= 120) {
            m = 4;
            d = doy-90;
        }else if(doy >= 121 && doy <= 151) {
            m = 5;
            d = doy-120;
        }else if(doy >= 152 && doy <= 181) {
            m = 6;
            d = doy-151;
        }else if(doy >= 181 && doy <= 212) {
            m = 7;
            d = doy-181;
        }else if(doy >= 213 && doy <= 243) {
            m = 8;
            d = doy-212;
        }else if(doy >= 244 && doy <= 273) {
            m = 9;
            d = doy-243;
        }else if(doy >= 274 && doy <= 304) {
            m = 10;
            d = doy-273;
        }else if(doy >= 305 && doy <= 334) {
            m = 11;
            d = doy-304;
        }else if(doy >= 335 && doy <= 365) {
            m = 12;
            d = doy-334;
        }
    }else{
        cout << "Error!" << endl;
        exit(0);
    }
}

DateCalculator2019 :: DateCalculator2019 (int dd , int mm)
{
    if(mm >= 1 && mm <= 12){
        if(mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12){
            if (dd >= 1 && dd <= 31) {
                m = mm;
                d = dd;
            }else{
                cout << "Error!";
            }
        }else if (mm == 4 || mm == 6 || mm == 9 || mm == 11) {
            if(dd >= 1 && dd <= 30){
                m = mm;
                d = dd;
            }else{
                cout << "Error!";
            }
        }else if(mm == 2){
            if(dd >= 1 && dd <= 28){
                m = mm;
                d = dd;
            }else{
                cout << "Error!";
            }
        }
    }else{
        cout << "Error!" << endl;
        exit(0);
    }if (mm == 1) {
        sum += dd;
    }else if(mm == 2){
        sum += 31+dd;
    }else if(mm == 3){
        sum += 59+dd;
    }else if(mm == 4){
        sum += 90+dd;
    }else if(mm == 5){
        sum += 120+dd;
    }else if(mm == 6){
        sum += 151+dd;
    }else if(mm == 7){
        sum += 181+dd;
    }else if(mm == 8){
        sum += 212+dd;
    }else if(mm == 9){
        sum += 243+dd;
    }else if(mm == 10){
        sum += 273+dd;
    }else if(mm == 11){
        sum += 304+dd;
    }else if(mm == 12){
        sum += 334+dd;
    }
}

void DateCalculator2019 :: setdate (int dd, int mm)
{
    if(mm >= 1 && mm <= 12){
        if(mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12){
            if (dd >= 1 && dd <= 31) {
                m = mm;
                d = dd;
            }else{
                cout << "Error!";
            }
        }else if (mm == 4 || mm == 6 || mm == 9 || mm == 11) {
            if(dd >= 1 && dd <= 30){
                m = mm;
                d = dd;
            }else{
                cout << "Error!";
            }
        }else if(mm == 2){
            if(dd >= 1 && dd <= 28){
                m = mm;
                d = dd;
            }else{
                cout << "Error!";
            }
        }
    }else{
        cout << "Error!" << endl;
        exit(0);
    }
}

void DateCalculator2019 :: plusday(int days)
{
    sum += days;
    if (sum >= 1 && sum <= 31) {
        m = 1;
        d = sum;
    }else if(sum >= 32 && sum <= 59) {
        m = 2;
        d = sum-31;
    }else if(sum >= 60 && sum <= 90) {
        m = 3;
        d = sum-59;
    }else if(sum >= 91 && sum <= 120) {
        m = 4;
        d = sum-90;
    }else if(sum >= 121 && sum <= 151) {
        m = 5;
        d = sum-120;
    }else if(sum >= 152 && sum <= 181) {
        m = 6;
        d = sum-151;
    }else if(sum >= 181 && sum <= 212) {
        m = 7;
        d = sum-181;
    }else if(sum >= 213 && sum <= 243) {
        m = 8;
        d = sum-212;
    }else if(sum >= 244 && sum <= 273) {
        m = 9;
        d = sum-243;
    }else if(sum >= 274 && sum <= 304) {
        m = 10;
        d = sum-273;
    }else if(sum >= 305 && sum <= 334) {
        m = 11;
        d = sum-304;
    }else if(sum >= 335 && sum <= 365) {
        m = 12;
        d = sum-334;
    }
    if(sum>=1 && sum<=31){
        m =1;
        months =1;
    }
}

void DateCalculator2019 :: print()
{
    string x,y;
    if(sum % 7 == 0){
        y = "Monday";
    }else if(sum % 7 == 1){
        y = "Tuesday";
    }else if(sum % 7 == 2){
        y = "Wednesday";
    }else if(sum % 7 == 3) {
        y = "Thursday";
    }else if(sum % 7 == 4) {
        y = "Friday";
    }else if(sum % 7 == 5) {
        y = "Saturday";
    }else if(sum % 7 == 6) {
        y = "Sunday";
    }
    
    if(months == 1){
        x = "January";
    }else if(months == 2){
        x = "Fabuary";
    }else if(months == 3){
        x = "March";
    }else if(months == 4){
        x = "April";
    }else if(months == 5){
        x = "May";
    }else if(months == 6){
        x = "June";
    }else if(months == 7){
        x = "July";
    }else if(months == 8){
        x = "August";
    }else if(months == 9){
        x = "September";
    }else if(months == 10){
        x = "October";
    }else if(months == 11){
        x = "November";
    }else if(months == 12){
        x = "December";
    }
    
    if(sum<=365){
        cout << d <<" days after "<< y <<", " << x <<" "<< d << " , 2019 is "<< y <<" , September "<< d <<", 2019."<<endl;
    }else {
        cout << d <<"days after "<< y << ", "<< x << sum <<" , 2019 is a date not in 2019."<<endl;
    }
}


