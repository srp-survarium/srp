void __thiscall survarium::inventory::set_item(
        survarium::inventory *this,
        survarium::profile_slot_enum slot,
        vostok::intrusive_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *item)
{
  survarium::game_camera *v3; // ecx
  survarium::inventory_item **v4; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v5; // ecx
  const vostok::variant<32> **v6; // eax
  survarium::inventory_slot *v8; // [esp+Ch] [ebp-1Ch]
  survarium::inventory_item *v9; // [esp+18h] [ebp-10h]
  vostok::resources::resource_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base> v10; // [esp+20h] [ebp-8h] BYREF
  char v11; // [esp+26h] [ebp-2h]
  char v12; // [esp+27h] [ebp-1h]

  v12 = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  v11 = 0;
  survarium::weapon_user_dead_state::finalize(v3);
  v8 = &this->m_slots[slot];
  vostok::resources::resource_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base>::resource_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base>(
    item,
    &v10.m_object);
  v9 = *v4;
  *v4 = v8->item.m_object;
  v8->item.m_object = v9;
  vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>(&v10);
  v6 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v5, (int)item);
  ((void (__thiscall *)(const vostok::variant<32> **, survarium::inventory *, survarium::profile_slot_enum))(*v6)[1].m_helper)(
    v6,
    this,
    slot);
}
