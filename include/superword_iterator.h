#ifndef _SUPERWORD_ITERATOR_
#define _SUPERWORD_ITERATOR_

#include <string_set.h>
#include <side.h>

template <Side side>
class SuperwordIterator
{

	public:

		SuperwordIterator(const std::string& wordToMatch, const SortedStringSet<side>& wordsToSearch);

		const std::string& operator*() const;

		bool hasNext() const;

		SuperwordIterator<side>& operator++();

	private:

		typename SortedStringSet<side>::const_iterator calculateUpperBounds(const std::string& wordToMatch, const SortedStringSet<side>& wordsToSearch);

		typename SortedStringSet<side>::const_iterator mCurrentValue;

		const typename SortedStringSet<side>::const_iterator mUpperBounds;

};

#endif
