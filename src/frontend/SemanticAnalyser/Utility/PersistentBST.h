#ifndef COBALT_SRC_FRONTEND_SEMANTICANALYSER_AST_UTILITY_PERSISTENTBST_H_
#define COBALT_SRC_FRONTEND_SEMANTICANALYSER_AST_UTILITY_PERSISTENTBST_H_

#include <cstddef>
#include <list>
#include <memory>
#include <random>
#include <tuple>
#include <utility>

namespace Cobalt::util {
/**
 * \brief Persistent BST. FHQ Treap
 */
template <typename Key, typename Value, typename Comp = std::less<Key>, typename Alloc = std::allocator<std::pair<Key, Value>>>
class PersistentMap {
public:
    using ValueType = Value;
    using KeyType = Key;
    using AllocatorType = Alloc;
    PersistentMap()
        : alloc_(std::allocator<Node>())
    {
    }
    explicit PersistentMap(const Alloc alloc)
        : alloc_(alloc)
    {
    }
    void insert(const Key& key, const Value& value)
    {
        auto tmp = split(current_, key);
    }

private:
    struct Node;
    using NodePtr = std::shared_ptr<Node>;
    struct Node {
        NodePtr lson, rson;
        std::size_t size, prior;
        KeyType key;
        ValueType val;
    };
    std::list<NodePtr, AllocatorType> roots_;
    typename std::list<NodePtr, AllocatorType>::iterator current_;
    Alloc alloc_;
    void pushup(NodePtr p)
    {
        p->size = p->lson->size + p->rson->size + 1;
    }
    std::pair<NodePtr, NodePtr> split_without_eq(NodePtr ptr, const Key& value)
    {
        if (ptr == nullptr)
            return { nullptr, nullptr };
        std::pair<NodePtr, NodePtr> tmp;
        auto new_node = std::allocate_shared<Node>(alloc_, &ptr);
        if (Comp {}(new_node->data, value)) {
            tmp = split_without_eq(new_node->rson, value);
            new_node->rson = tmp.first;
            pushup(new_node);
            return { new_node, tmp.second };
        } else {
            tmp = split_without_eq(new_node->lson, value);
            new_node->lson = tmp.second;
            pushup(new_node);
            return { tmp.first, new_node };
        }
    }
    std::pair<NodePtr, NodePtr> split_eq(NodePtr ptr, const Key& value)
    {
        if (ptr == nullptr)
            return { nullptr, nullptr };
        std::pair<NodePtr, NodePtr> tmp;
        auto new_node = std::allocate_shared<Node>(alloc_, &ptr);
        if (Comp {}(new_node->data, value) || new_node->data == value) {
            tmp = split_eq(new_node->rson, value);
            new_node->rson = tmp.first;
            pushup(new_node);
            return { new_node, tmp.second };
        } else {
            tmp = split_eq(new_node->lson, value);
            new_node->lson = tmp.second;
            pushup(new_node);
            return { tmp.first, new_node };
        }
    }
    std::tuple<NodePtr, NodePtr, NodePtr> split(NodePtr ptr, const Key& value)
    {
        if (ptr == nullptr)
            return { nullptr, nullptr };
        std::tuple<NodePtr, NodePtr, NodePtr> tmp;
        auto new_node = std::allocate_shared<Node>(alloc_, &ptr);
        if (Comp {}(new_node->data, value)) {
            tmp = split(new_node->rson, value);
            new_node->rson = std::get<0>(tmp);
            pushup(new_node);
            return { new_node, std::get<1>(tmp), std::get<2>(tmp) };
        } else if (new_node->data == value) {
            auto res = { new_node->lson, new_node, new_node->rson };
            new_node->lson = new_node->rson = nullptr;
            return res;
        } else {
            tmp = split(new_node->lson, value);
            new_node->lson = tmp.second;
            pushup(new_node);
            return { tmp.first, new_node };
        }
    }
    NodePtr merge(NodePtr u, NodePtr v)
    {
        if (u == nullptr && v == nullptr)
            return nullptr;
        if (u == nullptr)
            return v;
        if (v == nullptr)
            return u;
        if (u->prior <= v->prior) {
            u->rson = merge(u->rson, v);
            pushup(u);
            return u;
        } else {
            v->lson = merge(u, v->lson);
            pushup(v);
            return v;
        }
    }
    auto random()
    {
        static std::random_device rd;
        static std::mt19937_64 mt(rd());
        static std::uniform_int_distribution<std::size_t> dist;
        return dist(mt);
    }
};

}

#endif