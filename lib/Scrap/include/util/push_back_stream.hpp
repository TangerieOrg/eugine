#pragma once
#include <utility>
#include <functional>
#include <vector>
#include <stack>

#define IS_NEWLINE(c) ((c) == '\n' || (c) == '\r')


using get_character = std::function<int()>;


namespace Scrap {

class PushBackStream {
private:
    const get_character& _input;
    std::stack<int> _stack;
    size_t _line_number;
    size_t _char_index;
    
public:
    PushBackStream(const get_character& input) : _input(input), _line_number(0), _char_index(0) {}

    int operator()() {
        int ret = -1;

        if(_stack.empty()) {
            ret = _input();
        } else {
            ret = _stack.top();
            _stack.pop();
        }

        if(IS_NEWLINE(ret)) {
            _line_number++;
        }

        return ret;
    }

    void push_back(int c) {
        _stack.push(c);

        if(IS_NEWLINE(c)) {
            _line_number--;
        }

        _char_index--;
    }

    size_t line_number() const {
        return _line_number;
    }
    size_t char_index() const {
        return _char_index;
    }
};

} // namespace Scrap