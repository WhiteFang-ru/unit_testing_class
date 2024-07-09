#include <string>
#include <map>
#include <set>

using namespace std;

class Synonyms
{
public:
    void Add(const string &first_word, const string &second_word) {
        synonyms_[first_word].insert(second_word);
        synonyms_[second_word].insert(first_word);
    }

    size_t GetSynonymCount(const string &word) const
    {
        if(synonyms_.count(word) != 0) {
            return synonyms_.at(word).size();
        }
        return 0;
    }

    bool AreSynonyms(const string &first_word, const string &second_word) const
    {
        if (auto search = synonyms_.find(first_word); search != synonyms_.end()) {
            for(const string& try_syn: synonyms_.at(first_word)) {
                if(try_syn == second_word)
                    return true;
            } 
        }
        return false;
    }

private:
    map<string, set<string>> synonyms_;
};

