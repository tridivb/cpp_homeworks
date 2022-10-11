#include <array>
#include <iostream>
#include <string>
#include <unordered_map>

using std::cin;
using std::cout;
using std::endl;
using std::string_literals::operator""s;

int main() {
  std::unordered_map<std::string, std::string> noun = {
      {"spring"s, "STL guru"s},
      {"summer"s, "C++ expert"s},
      {"autumn"s, "coding beast"s},
      {"winter"s, "software design hero"s}};

  std::array<std::string, 2> adjective = {"", ""};

  std::array<std::string, 3> ending = {
      "eats UB for breakfast"s,
      "finds errors quicker than the compiler"s,
      "is not afraid of C++ error messages"s};

  cout << "Welcome to the fortune teller program!"s << endl;

  cout << "Please enter your name:"s << endl;
  std::string name;
  cin >> name;

  std::string season;
  while (1) {
    cout
        << "Please enter the time of year when you were born:\n(pick from 'spring', 'summer', 'autumn', 'winter')"s
        << endl;
    cin >> season;
    if (noun.find(season) == noun.end()) {
      cout << "Invalid season value. Please try again. There is no escape!"s
           << endl;
    } else {
      break;
    }
  }

  cout << "Please enter an adjective:"s << endl;
  cin >> adjective[0];

  cout << "Please enter another adjective:"s << endl;
  cin >> adjective[1];

  int adj_index = name.size() % adjective.size();
  // clip out of bounds index value
  adj_index =
      adj_index > adjective.size() - 1 ? adjective.size() - 1 : adj_index;

  int ending_index = name.size() % ending.size();
  // clip out of bounds index value
  ending_index =
      ending_index > ending.size() - 1 ? ending.size() - 1 : ending_index;

  cout << name + ", the "s + adjective[adj_index] + " "s + noun.at(season) +
              " that "s + ending[ending_index]
       << endl;

  // cout << "Hello "s + name << endl;

  return 0;
}