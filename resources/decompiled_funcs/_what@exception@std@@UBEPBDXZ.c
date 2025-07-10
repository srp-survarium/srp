const char *__thiscall std::exception::what(std::exception *this)
{
  const char *result; // eax

  result = this->_m_what;
  if ( !result )
    return "Unknown exception";
  return result;
}
