#ifndef Soundex_h
#define Soundex_h

class Soundex {
public:
   const static size_t MaxCodeLength{4};

   Soundex() {
      initializeCodeMap();
   }

   void initializeCodeMap() {
      codes_['b'] = codes_['f'] = codes_['p'] = codes_ ['v'] = "1";
      codes_['c'] = codes_['g'] = codes_['j'] = codes_ ['k'] = 
         codes_['q'] = codes_['s'] = codes_['x'] = codes_['z'] = "2";
      codes_['d'] = codes_['t'] = "3";
      codes_['l'] = "4";
      codes_['m'] = codes_['n'] = "5";
      codes_['r'] = "6";
   }

// START:impl
   std::string encode(const std::string& word) const {
      std::string code(1, head(word));
// START_HIGHLIGHT
      encode(word, code);
// END_HIGHLIGHT
      return zeroPad(code);
   }

   void encode(const std::string& word, std::string& code) const {
      auto tailToEncode = tail(word);
      if (tailToEncode.empty() || isFull(code)) return;
      
      auto digit = codeFor(head(tailToEncode));
      if (isSameEncodingAsLast(digit, word))
         code += digit;
      encode(tailToEncode, code);
   }
   
   bool isSameEncodingAsLast(
         const std::string& digit, 
         const std::string& word) const {
      return digit != codeFor(head(word));
   }
// END:impl

   bool isFull(std::string& code) const {
      return code.length() == MaxCodeLength;
   }

   char head(const std::string& word) const {
      return word[0];
   }

   std::string tail(const std::string& word) const {
      return word.substr(1);
   }

   std::string codeFor(char c) const {
      return codes_[static_cast<size_t>(c)];
   }

   std::string zeroPad(const std::string& code) const {
      return code + std::string(MaxCodeLength - code.length(), '0');
   }

private:
   std::string codes_[128];
};

#endif
