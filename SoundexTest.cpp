#include "CppUTest/TestHarness.h"

#include "Soundex.h"

TEST_GROUP(ASoundexEncoding) {
   Soundex soundex;
};

TEST(ASoundexEncoding, AppendsZerosToWordForOneLetterWord) {
   CHECK_EQUAL("A000", soundex.encode("A"));
   CHECK_EQUAL("B000", soundex.encode("B"));
}

// START:test
TEST(ASoundexEncoding, ReplacesConsonantsWithAppropriateDigits) {
   CHECK_EQUAL("A100", soundex.encode("Ab"));
// START_HIGHLIGHT
   CHECK_EQUAL("A200", soundex.encode("Ac"));
// END_HIGHLIGHT
}
// END:test
