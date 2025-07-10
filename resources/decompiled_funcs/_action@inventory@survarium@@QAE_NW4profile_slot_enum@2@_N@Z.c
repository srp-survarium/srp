char __thiscall survarium::inventory::action(
        survarium::inventory *this,
        survarium::profile_slot_enum slot_id,
        bool key_down)
{
  vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v3; // ecx
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v4; // ecx
  const vostok::variant<32> *v5; // ecx
  const vostok::variant<32> **v7; // [esp+0h] [ebp-20h]
  vostok::resources::resource_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base> iitem; // [esp+1Ch] [ebp-4h] BYREF

  vostok::resources::resource_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base>::resource_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base>(
    (vostok::intrusive_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_slots[slot_id],
    (survarium::inventory **)&iitem);
  if ( vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator survarium::inventory_item * (__thiscall vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::*)(void)const(
         v3,
         &iitem) )
  {
    v5 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v4, (int)&iitem)[66];
    if ( v5 == (const vostok::variant<32> *)1 )
    {
      v7 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
             (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)1,
             (int)&iitem);
      ((void (__thiscall *)(const vostok::variant<32> **, bool))(*v7)[1].m_type_id)(v7, key_down);
    }
    else if ( v5 == (const vostok::variant<32> *)2
           && this->m_active_slot != slot_id
           && this->m_holder->set_new_active_item(this->m_holder, &iitem) )
    {
      this->m_active_slot = slot_id;
    }
    vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>((vostok::resources::resource_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base> *)&iitem);
    return 1;
  }
  else
  {
    vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>((vostok::resources::resource_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base> *)&iitem);
    return 0;
  }
}
