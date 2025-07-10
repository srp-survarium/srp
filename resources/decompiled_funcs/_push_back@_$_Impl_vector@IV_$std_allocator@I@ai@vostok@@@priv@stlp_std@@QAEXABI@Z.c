void __thiscall stlp_std::priv::_Impl_vector<unsigned int,vostok::ai::std_allocator<unsigned int>>::push_back(
        stlp_std::priv::_Impl_vector<unsigned int,vostok::ai::std_allocator<unsigned int> > *this,
        unsigned int *__x)
{
  stlp_std::__true_type __formal; // [esp+Bh] [ebp-1h] BYREF

  if ( this->_M_finish == this->_M_end_of_storage._M_data )
  {
    __formal = 0;
    stlp_std::priv::_Impl_vector<unsigned int,vostok::ai::std_allocator<unsigned int>>::_M_insert_overflow(
      this,
      (unsigned __int8 *)this->_M_finish,
      __x,
      &__formal,
      1u,
      1);
  }
  else
  {
    stlp_std::_Copy_Construct<unsigned int>(this->_M_finish, __x);
    ++this->_M_finish;
  }
}
