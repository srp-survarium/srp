void __thiscall stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::_M_range_initialize<char const *>(
        stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *this,
        char *__f,
        const char *__l,
        const stlp_std::forward_iterator_tag *__formal)
{
  unsigned __int8 *v4; // ebp
  unsigned int v5; // edi
  stlp_std::priv::_STLP_alloc_proxy<char *,char,stlp_std::allocator<char> > *p_M_start_of_storage; // ebx
  char *v8; // eax
  const char *v9; // edx
  unsigned __int8 *M_data; // eax
  int v11; // eax

  v4 = (unsigned __int8 *)__f;
  v5 = __l - __f;
  __f = (char *)(__l - __f + 1);
  if ( !__f )
    stlp_std::__stl_throw_length_error("basic_string");
  if ( (unsigned int)__f > 0x10 )
  {
    p_M_start_of_storage = &this->_M_start_of_storage;
    v8 = stlp_std::allocator<char>::_M_allocate(&this->_M_start_of_storage, (unsigned int)__f, (unsigned int *)&__f);
    v9 = __f;
    p_M_start_of_storage->_M_data = v8;
    this->_M_finish = v8;
    this->_M_buffers._M_end_of_storage = &v8[(_DWORD)v9];
  }
  M_data = (unsigned __int8 *)this->_M_start_of_storage._M_data;
  if ( __l != (const char *)v4 )
  {
    memcpy(M_data, v4, v5);
    M_data = (unsigned __int8 *)(v5 + v11);
  }
  this->_M_finish = (char *)M_data;
  *M_data = 0;
}
