// #include <iostream>
// #include <fstream>
// using namespace std;
// int main()
// {
//     ofstream fout;
//     fout.open("input.txt");
//     fout << "welcome to c++ class" << endl;
//     fout << "hello" << endl;
//     fout.close();
//     ifstream fin("input.txt");
//     string str;
//     while(getline(fin,str)){

//     cout << str << endl;
//     }
//     fin.close();
//     return 0;
// }
// #include<iostream>
// #include<fstream>
// using namespace std;
// int main() {
// char line[100];
// fstream file; 
// file.open("file.txt", ios :: out | ios :: app);
// if (file.fail()) { 
// cout << "Error Opening file ... " << endl; 
// }
// else {
// cout << "Enter a line : "; 
// cin.getline(line, 100);
// file << line << endl; 
// cout << "Line written into the file" << endl;
// file.close(); 
// }
// return 0;
// }
// Q WAP a line of text into a file calculate how many characters
//  how many words, no of vowels no of consonents in the file reading in file from the file
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    int vowel = 0, cons = 0 ,ascii, i=0, words=0;
    char line[100];
    fstream file;
    file.open("file.txt", ios ::out | ios ::app);
    if (file.fail())
    {
        cout << "Error Opening file ... " << endl;
    }
    else
    {
        cout << "Enter a line : ";
        cin.getline(line, 100);
        file << line << endl;
        cout << "Line written into the file" << endl;
        file.close();
    }
while(line[i]!='\0')
   {
      if(line[i]=='a'||line[i]=='e'||line[i]=='i'||line[i]=='o'||line[i]=='u')
         vowel++;
      else if(line[i]=='A'||line[i]=='E'||line[i]=='I'||line[i]=='O'||line[i]=='U')
         vowel++;
      else
      {
         ascii = line[i];
         if(ascii>=65 && ascii<=90)
            cons++;
         else if(ascii>=97 && ascii<=122)
            cons++;
      }
      i++;
   }
       for (i = 0; line[i] != '\0';i++)
    {
        if (line[i] == ' ')
            words++;    
    }
   cout << "total words = " << words + 1;
   cout<<endl<<"Total  Vowels = "<<vowel;
   cout<<endl<<"Total Consonants = "<<cons;
   cout<<"total charcters" << vowel+cons<<endl;
   return 0;
}
//Q WAP to read two complex no into the file as well as store then read from the file and display
#include<iostream>
#include<fstream>
using namespace std;
int main(){
    string line;
    fstream file;
    file.open("file.txt", ios ::out | ios ::app);
    if (file.fail())
    {
        cout << "Error Opening file ... " << endl;
    } 
    else{
        cout << "Enter a complex no. : ";
        cin.getline(file,line);
        file << line << endl;
        cout << "Line written into the file" << endl;
        file.close();
    }
}
// WAP A LINE OF TEXT USING FSTREAM OBJECT THEN READ THE FILE
// FROM THE 5TH POS OF THE BEGINNING AND READ 3RD POS FROM THE BACKWORDS AND FROM END TO BACKWORDS 4TH POS 
#include<iostream>
#include<fstream>
using namespace std;