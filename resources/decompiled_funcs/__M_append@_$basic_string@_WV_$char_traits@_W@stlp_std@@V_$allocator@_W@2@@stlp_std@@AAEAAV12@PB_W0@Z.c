stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t> > *__thiscall stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t>>::_M_append(
        stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t> > *this,
        wchar_t *__first,
        wchar_t *__last)
{
  const wchar_t *v3; // edx
  wchar_t *v4; // ebp
  wchar_t *M_finish; // ecx
  stlp_std::priv::_STLP_alloc_proxy<wchar_t *,wchar_t,stlp_std::allocator<wchar_t> > *p_M_start_of_storage; // edi
  unsigned int v8; // ebx
  unsigned int v9; // eax
  wchar_t *v10; // ebx
  wchar_t *v11; // eax
  wchar_t *v12; // ebp
  wchar_t *M_data; // eax
  wchar_t *v14; // ecx
  wchar_t *v16; // ecx
  unsigned int v17; // ebx

  v3 = __last;
  v4 = __first;
  if ( __first == __last )
    return this;
  M_finish = this->_M_finish;
  p_M_start_of_storage = &this->_M_start_of_storage;
  v8 = __last - __first;
  if ( (stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t> > *)this->_M_start_of_storage._M_data == this )
  {
    v9 = 16 - (((char *)M_finish - (char *)this) >> 1);
    v3 = __last;
  }
  else
  {
    v9 = this->_M_buffers._M_end_of_storage - M_finish;
  }
  if ( v8 < v9 )
  {
    stlp_std::priv::__ucopy<wchar_t const *,wchar_t *,int>(__first + 1, v3, M_finish + 1);
    v17 = v8;
    this->_M_finish[v17] = 0;
    *this->_M_finish = *v4;
    this->_M_finish = (wchar_t *)((char *)this->_M_finish + v17 * 2);
    return this;
  }
  __first = (wchar_t *)stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t>>::_M_compute_next_size(
                         this,
                         v8);
  v10 = (wchar_t *)stlp_std::allocator<wchar_t>::_M_allocate(
                     &this->_M_start_of_storage,
                     (unsigned int)__first,
                     (unsigned int *)&__first);
  v11 = stlp_std::priv::__ucopy<wchar_t const *,wchar_t *,int>(p_M_start_of_storage->_M_data, this->_M_finish, v10);
  v12 = stlp_std::priv::__ucopy<wchar_t const *,wchar_t *,int>(v4, __last, v11);
  *v12 = 0;
  M_data = p_M_start_of_storage->_M_data;
  if ( (stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t> > *)p_M_start_of_storage->_M_data != this
    && M_data )
  {
    if ( (unsigned int)(2 * (this->_M_buffers._M_end_of_storage - M_data)) > 0x80 )
    {
      operator delete(p_M_start_of_storage->_M_data);
      v14 = __first;
      p_M_start_of_storage->_M_data = v10;
      this->_M_finish = v12;
      this->_M_buffers._M_end_of_storage = &v10[(_DWORD)v14];
      return this;
    }
    stlp_std::__node_alloc::_M_deallocate(
      (_STLP_atomic_freelist::item *)M_data,
      2 * (this->_M_buffers._M_end_of_storage - M_data));
  }
  v16 = __first;
  p_M_start_of_storage->_M_data = v10;
  this->_M_finish = v12;
  this->_M_buffers._M_end_of_storage = &v10[(_DWORD)v16];
  return this;
}
