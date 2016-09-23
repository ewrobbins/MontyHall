#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

#define N 100000
#define numDoors 3

int main(void)
{
   bool willSwitch;
   int correctDoor, closedDoor, choice, gotCar = 0;
   srand(time(NULL));
   
   cout << "Want to switch? 1 for yes, 0 for no" << endl;
   cin >> willSwitch;

   for (int i = 0; i < N; i++) {
      choice = 0;
      
      // place car behind random door
      correctDoor = rand() % numDoors;
      
      // they picked the right door originally, so leave one of the wrong doors closed
      if (correctDoor == 0) closedDoor = 1;
      // they picked the wrong door originally, so leave the right door closed
      else closedDoor = correctDoor;

      // they decided to switch, so switch their choice to the other closed door
      if (willSwitch) choice = closedDoor;

      if (choice == correctDoor) gotCar++;
   }
   
   if (willSwitch != 1) cout << "You didn't switch, and won the car ";
   else cout << "You switched, and won the car ";
   cout << gotCar << "/" << N << " times, a winning percentage of " << ((double)gotCar/N) * 100 << "%" << endl;
   
   return 0;
}
      
