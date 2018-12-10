#pragma once
#include <string>

class BookDetails {
public:
	string author;
	string category;
	unsigned int nOfPages;
	bool inLib;

	BookDetails() { };

	BookDetails(string a, string c, unsigned int n, bool in = true)
		:author(a), category(c), nOfPages(n), inLib(in) { };

	void lend() {
		 if(inLib) {
		 	std::cout << "Book has been borrowed" << std::endl;
		 	inLib = false;
		 } else {
		 	std::cout << "Book not in a library at the moment" << std::endl;
		 }
	}

	friend std::ostream& operator<< (std::ostream& out, const BookDetails& e) {
		out << "Author: " << e.author << " \t" << "Category: " << e.category << " \t" << "Number of pages: " << e.nOfPages << std::endl;
		out << "\t Is book available? " << e.inLib;
		return out;
	}
};