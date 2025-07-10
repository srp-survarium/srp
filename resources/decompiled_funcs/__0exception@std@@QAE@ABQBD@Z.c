void __thiscall std::exception::exception(std::exception *this, const char *const *what)
{
  int v3; // eax
  unsigned int v4; // esi
  char *v5; // eax

  this->__vftable = (std::exception_vtbl *)&std::exception::`vftable';
  if ( *what )
  {
    strlen(*(unsigned __int8 **)what);
    v4 = v3 + 1;
    v5 = (char *)malloc(v3 + 1);
    this->_m_what = v5;
    if ( v5 )
      strcpy_s(v5, v4, *what);
  }
  else
  {
    this->_m_what = 0;
  }
  this->_m_doFree = 1;
}
