#include <cassert>
#include "synonyms.cpp"

Synonyms synonyms;
void TestAddingSynonymsIncreasesTheirCount()
{
    assert(synonyms.GetSynonymCount("music"s) == 0);
    assert(synonyms.GetSynonymCount("melody"s) == 0);

    synonyms.Add("music"s, "melody"s);
    // Два слова являются синонимами друг друга
    assert(synonyms.GetSynonymCount("music"s) == 1);
    assert(synonyms.GetSynonymCount("melody"s) == 1);

    synonyms.Add("music"s, "tune"s);
    assert(synonyms.GetSynonymCount("music"s) == 2);

    // Здесь синонимичность != транзитивность.
    // Поэтому слова "tune" и "melody" синонимами друг друга не являются
    assert(synonyms.GetSynonymCount("tune"s) == 1);
    assert(synonyms.GetSynonymCount("melody"s) == 1);
}

void TestIfSynonyms()
{
    assert(synonyms.AreSynonyms("music"s, "melody"s));
    assert(synonyms.AreSynonyms("music"s, "tune"s));
    assert(!synonyms.AreSynonyms("melody"s, "tune"s));
}

void TestSynonyms()
{
    TestAddingSynonymsIncreasesTheirCount();
    TestIfSynonyms();
}