void __thiscall stlp_std::__Named_exception::__Named_exception(
        stlp_std::__Named_exception *this,
        const stlp_std::__Named_exception *__x)
{
  unsigned int v3; // eax
  unsigned int v4; // edi
  char *v5; // eax

  std::exception::exception(this);
  this->__vftable = (stlp_std::__Named_exception_vtbl *)&stlp_std::__Named_exception::`vftable';
  v3 = strlen(__x->_M_name);
  v4 = v3 + 1;
  if ( v3 + 1 <= 0x100 )
  {
    this->_M_name = this->_M_static_name;
  }
  else
  {
    v5 = (char *)malloc(v3 + 1);
    this->_M_name = v5;
    if ( v5 )
    {
      *(_DWORD *)this->_M_static_name = v4;
    }
    else
    {
      v4 = 256;
      this->_M_name = this->_M_static_name;
    }
  }
  strncpy_s(this->_M_name, v4, __x->_M_name, v4 - 1);
}


void __thiscall stlp_std::__Named_exception::__Named_exception(
        stlp_std::__Named_exception *this,
        const stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *__str)
{
  unsigned int v3; // eax
  unsigned int v4; // edi
  char *v5; // eax

  std::exception::exception(this);
  this->__vftable = (stlp_std::__Named_exception_vtbl *)&stlp_std::__Named_exception::`vftable';
  v3 = strlen(__str->_M_start_of_storage._M_data);
  v4 = v3 + 1;
  if ( v3 + 1 <= 0x100 )
  {
    this->_M_name = this->_M_static_name;
  }
  else
  {
    v5 = (char *)malloc(v3 + 1);
    this->_M_name = v5;
    if ( v5 )
    {
      *(_DWORD *)this->_M_static_name = v4;
    }
    else
    {
      v4 = 256;
      this->_M_name = this->_M_static_name;
    }
  }
  strncpy_s(this->_M_name, v4, __str->_M_start_of_storage._M_data, v4 - 1);
}
