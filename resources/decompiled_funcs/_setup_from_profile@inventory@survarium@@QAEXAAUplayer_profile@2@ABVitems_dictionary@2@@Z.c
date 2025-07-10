void __thiscall survarium::inventory::setup_from_profile(
        survarium::inventory *this,
        survarium::player_profile *profile,
        survarium::items_dictionary *dict)
{
  survarium::game_camera *v3; // ecx
  survarium::inventory_item *v4; // ecx
  survarium::game_camera *v5; // ecx
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v6; // ecx
  const vostok::variant<32> **v7; // eax
  vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v8; // ecx
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v9; // ecx
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v10; // ecx
  const vostok::variant<32> **v11; // eax
  const vostok::variant<32> **v12; // eax
  survarium::inventory_item *v13; // ecx
  vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v15; // [esp+1Ch] [ebp-3Ch]
  vostok::ai::sound_player *object; // [esp+20h] [ebp-38h]
  survarium::inventory_item *v17; // [esp+28h] [ebp-30h]
  vostok::resources::resource_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base> *v18; // [esp+2Ch] [ebp-2Ch]
  survarium::inventory *v19; // [esp+30h] [ebp-28h]
  unsigned int k; // [esp+34h] [ebp-24h]
  unsigned int amount; // [esp+38h] [ebp-20h]
  vostok::resources::resource_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base> *iitem; // [esp+3Ch] [ebp-1Ch]
  survarium::inventory *v23; // [esp+40h] [ebp-18h]
  unsigned int j; // [esp+44h] [ebp-14h]
  vostok::resources::resource_ptr<survarium::weapon_core,vostok::resources::unmanaged_intrusive_base> weapon; // [esp+48h] [ebp-10h] BYREF
  survarium::profile_slot_enum current; // [esp+4Ch] [ebp-Ch]
  unsigned int i; // [esp+50h] [ebp-8h]
  survarium::profile_slot *slot; // [esp+54h] [ebp-4h]

  for ( i = 0; i < 2; ++i )
  {
    current = weapon_slots[i];
    slot = &profile->slots[current];
    if ( profile->slots[current].item.id )
    {
      v15 = (vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)survarium::inventory::item_in_slot((survarium::inventory *)current, (int)this);
      object = (vostok::ai::sound_player *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr(v15);
      vostok::resources::resource_ptr<vostok::ai::sound_player,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::ai::sound_player,vostok::resources::unmanaged_intrusive_base>(
        (vostok::resources::resource_ptr<vostok::ai::sound_player,vostok::resources::unmanaged_intrusive_base> *)&weapon,
        object);
      survarium::weapon_user_dead_state::finalize(v3);
      LOWORD(v4) = slot->item.condition_or_stack;
      survarium::inventory_item::set_amount(v4, (int)weapon.m_object);
      survarium::weapon_user_dead_state::finalize(v5);
      weapon.m_object->m_load_ammo_on_next_activate = 1;
      vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&weapon);
    }
  }
  for ( j = 0; j < 4; ++j )
  {
    v23 = (survarium::inventory *)ammunition_slots[j];
    slot = &profile->slots[(_DWORD)v23];
    if ( profile->slots[(_DWORD)v23].item.id )
    {
      iitem = survarium::inventory::item_in_slot(v23, (int)this);
      amount = vostok::math::min(slot->item.condition_or_stack, slot->item.amount_in_inventory);
      v7 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v6, (int)iitem);
      survarium::inventory_item::set_amount((survarium::inventory_item *)amount, (int)v7);
      slot->item.amount_in_inventory -= amount;
    }
  }
  for ( k = 0; k < 0xD; ++k )
  {
    v19 = (survarium::inventory *)item_slots[k];
    slot = &profile->slots[(_DWORD)v19];
    if ( profile->slots[(_DWORD)v19].item.id )
    {
      v18 = survarium::inventory::item_in_slot(v19, (int)this);
      if ( vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator survarium::inventory_item * (__thiscall vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::*)(void)const(
             v8,
             v18) )
      {
        if ( survarium::items_dictionary::item_by_id(dict, slot->item.dict_id)[283].gap0 )
        {
          v17 = (survarium::inventory_item *)vostok::math::min(
                                               slot->item.condition_or_stack,
                                               slot->item.amount_in_inventory);
          v11 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v10, (int)v18);
          survarium::inventory_item::set_amount(v17, (int)v11);
          slot->item.amount_in_inventory -= (unsigned int)v17;
        }
        else
        {
          v12 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v9, (int)v18);
          HIWORD(v13) = HIWORD(slot);
          LOWORD(v13) = slot->item.condition_or_stack;
          survarium::inventory_item::set_amount(v13, (int)v12);
        }
      }
    }
  }
}
