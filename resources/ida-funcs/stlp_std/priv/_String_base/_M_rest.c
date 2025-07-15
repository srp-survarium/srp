int __thiscall stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_rest(
        stlp_std::priv::_String_base<char,stlp_std::allocator<char> > *this)
{
  if ( (stlp_std::priv::_String_base<char,stlp_std::allocator<char> > *)this->_M_start_of_storage._M_data == this )
    return (char *)this - this->_M_finish + 16;
  else
    return this->_M_buffers._M_end_of_storage - this->_M_finish;
}
