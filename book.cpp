#include <sstream>
#include <iomanip>
#include "book.h"

using namespace std;

Book::Book(const std::string category, const std::string name, double price, int qty, const std::string author, const std::string isbn) :
    Product(category, name, price, qty),
    author_(author),
    isbn_(isbn)
{

}

Book::~Book()
{

}

std::set<std::string> Book::keywords() const {
  std::set<std::string> keys;
  keys.insert(name_);
  keys.insert(author_);
  keys.insert(isbn_);
  return keys;
}

std::string Book::displayString() const{
  std::ostringstream disp;
  disp << name_ << endl
       << "Author: " << author_ << " ISBN: " << isbn_ << "\n"
       << price_ << " " << qty_ << " left.";
  return disp.str();
}

void Book::dump(std::ostream& os) const
{
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ 
    << "\n" << author_ << "\n" << isbn_ << endl;
}