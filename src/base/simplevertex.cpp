#include "base/simplevertex.h"

namespace sg {

//======================================================================================================================
SimpleVertex::SimpleVertex(TVertexID id, const char * name, TWeight weight) : mId(id), mName(std::string(name)), mWeight(weight) {
}

//======================================================================================================================
SimpleVertex::SimpleVertex(TVertexID id, const std::string & name, TWeight weight) : mId(id), mName(name), mWeight(weight) {
}

//======================================================================================================================
SimpleVertex::SimpleVertex(const SimpleVertex & other) : mId(other.mId), mName(other.mName), mWeight(other.mWeight) {
}

//======================================================================================================================
SimpleVertex::SimpleVertex(SimpleVertex && other): mId(other.mId), mName(other.mName), mWeight(other.mWeight) {
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
    out << " }";
}

//======================================================================================================================
void SimpleVertex::swap(SimpleVertex & rhs) throw() {
    std::swap(mId, rhs.mId);
    std::swap(mName, rhs.mName);
    std::swap(mWeight, rhs.mWeight);
}

//======================================================================================================================
bool operator == (const SimpleVertex & lhs, const SimpleVertex & rhs) {
    if (lhs.id() != rhs.id())  {
        return false;
    }
    if (lhs.name() != rhs.name()) {
        return false;
    }
    if (lhs.weight() != rhs.weight()) {
        return false;
    }
    return true;
}

//======================================================================================================================
bool operator != (const SimpleVertex & lhs, const SimpleVertex & rhs) {
    return !(lhs == rhs);
}

}
