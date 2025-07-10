void __thiscall stlp_std::priv::_Impl_vector<vostok::logging::initiator_filter,vostok::vectora_allocator<vostok::logging::initiator_filter>>::push_back(
        stlp_std::priv::_Impl_vector<vostok::logging::initiator_filter,vostok::vectora_allocator<vostok::logging::initiator_filter> > *this,
        const vostok::logging::initiator_filter *__x)
{
  vostok::logging::initiator_filter *__pos; // [esp+4h] [ebp-28h]
  stlp_std::__false_type __formal; // [esp+Ah] [ebp-22h] BYREF
  char v5; // [esp+2Bh] [ebp-1h]

  if ( this->_M_finish == this->_M_end_of_storage._M_data )
  {
    v5 = 0;
    __pos = this->_M_finish;
    __formal = 0;
    stlp_std::priv::_Impl_vector<vostok::logging::initiator_filter,vostok::vectora_allocator<vostok::logging::initiator_filter>>::_M_insert_overflow_aux(
      this,
      __pos,
      __x,
      &__formal,
      1u,
      1);
  }
  else
  {
    stlp_std::_Param_Construct<vostok::logging::initiator_filter,vostok::logging::initiator_filter>(
      this->_M_finish,
      __x);
    ++this->_M_finish;
  }
}
