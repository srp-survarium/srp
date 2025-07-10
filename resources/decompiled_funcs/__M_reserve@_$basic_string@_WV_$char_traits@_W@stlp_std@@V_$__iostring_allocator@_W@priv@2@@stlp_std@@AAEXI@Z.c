void __thiscall stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::priv::__iostring_allocator<wchar_t>>::_M_reserve(
        stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::priv::__iostring_allocator<wchar_t> > *this,
        unsigned int __n)
{
  stlp_std::priv::_STLP_alloc_proxy<wchar_t *,wchar_t,stlp_std::priv::__iostring_allocator<wchar_t> > *p_M_start_of_storage; // ebp
  wchar_t *M_static_buf; // edi
  wchar_t *v5; // ebx
  wchar_t *M_data; // eax

  p_M_start_of_storage = &this->_M_start_of_storage;
  if ( __n <= 0x101 )
    M_static_buf = this->_M_start_of_storage._M_static_buf;
  else
    M_static_buf = (wchar_t *)stlp_std::allocator<wchar_t>::allocate(&this->_M_start_of_storage, __n, 0);
  v5 = stlp_std::priv::__ucopy<wchar_t const *,wchar_t *,int>(
         this->_M_start_of_storage._M_data,
         this->_M_finish,
         M_static_buf);
  *v5 = 0;
  M_data = this->_M_start_of_storage._M_data;
  if ( M_data != (wchar_t *)this && M_data && M_data != (wchar_t *)p_M_start_of_storage )
  {
    if ( (unsigned int)(2 * (this->_M_buffers._M_end_of_storage - M_data)) <= 0x80 )
      stlp_std::__node_alloc::_M_deallocate(
        (_STLP_atomic_freelist::item *)M_data,
        2 * (this->_M_buffers._M_end_of_storage - M_data));
    else
      operator delete(this->_M_start_of_storage._M_data);
  }
  this->_M_start_of_storage._M_data = M_static_buf;
  this->_M_finish = v5;
  this->_M_buffers._M_end_of_storage = &M_static_buf[__n];
}
