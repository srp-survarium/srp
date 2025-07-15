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


void __thiscall std::exception::exception(std::exception *this, const char **what, int __formal)
{
  const char *v4; // ecx

  this->__vftable = (std::exception_vtbl *)&std::exception::`vftable';
  v4 = *what;
  this->_m_doFree = 0;
  this->_m_what = v4;
}


void __thiscall std::exception::exception(std::exception *this, const std::exception *that)
{
  int m_doFree; // eax
  bool v4; // zf
  const char *m_what; // eax
  int v6; // eax
  unsigned int v7; // edi
  char *v8; // eax

  this->__vftable = (std::exception_vtbl *)&std::exception::`vftable';
  m_doFree = that->_m_doFree;
  this->_m_doFree = m_doFree;
  v4 = m_doFree == 0;
  m_what = that->_m_what;
  if ( v4 )
  {
    this->_m_what = m_what;
  }
  else if ( m_what )
  {
    strlen((unsigned __int8 *)that->_m_what);
    v7 = v6 + 1;
    v8 = (char *)malloc(v6 + 1);
    this->_m_what = v8;
    if ( v8 )
      strcpy_s(v8, v7, that->_m_what);
  }
  else
  {
    this->_m_what = 0;
  }
}


void __thiscall std::exception::exception(std::exception *this)
{
  this->_m_what = 0;
  this->_m_doFree = 0;
  this->__vftable = (std::exception_vtbl *)&std::exception::`vftable';
}
