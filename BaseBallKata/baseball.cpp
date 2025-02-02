#include <stdexcept>

using namespace std;

struct GuessResult {
	bool solved;
	int strikes;
	int balls;
};

class BaseBall {
public:
	explicit BaseBall(const string& question)
		: question(question) {

	}

	GuessResult guess(const string& guessNumber) {
		assertIllegalArgument(guessNumber);
		if (guessNumber == question) {
			return { true, 3, 0 };
		}

		return { false, getStrikes(guessNumber), getBalls(guessNumber) };
	}

	int getBalls(const std::string& guessNumber)
	{
		int balls = 0;

		if (guessNumber[0] == question[1]) balls++;
		if (guessNumber[0] == question[2]) balls++;
		if (guessNumber[1] == question[2]) balls++;

		if (question[0] == guessNumber[1]) balls++;
		if (question[0] == guessNumber[2]) balls++;
		if (question[1] == guessNumber[2]) balls++;

		return balls;
	}

	int getStrikes(const std::string& guessNumber)
	{
		int strike = 0;
		if (guessNumber[0] == question[0]) strike++;
		if (guessNumber[1] == question[1]) strike++;
		if (guessNumber[2] == question[2]) strike++;
		return strike;
	}

	void assertIllegalArgument(const std::string& guessNumber)
	{
		if (guessNumber.length() != 3) {
			throw length_error("Must be three letters.");
		}

		for (char ch : guessNumber) {
			if (ch >= '0' && ch <= '9') continue;
			throw invalid_argument("Must be number");
		}

		if (isDuplicatedNumber(guessNumber)) {
			throw invalid_argument("Must not have the same number");
		}
	}

	bool isDuplicatedNumber(const std::string& guessNumber)
	{
		return guessNumber[0] == guessNumber[1]
			|| guessNumber[0] == guessNumber[2]
			|| guessNumber[1] == guessNumber[2];
	}

private:
	string question;
};