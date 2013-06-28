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
}

TEST(SoundexEncoding, ReplacesMultipleConsonantsWithDigits) {
   CHECK_EQUAL("A234", soundex.encode("Acdl"));
}

TEST(SoundexEncoding, IgnoresVowelLikeLetters) {
   CHECK_EQUAL("B234", soundex.encode("BAaEeIiOoUuHhYycdl"));
}

TEST(SoundexEncoding, IgnoresNonAlphabetics) {
   CHECK_EQUAL("F234", soundex.encode("F987654321%#.=+cdl"));
}

TEST(SoundexEncoding, CombinesDuplicateEncodings) {
   CHECK_EQUAL(soundex.codeFor('f'), soundex.codeFor('b'));
   CHECK_EQUAL(soundex.codeFor('g'), soundex.codeFor('c'));
   CHECK_EQUAL(soundex.codeFor('t'), soundex.codeFor('d'));

   CHECK_EQUAL("A123", soundex.encode("Abfcgdt"));
}

// START:test2
TEST(SoundexEncoding, CombinesMultipleDuplicateEncodings) {
   CHECK_EQUAL("J100", soundex.encode("Jbbb"));
}
// END:test2

TEST(SoundexEncoding, CombinesDuplicateCodesWhen2ndLetterDuplicates1st) {
   CHECK_EQUAL("b230", soundex.encode("bbcd"));
}

// START:test
TEST(SoundexEncoding, DoesNotCombineDuplicateEncodingsSeparatedByVowels) {
   CHECK_EQUAL("J110", soundex.encode("Jbob")); 
}
// END:test

TEST(SoundexEncoding, LimitsLengthToFourCharacters) {
   CHECK_EQUAL(4u, soundex.encode("Dcdlb").length());
}

