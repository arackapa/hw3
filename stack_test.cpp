#include "stack.h"
#include <iostream> 
#include <string> 

using namespace std; 

int main(){
  Stack<int> joseph; 
  joseph.push(5);
  cout << "Size: " << joseph.size() << endl; 
  cout << joseph.top() << endl;
  joseph.push(10);
  cout << "Size: " << joseph.size() << endl; 
  cout << joseph.top() << endl;
  joseph.push(15);
  cout << "Size: " << joseph.size() << endl; 
  cout << joseph.top() << endl;
  joseph.pop();
  cout << "Size: " << joseph.size() << endl; 
  cout << joseph.top() << endl;
  joseph.pop();
  cout << "Size: " << joseph.size() << endl; 
  cout << joseph.top() << endl;
  joseph.pop();
  // joseph.pop(); 

  // joseph.push(25); 
  // cout << "Size: " << joseph.size() << endl; 
  // cout << joseph.top() << endl;

  cout << endl; 

  Stack<string> johnny; 
  johnny.push("Joseph");
  cout << "Size: " << johnny.size() << endl; 
  cout << johnny.top() << endl; 
  johnny.push("Johnny");
  cout << "Size: " << johnny.size() << endl; 
  cout << johnny.top() << endl; 
  johnny.push("Obafatemi");
  cout << "Size: " << johnny.size() << endl; 
  cout << johnny.top() << endl; 
  johnny.pop();
  cout << "Size: " << johnny.size() << endl; 
  cout << johnny.top() << endl; 
  johnny.pop(); 
  cout << "Size: " << johnny.size() << endl; 
  cout << johnny.top() << endl; 
}