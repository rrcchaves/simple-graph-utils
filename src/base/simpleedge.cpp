#include "base/simpleedge.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <stdexcept>
	
namespace sg {

//======================================================================================================================
SimpleEdge::SimpleEdge(TEdgeID id, const SimpleVertex & v1, const SimpleVertex & v2, TWeight weight, TFlag flag) : mId(id), mEnd1(v1), mEnd2(v2), mWeight(weight), mFlag(flag) {
    validate();
}

//======================================================================================================================
SimpleEdge::SimpleEdge(const SimpleEdge & other) : mId(other.mId), mEnd1(other.mEnd1), mEnd2(other.mEnd2), mWeight(other.mWeight), mFlag(other.mFlag) {
    validate();
}

//======================================================================================================================
SimpleEdge::SimpleEdge(SimpleEdge && other) : mId(other.mId), mEnd1(other.mEnd1), mEnd2(other.mEnd2), mWeight(other.mWeight), mFlag(other.mFlag) {
    validate();
}

//======================================================================================================================
SimpleEdge::~SimpleEdge() {
}

//======================================================================================================================
void SimpleEdge::print(std::ostringstream & out) {
    out << "{ ";
    out << "id: " << mId;
    out << ", ";
    out << "end1: ";
    mEnd1.print(out);
    out << ", ";
    out << "end2: ";
    mEnd2.print(out);
    out << ", ";
    out << "weight: " << mWeight;
    out << ", ";
    out << "flag: 0x" << std::setfill('0') << std::setw(2) << std::hex << (int)mFlag;
    out << " }";
}

//======================================================================================================================
void SimpleEdge::swap(SimpleEdge & rhs) throw() {
    std::swap(mId, rhs.mId);
    mEnd1.swap(rhs.mEnd1);
    mEnd2.swap(rhs.mEnd2);
    std::swap(mWeight, rhs.mWeight);
    std::swap(mFlag, rhs.mFlag);
}

//======================================================================================================================
void SimpleEdge::validate() {
    if (mEnd1 == mEnd2) {
        throw std::logic_error("SimpleEdge: edge with same ends is not allowed.");
    }
}

//======================================================================================================================
bool operator == (const SimpleEdge & lhs, const SimpleEdge & rhs) {
    //if (lhs.id() != rhs.id()) {
    //    return false;
    //}
    if (lhs.end1() != rhs.end1() && lhs.end1() != rhs.end2()) {
        return false;
    }
    if (lhs.end2() != rhs.end2() && lhs.end2() != rhs.end1()) {
        return false;
    }
    if (lhs.weight() != rhs.weight()) {
        return false;
    }
    if (lhs.flag() != rhs.flag()) {
        return false;
    }
    return true;
}

//======================================================================================================================
bool operator != (const SimpleEdge & lhs, const SimpleEdge & rhs) {
    return !(lhs == rhs);
}

}
