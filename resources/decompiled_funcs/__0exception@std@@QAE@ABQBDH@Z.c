void __thiscall std::exception::exception(std::exception *this, const char **what, int __formal)
{
  const char *v4; // ecx

  this->__vftable = (std::exception_vtbl *)&std::exception::`vftable';
  v4 = *what;
  this->_m_doFree = 0;
  this->_m_what = v4;
}
