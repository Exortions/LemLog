/**
 * @file level.hpp
 * @author LemLib Team
 * @brief
 * @version 0.1
 * @date 2024-11-29
 *
 * @copyright Copyright (c) 2024
 *
 */
#pragma once

namespace logger {
/**
 * @brief Enum containing different log levels
 *
 */
enum class LogLevel { TELEMETRY, DEBUG, INFO, WARNING, ERROR, FATAL };

static const LogLevel ALL[] = {LogLevel::TELEMETRY, LogLevel::DEBUG, LogLevel::INFO,
                               LogLevel::WARNING,   LogLevel::ERROR, LogLevel::FATAL};
} // namespace logger