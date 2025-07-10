void __thiscall stlp_std::priv::_Impl_vector<vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32>>>::resize(
        stlp_std::priv::_Impl_vector<vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32> > > *this,
        unsigned int __new_size,
        const vostok::fixed_vector<unsigned int,32> *__x)
{
  stlp_std::__false_type __formal; // [esp+3Bh] [ebp-9h] BYREF
  vostok::fixed_vector<unsigned int,32> *M_start; // [esp+3Ch] [ebp-8h]
  vostok::fixed_vector<unsigned int,32> *__last; // [esp+40h] [ebp-4h]

  if ( __new_size >= this->_M_finish - this->_M_start )
  {
    stlp_std::priv::_Impl_vector<vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32>>>::_M_fill_insert(
      this,
      this->_M_finish,
      __new_size - (this->_M_finish - this->_M_start),
      __x);
  }
  else
  {
    __last = this->_M_finish;
    M_start = this->_M_start;
    if ( &M_start[__new_size] != __last )
    {
      __formal = 0;
      stlp_std::priv::_Impl_vector<vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32>>>::_M_erase(
        this,
        &M_start[__new_size],
        __last,
        &__formal);
    }
  }
}
