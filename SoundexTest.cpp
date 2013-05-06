#include "CppUTest/TestHarness.h"

#include "Soundex.h"

TEST_GROUP(ASoundexEncoding) {
   Soundex soundex;
};

TEST(ASoundexEncoding, AppendsZerosToWordForOneLetterWord) {
   CHECK_EQUAL("A000", soundex.encode("A"));
   CHECK_EQUAL("B000", soundex.encode("B"));
}

TEST(ASoundexEncoding, ReplacesConsonantsWithAppropriateDigits) {
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

TEST(ASoundexEncoding, ReplacesMultipleConsonantsWithDigits) {
   CHECK_EQUAL("A234", soundex.encode("Acdl"));
}

TEST(ASoundexEncoding, IgnoresVowelLikeLetters) {
   CHECK_EQUAL("B234", soundex.encode("BAaEeIiOoUuHhYycdl"));
}

TEST(ASoundexEncoding, IgnoresNonAlphabetics) {
   CHECK_EQUAL("F234", soundex.encode("F987654321%#.=+cdl"));
}

TEST(ASoundexEncoding, CombinesDuplicateEncodings) {
   CHECK_EQUAL(soundex.codeFor('f'), soundex.codeFor('b'));
   CHECK_EQUAL(soundex.codeFor('g'), soundex.codeFor('c'));
   CHECK_EQUAL(soundex.codeFor('t'), soundex.codeFor('d'));

   CHECK_EQUAL("A123", soundex.encode("Abfcgdt"));
}

