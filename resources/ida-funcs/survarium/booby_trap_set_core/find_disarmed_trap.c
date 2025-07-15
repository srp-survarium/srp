survarium::booby_trap_core *__thiscall survarium::booby_trap_set_core::find_disarmed_trap(
        survarium::booby_trap_set_core *this,
        int a2)
{
  vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base> *v2; // eax
  boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::booby_trap_core>,boost::_bi::list1<boost::_bi::bind_t<survarium::booby_trap_core *,boost::_mfi::cmf0<survarium::booby_trap_core *,vostok::intrusive_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> >,boost::_bi::list1<boost::arg<1> > > > > v4; // [esp-10h] [ebp-34h]
  int v5; // [esp+1Ch] [ebp-8h]

  LODWORD(v4.f_.f_) = survarium::booby_trap_core::is_disarmed;
  HIDWORD(v4.f_.f_) = 0;
  v4.l_.a1_.f_.f_ = (survarium::booby_trap_core *(__thiscall *)(vostok::intrusive_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *))vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr;
  *(_DWORD *)&v4.l_.a1_.l_.boost::_bi::storage1<boost::arg<1> > = v5;
  v2 = stlp_std::priv::__find_if<vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base> *,boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::booby_trap_core>,boost::_bi::list1<boost::_bi::bind_t<survarium::booby_trap_core *,boost::_mfi::cmf0<survarium::booby_trap_core *,vostok::intrusive_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>>,boost::_bi::list1<boost::arg<1>>>>>>(
         *(vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base> **)(a2 + 288),
         *(vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base> **)(a2 + 292),
         v4);
  if ( v2 == *(vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base> **)(a2 + 292) )
    return 0;
  else
    return v2->m_object;
}
