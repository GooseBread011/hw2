#include <sstream>
#include <iomanip>
#include "clothing.h"

using namespace std;

Clothing::Clothing(const std::string category, const std::string name, double price, int qty, const std::string size, const std::string brand) :
    Product(category, name, price, qty),
    size_(size),
    brand_(brand)
{

}

Clothing::~Clothing()
{

}

std::set<std::string> Clothing::keywords() const {
  std::set<std::string> keys;
  keys.insert(name_);
  keys.insert(size_);
  keys.insert(brand_);
  return keys;
}

std::string Clothing::displayString() const{
  std::ostringstream disp;
  disp << name_ << "\n"
       << "Size: " << size_ << " Brand: " << brand_ << "\n"
       << price_ << " " << qty_ << " left.";
  return disp.str();
}

void Clothing::dump(std::ostream& os) const
{
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ 
    << "\n" << size_ << "\n" << brand_ << endl;
}