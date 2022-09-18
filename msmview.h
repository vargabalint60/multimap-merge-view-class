#ifndef MM_VIEW__H
#define MM_VIEW__H

#include <set>
#include <iterator>


template <typename T, typename Comp = std::less<T>>
class multisets_merge_view{
	std::multiset<T, Comp> &a;
	std::multiset<T, Comp> &b;
	int aSize;
	int bSize;
	std::multiset<T, Comp> commonSet;
	std::multiset<T, Comp> aOriginal;
	std::multiset<T, Comp> bOriginal;

public:
	multisets_merge_view(std::multiset<T, Comp> &a, std::multiset<T, Comp> &b): a(a), b(b), aSize(a.size()), bSize(b.size()) {
		aOriginal = a;
		bOriginal = b;
		commonSet.insert(a.begin(), a.end());
		commonSet.insert(b.begin(), b.end());
		typename std::multiset<T>::iterator commonIt = commonSet.begin();
		a.clear();
		for (int i = 0; i < aSize; i++) {
			a.insert(*commonIt);
			commonIt++;
		}
		b.clear();
		for (int i = 0; i < bSize; i++) {
			b.insert(*commonIt);
			commonIt++;
		}
	}

	int count(T e) const {
		int c = 0;
		for (typename std::multiset<T, Comp>::const_iterator i(commonSet.begin()), end(commonSet.end()); i != end; ++i){
	    	if (*i == e){c++;}
		}
		return c;
	}

	int size() const {
		return commonSet.size();
	}

	~multisets_merge_view() {
		a.clear();
		for (typename std::multiset<T>::const_iterator i(aOriginal.begin()), end(aOriginal.end()); i != end; ++i){
	    	a.insert(*i);
		}

		b.clear();
		for (typename std::multiset<T>::const_iterator i(bOriginal.begin()), end(bOriginal.end()); i != end; ++i){
	    	b.insert(*i);
		}
	}

};

#endif