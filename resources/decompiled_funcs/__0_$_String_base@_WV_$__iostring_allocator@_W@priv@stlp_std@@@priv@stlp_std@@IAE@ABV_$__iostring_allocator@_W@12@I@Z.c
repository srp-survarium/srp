void __thiscall stlp_std::priv::_String_base<wchar_t,stlp_std::priv::__iostring_allocator<wchar_t>>::_String_base<wchar_t,stlp_std::priv::__iostring_allocator<wchar_t>>(
        stlp_std::priv::_String_base<wchar_t,stlp_std::priv::__iostring_allocator<wchar_t> > *this,
        const stlp_std::priv::__iostring_allocator<wchar_t> *__a,
        int __n)
{
  stlp_std::allocator<wchar_t> *p_M_start_of_storage; // eax

  p_M_start_of_storage = &this->_M_start_of_storage;
  this->_M_finish = (wchar_t *)this;
  qmemcpy(&this->_M_start_of_storage, __a, 0x202u);
  this->_M_start_of_storage._M_data = (wchar_t *)this;
  if ( __n <= 0 )
    stlp_std::__stl_throw_length_error("basic_string");
  if ( (unsigned int)__n > 0x10 )
  {
    if ( (unsigned int)__n > 0x101 )
      p_M_start_of_storage = (stlp_std::allocator<wchar_t> *)stlp_std::allocator<wchar_t>::allocate(
                                                               p_M_start_of_storage,
                                                               __n,
                                                               0);
    this->_M_start_of_storage._M_data = (wchar_t *)p_M_start_of_storage;
    this->_M_finish = (wchar_t *)p_M_start_of_storage;
    this->_M_buffers._M_end_of_storage = (wchar_t *)&p_M_start_of_storage[2 * __n];
  }
}
