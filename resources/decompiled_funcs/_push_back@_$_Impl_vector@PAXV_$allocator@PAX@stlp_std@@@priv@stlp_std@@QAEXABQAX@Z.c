void __thiscall stlp_std::priv::_Impl_vector<void *,stlp_std::allocator<void *>>::push_back(
        stlp_std::priv::_Impl_vector<void *,stlp_std::allocator<void *> > *this,
        void *const *__x)
{
  stlp_std::__true_type __formal; // [esp+Bh] [ebp-1h] BYREF

  if ( this->_M_finish == this->_M_end_of_storage._M_data )
  {
    __formal = 0;
    stlp_std::priv::_Impl_vector<void *,stlp_std::allocator<void *>>::_M_insert_overflow(
      this,
      this->_M_finish,
      __x,
      &__formal,
      1u,
      1);
  }
  else
  {
    stlp_std::_Copy_Construct<void *>(this->_M_finish, __x);
    ++this->_M_finish;
  }
}
