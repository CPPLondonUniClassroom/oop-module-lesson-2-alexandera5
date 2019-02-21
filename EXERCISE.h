#pragma once

#include <string>

//This is for part 1
class ILogger {
public:
    virtual ~ILogger() = default;
    virtual ILogger& LogInfo(const std::string& message) = 0;
    virtual ILogger& LogError(const std::string& message) = 0;
    virtual const std::string& GetLastError() const = 0;
};

// This is for Part 2/3
class StringLogger : public ILogger {
public:
    explicit StringLogger(std::ostream& stream);
    ILogger& LogInfo(const std::string& message) override;
    ILogger& LogError(const std::string& message) override;
    const std::string& GetLastError() const override;
private:
    std::ostream& _stream;
    std::string _lastError;
};

static int Version();