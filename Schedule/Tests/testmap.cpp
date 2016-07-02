// constructing maps
#include <iostream>
#include <map>
#include "valve_info.h"

using namespace std;



int main (){

  Valve_info vi1(0,2,1);
  Valve_info vi2(1,3,4);
  
  Valve_info vii;

  cout << vii.getValve().getNumber()<< endl;

  map<int, Valve_info> mapOfWords;
  // Inserting data in std::map
  mapOfWords.insert(make_pair(vi1.getValve().getNumber(), vi1));
  mapOfWords.insert(make_pair(vi2.getValve().getNumber(), vi2));

  cout << mapOfWords[1] << endl;

  //mapOfWords["sun"] = 3;
  // Will replace the value of already added key i.e. earth
  //mapOfWords["earth"] = 4;
  // Iterate through all elements in std::map
  //map<int, Valve_info>::iterator it = mapOfWords.begin();
  
  //while(it != mapOfWords.end();){
//    cout << it->first << " :: " << it->second << endl;
    //it++;
  //}

  for(map<int, Valve_info>::iterator it = mapOfWords.begin(); it != mapOfWords.end(); it++ ){
    cout << it->first << " :: " << it->second << endl;
  }
  
  // Check if insertion is successful or not
  //if(mapOfWords.insert(make_pair("earth", 1)).second == false) {
//    cout << "Element with key 'earth' not inserted because already existed" << endl;
//  }

  // Searching element in std::map by key.
//  if(mapOfWords.find("sun") != mapOfWords.end())
    //cout << "word 'sun' found" << endl;

//  if(mapOfWords.find("mars") == mapOfWords.end())
    //cout << "word 'mars' not found" << endl;
  
  return 0;
}