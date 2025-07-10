void __thiscall stlp_std::priv::_Impl_vector<unsigned int,vostok::ai::std_allocator<unsigned int>>::_Impl_vector<unsigned int,vostok::ai::std_allocator<unsigned int>>(
        stlp_std::priv::_Impl_vector<unsigned int,vostok::ai::std_allocator<unsigned int> > *this,
        unsigned int __n,
        unsigned int *__val,
        const vostok::ai::std_allocator<unsigned int> *__a)
{
  stlp_std::priv::_Vector_base<unsigned int,vostok::ai::std_allocator<unsigned int>>::_Vector_base<unsigned int,vostok::ai::std_allocator<unsigned int>>(
    this,
    __n,
    __a);
  this->_M_finish = stlp_std::priv::__uninitialized_fill_n<unsigned int *,unsigned int,unsigned int>(
                      this->_M_start,
                      __n,
                      __val);
}
