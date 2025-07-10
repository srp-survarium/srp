stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::priv::__iostring_allocator<char> > *__thiscall stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::priv::__iostring_allocator<char>>::_M_appendT<char const *>(
        stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::priv::__iostring_allocator<char> > *this,
        char *__first,
        char *__last,
        const stlp_std::forward_iterator_tag *__formal)
{
  char *M_finish; // edx
  unsigned int v7; // ebp
  char *v8; // eax
  unsigned int size; // eax
  unsigned __int8 *p_M_start_of_storage; // ebx
  char *v11; // ecx
  unsigned __int8 *M_data; // eax
  unsigned __int8 *v13; // eax
  int v14; // ebp
  int v15; // eax
  int v16; // eax
  char *v17; // edi
  unsigned __int8 v19; // al
  unsigned __int8 *v20; // edi
  const char *__firsta; // [esp+Ch] [ebp+4h]
  const char *__lasta; // [esp+10h] [ebp+8h]

  if ( __first == __last )
    return this;
  M_finish = this->_M_finish;
  v7 = __last - __first;
  __firsta = (const char *)(__last - __first);
  if ( (stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::priv::__iostring_allocator<char> > *)this->_M_start_of_storage._M_data == this )
    v8 = (char *)((char *)this - M_finish + 16);
  else
    v8 = (char *)(this->_M_buffers._M_end_of_storage - M_finish);
  if ( v7 < (unsigned int)v8 )
  {
    v19 = *__first;
    v20 = (unsigned __int8 *)(__first + 1);
    *M_finish = v19;
    if ( __last != (char *)v20 )
      memcpy((unsigned __int8 *)this->_M_finish + 1, v20, __last - (char *)v20);
    this->_M_finish[v7] = 0;
    this->_M_finish += v7;
    return this;
  }
  else
  {
    size = stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::priv::__iostring_allocator<char>>::_M_compute_next_size(
             this,
             __last - __first);
    __lasta = (const char *)size;
    if ( size <= 0x101 )
      p_M_start_of_storage = (unsigned __int8 *)&this->_M_start_of_storage;
    else
      p_M_start_of_storage = (unsigned __int8 *)stlp_std::allocator<char>::allocate(&this->_M_start_of_storage, size, 0);
    v11 = this->_M_finish;
    M_data = (unsigned __int8 *)this->_M_start_of_storage._M_data;
    if ( v11 == (char *)M_data )
    {
      v13 = p_M_start_of_storage;
    }
    else
    {
      v14 = v11 - (char *)M_data;
      memcpy(p_M_start_of_storage, M_data, v11 - (char *)M_data);
      v13 = (unsigned __int8 *)(v14 + v15);
      v7 = (unsigned int)__firsta;
    }
    memcpy(v13, (unsigned __int8 *)__first, v7);
    v17 = (char *)(v7 + v16);
    *(_BYTE *)(v7 + v16) = 0;
    stlp_std::priv::_String_base<char,stlp_std::priv::__iostring_allocator<char>>::_M_deallocate_block((stlp_std::priv::__basic_iostring<char> *)this);
    this->_M_start_of_storage._M_data = (char *)p_M_start_of_storage;
    this->_M_finish = v17;
    this->_M_buffers._M_end_of_storage = (char *)&__lasta[(_DWORD)p_M_start_of_storage];
    return this;
  }
}
