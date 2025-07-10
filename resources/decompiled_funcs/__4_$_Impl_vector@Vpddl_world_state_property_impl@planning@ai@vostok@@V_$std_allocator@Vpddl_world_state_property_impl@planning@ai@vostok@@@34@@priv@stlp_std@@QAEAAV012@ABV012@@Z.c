stlp_std::priv::_Impl_vector<vostok::ai::planning::pddl_world_state_property_impl,vostok::ai::std_allocator<vostok::ai::planning::pddl_world_state_property_impl> > *__thiscall stlp_std::priv::_Impl_vector<vostok::ai::planning::pddl_world_state_property_impl,vostok::ai::std_allocator<vostok::ai::planning::pddl_world_state_property_impl>>::operator=(
        stlp_std::priv::_Impl_vector<vostok::ai::planning::pddl_world_state_property_impl,vostok::ai::std_allocator<vostok::ai::planning::pddl_world_state_property_impl> > *this,
        const stlp_std::priv::_Impl_vector<vostok::ai::planning::pddl_world_state_property_impl,vostok::ai::std_allocator<vostok::ai::planning::pddl_world_state_property_impl> > *__x)
{
  vostok::ai::planning::pddl_world_state_property_impl *__val; // [esp+10h] [ebp-D8h]
  int i; // [esp+38h] [ebp-B0h]
  vostok::ai::planning::pddl_world_state_property_impl *__p; // [esp+3Ch] [ebp-ACh]
  stlp_std::random_access_iterator_tag v7; // [esp+63h] [ebp-85h] BYREF
  vostok::ai::planning::pddl_world_state_property_impl *M_finish; // [esp+64h] [ebp-84h]
  vostok::ai::planning::pddl_world_state_property_impl *__last; // [esp+B0h] [ebp-38h]
  vostok::ai::planning::pddl_world_state_property_impl *__first; // [esp+B4h] [ebp-34h]
  vostok::ai::planning::pddl_world_state_property_impl *__result; // [esp+D0h] [ebp-18h]
  char v12; // [esp+D5h] [ebp-13h]
  char v13; // [esp+D6h] [ebp-12h]
  stlp_std::__false_type __formal; // [esp+D7h] [ebp-11h] BYREF
  vostok::ai::planning::pddl_world_state_property_impl *__i; // [esp+D8h] [ebp-10h]
  vostok::ai::planning::pddl_world_state_property_impl *__tmp; // [esp+DCh] [ebp-Ch]
  unsigned int __len; // [esp+E0h] [ebp-8h] BYREF
  unsigned int __xlen; // [esp+E4h] [ebp-4h]

  if ( __x != this )
  {
    __xlen = __x->_M_finish - __x->_M_start;
    if ( __xlen <= this->_M_end_of_storage._M_data - this->_M_start )
    {
      if ( this->_M_finish - this->_M_start < __xlen )
      {
        v13 = 0;
        stlp_std::priv::__copy<vostok::ai::planning::pddl_world_state_property_impl const *,vostok::ai::planning::pddl_world_state_property_impl *,int>(
          __x->_M_start,
          &__x->_M_start[this->_M_finish - this->_M_start],
          this->_M_start,
          &v7,
          0);
        v12 = 0;
        __val = &__x->_M_start[this->_M_finish - this->_M_start];
        __p = this->_M_finish;
        for ( i = __x->_M_finish - __val; i > 0; --i )
          stlp_std::_Param_Construct<vostok::ai::planning::pddl_world_state_property_impl,vostok::ai::planning::pddl_world_state_property_impl>(
            __p++,
            __val++);
      }
      else
      {
        __formal = 0;
        __i = stlp_std::priv::__copy_ptrs<vostok::ai::planning::pddl_world_state_property_impl const *,vostok::ai::planning::pddl_world_state_property_impl *>(
                __x->_M_start,
                __x->_M_finish,
                this->_M_start,
                &__formal);
        M_finish = this->_M_finish;
        stlp_std::__destroy_range<vostok::ai::planning::pddl_world_state_property_impl *,vostok::ai::planning::pddl_world_state_property_impl>(
          __i,
          M_finish,
          0);
      }
    }
    else
    {
      __len = __xlen;
      __last = __x->_M_finish;
      __first = __x->_M_start;
      __result = stlp_std::priv::_STLP_alloc_proxy<vostok::ai::planning::pddl_world_state_property_impl *,vostok::ai::planning::pddl_world_state_property_impl,vostok::ai::std_allocator<vostok::ai::planning::pddl_world_state_property_impl>>::allocate(
                   &this->_M_end_of_storage,
                   __xlen,
                   &__len);
      stlp_std::uninitialized_copy<vostok::ai::planning::pddl_world_state_property_impl const *,vostok::ai::planning::pddl_world_state_property_impl *>(
        __first,
        __last,
        __result);
      __tmp = __result;
      stlp_std::priv::_Impl_vector<vostok::ai::planning::pddl_world_state_property_impl,vostok::ai::std_allocator<vostok::ai::planning::pddl_world_state_property_impl>>::_M_clear_after_move(this);
      this->_M_start = __result;
      this->_M_end_of_storage._M_data = &this->_M_start[__len];
    }
    this->_M_finish = &this->_M_start[__xlen];
  }
  return this;
}
