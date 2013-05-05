#ifndef Soundex_h
#define Soundex_h

// START:impl
class Soundex {
public:
// START_HIGHLIGHT
   Soundex() {
      codes_['b'] = "1";
      codes_['c'] = "2";
   }
// END_HIGHLIGHT
   // ...
// END:impl

   std::string encode(const std::string& word) const {
      std::string code("");
      code += head(word) + encodeTail(word);
      return zeroPad(code);
   }

   char head(const std::string& word) const {
      return word[0];
   }

// START:impl
   std::string encodeTail(const std::string& word) const {
      if (word[1] != 0) 
// START_HIGHLIGHT
         return codes_[static_cast<size_t>(word[1])];
// END_HIGHLIGHT
      return "";
   }
   // ...
// END:impl

   std::string zeroPad(const std::string& code) const {
      return code + (hasEncodedCharacters(code) ? "00" : "000");
   }

   bool hasEncodedCharacters(const std::string& code) const {
      return code[1] != 0;
   }

// START:impl
// START_HIGHLIGHT
private:
   std::string codes_[128];
// END_HIGHLIGHT
};
// END:impl

#endif
