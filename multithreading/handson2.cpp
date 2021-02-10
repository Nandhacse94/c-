//Create a threads and run a same method with different threads.
//Introduce mutex and lock/unlock the critical section.

#include <iostream>
#include <thread>
#include <mutex> //include mutex header

std::mutex mu;

int printEvenNumbers(int n){
  //std::unique_lock<std::mutex> lock(mu);
  mu.lock();
  for (int i=1; i<=n; i++) {
	std::cout << i << std::endl;
  }
  std::cout<< "Done" << std::endl << std::endl;
  mu.unlock();
  return 0;
}

int main(){

  std::thread thread1(printEvenNumbers,10);
  std::thread thread2(printEvenNumbers,10);

  thread1.join();
  thread2.join();

  return 0;
}
