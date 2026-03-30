#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void disorderfile(string input, string output, int size){
  ifstream order100(input);
  ofstream unorderer100;
  vector<string> mush(size);
  string line;
  int mushi=0;
  while (getline(order100, line)) {
    mush[mushi] = line;
    mushi++;
  } 
  order100.close();

  string x;
  int random;
  for(int i = 0; i<size; i++){
    random = rand() % size;
    x = mush[i];
    mush[i] = mush[random];
    mush[random] = x;
  }

  ofstream mush100;
  mush100.open (output);
  for(int i = 0; i<size; i++){
    mush100 << mush[i] + "\n";
  }
  mush100.close(); 
}

int main(){


  disorderfile("../random100/ordered.txt", "../benchmarks/random100.txt", 100);
  disorderfile("../random1000/ordered.txt", "../benchmarks/random1000.txt", 1000);
  disorderfile("../test-1/ordered.txt", "../benchmarks/test-1.txt", 100);
  for(int i = 3; i<=12; i++){
    disorderfile("../numbers/"+to_string(i)+"digits.txt", "../numbers/"+to_string(i)+"mush.txt", 25);
  }

  ofstream test2;
  test2.open("../benchmarks/test-2.txt");
  for(int i = 3; i<=6; i++){
    ifstream x("../numbers/" + to_string(i) + "mush.txt");
    string line;
    while (getline(x, line)){
      test2 << line + "\n";
    }
  }

  ofstream test3;
  test3.open("../benchmarks/test-3.txt");
  for(int i = 3; i<=12; i=i+3){
    ifstream y("../numbers/" + to_string(i) + "mush.txt");
    string line;
    while (getline(y, line)){
      test3 << line + "\n";
    }
  }


  /*
  ifstream order100("../random100/ordered.txt");
  ofstream unorderer100;
  vector<string> mush(100);
  string line;
  int mushi=0;
  while (getline(order100, line)) {
    mush[mushi] = line;
    mushi++;
  } 
  order100.close();

  string x;
  int random;
  for(int i=0; i<100; i++){
    random = rand() % 100;
    x = mush[i];
    mush[i] = mush[random];
    mush[random] = x;
  }

  ofstream mush100;
  mush100.open ("../random100/unordered.txt");
  for(int i =0; i<100; i++){
    mush100 << mush[i] + "\n";
  }
  mush100.close(); 
  */

  return 0;
}