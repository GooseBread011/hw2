#include <string>
#include <set>
#include <vector>
#include <map>
#include "mydatastore.h"
#include "util.h"

using namespace std;

MyDataStore::MyDataStore()
{

}

MyDataStore::~MyDataStore()
{

}

void MyDataStore::addProduct(Product* P){
  product_.pushback(p);
  std::set<std::string> keywords = p->keywords();
  std::set<std::string>::iterator it;
  for (it = keywords.begin(); it != keywords.end(); it++){
    keys_[it*].insert(p);
  }

}

void MyDataStore::addUser(User* u){
  user_[u->getName()] = u;
}

void std::vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type){

}
