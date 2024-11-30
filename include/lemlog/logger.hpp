/**
 * @file logger.hpp
 * @author LemLib Team
 * @brief
 * @version 0.1
 * @date 2024-11-29
 *
 * @copyright Copyright (c) 2024
 *
 */
#pragma once

#include "lemlog/sink.hpp"
#include "lemlog/level.hpp"

#include <unordered_map>
#include <vector>

namespace logger {
class Logger {
    public:
        Logger()
            : levelToSinks() {}

        void registerSink(std::shared_ptr<Sink> sink, std::initializer_list<LogLevel> blacklist = {});

        template <typename... Args> void log(LogLevel level, const std::string& format, Args&&... args);

        template <typename... Args> void telemetry(const std::string& format, Args&&... args);
        template <typename... Args> void debug(const std::string& format, Args&&... args);
        template <typename... Args> void info(const std::string& format, Args&&... args);
        template <typename... Args> void warning(const std::string& format, Args&&... args);
        template <typename... Args> void error(const std::string& format, Args&&... args);
        template <typename... Args> void fatal(const std::string& format, Args&&... args);
    private:
        std::unordered_map<LogLevel, std::vector<std::shared_ptr<Sink>>> levelToSinks;
};

inline Logger logger;

inline void registerSink(std::shared_ptr<Sink> sink, std::initializer_list<LogLevel> blacklist = {}) {
    logger.registerSink(sink, blacklist);
}
} // namespace logger