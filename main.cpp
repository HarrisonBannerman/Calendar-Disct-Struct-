//Roosevelt Bannerman#include <iostream>

using namespace std;


string
   months [] = {"January","February","March","April","May","June","July","August","September","October","November","December"},
   weekdays [] = {"Su","Mo","Tu","We","Th","Fr","Sa"},
               //   0    1    2    3    4    5    6
   nullString (28,'\0'),
   dashString (28,'-');

int days [] = {31,28,31,30,31,30,31,31,30,31,30,31};

void displayResults(int,int);

int
   calculateLeaps(int),
   calculateDayOne(int,int),
   obtainYear(),
   yearValidation(int);

bool calculateLeap(int);

const int AMOUNTWEEKDAYS = 7;
const int AMOUNTMONTHS = 12;



int main(){   int chosenYear = obtainYear();
   bool isLeap = calculateLeap(chosenYear);
   if(isLeap){
      days[1] = 29;
   }
   int totalLeaps = calculateLeaps(chosenYear);
   int JanOne =  calculateDayOne(chosenYear,totalLeaps);
   displayResults(chosenYear,JanOne);
}

int obtainYear(){
   int year;

   cout << "\n\nPlease enter a year to display: ";
   cin >> year;

   year = yearValidation(year);

     return year;
}

int yearValidation(int validateThis){

   if( validateThis < 1900){
      cout << "Error: Please enter a valid year.";
      obtainYear();
   }

   return validateThis;
}

bool calculateLeap(int year){
  if(year % 4 == 0){
      if(year % 100 == 0){
         if(year % 400 == 0){
            return true;
         }
         return false;
      }
      return true;
   }
   return false;
}

int calculateLeaps(int year){

   int totalLeaps = 0;

   for(int i=1900; i<year; i++){
      if(i % 4 == 0){
         if(i % 100 == 0){
            if(i % 400 == 0){
               totalLeaps += 1;
            }
            continue;
         }
         totalLeaps += 1;
      }
      continue;
   }

   return totalLeaps;

}

int calculateDayOne(int year, int leaps){

   int difference = year - 1900;
   int days = (difference * 365) + leaps;

   return (days % AMOUNTWEEKDAYS);
}

void displayResults(int year, int start){

   int counter = start + 1;
   if(counter == AMOUNTWEEKDAYS) counter = 0;

   for (int i=0;i<AMOUNTMONTHS;i++){

      string nullspaces((23 - months[i].length())/2,'\0');

      cout << endl << nullspaces << months[i] << " " << year << endl;

      for(int i=0;i<AMOUNTWEEKDAYS;i++){
         cout << "  " << weekdays[i];
      }
      cout << endl << dashString << endl;

      string startPosition(0+(counter*4),' ');
      cout << startPosition;

      for(int ii=1;ii<=days[i];ii++){
         if(ii>9){
            cout << "  " << ii;
            counter++;
            if(counter == AMOUNTWEEKDAYS){
               if(ii!=days[i]) cout << endl;
               counter = 0;
            }
         }
      else{
            cout << "   " << ii;
            counter++;
            if(counter == AMOUNTWEEKDAYS){
               if(ii!=days[i]) cout << endl;
               counter = 0;
            }
         }
      }
      cout << endl;

   }
   cout << endl;
}



/*
January 1, 1920 was a Thursday
December 31, 1920 was a Friday

January 1, 1965 was a Friday
December 31, 1965 was a Friday

January 1, 1988 was a Friday
December 31, 1988 was a Saturday
*/
