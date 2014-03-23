#include "Fault.hpp"

Fault::Fault(std::string const& err, std::string const& file, std::string const& func, bool full) throw()
{
  m_err = err;
  if (full)
    m_err += std::string(" (in file ") + file + std::string(" ,in function: ") + func + std::string(")");
}

const char* Fault::what() const throw()
{
  return m_err.c_str();
}
