#include "pch.h"
#include <stdexcept>
#include "../BaseBallKata/baseball.cpp"

using namespace std;

class BaseballFixture : public testing::Test {
public:
	BaseBall game;
	void assertIllegalArgument(string guessNumber) {
		try {
			game.guess(guessNumber);
			FAIL();
		}
		catch (exception e) {
			//PASS
		}
	}
};

TEST_F(BaseballFixture, ThrowExceptionWhenInvalidCase) {
	assertIllegalArgument("12");
	assertIllegalArgument("12s");
}