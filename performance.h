//
// Created by Tom Fewster on 13/03/2016.
//

#ifndef FASTPATH_PERFORMANCE_H
#define FASTPATH_PERFORMANCE_H

#include <chrono>
#include <utility>

namespace tf {
    template<typename T = std::chrono::milliseconds>
    struct measure {
        template<typename F, typename ...Args>
        static T execution(F &&func, Args &&... args) {
            auto start = std::chrono::system_clock::now();
            std::forward<decltype(func)>(func)(std::forward<Args>(args)...);
            auto duration = std::chrono::duration_cast<T>(std::chrono::system_clock::now() - start);
            return duration;
        }
    };
}

#endif //FASTPATH_PERFORMANCE_H
