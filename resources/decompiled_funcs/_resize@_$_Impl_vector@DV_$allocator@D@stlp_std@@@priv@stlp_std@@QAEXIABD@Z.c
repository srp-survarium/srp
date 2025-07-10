void __thiscall stlp_std::priv::_Impl_vector<char,stlp_std::allocator<char>>::resize(
        stlp_std::priv::_Impl_vector<char,stlp_std::allocator<char> > *this,
        unsigned int __new_size,
        const char *__x)
{
  if ( __new_size >= this->_M_finish - this->_M_start )
    stlp_std::priv::_Impl_vector<char,stlp_std::allocator<char>>::_M_fill_insert(
      this,
      this->_M_finish,
      __new_size - (this->_M_finish - this->_M_start),
      __x);
  else
    stlp_std::priv::_Impl_vector<char,stlp_std::allocator<char>>::erase(
      this,
      &this->_M_start[__new_size],
      this->_M_finish);
}
