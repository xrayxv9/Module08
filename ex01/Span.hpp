#pragma once

#include <array>
#include <iostream>
#include <vector>

class Span
{
	public :
		Span();
		Span( unsigned int );
		~Span();
		Span &operator=( Span & );
		Span( Span & );

		class ExceptionNotEnoughSpace : std::exception
		{
			public:
				virtual const char *what() const throw(); 
		};

		class NotEnoughNumber : std::exception
		{
			public:
				virtual const char *what() const throw(); 
		};

		unsigned int getMax();
		unsigned int shortestSpan();
		unsigned int longestSpan();
		std::vector<unsigned int> getSpan();

	private :
		std::vector<unsigned int> _span;
		unsigned int _max;
};
