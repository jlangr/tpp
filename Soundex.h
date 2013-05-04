#ifndef Soundex_h
#define Soundex_h

// START:impl
class Soundex {
public:
   std::string encode(const std::string& word) const {
      std::string code("");
// START_HIGHLIGHT
      code += head(word) + encodeTail(word);
      return zeroPad(code);
// END_HIGHLIGHT
   }

// START_HIGHLIGHT
   char head(const std::string& word) const {
      return word[0];
   }
// END_HIGHLIGHT

// START_HIGHLIGHT
   std::string encodeTail(const std::string& word) const {
      if (word[1] != 0) return "1";
      return "";
   }
// END_HIGHLIGHT

// START_HIGHLIGHT
   std::string zeroPad(const std::string& code) const {
      if (code[1] != 0)
         return code + "00";
      return code + "000";
   }
// END_HIGHLIGHT
};
// END:impl
#endif
