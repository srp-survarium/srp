void __thiscall stlp_std::priv::_Impl_vector<unsigned int,vostok::ai::std_allocator<unsigned int>>::resize(
        stlp_std::priv::_Impl_vector<unsigned int,vostok::ai::std_allocator<unsigned int> > *this,
        unsigned int __new_size,
        const unsigned int *__x)
{
  if ( __new_size >= this->_M_finish - this->_M_start )
    stlp_std::priv::_Impl_vector<unsigned int,vostok::ai::std_allocator<unsigned int>>::_M_fill_insert(
      this,
      this->_M_finish,
      __new_size - (this->_M_finish - this->_M_start),
      __x);
  else
    stlp_std::priv::_Impl_vector<unsigned int,vostok::ai::std_allocator<unsigned int>>::erase(
      this,
      &this->_M_start[__new_size],
      this->_M_finish);
}
