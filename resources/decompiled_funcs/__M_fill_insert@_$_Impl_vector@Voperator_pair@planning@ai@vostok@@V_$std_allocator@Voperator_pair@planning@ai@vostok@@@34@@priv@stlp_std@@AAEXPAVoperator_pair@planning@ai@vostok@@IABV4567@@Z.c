void __thiscall stlp_std::priv::_Impl_vector<vostok::ai::planning::operator_pair,vostok::ai::std_allocator<vostok::ai::planning::operator_pair>>::_M_fill_insert(
        stlp_std::priv::_Impl_vector<vostok::ai::planning::operator_pair,vostok::ai::std_allocator<vostok::ai::planning::operator_pair> > *this,
        vostok::ai::planning::operator_pair *__pos,
        unsigned int __n,
        const vostok::ai::planning::operator_pair *__x)
{
  stlp_std::__true_type v4; // [esp+6h] [ebp-2h] BYREF
  stlp_std::__false_type __formal; // [esp+7h] [ebp-1h] BYREF

  if ( __n )
  {
    if ( this->_M_end_of_storage._M_data - this->_M_finish < __n )
    {
      v4 = 0;
      stlp_std::priv::_Impl_vector<vostok::ai::planning::operator_pair,vostok::ai::std_allocator<vostok::ai::planning::operator_pair>>::_M_insert_overflow(
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
      stlp_std::priv::_Impl_vector<vostok::ai::planning::operator_pair,vostok::ai::std_allocator<vostok::ai::planning::operator_pair>>::_M_fill_insert_aux(
        this,
        __pos,
        __n,
        __x,
        &__formal);
    }
  }
}
