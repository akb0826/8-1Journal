/*
 * TempReading.cpp
 *
 *  Created on: Oct 6, 2023
 *      Author: ashly
 */

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
int FtoC(int temp){
	temp = (temp - 32) * 5 / 9;

	return temp;
}

int main() {
   ifstream tempFS;
   vector<string> cityName(6);
   vector<int> cityTemp(6);


   tempFS.open("FahrenheitTemperature.txt");
   if (!tempFS.is_open()){
	   cout << "ERROR COULD NOT OPEN";
   }
   for (int i = 0; i < 6; i++){
	   tempFS >> cityName.at(i);
	   tempFS >> cityTemp.at(i);
   }
   tempFS.close();
   ofstream celsiusFS;
   celsiusFS.open("CelsiusTemperature.txt");
   if (!celsiusFS.is_open()){
	   cout<<"error";
   }
   for (int i = 0; i < 6; i ++){
	   celsiusFS << cityName.at(i) << " ";
	   celsiusFS << FtoC(cityTemp.at(i)) << endl;
   }
   return 0;
}


