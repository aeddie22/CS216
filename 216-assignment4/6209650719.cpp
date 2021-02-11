//6209650719   อาดีนัน อับดุลลี
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<math.h>

using namespace std;

int main()
{
   ifstream file("dict.txt");
   string myText;
   int hash_size = 127031;
   string hash[hash_size];
   while (getline(file,myText))
   {
      
      int index = 0;
       for(int i = 0 ; i < myText.length(); i++){
         
          index += pow(int(myText[i]),3);
          
       }

       index = index%hash_size;

      while(true){
         if(hash[index].empty()){
            hash[index] = myText;
         } 
         else
         {
            int h2 = 0;
            int hash2 = index + pow(h2,2);
            hash2 %= hash_size;
            if(hash[hash2].empty()) {
               hash[hash2] = myText;
            } else {
               h2++;
            }
         }
      }
   }

  while (true)
  {
      string find;
      cout << "Enter a word: ";
      getline(cin,find);
      if(find.empty()) {
         exit(0);
      }
         int index = 0;
         for(int i = 0 ; i < find.length(); i++){
             int x = (int)find.at(i);
            index += pow(x, 3);  
         }
            index = index%hash_size;

         while(true) 
         {

            if(hash[index].empty()){
               hash[index] = find;
               cout << "FOUND: " << find << endl;
               break;
            }else{
               int h2 = 0;
               int hash2 = index + pow(h2,2);
               hash2 %= hash_size;
               if(hash[hash2].empty()){
                  hash[hash2] = find; 
                  cout << "FOUND: " << find << endl;
                  break;
               }else{
               cout << "Collision: " << find << endl;
               h2++;
               }
               cout << "NOT FOUND." << endl;
            }
         }
   }
   file.close();
}
