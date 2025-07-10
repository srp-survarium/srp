stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *__thiscall stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::assign(
        stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *this,
        unsigned int __n,
        char __c)
{
  char *M_finish; // ecx
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *M_data; // eax
  unsigned __int8 *v6; // ebx
  unsigned __int8 *v7; // edi
  int v8; // edx
  stlp_std::allocator<char> __a; // [esp+17h] [ebp-29h] BYREF
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > __str; // [esp+18h] [ebp-28h] BYREF
  int v12; // [esp+3Ch] [ebp-4h]

  M_finish = this->_M_finish;
  M_data = (stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)this->_M_start_of_storage._M_data;
  if ( __n > M_finish - (char *)M_data )
  {
    if ( M_data == this )
      v8 = 16;
    else
      v8 = this->_M_buffers._M_end_of_storage - (char *)M_data;
    if ( __n >= v8 - 1 )
    {
      stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>(
        &__str,
        __n,
        __c,
        &__a);
      v12 = 0;
      stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_swap(this, &__str);
      v12 = -1;
      if ( (stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)__str._M_start_of_storage._M_data != &__str
        && __str._M_start_of_storage._M_data )
      {
        if ( (unsigned int)(__str._M_buffers._M_end_of_storage - __str._M_start_of_storage._M_data) <= 0x80 )
          stlp_std::__node_alloc::_M_deallocate(
            (_STLP_atomic_freelist::item *)__str._M_start_of_storage._M_data,
            __str._M_buffers._M_end_of_storage - __str._M_start_of_storage._M_data);
        else
          operator delete(__str._M_start_of_storage._M_data);
      }
    }
    else
    {
      memset((unsigned __int8 *)M_data, __c, M_finish - (char *)M_data);
      stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::append(
        this,
        __n + this->_M_start_of_storage._M_data - this->_M_finish,
        __c);
    }
  }
  else
  {
    memset((unsigned __int8 *)M_data, __c, __n);
    v6 = (unsigned __int8 *)this->_M_finish;
    v7 = (unsigned __int8 *)&this->_M_start_of_storage._M_data[__n];
    if ( v7 != v6 )
    {
      memmove(v7, v6, 1u);
      this->_M_finish += v7 - v6;
    }
  }
  return this;
}
