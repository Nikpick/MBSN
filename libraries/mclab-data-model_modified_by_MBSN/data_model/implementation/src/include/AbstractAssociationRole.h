#ifndef SMARTPTRTEST_ASSOCIATIONROLE_H
#define SMARTPTRTEST_ASSOCIATIONROLE_H

#include <vector>
#include <memory>
#include <type_traits>
#include <iostream>
#include <limits>
#include "MultiplicityConstraintException.h"

#define N std::numeric_limits<unsigned int>::max()

template <class LinkType, const unsigned int MIN, const unsigned int MAX>
class AbstractAssociationRole {

private:
    static_assert(MIN >= 0, "Minimum specified multiplicity must be greater than or equal to zero");
    static_assert(MIN <= MAX, "Minimum specified multiplicity must be lesser than maximum specified multiplicity");
    static_assert(MAX > 0, "Maximum specified multiplicity must be greater than zero");

protected:
    void addLink(std::shared_ptr<LinkType> link);

    void removeLink(std::shared_ptr<LinkType> link);

    virtual void insert(std::shared_ptr<LinkType> link) = 0;

    virtual void remove(std::shared_ptr<LinkType> link) = 0;

    virtual ~AbstractAssociationRole() = 0;

    AbstractAssociationRole() = default;

public:
    [[nodiscard]] virtual unsigned int countLinks() const = 0;

};

template <typename LinkType, const unsigned int MIN, const unsigned int MAX>
AbstractAssociationRole<LinkType, MIN, MAX>::~AbstractAssociationRole() = default;


template<typename LinkType, const unsigned int MIN, const unsigned int MAX>
void AbstractAssociationRole<LinkType, MIN, MAX>::addLink(std::shared_ptr<LinkType> link) {
    if (MAX < this->countLinks() + 1) {
        throw MultiplicityConstraintException();
    }
    this->insert(std::move(link));
}

template<class LinkType, const unsigned int MIN, const unsigned int MAX>
void AbstractAssociationRole<LinkType, MIN, MAX>::removeLink(std::shared_ptr<LinkType> link) {
    if (MIN > this->countLinks() - 1) {
        throw MultiplicityConstraintException();
    }
    this->remove(std::move(link));
}

#endif //SMARTPTRTEST_ASSOCIATIONROLE_H
