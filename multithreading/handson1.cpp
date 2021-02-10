//Create a multiple threads for same method.

#include <iostream>
#include <thread>

int printEvenNumbers(int n){
  for (int i=1; i<=n; i++) {
	std::cout << i << std::endl;
  }
  std::cout<<"Done";
  return 0;
}

int main(){

  std::thread thread1(printEvenNumbers,10);
  std::thread thread2(printEvenNumbers,10);

  thread1.join();
  thread2.join();

  return 0;
}
