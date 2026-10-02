#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "util.h"

using namespace std;
std::string convToLower(std::string src)
{
    std::transform(src.begin(), src.end(), src.begin(), ::tolower);
    return src;
}

/** Complete the code to convert a string containing a rawWord
    to a set of words based on the criteria given in the assignment **/
std::set<std::string> parseStringToWords(string rawWords)
{
  // Check later
  std::stringstream parse(rawWords);
  std::set<std::string> parseWord;
  std::string words;

  while(parse >> words){
    std::string parseKey;
    // loop through all indexes
    for(int i = 0; i < words.length(); i++){
      // checks for punctation
      if(std::ispunct(words[i])){
        // at least 2 character words
        if(parseKey.length() >= 2){
          parseWord.insert(convToLower(parseKey));
        }
        parseKey.clear();
      }
      // Print out the word
      else{
        parseKey += words[i];
      }
    }
    // If something is only one character after parsing
    if (parseKey.length() >= 2){
      parseWord.insert(convToLower(parseKey));
    }
  }
  return parseWord;
}

/**************************************************
 * COMPLETED - You may use the following functions
 **************************************************/

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// trim from start
std::string &ltrim(std::string &s) {
    s.erase(s.begin(), 
	    std::find_if(s.begin(), 
			 s.end(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
std::string &rtrim(std::string &s) {
    s.erase(
	    std::find_if(s.rbegin(), 
			 s.rend(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))).base(), 
	    s.end());
    return s;
}

// trim from both ends
std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}
