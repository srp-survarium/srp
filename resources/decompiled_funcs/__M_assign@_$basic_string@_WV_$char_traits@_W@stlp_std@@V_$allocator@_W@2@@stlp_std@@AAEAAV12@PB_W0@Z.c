stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t> > *__thiscall stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t>>::_M_assign(
        stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t> > *this,
        wchar_t *__f,
        wchar_t *__l)
{
  unsigned __int8 *M_data; // edx
  unsigned int v5; // eax
  unsigned int v6; // ecx
  unsigned int v7; // ebp
  unsigned __int8 *M_finish; // edi
  unsigned __int8 *v9; // ebx

  M_data = (unsigned __int8 *)this->_M_start_of_storage._M_data;
  v5 = __l - __f;
  v6 = ((char *)this->_M_finish - (char *)M_data) >> 1;
  if ( v5 > v6 )
  {
    memcpy(M_data, (unsigned __int8 *)__f, 2 * v6);
    stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t>>::_M_append(
      this,
      &__f[this->_M_finish - this->_M_start_of_storage._M_data],
      __l);
  }
  else
  {
    v7 = v5;
    memcpy(M_data, (unsigned __int8 *)__f, 2 * v5);
    M_finish = (unsigned __int8 *)this->_M_finish;
    v9 = (unsigned __int8 *)&this->_M_start_of_storage._M_data[v7];
    if ( v9 != M_finish )
    {
      memmove(v9, M_finish, 2u);
      this->_M_finish -= (M_finish - v9) >> 1;
      return this;
    }
  }
  return this;
}
