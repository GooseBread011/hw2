#ifndef MYDATASTORE_H
#define MYDATASTORE_H
#include <string>
#include <set>
#include <vector>
#include "database.h"

class MyDataStore : public Datastore(){
  public:
    MyDataStore();
    virtual ~DataStore();

    virtual void addProduct(Product* P);
    virtual void addUser(User* u);
    virtual std::vector<Product*> search(std::vector<std::string>& terms, int type);
    virtual void dump(std::ostream& ofile);
  
  private:
    

};
#endif