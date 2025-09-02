#pragma once

#include <sstream>
#include <iostream>
#include <vector>
#include <cstdlib>

class Span
{
	public :
		Span();
		Span( unsigned int );
		~Span();
		Span &operator=( const Span & );
		Span( const Span & );

		class ExceptionNotEnoughSpace : public std::exception
		{
			public:
				virtual const char *what() const throw(); 
		};

		class NotEnoughNumber : public std::exception
		{
			public:
				virtual const char *what() const throw(); 
		};

		unsigned int getMax() const;
		unsigned int getCurrent() const;
		unsigned int shortestSpan();
		unsigned int longestSpan();
		void addNumber( unsigned int );
		void improvedAddNumber( unsigned int, int );
		std::vector<unsigned int> getSpan() const;

	private :
		std::vector<unsigned int> _span;
		unsigned int _max;
		unsigned int _current;
};


std::ostream &operator<<( std::ostream &, const Span & );
