BOOL __thiscall stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_using_static_buf(
        stlp_std::priv::_String_base<char,stlp_std::allocator<char> > *this)
{
  return this->_M_start_of_storage._M_data == (char *)this;
}
