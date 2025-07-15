void __thiscall survarium::inventory::setup_demo_profile(survarium::inventory *this)
{
  survarium::game_camera *v1; // ecx
  survarium::game_camera *v2; // ecx
  vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v3; // ecx
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v4; // ecx
  const vostok::variant<32> **v5; // eax
  vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v6; // ecx
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v7; // ecx
  const vostok::variant<32> **v8; // eax
  vostok::sound::encoded_sound_interface *(__thiscall *v10)(vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *); // [esp+10h] [ebp-38h]
  vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v11; // [esp+14h] [ebp-34h]
  survarium::weapon_user_animations_container *object; // [esp+18h] [ebp-30h]
  vostok::resources::resource_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base> *v13; // [esp+24h] [ebp-24h]
  unsigned int k; // [esp+2Ch] [ebp-1Ch]
  vostok::resources::resource_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base> *iitem; // [esp+30h] [ebp-18h]
  unsigned int j; // [esp+38h] [ebp-10h]
  vostok::resources::resource_ptr<survarium::weapon_core,vostok::resources::unmanaged_intrusive_base> weapon; // [esp+3Ch] [ebp-Ch] BYREF
  survarium::profile_slot_enum current; // [esp+40h] [ebp-8h]
  unsigned int i; // [esp+44h] [ebp-4h]

  for ( i = 0; i < 2; ++i )
  {
    current = weapon_slots[i];
    v11 = (vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)survarium::inventory::item_in_slot((survarium::inventory *)current, (int)this);
    object = (survarium::weapon_user_animations_container *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr(v11);
    weapon.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_allocation_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      (vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&weapon,
      object);
    if ( weapon.m_object )
      v10 = vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::c_ptr;
    else
      v10 = 0;
    if ( v10 )
    {
      survarium::weapon_user_dead_state::finalize(v1);
      survarium::inventory_item::set_amount((survarium::inventory_item *)0x64, (int)weapon.m_object);
      survarium::weapon_user_dead_state::finalize(v2);
      weapon.m_object->m_load_ammo_on_next_activate = 1;
    }
    vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&weapon);
  }
  for ( j = 0; j < 4; ++j )
  {
    iitem = survarium::inventory::item_in_slot((survarium::inventory *)ammunition_slots[j], (int)this);
    if ( vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator survarium::inventory_item * (__thiscall vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::*)(void)const(
           v3,
           iitem) )
    {
      v5 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v4, (int)iitem);
      survarium::inventory_item::set_amount((survarium::inventory_item *)0x64, (int)v5);
    }
  }
  for ( k = 0; k < 0xD; ++k )
  {
    v13 = survarium::inventory::item_in_slot((survarium::inventory *)item_slots[k], (int)this);
    if ( vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator survarium::inventory_item * (__thiscall vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::*)(void)const(
           v6,
           v13) )
    {
      v8 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v7, (int)v13);
      survarium::inventory_item::set_amount((survarium::inventory_item *)0x64, (int)v8);
    }
  }
}
