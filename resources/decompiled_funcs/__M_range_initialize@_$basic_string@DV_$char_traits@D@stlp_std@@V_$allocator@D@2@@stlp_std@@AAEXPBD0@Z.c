void __thiscall stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::_M_range_initialize(
        stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *this,
        char *__f,
        const char *__l)
{
  unsigned __int8 *v3; // ebp
  unsigned int v4; // edi
  stlp_std::priv::_STLP_alloc_proxy<char *,char,stlp_std::allocator<char> > *p_M_start_of_storage; // ebx
  char *v7; // eax
  const char *v8; // edx
  unsigned __int8 *M_data; // eax
  int v10; // eax

  v3 = (unsigned __int8 *)__f;
  v4 = __l - __f;
  __f = (char *)(__l - __f + 1);
  if ( !__f )
    stlp_std::__stl_throw_length_error("basic_string");
  if ( (unsigned int)__f > 0x10 )
  {
    p_M_start_of_storage = &this->_M_start_of_storage;
    v7 = stlp_std::allocator<char>::_M_allocate(&this->_M_start_of_storage, (unsigned int)__f, (unsigned int *)&__f);
    v8 = __f;
    p_M_start_of_storage->_M_data = v7;
    this->_M_finish = v7;
    this->_M_buffers._M_end_of_storage = &v7[(_DWORD)v8];
  }
  M_data = (unsigned __int8 *)this->_M_start_of_storage._M_data;
  if ( __l != (const char *)v3 )
  {
    memcpy(M_data, v3, v4);
    M_data = (unsigned __int8 *)(v4 + v10);
  }
  this->_M_finish = (char *)M_data;
  *M_data = 0;
}
