#ifndef CODE_C___SINGLEOWNERASSOCIATIONLINK_H
#define CODE_C___SINGLEOWNERASSOCIATIONLINK_H

#include <memory>
#include "AbstractAssociationLink.h"

template <class RoleX, class RoleY>
class SingleOwnerAssociationLink : public AbstractAssociationLink<RoleX, RoleY> {

private:
    std::weak_ptr<RoleX> roleX;

    std::shared_ptr<RoleY> roleY;

protected:
    const std::weak_ptr<RoleX> getRoleX() const;

    const std::weak_ptr<RoleY> getRoleY() const;

    void setRoleX(std::shared_ptr<RoleX> x);

    void setRoleY(std::shared_ptr<RoleY> y);

    virtual ~SingleOwnerAssociationLink() = 0;

public:
    SingleOwnerAssociationLink(std::shared_ptr<RoleX> x, std::shared_ptr<RoleY> y);

};

template<class RoleX, class RoleY>
const std::weak_ptr<RoleX> SingleOwnerAssociationLink<RoleX, RoleY>::getRoleX() const {
    return this->roleX;
}

template<class RoleX, class RoleY>
const std::weak_ptr<RoleY> SingleOwnerAssociationLink<RoleX, RoleY>::getRoleY() const {
    return this->roleY;
}

template<class RoleX, class RoleY>
void SingleOwnerAssociationLink<RoleX, RoleY>::setRoleX(std::shared_ptr<RoleX> x) {
    this->roleX = std::move(x);
}

template<class RoleX, class RoleY>
void SingleOwnerAssociationLink<RoleX, RoleY>::setRoleY(std::shared_ptr<RoleY> y) {
    this->roleY = std::move(y);
}

template<class RoleX, class RoleY>
SingleOwnerAssociationLink<RoleX, RoleY>::SingleOwnerAssociationLink(std::shared_ptr<RoleX> x, std::shared_ptr<RoleY> y)
        : AbstractAssociationLink<RoleX, RoleY>(), roleX(std::move(x)), roleY(std::move(y)) { }

template<class RoleX, class RoleY>
SingleOwnerAssociationLink<RoleX, RoleY>::~SingleOwnerAssociationLink() = default;


#endif //CODE_C___SINGLEOWNERASSOCIATIONLINK_H
