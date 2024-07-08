#include <gtest/gtest.h>
#include "Soundex.h"

TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits) {
 //AAA
  char soundex[5];
  generateSoundex("AX", soundex);
 ASSERT_STREQ(soundex,"A200");
}

TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits_1) {
 //AAA
  char soundex[5];
  generateSoundex("5HIvv@", soundex);
 ASSERT_STREQ(soundex,"5100");
}

TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits_2) {
 //AAA
  char soundex[5];
  generateSoundex("BM^", soundex);
 ASSERT_STREQ(soundex,"B500");
}

TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits_3) {
 //AAA
  char soundex[5];
  generateSoundex("ACGJ", soundex);
 ASSERT_STREQ(soundex,"A200");
}

TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits_4) {
 //AAA
  char soundex[5];
  generateSoundex("@@BBCCDD", soundex);
 ASSERT_STREQ(soundex,"@123");
}

TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits_5) {
 //AAA
  char soundex[5];
  generateSoundex("9Vasi_091", soundex);
  ASSERT_STREQ(soundex, "9120"); 
}
