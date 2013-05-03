#include "CppUTest/TestHarness.h"

#include "Soundex.h"

TEST_GROUP(ASoundexEncoding) {};

// START:test
TEST(ASoundexEncoding, RetainsSoleLetterOfOneLetterWord) {
   Soundex soundex;

   auto encoded = soundex.encode("A");

   CHECK_EQUAL("A", encoded);
}
// END:test
