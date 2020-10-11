#ifndef CODE_C___WEAKASSOCIATIONROLE_H
#define CODE_C___WEAKASSOCIATIONROLE_H

#include <set>
#include "AbstractAssociationRole.h"

template <class LinkType, const unsigned int MIN, const unsigned int MAX>
class WeakAssociationRole : public AbstractAssociationRole<LinkType, MIN, MAX> {

private:
    typedef typename std::set<std::weak_ptr<LinkType>, std::owner_less<std::weak_ptr<LinkType>>>::const_iterator constIterator;

    std::set<std::weak_ptr<LinkType>, std::owner_less<std::weak_ptr<LinkType>>> assocLinks;

protected:
    void insert(std::shared_ptr<LinkType> link);

    void remove(std::shared_ptr<LinkType> link);

    constIterator cendLinks() const;

    constIterator cbeginLinks() const;

    virtual ~WeakAssociationRole() = 0;

    WeakAssociationRole() = default;

public:
    [[nodiscard]] unsigned int countLinks() const;

};

template <class LinkType, const unsigned int MIN, const unsigned int MAX>
void WeakAssociationRole<LinkType, MIN, MAX>::insert(std::shared_ptr<LinkType> link) {
    this->assocLinks.insert(std::move(link));
}

template <class LinkType, const unsigned int MIN, const unsigned int MAX>
void WeakAssociationRole<LinkType, MIN, MAX>::remove(std::shared_ptr<LinkType> link) {
    for (auto itr = this->cbeginLinks(); itr != this->cendLinks(); itr++) {
        if (link.get() == (*itr).lock().get()) {
            this->assocLinks.erase(itr);
            break;
        }
    }
}

template <class LinkType, const unsigned int MIN, const unsigned int MAX>
typename WeakAssociationRole<LinkType, MIN, MAX>::constIterator WeakAssociationRole<LinkType, MIN, MAX>::cendLinks() const {
    return this->assocLinks.cend();
}

template <class LinkType, const unsigned int MIN, const unsigned int MAX>
typename WeakAssociationRole<LinkType, MIN, MAX>::constIterator WeakAssociationRole<LinkType, MIN, MAX>::cbeginLinks() const {
    return this->assocLinks.cbegin();
}

template <class LinkType, const unsigned int MIN, const unsigned int MAX>
WeakAssociationRole<LinkType, MIN, MAX>::~WeakAssociationRole() = default;

template <class LinkType, const unsigned int MIN, const unsigned int MAX>
unsigned int WeakAssociationRole<LinkType, MIN, MAX>::countLinks() const {
    return this->assocLinks.size();
}

#endif //CODE_C___WEAKASSOCIATIONROLE_H
