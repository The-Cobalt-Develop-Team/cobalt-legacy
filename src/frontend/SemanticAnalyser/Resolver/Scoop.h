#ifndef COBALT_SRC_FRONTEND_SEMANTICANALYSER_AST_RESOLVER_SCOOP_H_
#define COBALT_SRC_FRONTEND_SEMANTICANALYSER_AST_RESOLVER_SCOOP_H_

#include <map>
#include <stdexcept>
#include <string_view>
#include <unordered_map>

namespace Cobalt {

namespace detail {
    template <typename T>
    struct hasNameMember {
        template <typename U>
        static constexpr bool check(decltype(&U::name)) { return true; }
        template <typename U>
        static constexpr bool check(...) { return false; }
        static constexpr bool value = check<T>(nullptr);
    };
}

template <typename T>
class Scoop {
public:
    using NodeType = T;
    static_assert(detail::hasNameMember<NodeType>::value, "NodeType must has a member with type std::string_view named \"name\"");
    void addDefinition(NodeType* node)
    {
        if (findDefinition(node->name) != nullptr)
            throw std::invalid_argument("Already have a node with the same name.");
        mp_.emplace(node->name, node);
    }
    NodeType* findDefinition(std::string_view name)
    {
        auto r = mp_.find(name);
        if (r == mp_.end())
            return nullptr;
        return r->second;
    }

private:
    std::unordered_map<std::string_view, NodeType*> mp_;
};

}

#endif