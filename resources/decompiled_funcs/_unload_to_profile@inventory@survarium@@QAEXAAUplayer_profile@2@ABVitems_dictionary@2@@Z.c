void __thiscall survarium::inventory::unload_to_profile(
        survarium::inventory *this,
        survarium::player_profile *profile,
        survarium::items_dictionary *dict)
{
  survarium::game_camera *v3; // ecx
  survarium::game_camera *v4; // ecx
  survarium::game_camera *v5; // ecx
  survarium::inventory_item *v6; // ecx
  unsigned __int16 v7; // ax
  vostok::resources::resource_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base> *v8; // eax
  survarium::game_camera *v9; // ecx
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v10; // ecx
  const vostok::variant<32> **v11; // eax
  survarium::inventory_item *v12; // ecx
  unsigned __int16 v13; // ax
  vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v14; // ecx
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v15; // ecx
  const vostok::variant<32> **v16; // eax
  survarium::inventory_item *v17; // ecx
  unsigned __int16 v18; // ax
  const vostok::variant<32> **v19; // eax
  survarium::inventory_item *v20; // ecx
  unsigned __int16 v21; // ax
  vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v23; // [esp+1Ch] [ebp-34h]
  vostok::ai::sound_player *object; // [esp+20h] [ebp-30h]
  vostok::resources::resource_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base> *iitem; // [esp+28h] [ebp-28h]
  survarium::inventory *v26; // [esp+2Ch] [ebp-24h]
  unsigned int k; // [esp+30h] [ebp-20h]
  vostok::resources::resource_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base> ammo; // [esp+34h] [ebp-1Ch] BYREF
  survarium::inventory *v29; // [esp+38h] [ebp-18h]
  unsigned int j; // [esp+3Ch] [ebp-14h]
  vostok::resources::resource_ptr<survarium::weapon_core,vostok::resources::unmanaged_intrusive_base> weapon; // [esp+40h] [ebp-10h] BYREF
  survarium::profile_slot_enum current; // [esp+44h] [ebp-Ch]
  unsigned int i; // [esp+48h] [ebp-8h]
  survarium::profile_slot *slot; // [esp+4Ch] [ebp-4h]

  for ( i = 0; i < 2; ++i )
  {
    current = weapon_slots[i];
    slot = &profile->slots[current];
    if ( profile->slots[current].item.id )
    {
      v23 = (vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)survarium::inventory::item_in_slot((survarium::inventory *)current, (int)this);
      object = (vostok::ai::sound_player *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr(v23);
      vostok::resources::resource_ptr<vostok::ai::sound_player,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::ai::sound_player,vostok::resources::unmanaged_intrusive_base>(
        (vostok::resources::resource_ptr<vostok::ai::sound_player,vostok::resources::unmanaged_intrusive_base> *)&weapon,
        object);
      survarium::weapon_user_dead_state::finalize(v3);
      survarium::weapon_user_dead_state::finalize(v4);
      survarium::weapon_core::unload_ammo(weapon.m_object);
      survarium::weapon_user_dead_state::finalize(v5);
      v7 = survarium::inventory_item::amount(v6, (int)weapon.m_object);
      slot->item.condition_or_stack = v7;
      vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&weapon);
    }
  }
  for ( j = 0; j < 4; ++j )
  {
    v29 = (survarium::inventory *)ammunition_slots[j];
    slot = &profile->slots[(_DWORD)v29];
    if ( profile->slots[(_DWORD)v29].item.id )
    {
      v8 = survarium::inventory::item_in_slot(v29, (int)this);
      vostok::resources::resource_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base>::resource_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base>(
        (vostok::intrusive_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v8,
        (survarium::inventory **)&ammo);
      survarium::weapon_user_dead_state::finalize(v9);
      v11 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v10, (int)&ammo);
      v13 = survarium::inventory_item::amount(v12, (int)v11);
      slot->item.amount_in_inventory += v13;
      vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>((vostok::resources::resource_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base> *)&ammo);
    }
  }
  for ( k = 0; k < 0xD; ++k )
  {
    v26 = (survarium::inventory *)item_slots[k];
    slot = &profile->slots[(_DWORD)v26];
    if ( profile->slots[(_DWORD)v26].item.id )
    {
      iitem = survarium::inventory::item_in_slot(v26, (int)this);
      if ( vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator survarium::inventory_item * (__thiscall vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::*)(void)const(
             v14,
             iitem) )
      {
        if ( survarium::items_dictionary::item_by_id(dict, slot->item.dict_id)[283].gap0 )
        {
          v16 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v15, (int)iitem);
          v18 = survarium::inventory_item::amount(v17, (int)v16);
          slot->item.amount_in_inventory += v18;
        }
        else
        {
          v19 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v15, (int)iitem);
          v21 = survarium::inventory_item::amount(v20, (int)v19);
          slot->item.condition_or_stack = v21;
        }
      }
    }
  }
}
