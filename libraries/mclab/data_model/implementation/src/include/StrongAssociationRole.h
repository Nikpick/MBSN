#ifndef CODE_C___STRONGASSOCIATIONROLE_H
#define CODE_C___STRONGASSOCIATIONROLE_H

#include <unordered_set>
#include "AbstractAssociationRole.h"


template <class LinkType, const unsigned int MIN, const unsigned int MAX>
class StrongAssociationRole : public AbstractAssociationRole<LinkType, MIN, MAX> {

private:
    std::unordered_set<std::shared_ptr<LinkType>> assocLinks;

    typedef typename std::unordered_set<std::shared_ptr<LinkType>>::const_iterator constIterator;

protected:
    void insert(std::shared_ptr<LinkType> link);

    void remove(std::shared_ptr<LinkType> link);

    constIterator cendLinks() const;

    constIterator cbeginLinks() const;

    virtual ~StrongAssociationRole() = 0;

    StrongAssociationRole() = default;

public:
    [[nodiscard]] unsigned int countLinks() const;

};

template <class LinkType, const unsigned int MIN, const unsigned int MAX>
void StrongAssociationRole<LinkType, MIN, MAX>::insert(std::shared_ptr<LinkType> link) {
    this->assocLinks.insert(std::move(link));
}

template <class LinkType, const unsigned int MIN, const unsigned int MAX>
void StrongAssociationRole<LinkType, MIN, MAX>::remove(std::shared_ptr<LinkType> link) {
    for (auto itr = this->cbeginLinks(); itr != this->cendLinks(); itr++) {
        if (link.get() == (*itr).get()) {
            this->assocLinks.erase(itr);
            break;
        }
    }
}

template <class LinkType, const unsigned int MIN, const unsigned int MAX>
typename StrongAssociationRole<LinkType, MIN, MAX>::constIterator StrongAssociationRole<LinkType, MIN, MAX>::cendLinks() const {
    return this->assocLinks.cend();
}

template <class LinkType, const unsigned int MIN, const unsigned int MAX>
typename StrongAssociationRole<LinkType, MIN, MAX>::constIterator StrongAssociationRole<LinkType, MIN, MAX>::cbeginLinks() const {
    return this->assocLinks.cbegin();
}

template <class LinkType, const unsigned int MIN, const unsigned int MAX>
StrongAssociationRole<LinkType, MIN, MAX>::~StrongAssociationRole() = default;

template <class LinkType, const unsigned int MIN, const unsigned int MAX>
unsigned int StrongAssociationRole<LinkType, MIN, MAX>::countLinks() const {
    return this->assocLinks.size();
}

#endif //CODE_C___STRONGASSOCIATIONROLE_H
