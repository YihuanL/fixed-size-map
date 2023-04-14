/*
 * @Author: liuyihuan 
 * @Date: 2023-03-08
 * @LastEditors: liuyihuan 
 * @FilePath: 
 * @Description: fifo-fixed-size map
 */
#include <vector>
#include <unordered_map>
#include <iostream>
#include <queue>
template<typename Key, typename U, std::size_t capacity>
class fixed_size_unordered_map {
    using iterator = typename std::unordered_map<Key, U>::iterator;
    using size_type = typename std::unordered_map<Key, U>::size_type;
    using value_type = typename std::unordered_map<Key, U>::value_type;
    using const_iterator = typename std::unordered_map<Key, U>::const_iterator;
public:
    fixed_size_unordered_map() { }
    fixed_size_unordered_map(const fixed_size_unordered_map&) = default;
    fixed_size_unordered_map& operator=(const fixed_size_unordered_map&) = default;
    fixed_size_unordered_map(fixed_size_unordered_map&&) = default;
    fixed_size_unordered_map& operator=(fixed_size_unordered_map&&) = default;
    fixed_size_unordered_map(std::initializer_list<value_type> init){
        for(auto x:init){
            insert(x);
        }
    }
    iterator find(const Key &key)
    {
        return items.find(key);
    }
    size_type count(const Key &key) const
    {
        return items.count(key);
    }

    const U &at(const Key &key) const
    {
        return items.at(key);
    }

    std::pair<iterator, bool> insert(const value_type &v) {

        while(iter_queue.size()>=capacity){
            auto old=iter_queue.front();
            //std::cout<<"old: "<<old->first<<" "<old->second;
            iterator it=items.find(old);
            if (it!=items.end()){
                items.erase(it);
            }
            iter_queue.pop();
        }
        const auto ret = items.insert(v);
        if(ret.second){
            iter_queue.push(ret.first->first);
        }
        return ret;
    }

    iterator begin() noexcept
    {
        return items.begin();
    }

    /// returns an iterator to the end
    iterator end() noexcept
    {
        return items.end();
    }

    /// returns an iterator to the beginning
    const_iterator begin() const noexcept
    {
        return items.begin();
    }

    /// returns an iterator to the end
    const_iterator end() const noexcept
    {
        return items.end();
    }

    /// returns an iterator to the beginning
    const_iterator cbegin() const noexcept
    {
        return items.cbegin();
    }

    /// returns an iterator to the end
    const_iterator cend() const noexcept
    {
        return items.cend();
    }

protected:
    std::unordered_map<Key, U> items;
    std::queue<Key> iter_queue;
};