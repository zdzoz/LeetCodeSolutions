//
// Created by ザスキ・オスカー on 2023/03/19.
//

#include <gtest/gtest.h>

#include <vector>
#include <unordered_map>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    if (strs.size() < 2) return {strs};

    unordered_map<string, int> words;
    int pos = 0;
    vector<vector<string>> re;
    for (const auto& e : strs) {
        string w = e;
        sort(w.begin(), w.end());
        if (words.find(w) != words.end()) {
            re[words.at(w)].push_back(e);
        } else {
            words[w] = pos++;
            re.push_back({e});
        }
    }
    return re;
}

void sortResult(vector<vector<string>>& re) {
    sort(re.begin(), re.end(), [](const auto& x, const auto& y) {
        return x.size() < y.size();
    });
    for (auto& e : re) sort(e.begin(), e.end());
}

TEST(GroupAnagram, Case1) {
    vector<string> in = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> ex = {{"bat"},{"nat","tan"},{"ate","eat","tea"}};
    auto re = groupAnagrams(in);
    sortResult(re);
    ASSERT_EQ(ex, re);
}

TEST(GroupAnagram, Case2) {
    vector<string> in = {""};
    vector<vector<string>> ex = {{""}};
    auto re = groupAnagrams(in);
    sortResult(re);
    ASSERT_EQ(ex, re);
}

TEST(GroupAnagram, Case3) {
    vector<string> in = {"a"};
    vector<vector<string>> ex = {{"a"}};
    auto re = groupAnagrams(in);
    sortResult(re);
    ASSERT_EQ(ex, re);
}
