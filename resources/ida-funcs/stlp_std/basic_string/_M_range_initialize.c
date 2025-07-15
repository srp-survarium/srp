void __thiscall stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::_M_range_initialize<char const *>(
        stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *this,
        char *__f,
        char *__l,
        const stlp_std::forward_iterator_tag *__formal)
{
  unsigned __int8 *v5; // eax

  stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_allocate_block(this, __l - __f + 1);
  v5 = stlp_std::priv::__ucopy_trivial(
         (unsigned __int8 *)__f,
         (unsigned __int8 *)__l,
         (unsigned __int8 *)this->_M_start_of_storage._M_data);
  this->_M_finish = (char *)v5;
  *v5 = 0;
}


void __thiscall stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t>>::_M_range_initialize<wchar_t const *>(
        stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t> > *this,
        wchar_t *__f,
        const wchar_t *__l,
        const stlp_std::forward_iterator_tag *__formal)
{
  unsigned __int8 *v4; // ebp
  unsigned int v5; // edi
  wchar_t *v6; // eax
  stlp_std::priv::_STLP_alloc_proxy<wchar_t *,wchar_t,stlp_std::allocator<wchar_t> > *p_M_start_of_storage; // ebx
  wchar_t *v9; // eax
  wchar_t *v10; // edx
  unsigned __int8 *M_data; // eax
  int v12; // eax

  v4 = (unsigned __int8 *)__f;
  v5 = (char *)__l - (char *)__f;
  v6 = (wchar_t *)(__l - __f + 1);
  __f = v6;
  if ( (int)v6 <= 0 )
    stlp_std::__stl_throw_length_error("basic_string");
  if ( (unsigned int)v6 > 0x10 )
  {
    p_M_start_of_storage = &this->_M_start_of_storage;
    v9 = (wchar_t *)stlp_std::allocator<wchar_t>::_M_allocate(
                      &this->_M_start_of_storage,
                      (unsigned int)v6,
                      (unsigned int *)&__f);
    v10 = __f;
    p_M_start_of_storage->_M_data = v9;
    this->_M_finish = v9;
    this->_M_buffers._M_end_of_storage = &v9[(_DWORD)v10];
  }
  M_data = (unsigned __int8 *)this->_M_start_of_storage._M_data;
  if ( __l != (const wchar_t *)v4 )
  {
    memcpy(M_data, v4, v5);
    M_data = (unsigned __int8 *)(v5 + v12);
  }
  this->_M_finish = (wchar_t *)M_data;
  *(_WORD *)M_data = 0;
}


void __thiscall stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::_M_range_initialize(
        stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *this,
        char *__f,
        char *__l)
{
  unsigned __int8 *v4; // eax

  stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_allocate_block(this, __l - __f + 1);
  v4 = stlp_std::priv::__ucopy_trivial(
         (unsigned __int8 *)__f,
         (unsigned __int8 *)__l,
         (unsigned __int8 *)this->_M_start_of_storage._M_data);
  this->_M_finish = (char *)v4;
  *v4 = 0;
}


void __thiscall stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t>>::_M_range_initialize(
        stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t> > *this,
        wchar_t *__f,
        const wchar_t *__l)
{
  unsigned __int8 *v3; // ebp
  unsigned int v4; // edi
  wchar_t *v5; // eax
  stlp_std::priv::_STLP_alloc_proxy<wchar_t *,wchar_t,stlp_std::allocator<wchar_t> > *p_M_start_of_storage; // ebx
  wchar_t *v8; // eax
  wchar_t *v9; // edx
  unsigned __int8 *M_data; // eax
  int v11; // eax

  v3 = (unsigned __int8 *)__f;
  v4 = (char *)__l - (char *)__f;
  v5 = (wchar_t *)(__l - __f + 1);
  __f = v5;
  if ( (int)v5 <= 0 )
    stlp_std::__stl_throw_length_error("basic_string");
  if ( (unsigned int)v5 > 0x10 )
  {
    p_M_start_of_storage = &this->_M_start_of_storage;
    v8 = (wchar_t *)stlp_std::allocator<wchar_t>::_M_allocate(
                      &this->_M_start_of_storage,
                      (unsigned int)v5,
                      (unsigned int *)&__f);
    v9 = __f;
    p_M_start_of_storage->_M_data = v8;
    this->_M_finish = v8;
    this->_M_buffers._M_end_of_storage = &v8[(_DWORD)v9];
  }
  M_data = (unsigned __int8 *)this->_M_start_of_storage._M_data;
  if ( __l != (const wchar_t *)v3 )
  {
    memcpy(M_data, v3, v4);
    M_data = (unsigned __int8 *)(v4 + v11);
  }
  this->_M_finish = (wchar_t *)M_data;
  *(_WORD *)M_data = 0;
}
