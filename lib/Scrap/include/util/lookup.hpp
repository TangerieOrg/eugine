#pragma once
#include <utility>
#include <vector>

namespace Scrap {

template <typename TKey, typename TValue>
class Lookup {
    // Type Aliases
    using value_type = std::pair<TKey, TValue>;
    using container_type = std::vector<value_type>;

private:
    container_type _container;

public:
    using iterator = typename container_type::const_iterator;
    using const_iterator = iterator;

    Lookup(std::initializer_list<value_type> init) : _container(init) {
        std::sort(_container.begin(), _container.end());
    }

    const_iterator begin() const {
        return _container.begin();
    }

    const_iterator end() const {
        return _container.end();
    }

    template <typename K>
    const_iterator find(const K& key) const {
        const_iterator iter = std::lower_bound(
            begin(),
            end(),
            key,
            [](cosnt value_type& p, const K& key) {
                return p.first < key;
            }
        );

        return iter != end() && iter->first == key ? iter : end();
    }

    size_t size() const {
        return _container.size();
    }
};

} // namespace Scrap