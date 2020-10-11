#ifndef CODE_C___ORDEREDASSOCIATIONROLE_H
#define CODE_C___ORDEREDASSOCIATIONROLE_H

#include "AbstractAssociationRole.h"
#include "OrderedSet.h"


template <class LinkType, const unsigned int MIN, const unsigned int MAX>
class OrderedAssociationRole : public AbstractAssociationRole<LinkType, MIN, MAX> {

private:
    OrderedSet<std::shared_ptr<LinkType>> assocLinks;

protected:
    void insert(std::shared_ptr<LinkType> link);

    void remove(std::shared_ptr<LinkType> link);

    const std::weak_ptr<LinkType> getLink(unsigned int pos) const;

    virtual ~OrderedAssociationRole() = 0;

    OrderedAssociationRole() = default;

public:
    [[nodiscard]] unsigned int countLinks() const;

};

template <class LinkType, const unsigned int MIN, const unsigned int MAX>
void OrderedAssociationRole<LinkType, MIN, MAX>::insert(std::shared_ptr<LinkType> link) {
    this->assocLinks.insert(std::move(link));
}

template<class LinkType, const unsigned int MIN, const unsigned int MAX>
const std::weak_ptr<LinkType> OrderedAssociationRole<LinkType, MIN, MAX>::getLink(unsigned int pos) const {
    return this->assocLinks.get(pos);
}

template<class LinkType, const unsigned int MIN, const unsigned int MAX>
unsigned int OrderedAssociationRole<LinkType, MIN, MAX>::countLinks() const {
    return this->assocLinks.size();
}

template<class LinkType, const unsigned int MIN, const unsigned int MAX>
void OrderedAssociationRole<LinkType, MIN, MAX>::remove(std::shared_ptr<LinkType> link) {
    for (unsigned int i = 0; i < this->countLinks(); i++) {
        if (this->getLink(i).lock().get() == link.get()){
            this->assocLinks.remove(i);
            break;
        }
    }
}

template<class LinkType, const unsigned int MIN, const unsigned int MAX>
OrderedAssociationRole<LinkType, MIN, MAX>::~OrderedAssociationRole() = default;


#endif //CODE_C___ORDEREDASSOCIATIONROLE_H
