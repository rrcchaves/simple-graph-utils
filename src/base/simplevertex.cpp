#include "base/simplevertex.h"
#include <iomanip>

namespace sg {

//======================================================================================================================
SimpleVertex::SimpleVertex(TVertexID id, const char * name, TWeight weight, TFlag flag) : mId(id), mName(std::string(name)), mWeight(weight), mFlag(flag) {
}

//======================================================================================================================
SimpleVertex::SimpleVertex(TVertexID id, const std::string & name, TWeight weight, TFlag flag) : mId(id), mName(name), mWeight(weight), mFlag(flag) {
}

//======================================================================================================================
SimpleVertex::SimpleVertex(const SimpleVertex & other) : mId(other.mId), mName(other.mName), mWeight(other.mWeight), mFlag(other.mFlag) {
}

//======================================================================================================================
SimpleVertex::SimpleVertex(SimpleVertex && other): mId(other.mId), mName(other.mName), mWeight(other.mWeight), mFlag(other.mFlag) {
}

//======================================================================================================================
SimpleVertex::~SimpleVertex() {
}

//======================================================================================================================
void SimpleVertex::print(std::ostringstream & out) {
    out << "{ ";
    out << "id: " << mId;
    out << ", ";
    out << "name: \"" << mName << "\"";
    out << ", ";
    out << "weight: " << mWeight;
    out << ", ";
    out << "flag: 0x" << std::setfill('0') << std::setw(2) << std::hex << (int)mFlag;
    out << " }";
}

//======================================================================================================================
void SimpleVertex::swap(SimpleVertex & rhs) throw() {
    std::swap(mId, rhs.mId);
    std::swap(mName, rhs.mName);
    std::swap(mWeight, rhs.mWeight);
    std::swap(mFlag, rhs.mFlag);
}

//======================================================================================================================
bool operator == (const SimpleVertex & lhs, const SimpleVertex & rhs) {
    //if (lhs.id() != rhs.id())  {
    //    return false;
    //}
    if (lhs.name() != rhs.name()) {
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
bool operator != (const SimpleVertex & lhs, const SimpleVertex & rhs) {
    return !(lhs == rhs);
}

}
