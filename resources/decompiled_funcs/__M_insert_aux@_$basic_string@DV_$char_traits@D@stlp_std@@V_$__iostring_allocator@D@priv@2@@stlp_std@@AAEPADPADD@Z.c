char *__thiscall stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::priv::__iostring_allocator<char>>::_M_insert_aux(
        stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::priv::__iostring_allocator<char> > *this,
        char *__p,
        char __c)
{
  char *M_finish; // ecx
  char *v6; // eax
  unsigned int v7; // eax
  char *result; // eax
  unsigned int size; // eax
  char *M_static_buf; // ebp
  char *v11; // edi
  char *v12; // ebx
  char *M_data; // eax
  char *__pa; // [esp+Ch] [ebp+4h]

  M_finish = this->_M_finish;
  if ( (stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::priv::__iostring_allocator<char> > *)this->_M_start_of_storage._M_data == this )
    v6 = (char *)((char *)this - M_finish + 16);
  else
    v6 = (char *)(this->_M_buffers._M_end_of_storage - M_finish);
  if ( (unsigned int)v6 <= 1 )
  {
    size = stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::priv::__iostring_allocator<char>>::_M_compute_next_size(
             this,
             1u);
    __pa = (char *)size;
    if ( size <= 0x101 )
      M_static_buf = this->_M_start_of_storage._M_static_buf;
    else
      M_static_buf = (char *)stlp_std::allocator<char>::allocate(&this->_M_start_of_storage, size, 0);
    v11 = stlp_std::priv::__ucopy<char *,char *,int>(this->_M_start_of_storage._M_data, __p, M_static_buf);
    *v11 = __c;
    v12 = stlp_std::priv::__ucopy<char *,char *,int>(__p, this->_M_finish, v11 + 1);
    *v12 = 0;
    M_data = this->_M_start_of_storage._M_data;
    if ( M_data != (char *)this && M_data && M_data != (char *)&this->_M_start_of_storage )
    {
      if ( (unsigned int)(this->_M_buffers._M_end_of_storage - M_data) <= 0x80 )
        stlp_std::__node_alloc::_M_deallocate(
          (_STLP_atomic_freelist::item *)M_data,
          this->_M_buffers._M_end_of_storage - M_data);
      else
        operator delete(this->_M_start_of_storage._M_data);
    }
    result = v11;
    this->_M_start_of_storage._M_data = M_static_buf;
    this->_M_finish = v12;
    this->_M_buffers._M_end_of_storage = &M_static_buf[(_DWORD)__pa];
  }
  else
  {
    M_finish[1] = 0;
    v7 = this->_M_finish - __p;
    if ( v7 )
      memmove((unsigned __int8 *)__p + 1, (unsigned __int8 *)__p, v7);
    *__p = __c;
    ++this->_M_finish;
    return __p;
  }
  return result;
}
