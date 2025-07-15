survarium::booby_trap_core *__thiscall survarium::booby_trap_set_core::find_inactive_trap(
        survarium::booby_trap_set_core *this,
        int a2)
{
  vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base> *v2; // eax
  vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base> *v3; // edx
  vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base> *v4; // eax
  boost::_bi::bind_t<bool,boost::_bi::logical_not,boost::_bi::list1<boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::booby_trap_core>,boost::_bi::list1<boost::_bi::bind_t<survarium::booby_trap_core *,boost::_mfi::cmf0<survarium::booby_trap_core *,vostok::intrusive_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> >,boost::_bi::list1<boost::arg<1> > > > > > > v6; // [esp-18h] [ebp-54h] BYREF
  _DWORD v7[11]; // [esp+10h] [ebp-2Ch] BYREF

  v7[6] = survarium::booby_trap_core::is_active;
  v7[7] = 0;
  v2 = *(vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base> **)(a2 + 288);
  v7[8] = vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr;
  v3 = *(vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base> **)(a2 + 292);
  v7[2] = survarium::booby_trap_core::is_active;
  v7[3] = 0;
  v7[4] = vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr;
  v7[5] = v7[9];
  qmemcpy(&v6, v7, sizeof(v6));
  v4 = stlp_std::priv::__find_if<vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base> *,boost::_bi::bind_t<bool,boost::_bi::logical_not,boost::_bi::list1<boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::booby_trap_core>,boost::_bi::list1<boost::_bi::bind_t<survarium::booby_trap_core *,boost::_mfi::cmf0<survarium::booby_trap_core *,vostok::intrusive_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>>,boost::_bi::list1<boost::arg<1>>>>>>>>(
         v2,
         v3,
         v6);
  if ( v4 == *(vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base> **)(a2 + 292) )
    return 0;
  else
    return v4->m_object;
}
