stlp_std::priv::_Impl_vector<vostok::ai::planning::world_state_property,vostok::ai::std_allocator<vostok::ai::planning::world_state_property> > *__thiscall stlp_std::priv::_Impl_vector<vostok::ai::planning::world_state_property,vostok::ai::std_allocator<vostok::ai::planning::world_state_property>>::operator=(
        stlp_std::priv::_Impl_vector<vostok::ai::planning::world_state_property,vostok::ai::std_allocator<vostok::ai::planning::world_state_property> > *this,
        const stlp_std::priv::_Impl_vector<vostok::ai::planning::world_state_property,vostok::ai::std_allocator<vostok::ai::planning::world_state_property> > *__x)
{
  vostok::ai::planning::world_state_property *__last; // [esp+68h] [ebp-38h]
  vostok::ai::planning::world_state_property *__first; // [esp+6Ch] [ebp-34h]
  vostok::ai::planning::world_state_property *__result; // [esp+88h] [ebp-18h]
  unsigned int __len; // [esp+98h] [ebp-8h] BYREF
  unsigned int __xlen; // [esp+9Ch] [ebp-4h]

  if ( __x != this )
  {
    __xlen = __x->_M_finish - __x->_M_start;
    if ( __xlen <= this->_M_end_of_storage._M_data - this->_M_start )
    {
      if ( this->_M_finish - this->_M_start < __xlen )
      {
        stlp_std::priv::__copy_trivial(
          (unsigned __int8 *)__x->_M_start,
          (unsigned __int8 *)&__x->_M_start[this->_M_finish - this->_M_start],
          (unsigned __int8 *)this->_M_start);
        stlp_std::priv::__ucopy_trivial(
          (unsigned __int8 *)&__x->_M_start[this->_M_finish - this->_M_start],
          (unsigned __int8 *)__x->_M_finish,
          (unsigned __int8 *)this->_M_finish);
      }
      else
      {
        stlp_std::priv::__copy_trivial(
          (unsigned __int8 *)__x->_M_start,
          (unsigned __int8 *)__x->_M_finish,
          (unsigned __int8 *)this->_M_start);
      }
    }
    else
    {
      __len = __xlen;
      __last = __x->_M_finish;
      __first = __x->_M_start;
      __result = stlp_std::priv::_STLP_alloc_proxy<vostok::ai::planning::world_state_property *,vostok::ai::planning::world_state_property,vostok::ai::std_allocator<vostok::ai::planning::world_state_property>>::allocate(
                   &this->_M_end_of_storage,
                   __xlen,
                   &__len);
      stlp_std::uninitialized_copy<void * *,void * *>(__first, __last, __result);
      stlp_std::priv::_Impl_vector<vostok::ai::planning::world_state_property,vostok::ai::std_allocator<vostok::ai::planning::world_state_property>>::_M_clear(this);
      this->_M_start = __result;
      this->_M_end_of_storage._M_data = &this->_M_start[__len];
    }
    this->_M_finish = &this->_M_start[__xlen];
  }
  return this;
}
