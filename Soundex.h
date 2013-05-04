#ifndef Soundex_h
#define Soundex_h

// START:impl
class Soundex {
public:
   std::string encode(const std::string& word) const {
// START_HIGHLIGHT
      return word + "000";
// END_HIGHLIGHT
   }
};
// END:impl
#endif
