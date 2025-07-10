void __thiscall stlp_std::priv::_Impl_vector<vostok::sound::propagator_info,vostok::vectora_allocator<vostok::sound::propagator_info>>::push_back(
        stlp_std::priv::_Impl_vector<vostok::sound::propagator_info,vostok::vectora_allocator<vostok::sound::propagator_info> > *this,
        const vostok::sound::propagator_info *__x)
{
  stlp_std::__true_type __formal; // [esp+Fh] [ebp-1h] BYREF

  if ( this->_M_finish == this->_M_end_of_storage._M_data )
  {
    __formal = 0;
    stlp_std::priv::_Impl_vector<vostok::sound::propagator_info,vostok::vectora_allocator<vostok::sound::propagator_info>>::_M_insert_overflow(
      this,
      this->_M_finish,
      __x,
      &__formal,
      1u,
      1);
  }
  else
  {
    *this->_M_finish++ = *__x;
  }
}
