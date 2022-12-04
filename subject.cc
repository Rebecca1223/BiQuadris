#include "subject.h"
#include <vector>
#include "observer.h"
#include <iostream>

using namespace std;

void Subject::attach(Observer *o) {
  observers.emplace_back(o);
}


void Subject::detach(Observer *o) {
  for (int i = 0; i < observers.size(); ++i) {
    if (observers[i] == o) {
      observers.erase(observers.begin() + i);
      break;
    }
  }
}


void Subject::notifyObservers() {
  for (auto o : observers) {
    cout << "before notify" << endl;
    o->notify();
    cout << "after notify" << endl;
  }
}
