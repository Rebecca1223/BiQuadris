#include "subject.h"
#include <vector>
#include "observer.h"

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
  for (auto o : observers) o->notify();
}
