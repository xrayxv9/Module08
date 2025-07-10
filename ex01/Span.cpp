#include "Span.hpp"

Span::Span( unsigned int n ): _max(n) {}
Span::Span(): _max(2) {}

Span::Span( Span &cpy )
{
	*this = cpy;
}

Span &Span::operator=( Span &cpy )
{
	this->_max = cpy.getMax();

	this->_span = std::vector<unsigned int>(cpy._span);
	return *this;
}

Span::~Span() {}


const char *Span::ExceptionNotEnoughSpace::what() const throw()
{
	return ("You do not have enough space to add a new number");
}

const char *Span::NotEnoughNumber::what() const throw()
{
	return ("You do not have enough number to try the spans functions");
}


unsigned int Span::getMax()
{
	return _max;
}

unsigned int Span::longestSpan()
{
	unsigned int min = *_span.begin();
	unsigned int max = *_span.begin();

	for (std::vector<unsigned int>::iterator it = _span.begin(); it != _span.end(); it++)
	{
		if (*it < min)
			min = *it;
		else if (*it > max)
			max = *it;
	}
	return max - min; 
}

unsigned int Span::shortestSpan()
{
	unsigned int min1 = *_span.begin();
	unsigned int min2 = *_span.begin();
	unsigned int tmp;
	for (std::vector<unsigned int>::iterator it = _span.begin(); it != _span.end(); it++)
	{
		if (*it < min2)
			min2 = *it;
		if (min2 < min1)
		{
			tmp = min1;
			min1 = min2;
			min2 = tmp;
		}
	}
}

