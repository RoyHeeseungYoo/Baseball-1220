#include <stdexcept>

using namespace std;

class BaseBall {
public:
	void guess(const string& string) {
		throw length_error("Must be three letters.");
	}
};