#include "lemlog/logger.hpp"

void logger::Logger::registerSink(std::shared_ptr<Sink> sink, std::initializer_list<LogLevel> blacklist) {
    // add all levels not in the blacklist
    for (auto level : ALL) {
        if (std::find(blacklist.begin(), blacklist.end(), level) == blacklist.end())
            levelToSinks[level].push_back(sink);
    }
}

template <typename... Args> void logger::Logger::log(LogLevel level, const std::string& format, Args&&... args) {
    Message message(level, format, std::forward<Args>(args)...);

    if (levelToSinks.find(level) == levelToSinks.end()) return;

    for (auto sink : levelToSinks[level]) sink->write(message);
}

template <typename... Args> void logger::Logger::telemetry(const std::string& format, Args&&... args) {
    log(LogLevel::TELEMETRY, format, std::forward<Args>(args)...);
}

template <typename... Args> void logger::Logger::debug(const std::string& format, Args&&... args) {
    log(LogLevel::DEBUG, format, std::forward<Args>(args)...);
}

template <typename... Args> void logger::Logger::info(const std::string& format, Args&&... args) {
    log(LogLevel::INFO, format, std::forward<Args>(args)...);
}

template <typename... Args> void logger::Logger::warning(const std::string& format, Args&&... args) {
    log(LogLevel::WARNING, format, std::forward<Args>(args)...);
}

template <typename... Args> void logger::Logger::error(const std::string& format, Args&&... args) {
    log(LogLevel::ERROR, format, std::forward<Args>(args)...);
}

template <typename... Args> void logger::Logger::fatal(const std::string& format, Args&&... args) {
    log(LogLevel::FATAL, format, std::forward<Args>(args)...);
}