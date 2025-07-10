void __thiscall stlp_std::priv::_Impl_vector<vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32>>>::_M_fill_insert(
        stlp_std::priv::_Impl_vector<vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32> > > *this,
        vostok::fixed_vector<unsigned int,32> *__pos,
        unsigned int __n,
        const vostok::fixed_vector<unsigned int,32> *__x)
{
  stlp_std::__false_type v4; // [esp+5h] [ebp-3h] BYREF
  char v5; // [esp+6h] [ebp-2h]
  stlp_std::__false_type __formal; // [esp+7h] [ebp-1h] BYREF

  if ( __n )
  {
    if ( this->_M_end_of_storage._M_data - this->_M_finish < __n )
    {
      v5 = 0;
      v4 = 0;
      stlp_std::priv::_Impl_vector<vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32>>>::_M_insert_overflow_aux(
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
      stlp_std::priv::_Impl_vector<vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32>>>::_M_fill_insert_aux(
        this,
        __pos,
        __n,
        __x,
        &__formal);
    }
  }
}
