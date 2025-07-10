void __thiscall stlp_std::priv::_Impl_vector<unsigned int,vostok::ai::std_allocator<unsigned int>>::_M_insert_overflow(
        stlp_std::priv::_Impl_vector<unsigned int,vostok::ai::std_allocator<unsigned int> > *this,
        unsigned __int8 *__pos,
        unsigned int *__x,
        const stlp_std::__true_type *__formal,
        unsigned int __fill_len,
        bool __atend)
{
  unsigned __int8 *v6; // eax
  unsigned int *v8; // [esp+4h] [ebp-74h]
  unsigned __int8 *__new_finish; // [esp+6Ch] [ebp-Ch]
  unsigned int *__new_start; // [esp+70h] [ebp-8h]
  unsigned int __len; // [esp+74h] [ebp-4h] BYREF

  __len = stlp_std::priv::_Impl_vector<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>,vostok::vectora_allocator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>>>::_M_compute_next_size(
            this,
            __fill_len);
  __new_start = stlp_std::priv::_STLP_alloc_proxy<unsigned int *,unsigned int,vostok::ai::std_allocator<unsigned int>>::allocate(
                  &this->_M_end_of_storage,
                  __len,
                  &__len);
  v6 = stlp_std::priv::__copy_trivial((unsigned __int8 *)this->_M_start, __pos, (unsigned __int8 *)__new_start);
  __new_finish = (unsigned __int8 *)stlp_std::priv::__fill_n<unsigned int *,unsigned int,unsigned int>(
                                      __fill_len,
                                      __x,
                                      (unsigned int *)v6);
  if ( !__atend )
    __new_finish = stlp_std::priv::__copy_trivial(__pos, (unsigned __int8 *)this->_M_finish, __new_finish);
  stlp_std::priv::_Impl_vector<unsigned int,vostok::ai::std_allocator<unsigned int>>::_M_clear(this);
  v8 = &__new_start[__len];
  this->_M_start = __new_start;
  this->_M_finish = (unsigned int *)__new_finish;
  this->_M_end_of_storage._M_data = v8;
}
