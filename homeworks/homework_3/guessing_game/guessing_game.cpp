#include <iostream>
#include <random>

using std::cin;
using std::cout;
using std::endl;
using std::string_literals::operator""s;

int main() {
  cout
      << "Welcome to the GUESSING GAME!\nI will generate a number and you will guess it!"s
      << endl;

  cout << "Please provide the smallest number: "s << endl;
  int smallest = 0;
  cin >> smallest;

  cout << "Please provide the largest number: "s << endl;
  int largest = 0;
  cin >> largest;

  std::random_device rand_dev;
  std::default_random_engine engine(rand_dev());
  std::uniform_int_distribution<int> uniform_dist(smallest, largest);
  int random_number = uniform_dist(engine);

  cout << "I've generated a number. Try to guess it!"s << endl;
  int no_of_guesses = 0;
  while (true) {
    cout << "Please provide the next guess:";
    int guess;
    cin >> guess;
    no_of_guesses++;
    if (guess == random_number) {
      cout << " You've done it! You guessed the number "s << random_number
           << " in "s << no_of_guesses << " guesses!"s << endl;
      break;
    } else if (guess < random_number) {
      cout << " Your number is too small. Try again!"s << endl;
    } else if (guess > random_number) {
      cout << " Your number is too big. Try again!"s << endl;
    }
  }

  return 0;
}
