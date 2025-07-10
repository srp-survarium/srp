void __thiscall stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t>>::_M_reserve(
        stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t> > *this,
        unsigned int __n)
{
  stlp_std::priv::_STLP_alloc_proxy<wchar_t *,wchar_t,stlp_std::allocator<wchar_t> > *p_M_start_of_storage; // edi
  wchar_t *v4; // ebx
  wchar_t *v5; // ebp
  wchar_t *M_data; // eax
  wchar_t *v7; // edx
  wchar_t *v8; // edx

  p_M_start_of_storage = &this->_M_start_of_storage;
  v4 = (wchar_t *)stlp_std::allocator<wchar_t>::_M_allocate(&this->_M_start_of_storage, __n, &__n);
  v5 = stlp_std::priv::__ucopy<wchar_t const *,wchar_t *,int>(p_M_start_of_storage->_M_data, this->_M_finish, v4);
  *v5 = 0;
  M_data = p_M_start_of_storage->_M_data;
  if ( (stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t> > *)p_M_start_of_storage->_M_data != this
    && M_data )
  {
    if ( (unsigned int)(2 * (this->_M_buffers._M_end_of_storage - M_data)) > 0x80 )
    {
      operator delete(p_M_start_of_storage->_M_data);
      v7 = &v4[__n];
      p_M_start_of_storage->_M_data = v4;
      this->_M_finish = v5;
      this->_M_buffers._M_end_of_storage = v7;
      return;
    }
    stlp_std::__node_alloc::_M_deallocate(
      (_STLP_atomic_freelist::item *)M_data,
      2 * (this->_M_buffers._M_end_of_storage - M_data));
  }
  v8 = &v4[__n];
  p_M_start_of_storage->_M_data = v4;
  this->_M_finish = v5;
  this->_M_buffers._M_end_of_storage = v8;
}
