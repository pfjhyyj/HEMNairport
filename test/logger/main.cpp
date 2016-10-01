#include "logger.h"
using XXYY::Logger;

int main() {
    Logger test;

  	test.LogOne("test case 1");

  	test.TakeOff(1);
    test.Land(2, 3);
  	test.ReadyToTakeOff(4);
  	test.LogAll();

  	test.ReadyToLand(5);
  	test.Reject(6);
  	test.LogAll();

  	test.Print(0, 1);
}
