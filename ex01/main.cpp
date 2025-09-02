#include "Span.hpp"
#include <cstdlib>

int main()
{
	srand(time(0));
	Span span = Span();
	Span span2 = Span();
	Span customSpan = Span(11);
	Span customSpanHuge = Span(10001);

	std::cout << "NOT ENOUGH SPACE EXCEPTION TEST" << std::endl;
	try
	{
		span.addNumber(1);
		span.addNumber(2);
		span.addNumber(3);
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << std::endl << "NOT ENOUGH NUMBER EXCEPTION TEST" << std::endl;
	try
	{
		span2.addNumber(1);
		std::cout << span2.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << std::endl << "10 VALUES TEST" << std::endl;
	try 
	{
		customSpan.improvedAddNumber(10, 100);
		std::cout << customSpan << std::endl;
		std::cout << "the longestSpan is : " << customSpan.longestSpan() << std::endl;
		std::cout << "the shortestSpan is : " << customSpan.shortestSpan() << std::endl;
	} 
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << std::endl << "10000 VALUES TEST" << std::endl;
	try 
	{
		customSpanHuge.improvedAddNumber(10000, 10000);
		std::cout << "the longestSpan is : " << customSpanHuge.longestSpan() << std::endl;
		std::cout << "the shortestSpan is : " << customSpanHuge.shortestSpan() << std::endl;
	} 
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}
