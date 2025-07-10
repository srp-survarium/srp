stlp_std::priv::_String_base<char,stlp_std::allocator<char> > *__thiscall stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::erase(
        stlp_std::priv::_String_base<char,stlp_std::allocator<char> > *this,
        unsigned int a2,
        unsigned int a3)
{
  char *M_finish; // edx
  char *M_data; // ecx
  unsigned int v6; // edi
  bool v7; // cf
  unsigned int *v8; // eax
  unsigned __int8 *v9; // esi
  unsigned __int8 *v10; // edi
  unsigned int v11; // edx

  M_finish = this->_M_finish;
  M_data = this->_M_start_of_storage._M_data;
  v6 = a2;
  if ( a2 > M_finish - M_data )
    stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_throw_out_of_range(this);
  v7 = M_finish - M_data - a2 < a3;
  a2 = M_finish - M_data - a2;
  v8 = &a2;
  if ( !v7 )
    v8 = &a3;
  v9 = (unsigned __int8 *)&M_data[*v8 + v6];
  v10 = (unsigned __int8 *)&M_data[v6];
  if ( v10 != v9 )
  {
    v11 = M_finish - (char *)v9 + 1;
    if ( v11 )
      memmove(v10, v9, v11);
    this->_M_finish += v10 - v9;
  }
  return this;
}
