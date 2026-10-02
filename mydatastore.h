#ifndef MYDATASTORE_H
#define MYDATASTORE_H
#include <string>
#include <set>
#include <vector>
#include <map>
#include "datastore.h"

class MyDataStore : public DataStore{
  public:
    MyDataStore();
    virtual ~MyDataStore();

    virtual void addProduct(Product* P);
    virtual void addUser(User* u);
    virtual std::vector<Product*> search(std::vector<std::string>& terms, int type);
    virtual void dump(std::ostream& ofile);
    bool addtoCart(std::string u, Product* P);
    bool viewCart(std::string u, ostream& infile);
    bool buyProduct(std::string u);
  
  private:
    std::vector<Product*> product_;
    std::map<std::string, User*> user_;
    std::map<std::string, std::set<Product*>> keys_;
    std::map<std::string, std::vector<Product*> > cart_;
    

};
#endif