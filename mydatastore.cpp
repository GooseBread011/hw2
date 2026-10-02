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
  vector<Product*>::iterator pt;
  for(pt = product_.begin(); pt != product_.end(); pt++){
    delete *pt; // Removes Product objects
  }
  map<string, User*>::iterator ur;
  for (ur = user_.begin(); ur != user_.end(); ur++){
    delete ur->second; //Removes User Objects
  }
}

void MyDataStore::addProduct(Product* P){
  product_.push_back(P);
  std::set<std::string> keywords = P->keywords();
  std::set<std::string>::iterator it;
  for (it = keywords.begin(); it != keywords.end(); it++){
    keys_[*it].insert(P);
  }

}

void MyDataStore::addUser(User* U){
  user_[U->getName()] = U;
}

std::vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type){
  vector<Product*> search_;
  set<Product*> match;
  // Empty search bar
  if (terms.size() == 0){
    return search_;
  }
  
  map<string, set<Product*>>::iterator found;
  found = keys_.find(terms[0]);
  if (found != keys_.end()){
    match = found->second;
  }

  for (size_t i = 1; i < terms.size(); i++){
    found = keys_.find(terms[i]);
    set<Product*> curr_;
    if (found != keys_.end()){
      curr_ = found->second;
    }
    // AND Keyword
    if(type == 0){
      match = setUnion(match, curr_);
    }
    // OR Keyword
    if(type == 1){
      match = setIntersection(match, curr_);
    }
  }
  set<Product*>::iterator it;
  for(it = match.begin(); it != match.end(); it++){
    search_.push_back(*it);
  }
  return search_;
}

void MyDataStore::dump(std::ostream& ofile){
  vector<Product*>::iterator prd;
  map<string,User*>::iterator usr;
  for (prd = product_.begin(); prd != product_.end(); prd++){
    (*prd)->dump(ofile);
  }
  for (usr = user_.begin(); usr != user_.end(); usr++){
    usr->second->dump(ofile);
  }
}