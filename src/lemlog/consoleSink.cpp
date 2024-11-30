#include "lemlog/consoleSink.hpp"

#include <iostream>

logger::ConsoleSink::ConsoleSink() { logger::registerSink(std::make_shared<ConsoleSink>(this), {}); }

void logger::ConsoleSink::write(const Message& message) {
    std::cout << logLevelStrings.at(message.level) << " " << message.formattedMessage << std::endl;
}