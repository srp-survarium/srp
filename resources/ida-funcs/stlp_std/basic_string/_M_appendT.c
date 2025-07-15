stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::priv::__iostring_allocator<char> > *__thiscall stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::priv::__iostring_allocator<char>>::_M_appendT<char const *>(
        stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::priv::__iostring_allocator<char> > *this,
        char *__first,
        const char *__last,
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
  unsigned __int8 *src; // [esp+Ch] [ebp+4h]
  unsigned int v22; // [esp+10h] [ebp+8h]

  if ( __first == __last )
    return this;
  M_finish = this->_M_finish;
  v7 = __last - __first;
  src = (unsigned __int8 *)(__last - __first);
  if ( (stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::priv::__iostring_allocator<char> > *)this->_M_start_of_storage._M_data == this )
    v8 = (char *)((char *)this - M_finish + 16);
  else
    v8 = (char *)(this->_M_buffers._M_end_of_storage - M_finish);
  if ( v7 < (unsigned int)v8 )
  {
    v19 = *__first;
    v20 = (unsigned __int8 *)(__first + 1);
    *M_finish = v19;
    if ( __last != (const char *)v20 )
      memcpy((unsigned __int8 *)this->_M_finish + 1, v20, __last - (const char *)v20);
    this->_M_finish[v7] = 0;
    this->_M_finish += v7;
    return this;
  }
  else
  {
    size = stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::priv::__iostring_allocator<char>>::_M_compute_next_size(
             this,
             __last - __first);
    v22 = size;
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
      v7 = (unsigned int)src;
    }
    memcpy(v13, (unsigned __int8 *)__first, v7);
    v17 = (char *)(v7 + v16);
    *(_BYTE *)(v7 + v16) = 0;
    stlp_std::priv::_String_base<char,stlp_std::priv::__iostring_allocator<char>>::_M_deallocate_block((stlp_std::priv::__basic_iostring<char> *)this);
    this->_M_start_of_storage._M_data = (char *)p_M_start_of_storage;
    this->_M_finish = v17;
    this->_M_buffers._M_end_of_storage = (char *)&p_M_start_of_storage[v22];
    return this;
  }
}


stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::priv::__iostring_allocator<wchar_t> > *__thiscall stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::priv::__iostring_allocator<wchar_t>>::_M_appendT<wchar_t const *>(
        stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::priv::__iostring_allocator<wchar_t> > *this,
        wchar_t *__first,
        const wchar_t *__last,
        const stlp_std::forward_iterator_tag *__formal)
{
  wchar_t *M_finish; // edx
  unsigned int v7; // ebp
  unsigned int v8; // ebx
  unsigned int v9; // eax
  unsigned int size; // eax
  unsigned __int8 *p_M_start_of_storage; // ebx
  wchar_t *v12; // ecx
  unsigned __int8 *M_data; // eax
  unsigned __int8 *v14; // eax
  int v15; // ebp
  int v16; // eax
  int v17; // eax
  wchar_t *v18; // edi
  wchar_t v20; // dx
  unsigned __int8 *v21; // edi
  unsigned __int8 *src; // [esp+Ch] [ebp+4h]
  unsigned int v23; // [esp+10h] [ebp+8h]

  if ( __first == __last )
    return this;
  M_finish = this->_M_finish;
  v7 = (char *)__last - (char *)__first;
  v8 = __last - __first;
  src = (unsigned __int8 *)((char *)__last - (char *)__first);
  if ( (stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::priv::__iostring_allocator<wchar_t> > *)this->_M_start_of_storage._M_data == this )
    v9 = 16 - (((char *)M_finish - (char *)this) >> 1);
  else
    v9 = this->_M_buffers._M_end_of_storage - M_finish;
  if ( v8 < v9 )
  {
    v20 = *__first;
    v21 = (unsigned __int8 *)(__first + 1);
    *this->_M_finish = v20;
    if ( __last != (const wchar_t *)v21 )
      memcpy((unsigned __int8 *)this->_M_finish + 2, v21, (char *)__last - (char *)v21);
    this->_M_finish[v8] = 0;
    this->_M_finish += v8;
    return this;
  }
  size = stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::priv::__iostring_allocator<wchar_t>>::_M_compute_next_size(
           this,
           __last - __first);
  v23 = size;
  if ( size <= 0x101 )
    p_M_start_of_storage = (unsigned __int8 *)&this->_M_start_of_storage;
  else
    p_M_start_of_storage = (unsigned __int8 *)stlp_std::allocator<wchar_t>::allocate(
                                                &this->_M_start_of_storage,
                                                size,
                                                0);
  v12 = this->_M_finish;
  M_data = (unsigned __int8 *)this->_M_start_of_storage._M_data;
  if ( v12 == (wchar_t *)M_data )
  {
    v14 = p_M_start_of_storage;
  }
  else
  {
    v15 = (char *)v12 - (char *)M_data;
    memcpy(p_M_start_of_storage, M_data, (char *)v12 - (char *)M_data);
    v14 = (unsigned __int8 *)(v15 + v16);
    v7 = (unsigned int)src;
  }
  memcpy(v14, (unsigned __int8 *)__first, v7);
  v18 = (wchar_t *)(v7 + v17);
  *(_WORD *)(v7 + v17) = 0;
  stlp_std::priv::_String_base<wchar_t,stlp_std::priv::__iostring_allocator<wchar_t>>::_M_deallocate_block((stlp_std::priv::__basic_iostring<wchar_t> *)this);
  this->_M_start_of_storage._M_data = (wchar_t *)p_M_start_of_storage;
  this->_M_finish = v18;
  this->_M_buffers._M_end_of_storage = (wchar_t *)&p_M_start_of_storage[2 * v23];
  return this;
}
