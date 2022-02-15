#include <fstream>
#include <iostream>
#include <vector>

/*Thomas Morin
 *FILE NAME: project3_Morin_twm0023.cpp
 * AUTHOR: Thomas Morin
 * Sources: I used the project hints to give me an idea of how to structure the program.
 *          I used StackOverflow.com to better understand iostream and vectors in general.
*/

using namespace std;

bool check_file(string);

vector<int> read_file(string);

void write_file(string, vector<int>);

vector<int> merge(vector<int>, vector<int>);

void to_string(string, vector<int>);



int main() {
	
   //Declare Variables (per hints)
   
   string file1; //from hints

   string file2; //from hints

   string file3; //from hints

   vector<int> numbers1; //from hints (vector)

   vector<int> numbers2; //from hints (vector)

   vector<int> numbers3; //from hints (vector)

   cout << "*** Welcome to Morin's sorting program ***\n"; //Starts output

	
   
   do {
   //Prompt for input
      cout << "Enter the first input file name: ";
      cin >> file1;
      
      //Not sure what to output so I'll leave it blank.
      
      cout << " "; } 
   
   while (cin.fail() || !check_file(file1));

   numbers1 = read_file(file1); //Hints
   
   to_string(file1, numbers1); //Maybe?

   
   do {
   //Prompt for input
      cout << "Enter the second input file name: ";
      cin >> file2;
      
      //Not sure what to output so I'll leave it blank.
      
      cout << " "; }
      
   while (cin.fail() || !check_file(file2));

   numbers2 = read_file(file2); //Hints
   
   to_string(file2, numbers2);


   numbers3 = merge(numbers1, numbers2);
   
   
   cout << "The sorted list of " << numbers3.size() << "  "
       << "numbers is: ";

//Dsiplays the sorted list.

   for (int i = 0; i < numbers3.size() - 1; i++) {
      cout << numbers3.at(i) << " "; }
      
   cout << numbers3.at(numbers3.size() - 1) << "\n";

   do {
   
      cout << "Enter the output file name: ";
      cin >> file3;
      cout << ""; } 
   
   while (cin.fail());

   write_file(file3, numbers3); //From hints.
   
   //Dsiplays the last of the output
   
   cout << "*** Please check the new file - " << file3 << " ***\n";
   cout << "*** Goodbye. ***\n";

   return 1; }


bool check_file(string file) {

   ifstream stream;

   stream.open(file.c_str());
   if (stream.fail()) {
   
      cerr << "File not found.\n\n";
      return false; }
   
   stream.close();

   return true;}
   
   

vector<int> read_file(string file) {

   ifstream stream;
   vector<int> v;
   int i;


   stream.open(file.c_str());
   while (stream.good()) {
   
      stream >> i;
      
      v.push_back(i); }
      
   v.pop_back();
   
   stream.close();

   return v; }

void write_file(string file, vector<int> v) {

   ofstream stream;

   unsigned short i;

   stream.open(file.c_str());
   for (i = 0; i < v.size() - 1; i++) {
      
      stream << v.at(i) << "\n"; }
      
   stream << v.at(v.size() - 1);
   stream.close(); }
   
   

vector<int> merge(vector<int> v1, vector<int> v2) {

   vector<int> v3; //From Hints

	// Vector interator number
   unsigned short i;

	// Vector iterator size
   unsigned short s;

   while (v1.size() > 0 && v2.size() > 0) {
   
      if (v1.at(0) < v2.at(0)) {
      
         v3.push_back(v1.at(0));
         
         v1.erase(v1.begin()); } 
      
      else {
      
         v3.push_back(v2.at(0));
         
         v2.erase(v2.begin()); }
   }


   if (v1.size() > 0) {
   
      s = v1.size();
      
      for (i = 0; i < s; i++) {
      
         v3.push_back(v1.at(0));
         
         v1.erase(v1.begin());}
   }

//Same as above

   if (v2.size() > 0) {
   
      s = v2.size();
      
      for (i = 0; i < s; i++) {
      
         v3.push_back(v2.at(0));
         
         v2.erase(v2.begin()); }
   }
			
   return v3; }
  

void to_string(string file, vector<int> v) {

   unsigned short i;
	
   cout << "The list of " << v.size() << " numbers "
       << "in file " << file << " is:\n";


   for (i = 0; i < v.size(); i++) {
      cout << v.at(i) << "\n"; }

   cout << "\n"; }
