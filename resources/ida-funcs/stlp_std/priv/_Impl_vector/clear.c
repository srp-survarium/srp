void __usercall stlp_std::priv::_Impl_vector<void *,survarium::std_allocator<void *>>::clear(
        stlp_std::priv::_Impl_vector<void *,survarium::std_allocator<void *> > *this@<ecx>,
        void ***a2@<esi>)
{
  void **v2; // eax
  void **v3; // edi

  v2 = a2[1];
  if ( *a2 != v2 )
  {
    v3 = stlp_std::priv::__copy_ptrs<void * *,void * *>(v2, v2, *a2);
    stlp_std::_Destroy<vostok::fs_new::virtual_path_string>(v3, a2[1]);
    a2[1] = v3;
  }
}


void __thiscall stlp_std::priv::_Impl_vector<vostok::sound::search::vertex_id_type,vostok::sound::std_allocator<vostok::sound::search::vertex_id_type>>::clear(
        stlp_std::priv::_Impl_vector<vostok::sound::search::vertex_id_type,vostok::sound::std_allocator<vostok::sound::search::vertex_id_type> > *this)
{
  stlp_std::__false_type __formal; // [esp+1Fh] [ebp-9h] BYREF
  vostok::sound::search::vertex_id_type *__first; // [esp+20h] [ebp-8h]
  vostok::sound::search::vertex_id_type *__last; // [esp+24h] [ebp-4h]

  __last = this->_M_finish;
  __first = this->_M_start;
  if ( __first != __last )
  {
    __formal = 0;
    stlp_std::priv::_Impl_vector<vostok::sound::search::vertex_id_type,vostok::sound::std_allocator<vostok::sound::search::vertex_id_type>>::_M_erase(
      this,
      __first,
      __last,
      &__formal);
  }
}


void __thiscall stlp_std::priv::_Impl_vector<vostok::ai::planning::pddl_world_state_property_impl,vostok::ai::std_allocator<vostok::ai::planning::pddl_world_state_property_impl>>::clear(
        stlp_std::priv::_Impl_vector<vostok::ai::planning::pddl_world_state_property_impl,vostok::ai::std_allocator<vostok::ai::planning::pddl_world_state_property_impl> > *this)
{
  stlp_std::__false_type __formal; // [esp+3Bh] [ebp-9h] BYREF
  vostok::ai::planning::pddl_world_state_property_impl *__first; // [esp+3Ch] [ebp-8h]
  vostok::ai::planning::pddl_world_state_property_impl *__last; // [esp+40h] [ebp-4h]

  __last = this->_M_finish;
  __first = this->_M_start;
  if ( __first != __last )
  {
    __formal = 0;
    stlp_std::priv::_Impl_vector<vostok::ai::planning::pddl_world_state_property_impl,vostok::ai::std_allocator<vostok::ai::planning::pddl_world_state_property_impl>>::_M_erase(
      this,
      __first,
      __last,
      &__formal);
  }
}


void __thiscall stlp_std::priv::_Impl_vector<vostok::ai::planning::world_state_property,vostok::ai::std_allocator<vostok::ai::planning::world_state_property>>::clear(
        stlp_std::priv::_Impl_vector<vostok::ai::planning::world_state_property,vostok::ai::std_allocator<vostok::ai::planning::world_state_property> > *this)
{
  stlp_std::__false_type __formal; // [esp+1Fh] [ebp-9h] BYREF
  vostok::ai::planning::world_state_property *__first; // [esp+20h] [ebp-8h]
  vostok::ai::planning::world_state_property *__last; // [esp+24h] [ebp-4h]

  __last = this->_M_finish;
  __first = this->_M_start;
  if ( __first != __last )
  {
    __formal = 0;
    stlp_std::priv::_Impl_vector<survarium::hit_receiver_info,survarium::std_allocator<survarium::hit_receiver_info>>::_M_erase(
      this,
      __first,
      __last,
      &__formal);
  }
}
