#ifndef ORDEREDSET_H
#define ORDEREDSET_H

#include <unordered_set>
#include <vector>
#include "ArrayIndexOutOfBoundsException.h"

template <class ContentType>
class OrderedSet {

private:
    std::unordered_set<ContentType> elements;

    std::vector<ContentType> order;

public:
    void insert(const ContentType& c) {
        if (!this->contains(c)) {
            this->elements.insert(c);
            this->order.push_back(c);
        }
    }

    void insert(const ContentType&& c) {
        if (!this->contains(c)) {
            this->elements.insert(std::move(c));
            this->order.push_back(std::move(c));
        }
    }

    void insert(const ContentType& c, const unsigned int index) {
        if (index >= this->order.size()) throw ArrayIndexOutOfBoundsException();
        if (!this->contains(c)) {
            this->elements.insert(c);
            this->order.insert(index, c);
        }
    }

    void remove(const ContentType& c) {
        if (this->contains(c)) {
            this->elements.erase(c);
            unsigned int i;
            for (i = 0; i < this->order.size(); i++) {
                if (this->order.at(i) == c) break;
            }
            this->order.erase(i);
        }
    }

    void remove(const unsigned int index) {
        if (index >= this->order.size()) throw ArrayIndexOutOfBoundsException();
        ContentType c = this->order.at(index);
        this->order.erase(this->order.begin() + index);
        this->elements.erase(c);
    }

    bool contains(const ContentType& c) const {
        return this->elements.find(c) != this->elements.end();
    }

    ContentType get(const unsigned int index) const {
        if (index >= this->order.size()) throw ArrayIndexOutOfBoundsException();
        return this->order.at(index);
    }

    bool isEmpty() const {
        return this->elements.size() == 0;
    }

    unsigned int size() const {
        return this->elements.size();
    }

    /*std::vector<ContentType>::iterator begin() {
        return this->order.begin();
    }

    std::vector<ContentType*>::iterator end() {
        return this->order.end();
    }*/

    OrderedSet() = default;

};
    

#endif /* ORDEREDSET_H */

