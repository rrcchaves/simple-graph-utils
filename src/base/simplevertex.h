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
    SimpleVertex(TVertexID id, const char * name, TWeight weight = 0, TFlag flag = 0x00);
    SimpleVertex(TVertexID id, const std::string & name, TWeight weight = 0, TFlag flag = 0x00);
    SimpleVertex(const SimpleVertex & other);
    SimpleVertex(SimpleVertex && other);
    ~SimpleVertex();
    const TVertexID id() const { return mId; }
    const std::string & name() const { return mName; }
    const TWeight weight() const { return mWeight; }
    const TFlag flag() const { return mFlag; }
    void set_weight(TWeight weight) { mWeight = weight; }
    void set_flag(TFlag flag) { mFlag = flag; }
    void print(std::ostringstream & out);
    void swap(SimpleVertex & rhs) throw(); 
private:
    TVertexID mId;
    std::string mName;
    TWeight mWeight;
    TFlag mFlag;
};

bool operator == (const SimpleVertex & lhs, const SimpleVertex & rhs);
bool operator != (const SimpleVertex & lhs, const SimpleVertex & rhs);

}

#endif
