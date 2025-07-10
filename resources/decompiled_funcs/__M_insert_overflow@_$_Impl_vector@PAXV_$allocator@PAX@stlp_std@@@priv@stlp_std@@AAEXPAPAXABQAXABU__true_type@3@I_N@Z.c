void __thiscall stlp_std::priv::_Impl_vector<void *,stlp_std::allocator<void *>>::_M_insert_overflow(
        stlp_std::priv::_Impl_vector<void *,stlp_std::allocator<void *> > *this,
        void **__pos,
        void *const *__x,
        const stlp_std::__true_type *__formal,
        unsigned int __fill_len,
        bool __atend)
{
  unsigned __int8 *v6; // eax
  void **v8; // [esp+4h] [ebp-6Ch]
  void **__new_finish; // [esp+64h] [ebp-Ch]
  void **__new_start; // [esp+68h] [ebp-8h]
  unsigned int __len; // [esp+6Ch] [ebp-4h] BYREF

  __len = stlp_std::priv::_Impl_vector<void *,stlp_std::allocator<void *>>::_M_compute_next_size(this, __fill_len);
  __new_start = stlp_std::priv::_STLP_alloc_proxy<void * *,void *,stlp_std::allocator<void *>>::allocate(
                  &this->_M_end_of_storage,
                  __len,
                  &__len);
  v6 = stlp_std::priv::__copy_trivial(
         (unsigned __int8 *)this->_M_start,
         (unsigned __int8 *)__pos,
         (unsigned __int8 *)__new_start);
  __new_finish = stlp_std::priv::__fill_n<void * *,unsigned int,void *>((void **)v6, __fill_len, __x);
  if ( !__atend )
    __new_finish = (void **)stlp_std::priv::__copy_trivial(
                              (unsigned __int8 *)__pos,
                              (unsigned __int8 *)this->_M_finish,
                              (unsigned __int8 *)__new_finish);
  stlp_std::priv::_Impl_vector<void *,stlp_std::allocator<void *>>::_M_clear(this);
  v8 = &__new_start[__len];
  this->_M_start = __new_start;
  this->_M_finish = __new_finish;
  this->_M_end_of_storage._M_data = v8;
}
