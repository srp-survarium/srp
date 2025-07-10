void __thiscall stlp_std::priv::_Impl_vector<vostok::ai::planning::specified_action,vostok::ai::std_allocator<vostok::ai::planning::specified_action>>::push_back(
        stlp_std::priv::_Impl_vector<vostok::ai::planning::specified_action,vostok::ai::std_allocator<vostok::ai::planning::specified_action> > *this,
        const vostok::ai::planning::specified_action *__x)
{
  vostok::ai::planning::specified_action *__pos; // [esp+4h] [ebp-30h]
  stlp_std::__false_type __formal; // [esp+Bh] [ebp-29h] BYREF
  char v5; // [esp+33h] [ebp-1h]

  if ( this->_M_finish == this->_M_end_of_storage._M_data )
  {
    v5 = 0;
    __pos = this->_M_finish;
    __formal = 0;
    stlp_std::priv::_Impl_vector<vostok::ai::planning::specified_action,vostok::ai::std_allocator<vostok::ai::planning::specified_action>>::_M_insert_overflow_aux(
      this,
      __pos,
      __x,
      &__formal,
      1u,
      1);
  }
  else
  {
    stlp_std::_Copy_Construct<vostok::ai::planning::specified_action>(this->_M_finish, __x);
    ++this->_M_finish;
  }
}
