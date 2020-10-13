#ifndef SMARTPTRTEST_ASSOCIATIONLINK_H
#define SMARTPTRTEST_ASSOCIATIONLINK_H

#include <memory>
#include <type_traits>
#include <iostream>

template <class RoleX, class RoleY>
class AbstractAssociationLink {

protected:
    virtual const std::weak_ptr<RoleX> getRoleX() const = 0;

    virtual const std::weak_ptr<RoleY> getRoleY() const = 0;

    virtual void setRoleX(std::shared_ptr<RoleX> x) = 0;

    virtual void setRoleY(std::shared_ptr<RoleY> y) = 0;

    virtual ~AbstractAssociationLink() = 0;

public:
    AbstractAssociationLink() = default;

};


template <class RoleX, class RoleY>
AbstractAssociationLink<RoleX, RoleY>::~AbstractAssociationLink() = default;



#endif //SMARTPTRTEST_ASSOCIATIONLINK_H
