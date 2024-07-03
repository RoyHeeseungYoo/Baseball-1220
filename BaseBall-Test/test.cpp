#include "pch.h"
#include <stdexcept>
#include "../BaseBallKata/baseball.cpp"

using namespace std;

TEST(BaseballGame, ThrowExceptionWhenInputLengthIsUnmatched) {
	BaseBall game;
	EXPECT_THROW(game.guess(string("12")), length_error);
}