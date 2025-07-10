void __thiscall stlp_std::priv::_Impl_vector<unsigned int,vostok::ai::std_allocator<unsigned int>>::_M_fill_insert_aux(
        stlp_std::priv::_Impl_vector<unsigned int,vostok::ai::std_allocator<unsigned int> > *this,
        unsigned int *__pos,
        unsigned int __n,
        unsigned int *__x,
        const stlp_std::__false_type *__formal)
{
  stlp_std::__false_type v7; // [esp+37h] [ebp-Dh] BYREF
  unsigned int __x_copy; // [esp+38h] [ebp-Ch] BYREF
  unsigned int *__old_finish; // [esp+3Ch] [ebp-8h]
  unsigned int __elems_after; // [esp+40h] [ebp-4h]

  if ( __x >= this->_M_start && __x < this->_M_finish )
  {
    __x_copy = *__x;
    v7 = 0;
    stlp_std::priv::_Impl_vector<unsigned int,vostok::ai::std_allocator<unsigned int>>::_M_fill_insert_aux(
      this,
      __pos,
      __n,
      &__x_copy,
      &v7);
  }
  else
  {
    __elems_after = this->_M_finish - __pos;
    __old_finish = this->_M_finish;
    if ( __elems_after <= __n )
    {
      this->_M_finish = stlp_std::priv::__uninitialized_fill_n<unsigned int *,unsigned int,unsigned int>(
                          this->_M_finish,
                          __n - __elems_after,
                          __x);
      stlp_std::priv::__ucopy_ptrs<unsigned int *,unsigned int *>(
        (char *)__pos,
        (unsigned __int8 *)this->_M_finish,
        (char *)__old_finish);
      this->_M_finish += __elems_after;
      stlp_std::fill<unsigned int *,unsigned int>(__old_finish, __x, __pos);
    }
    else
    {
      stlp_std::priv::__ucopy_ptrs<unsigned int *,unsigned int *>(
        (char *)&this->_M_finish[-__n],
        (unsigned __int8 *)this->_M_finish,
        (char *)this->_M_finish);
      this->_M_finish += __n;
      stlp_std::priv::__copy_backward_ptrs<unsigned int *,unsigned int *>(
        (char *)&__old_finish[-__n],
        (unsigned __int8 *)__old_finish,
        __pos);
      stlp_std::fill<unsigned int *,unsigned int>(&__pos[__n], __x, __pos);
    }
  }
}
