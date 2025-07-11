#include "Span.hpp"

Span::Span( unsigned int n ): _max(n), _current(0){}
Span::Span(): _max(2), _current(0) {}

Span::Span( const Span &cpy )
{
	*this = cpy;
}

Span &Span::operator=( const Span &cpy )
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


unsigned int Span::getMax() const
{
	return _max;
}

unsigned int Span::getCurrent() const
{
	return _current;
}

std::vector<unsigned int> Span::getSpan() const
{
	return _span;
}

unsigned int Span::longestSpan()
{
	if (_span.size() <= 1)
		throw NotEnoughNumber();

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
	if (_span.size() <= 1)
		throw NotEnoughNumber();

	unsigned int result = *_span.begin() - (*_span.begin() + 1);
	for (std::vector<unsigned int>::iterator it = _span.begin(); it != _span.end(); it++)
	{
		for (std::vector<unsigned int>::iterator at = it; at != _span.end(); at++)
		{
			if (*it > *at)
			{
				if (*it - *at < result)
					result = *it - *at;
			}
			else if (*it < *at)
			{
				if (*at - *it < result)
					result = *at - *it;
			}
			else
			{
				if (it != at)
					result = 0;
			}
		}
	}
	return result;
}

void Span::addNumber( unsigned int number )
{
	 if (_max == _current)
		throw ExceptionNotEnoughSpace();
	_span.push_back(number);
	_current++;
}

std::ostream &operator<<( std::ostream &o, const Span &sp)
{
	std::vector<unsigned int> vect = sp.getSpan();

	o << "your span : " << std::endl;
	for (std::vector<unsigned int>::iterator it = vect.begin(); it != vect.end(); it++)
	{
		if (it != vect.end() - 1)
			o << *it << std::endl;
		else
			o << *it;

	}
	return o;
}
