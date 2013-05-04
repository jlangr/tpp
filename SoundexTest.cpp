#include "CppUTest/TestHarness.h"

#include "Soundex.h"

TEST_GROUP(ASoundexEncoding) {
   Soundex soundex;
};

// START:test
TEST(ASoundexEncoding, AppendsZerosToWordForOneLetterWord) {
   CHECK_EQUAL("A000", soundex.encode("A"));
// START_HIGHLIGHT
   CHECK_EQUAL("B000", soundex.encode("B"));
// END_HIGHLIGHT
}
// END:test
