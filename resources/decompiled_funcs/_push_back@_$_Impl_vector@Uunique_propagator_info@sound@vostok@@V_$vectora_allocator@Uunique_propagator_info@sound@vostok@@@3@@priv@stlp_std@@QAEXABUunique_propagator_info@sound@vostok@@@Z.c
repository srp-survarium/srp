void __thiscall stlp_std::priv::_Impl_vector<vostok::sound::unique_propagator_info,vostok::vectora_allocator<vostok::sound::unique_propagator_info>>::push_back(
        stlp_std::priv::_Impl_vector<vostok::sound::unique_propagator_info,vostok::vectora_allocator<vostok::sound::unique_propagator_info> > *this,
        const vostok::sound::unique_propagator_info *__x)
{
  vostok::sound::unique_propagator_info *__pos; // [esp+4h] [ebp-28h]
  stlp_std::__false_type __formal; // [esp+Bh] [ebp-21h] BYREF
  char v5; // [esp+2Bh] [ebp-1h]

  if ( this->_M_finish == this->_M_end_of_storage._M_data )
  {
    v5 = 0;
    __pos = this->_M_finish;
    __formal = 0;
    stlp_std::priv::_Impl_vector<vostok::sound::unique_propagator_info,vostok::vectora_allocator<vostok::sound::unique_propagator_info>>::_M_insert_overflow_aux(
      this,
      __pos,
      __x,
      &__formal,
      1u,
      1);
  }
  else
  {
    stlp_std::_Copy_Construct<vostok::sound::unique_propagator_info>(this->_M_finish, __x);
    ++this->_M_finish;
  }
}
