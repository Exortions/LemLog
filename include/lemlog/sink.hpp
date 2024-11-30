/**
 * @file sink.hpp
 * @author LemLib Team
 * @brief
 * @version 0.1
 * @date 2024-11-29
 *
 * @copyright Copyright (c) 2024
 *
 */
#pragma once

#include "lemlog/message.hpp"

namespace logger {
class Sink {
    public:
        Sink();

        virtual void write(const Message& message) = 0;
};
} // namespace logger