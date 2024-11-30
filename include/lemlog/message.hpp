/**
 * @file message.hpp
 * @author LemLib Team
 * @brief
 * @version 0.1
 * @date 2024-11-29
 *
 * @copyright Copyright (c) 2024
 *
 */
#pragma once

#include "lemlog/level.hpp"
#include "pros/rtos.hpp"
#include "fmt/core.h"
#include <string>

namespace logger {
/**
 * @brief Class representing a log message
 *
 */
class Message {
    public:
        std::string formattedMessage;
        LogLevel level;
        double time;

        /**
         * @brief Construct a Message
         *
         * @param level level the message is at
         * @param format the pre-formatted message
         * @param args the arguments to format the message with
         */
        template <typename... Args> Message(LogLevel level, std::string& format, Args&&... args)
            : level(level),
              formattedMessage(fmt::format(format, std::forward<Args>(args)...)),
              time(pros::millis()) {}
};
} // namespace lemlog