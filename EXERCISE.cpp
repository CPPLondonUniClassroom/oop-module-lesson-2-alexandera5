#include "EXERCISE.h"

#include <ostream>

StringLogger::StringLogger(std::ostream& stream)
    : _stream{stream} {}

ILogger& StringLogger::LogInfo(const std::string& message) {
    _stream << "INFO: " << message;
    return *this;
}
ILogger& StringLogger::LogError(const std::string& message) {
    _stream << "ERROR: " << message;
    _lastError = message;
    return *this;
}

const std::string& StringLogger::GetLastError() const {
    return _lastError;
}

int Version() {
    return 2;
}