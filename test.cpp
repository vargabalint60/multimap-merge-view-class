#include <set>
#include "msmview.h"
#include <iostream>

struct string_size_less
{

  bool operator()( const std::string& lhs,
                   const std::string& rhs ) const
  {
    return lhs.size() < rhs.size();
  }

};

void test2() {
	std::multiset<std::string, string_size_less> sa;
	std::multiset<std::string, string_size_less> sb;

	sa.insert( "C++" );
	sa.insert( "Haskell" );
	sb.insert( "Ada" );
	sb.insert( "SQL" );
	sb.insert( "LISP" );

	multisets_merge_view<std::string, string_size_less> mvs( sa, sb );
	for (std::string i : sa) {
		std::cout << i << std::endl;
	}
	std::cout << std::endl;
	for (std::string i : sb) {
		std::cout << i << std::endl;
	}
	std::cout << "size = " << mvs.size() << std::endl;
	std::cout << "count = " << mvs.count("Ada") << std::endl;
}

void test(std::multiset<int> &a, std::multiset<int> &b) {
	const multisets_merge_view<int> mvi( a, b );
	for (int i : a) {
		std::cout << i << std::endl;
	}
	std::cout << std::endl;
	for (int i : b) {
		std::cout << i << std::endl;
	}
	std::cout << "size = " << mvi.size() << std::endl;
	std::cout << "count = " << mvi.count(4) << std::endl;
}

int main() {
	std::multiset<int> a;
	std::multiset<int> b;
	a.insert( 1 );
	a.insert( 7 );
	a.insert( 4 );
	b.insert( 4 );
	b.insert( 3 );
	test(a, b);

	std::cout << std::endl << "outer" << std::endl;;
	for (int i : a) {
		std::cout << i << std::endl;
	}
	std::cout << std::endl;
	for (int i : b) {
		std::cout << i << std::endl;
	}

	test2();

}