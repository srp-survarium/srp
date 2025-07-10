void __thiscall stlp_std::priv::_String_base<char,stlp_std::priv::__iostring_allocator<char>>::_String_base<char,stlp_std::priv::__iostring_allocator<char>>(
        stlp_std::priv::_String_base<char,stlp_std::priv::__iostring_allocator<char> > *this,
        const stlp_std::priv::__iostring_allocator<char> *__a,
        unsigned int __n)
{
  stlp_std::allocator<char> *p_M_start_of_storage; // eax

  p_M_start_of_storage = &this->_M_start_of_storage;
  this->_M_finish = (char *)this;
  qmemcpy(&this->_M_start_of_storage, __a, 0x101u);
  this->_M_start_of_storage._M_data = (char *)this;
  if ( !__n )
    stlp_std::__stl_throw_length_error("basic_string");
  if ( __n > 0x10 )
  {
    if ( __n > 0x101 )
      p_M_start_of_storage = (stlp_std::allocator<char> *)stlp_std::allocator<char>::allocate(
                                                            p_M_start_of_storage,
                                                            __n,
                                                            0);
    this->_M_start_of_storage._M_data = (char *)p_M_start_of_storage;
    this->_M_finish = (char *)p_M_start_of_storage;
    this->_M_buffers._M_end_of_storage = (char *)&p_M_start_of_storage[__n];
  }
}
