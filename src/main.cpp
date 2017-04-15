#include <fstream>
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <functional>
#include <stack>

#include <reverse_less.h>
#include <palindrome_tools.h>


enum class Side
{

	Left,

	Right

};

template <class IteratorType>
struct IteratorBounds
{

	IteratorType lowerBound;
	IteratorType upperBound;

};

int main(int argc, char** argv)
{

	typedef std::set<std::string, std::less<std::string>> ForwardStringSet;
	typedef std::set<std::string, ReverseLess> ReverseStringSet;
	/*	
	std::fstream fileStream;
	fileStream.open("/home/sebastian/Downloads/words.txt", std::fstream::in);

	ForwardStringSet forwardOrdering;
	ReverseStringSet backwardOrdering;

	while (!fileStream.eof())
	{
		std::string line;
		fileStream >> line;
		
		forwardOrdering.insert(line);
		backwardOrdering.insert(line);
	}

	int numberOfWords = 3;

	std::vector<std::string> palindromes;

	std::vector<ForwardStringSet::iterator> forwardIterators;
	std::vector<ReverseStringSet::iterator> reverseIterators;

	std::vector<IteratorBounds<ForwardStringSet::iterator>> forwardIteratorBounds;
	std::vector<IteratorBounds<ReverseStringSet::iterator>> reverseIteratorBounds;

	ForwardStringSet::iterator seedIterator = forwardOrdering.begin();

	while (seedIterator != forwardOrdering.end())
	{
		int leftCharacters = 0;
		int rightCharacters = 0;
		int numberOfWordsSoFar = 0;
		
		// Setup first/seed word
		forwardIterators.push_back(seedIterator);
		leftCharacters += seedIterator->size();

		++numberOfWordsSoFar;

		// Insert new words
		while (numberOfWordsSoFar < numberOfWords)
		{
			if (leftCharacters >= rightCharacters)
			{
				// Begin inserting right words

				// Number of left characters that must be matched by the new right characters
				int numMatchingCharacters = leftCharacters - rightCharacters;

				int accumulatedChars = 0;

				int index = forwardIterators.size() - 1;
				for (; index >= 0 && accumulatedChars < numMatchingCharacters; --index)
				{
					accumulatedChars += forwardIterators[index]->size();	
				}

				int firstCharPosition = accumulatedChars - numMatchingCharacters;

				std::string matchingCharacters = "";

				// Deal with overlapping word
				matchingCharacters.insert(0, *(forwardIterators[index]), firstCharPosition, std::string::npos);
				++index;

				for (; index < forwardIterators.size() - 1; ++index)
				{
					matchingCharacters += *(forwardIterators[index]);
				}

				reverse(matchingCharacters.begin(), matchingCharacters.end());

				IteratorBounds<ReverseStringSet::iterator> newBounds;
				newBounds.lowerBound = backwardOrdering.lower_bound(matchingCharacters);
				newBounds.upperBound = backwardOrdering.upper_bound(matchingCharacters);

				
			}
			else
			{

			}

			++numberOfWordsSoFar;
			
		}

		// Check "overhanging" characters

		++seedIterator;
	}

	std::cout << *backwardOrdering.lower_bound("test") << std::endl;
	std::cout << *backwardOrdering.upper_bound("test") << std::endl;

	std::cout << "Found the following palindromes: " << std::endl;
	for (const auto& palindrome : palindromes)
	{
		std::cout << palindrome << std::endl;
	}
	*/

	ForwardStringSet set;
	set.insert("t");
	set.insert("te");
	set.insert("tes");
	set.insert("tea");
	set.insert("teaa");
	set.insert("test");
	set.insert("testy");
	set.insert("testacle");
	set.insert("testicle");
	set.insert("tesla");
	

	auto low = set.lower_bound("test");
	auto upper = set.upper_bound("tesu");

	for (auto itr = low; itr != upper; ++itr)
	{
		std::cout << *itr << std::endl;
	}

	return 0;
}