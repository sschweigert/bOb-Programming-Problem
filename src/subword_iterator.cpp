#include <subword_iterator.h>

template <>
std::string buildOntoWord<Side::Left>(std::string word, char toAdd)
{
	return (word + toAdd);
}

template <>
std::string buildOntoWord<Side::Right>(std::string word, char toAdd)
{
	return (toAdd + word);
}

template <Side side>
SubwordIterator<side>::SubwordIterator(const std::string& wordToMatch, const Set& wordsToSearch) :
	iterator(wordToMatch),
	mHasNext(iterator.current != iterator.end),
	mWordsToSearch(wordsToSearch),
	mSubWord(mHasNext ? std::string(1, *(iterator.current)) : "")
{}

template <Side side>
const std::string& SubwordIterator<side>::operator*() const 
{
	return mSubWord;	
}

template <Side side>
bool SubwordIterator<side>::hasNext()
{
	return mHasNext;
}

template <Side side>
SubwordIterator<side>& SubwordIterator<side>::operator++()
{
	// Note we ignore the case of the full word
	while (++iterator.current < iterator.end)
	{
		mSubWord = buildOntoWord<side>(mSubWord, *(iterator.current));

		if (mWordsToSearch.count(mSubWord) == 1)
		{
			// Subword is valid, so break out of loop
			return *this;
		}	
	}

	// Reached end of word so there is nothing new to add
	mHasNext = false;

	return *this;
}	

template class SubwordIterator<Side::Left>;
template class SubwordIterator<Side::Right>;
