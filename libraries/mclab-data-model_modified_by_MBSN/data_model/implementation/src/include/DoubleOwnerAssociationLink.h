#ifndef CODE_C___DOUBLEOWNERASSOCIATIONLINK_H
#define CODE_C___DOUBLEOWNERASSOCIATIONLINK_H

#include <memory>
#include "AbstractAssociationLink.h"

template <class RoleX, class RoleY>
class DoubleOwnerAssociationLink : public AbstractAssociationLink<RoleX, RoleY> {

private:
    std::weak_ptr<RoleX> roleX;

    std::weak_ptr<RoleY> roleY;

protected:
    const std::weak_ptr<RoleX> getRoleX() const;

    const std::weak_ptr<RoleY> getRoleY() const;

    void setRoleX(std::shared_ptr<RoleX> x);

    void setRoleY(std::shared_ptr<RoleY> y);

    virtual ~DoubleOwnerAssociationLink() = 0;

public:
    DoubleOwnerAssociationLink(std::shared_ptr<RoleX> x, std::shared_ptr<RoleY> y);

};

template<class RoleX, class RoleY>
const std::weak_ptr<RoleX> DoubleOwnerAssociationLink<RoleX, RoleY>::getRoleX() const {
    return this->roleX;
}

template<class RoleX, class RoleY>
const std::weak_ptr<RoleY> DoubleOwnerAssociationLink<RoleX, RoleY>::getRoleY() const {
    return this->roleY;
}

template<class RoleX, class RoleY>
void DoubleOwnerAssociationLink<RoleX, RoleY>::setRoleX(std::shared_ptr<RoleX> x) {
    this->roleX = std::move(x);
}

template<class RoleX, class RoleY>
void DoubleOwnerAssociationLink<RoleX, RoleY>::setRoleY(std::shared_ptr<RoleY> y) {
    this->roleY = std::move(y);
}

template<class RoleX, class RoleY>
DoubleOwnerAssociationLink<RoleX, RoleY>::DoubleOwnerAssociationLink(std::shared_ptr<RoleX> x, std::shared_ptr<RoleY> y)
    : AbstractAssociationLink<RoleX, RoleY>(), roleX(std::move(x)), roleY(std::move(y)) { }

template<class RoleX, class RoleY>
DoubleOwnerAssociationLink<RoleX, RoleY>::~DoubleOwnerAssociationLink() = default;


#endif //CODE_C___DOUBLEOWNERASSOCIATIONLINK_H
