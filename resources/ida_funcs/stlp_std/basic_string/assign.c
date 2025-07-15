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


stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t> > *__thiscall stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t>>::assign(
        stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t> > *this,
        unsigned int __n,
        int __c)
{
  wchar_t *M_finish; // eax
  stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t> > *M_data; // edi
  wchar_t *v6; // edi
  unsigned int j; // ecx
  unsigned __int8 *v8; // edi
  unsigned __int8 *v9; // ebx
  int v10; // ecx
  unsigned int v11; // eax
  wchar_t *v12; // edi
  int i; // ecx
  stlp_std::allocator<wchar_t> __a; // [esp+17h] [ebp-39h] BYREF
  stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t> > __str; // [esp+18h] [ebp-38h] BYREF
  int v17; // [esp+4Ch] [ebp-4h]

  M_finish = this->_M_finish;
  M_data = (stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t> > *)this->_M_start_of_storage._M_data;
  if ( __n > ((char *)M_finish - (char *)M_data) >> 1 )
  {
    if ( M_data == this )
      v10 = 16;
    else
      v10 = ((char *)this->_M_buffers._M_end_of_storage - (char *)M_data) >> 1;
    if ( __n >= v10 - 1 )
    {
      stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t>>::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t>>(
        &__str,
        __n,
        __c,
        &__a);
      v17 = 0;
      stlp_std::priv::_String_base<wchar_t,stlp_std::allocator<wchar_t>>::_M_swap(this, &__str);
      v17 = -1;
      if ( (stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t> > *)__str._M_start_of_storage._M_data != &__str
        && __str._M_start_of_storage._M_data )
      {
        if ( (unsigned int)(2 * (__str._M_buffers._M_end_of_storage - __str._M_start_of_storage._M_data)) <= 0x80 )
          stlp_std::__node_alloc::_M_deallocate(
            (_STLP_atomic_freelist::item *)__str._M_start_of_storage._M_data,
            2 * (__str._M_buffers._M_end_of_storage - __str._M_start_of_storage._M_data));
        else
          operator delete(__str._M_start_of_storage._M_data);
      }
    }
    else
    {
      v11 = ((char *)M_finish - (char *)M_data) >> 1;
      if ( v11 )
      {
        memset32(M_data, ((unsigned __int16)__c << 16) | (unsigned __int16)__c, v11 >> 1);
        v12 = &M_data->_M_buffers._M_static_buf[2 * (v11 >> 1)];
        for ( i = v11 & 1; i; --i )
          *v12++ = __c;
      }
      stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t>>::append(
        this,
        __n - (this->_M_finish - this->_M_start_of_storage._M_data),
        __c);
    }
  }
  else
  {
    if ( __n )
    {
      memset32(M_data, ((unsigned __int16)__c << 16) | (unsigned __int16)__c, __n >> 1);
      v6 = &M_data->_M_buffers._M_static_buf[2 * (__n >> 1)];
      for ( j = __n & 1; j; --j )
        *v6++ = __c;
    }
    v8 = (unsigned __int8 *)this->_M_finish;
    v9 = (unsigned __int8 *)&this->_M_start_of_storage._M_data[__n];
    if ( v9 != v8 )
    {
      memmove(v9, v8, 2u);
      this->_M_finish -= (v8 - v9) >> 1;
    }
  }
  return this;
}
