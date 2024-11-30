#include "lemlog/logger.hpp"

#include <map>

namespace logger {
class ConsoleSink : public Sink {
    public:
        ConsoleSink();

        void write(const Message& message) override;
    private:
        const std::map<LogLevel, std::string> logLevelStrings = {
            {LogLevel::TELEMETRY, "\033[1;36m[TELEMETRY]\033[0m"}, {LogLevel::DEBUG, "\033[1;32m[DEBUG]\033[0m"},
            {LogLevel::INFO, "\033[1;34m[INFO]\033[0m"},           {LogLevel::WARNING, "\033[1;33m[WARNING]\033[0m"},
            {LogLevel::ERROR, "\033[1;31m[ERROR]\033[0m"},         {LogLevel::FATAL, "\033[1;31m[FATAL]\033[0m"}};
};
} // namespace logger