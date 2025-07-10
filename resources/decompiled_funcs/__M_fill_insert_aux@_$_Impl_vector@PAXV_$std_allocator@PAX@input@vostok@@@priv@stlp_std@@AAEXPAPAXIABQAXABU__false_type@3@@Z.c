void __thiscall stlp_std::priv::_Impl_vector<void *,vostok::input::std_allocator<void *>>::_M_fill_insert_aux(
        stlp_std::priv::_Impl_vector<void *,vostok::input::std_allocator<void *> > *this,
        void **__pos,
        unsigned int __n,
        void **__x,
        const stlp_std::__false_type *__formal)
{
  void **M_finish; // esi
  unsigned int v7; // ebx
  void **v8; // ebx
  signed int v9; // ebx
  void **v10; // eax
  void *const *v11; // [esp-2Ch] [ebp-34h]
  void *__x_copy; // [esp+4h] [ebp-4h] BYREF
  unsigned int __na; // [esp+10h] [ebp+8h]

  if ( __x < this->_M_start || __x >= this->_M_finish )
  {
    M_finish = this->_M_finish;
    v7 = M_finish - __pos;
    if ( v7 <= __n )
    {
      v10 = stlp_std::priv::__uninitialized_fill_n<void * *,unsigned int,void *>(M_finish, __n - v7, __x);
      this->_M_finish = v10;
      stlp_std::priv::__ucopy_ptrs<void * *,void * *>(__pos, M_finish, v10);
      v11 = __x;
      this->_M_finish += v7;
      stlp_std::fill<void * *,void *>(__pos, M_finish, v11);
    }
    else
    {
      v8 = &M_finish[-__n];
      __na = __n;
      stlp_std::priv::__ucopy_ptrs<void * *,void * *>(v8, M_finish, M_finish);
      this->_M_finish = (void **)((char *)this->_M_finish + __na * 4);
      v9 = (char *)v8 - (char *)__pos;
      if ( v9 > 0 )
        memmove((unsigned __int8 *)M_finish - v9, (unsigned __int8 *)__pos, v9);
      stlp_std::fill<void * *,void *>(__pos, &__pos[__na], __x);
    }
  }
  else
  {
    __x_copy = *__x;
    LOBYTE(__x) = 0;
    stlp_std::priv::_Impl_vector<void *,vostok::input::std_allocator<void *>>::_M_fill_insert_aux(
      this,
      __pos,
      __n,
      &__x_copy,
      (const stlp_std::__false_type *)&__x);
  }
}
