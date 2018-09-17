#pragma once

#include <string>

class NxEngineException
{
  private:
    std::string m_errorMsg = "NxEngine exception";

  public:
    NxEngineException() {}
    NxEngineException(const std::string errorMsg) : m_errorMsg(errorMsg) {}
    ~NxEngineException();

    const std::string &what() const { return m_errorMsg; }
};