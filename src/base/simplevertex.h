#ifndef simplevertexH
#define simplevertexH

#include "base/simplegraphtypes.h"
#include <string>
#include <utility>
#include <iostream>
#include <sstream>

namespace sg {

class SimpleVertex {
public:
    SimpleVertex(TVertexID id, const char * name, TWeight weight = 0);
    SimpleVertex(TVertexID id, const std::string & name, TWeight weight = 0);
    SimpleVertex(const SimpleVertex & other);
    SimpleVertex(SimpleVertex && other);
    ~SimpleVertex();
    const TVertexID id() const { return mId; }
    const std::string & name() const { return mName; }
    const TWeight weight() const { return mWeight; }
    void set_weight(TWeight weight) { mWeight = weight; }
    void print(std::ostringstream & out);
    void swap(SimpleVertex & rhs) throw(); 
private:
    TVertexID mId;
    std::string mName;
    TWeight mWeight;
};

bool operator == (const SimpleVertex & lhs, const SimpleVertex & rhs);
bool operator != (const SimpleVertex & lhs, const SimpleVertex & rhs);

}

#endif
