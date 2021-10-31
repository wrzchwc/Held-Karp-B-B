#include <regex>
#include <string>
#include "Utility.h"

vector<string> Utility::split(const string &text, const string &pattern) {
    vector<string> tmp;
    const regex regex(pattern);
    sregex_token_iterator iter(text.begin(), text.end(), regex, -1);

    for (sregex_token_iterator end; iter != end; ++iter) {
        tmp.push_back(iter->str());
    }

    return tmp;
}
