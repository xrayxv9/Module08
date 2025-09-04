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

	this->_span = std::vector<int>(cpy._span);
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

std::vector<int> Span::getSpan() const
{
	return _span;
}

unsigned int Span::longestSpan()
{
	if (_span.size() <= 1)
		throw NotEnoughNumber();

	int min = *_span.begin();
	int max = *_span.begin();

	for (std::vector<int>::iterator it = _span.begin(); it != _span.end(); it++)
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
	int result;
	if (_span.size() <= 1)
		throw NotEnoughNumber();

	result = std::abs(_span[1] - _span[0]);
	for (std::vector<int>::iterator it = _span.begin(); it != _span.end(); it++)
	{
		for (std::vector<int>::iterator at = it + 1; at != _span.end(); at++)
		{
			int diff = std::abs(*it - *at);
			if (diff < result)
				result = diff;
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

void Span::improvedAddNumber( unsigned int range, int seed )
{
	if (range + _current >= _max)
		throw ExceptionNotEnoughSpace();
	for (unsigned int i = 0; i <= range; i++)
		this->addNumber(rand() % seed);
}

std::ostream &operator<<( std::ostream &o, const Span &sp)
{
	std::vector<int> vect = sp.getSpan();

	o << "your span : " << std::endl;
	for (std::vector<int>::iterator it = vect.begin(); it != vect.end(); it++)
	{
		if (it != vect.end() - 1)
			o << *it << std::endl;
		else
			o << *it;

	}
	return o;
}
