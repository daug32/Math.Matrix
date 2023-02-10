#pragma once
#include <string>
#include <stdexcept>

class TestException : std::exception
{
private: 
    std::string m_message;

public:
    TestException(
        const std::string& message,
        const std::string& expected, 
        const std::string& result)
        : m_message(message + ". Expected: " + expected + ". Result: " + result)
    {
    }

    TestException(const std::string& message) : m_message(message)
    {}

    char const* what() const
    {
        return m_message.c_str();
    }
};