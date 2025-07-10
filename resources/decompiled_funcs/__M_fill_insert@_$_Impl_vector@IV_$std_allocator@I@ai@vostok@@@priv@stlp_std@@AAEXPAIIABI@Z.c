void __thiscall stlp_std::priv::_Impl_vector<unsigned int,vostok::ai::std_allocator<unsigned int>>::_M_fill_insert(
        stlp_std::priv::_Impl_vector<unsigned int,vostok::ai::std_allocator<unsigned int> > *this,
        unsigned __int8 *__pos,
        unsigned int __n,
        unsigned int *__x)
{
  stlp_std::__true_type v4; // [esp+6h] [ebp-2h] BYREF
  stlp_std::__false_type __formal; // [esp+7h] [ebp-1h] BYREF

  if ( __n )
  {
    if ( this->_M_end_of_storage._M_data - this->_M_finish < __n )
    {
      v4 = 0;
      stlp_std::priv::_Impl_vector<unsigned int,vostok::ai::std_allocator<unsigned int>>::_M_insert_overflow(
        this,
        __pos,
        __x,
        &v4,
        __n,
        0);
    }
    else
    {
      __formal = 0;
      stlp_std::priv::_Impl_vector<unsigned int,vostok::ai::std_allocator<unsigned int>>::_M_fill_insert_aux(
        this,
        (unsigned int *)__pos,
        __n,
        __x,
        &__formal);
    }
  }
}
