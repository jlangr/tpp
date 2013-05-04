#include "CppUTest/TestHarness.h"

#include "Soundex.h"

TEST_GROUP(ASoundexEncoding) {};

// START:test
TEST(ASoundexEncoding, AppendsZerosToWordForOneLetterWord) {
   Soundex soundex;

   auto encoded = soundex.encode("A");

   CHECK_EQUAL("A000", encoded);
}
// END:test
