#ifndef simpleedgeH
#define simpleedgeH

#include "base/simplegraphtypes.h"
#include "base/simplevertex.h"
#include <string>
#include <utility>

namespace sg {

class SimpleEdge {
public:
    SimpleEdge(TEdgeID id, const SimpleVertex & v1, const SimpleVertex & v2, TWeight weight = 0, TFlag flag = 0x00);
    SimpleEdge(const SimpleEdge & other);
    SimpleEdge(SimpleEdge && other);
    ~SimpleEdge();
    const TEdgeID id() const { return mId; }
    const SimpleVertex & end1() const { return mEnd1; }
    const SimpleVertex & end2() const { return mEnd2; }
    const TWeight weight() const { return mWeight; }
    const TFlag flag() const { return mFlag; }
    void set_weight(TWeight weight) { mWeight = weight; }
    void set_flag(TFlag flag) { mFlag = flag; }
    void print(std::ostringstream & out);
    void swap(SimpleEdge & rhs) throw(); 
private:
    void validate();
    TEdgeID mId;
    SimpleVertex mEnd1;
    SimpleVertex mEnd2;
    TWeight mWeight;
    TFlag mFlag;
};

bool operator == (const SimpleEdge & lhs, const SimpleEdge & rhs);
bool operator != (const SimpleEdge & lhs, const SimpleEdge & rhs);

}
#endif
