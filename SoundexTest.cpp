#include "CppUTest/TestHarness.h"

#include "Soundex.h"

TEST_GROUP(SoundexEncoding) {
   Soundex soundex;
};

TEST(SoundexEncoding, AppendsZerosToWordForOneLetterWord) {
   CHECK_EQUAL("A000", soundex.encode("A"));
   CHECK_EQUAL("B000", soundex.encode("B"));
}

TEST(SoundexEncoding, ReplacesConsonantsWithAppropriateDigits) {
   CHECK_EQUAL("A100", soundex.encode("Ab"));
   CHECK_EQUAL("A200", soundex.encode("Ac"));
   CHECK_EQUAL("A300", soundex.encode("Ad"));
   CHECK_EQUAL("A100", soundex.encode("Af"));
   CHECK_EQUAL("A200", soundex.encode("Ag"));
   CHECK_EQUAL("A200", soundex.encode("Aj"));
   CHECK_EQUAL("A200", soundex.encode("Ak"));
   CHECK_EQUAL("A400", soundex.encode("Al"));
   CHECK_EQUAL("A500", soundex.encode("Am"));
   CHECK_EQUAL("A500", soundex.encode("An"));
   CHECK_EQUAL("A100", soundex.encode("Ap"));
   CHECK_EQUAL("A200", soundex.encode("Aq"));
   CHECK_EQUAL("A600", soundex.encode("Ar"));
   CHECK_EQUAL("A200", soundex.encode("As"));
   CHECK_EQUAL("A300", soundex.encode("At"));
   CHECK_EQUAL("A100", soundex.encode("Av"));
   CHECK_EQUAL("A200", soundex.encode("Ax"));
   CHECK_EQUAL("A200", soundex.encode("Az"));
}

TEST(SoundexEncoding, ReplacesMultipleConsonantsWithDigits) {
   CHECK_EQUAL("A234", soundex.encode("Acdl"));
}

// START:test
TEST(SoundexEncoding, IgnoresVowelLikeLetters) {
   CHECK_EQUAL("B234", soundex.encode("BAaEeIiOoUuHhYycdl"));
}
// END:test

