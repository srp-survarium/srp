void __userpurge survarium::inventory::setup_from_profile(
        survarium::inventory *this@<ecx>,
        float a2@<xmm0>,
        survarium::player_profile *profile,
        int a4)
{
  __int32 v4; // ecx
  _WORD *v5; // esi
  survarium::empty_hands *m_object; // edi
  survarium::inventory_item *v7; // ecx
  __int32 v8; // eax
  _DWORD *v9; // esi
  int v10; // ecx
  survarium::profile_slot_enum v11; // eax
  bool v12; // zf
  survarium::empty_hands *v13; // edi
  unsigned int *v14; // esi
  survarium::inventory_item *v15; // ecx
  int v16; // ecx
  int v17; // ecx
  float v18; // xmm0_4
  unsigned __int8 v19; // al
  _DWORD *v20; // eax
  unsigned __int8 v21; // [esp+17h] [ebp-11h]
  unsigned __int8 m; // [esp+17h] [ebp-11h]
  unsigned int i; // [esp+1Ch] [ebp-Ch]
  unsigned int j; // [esp+1Ch] [ebp-Ch]
  unsigned int k; // [esp+1Ch] [ebp-Ch]
  vostok::intrusive_ptr<survarium::empty_hands,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v26; // [esp+20h] [ebp-8h] BYREF
  int v27; // [esp+24h] [ebp-4h]

  for ( i = 0; i < 2; ++i )
  {
    v4 = 16 * weapon_slots[i];
    v5 = (_WORD *)(v4 + a4 + 72);
    if ( *(_DWORD *)(v4 + a4 + 80) )
    {
      vostok::static_cast_resource_ptr<vostok::resources::resource_ptr<survarium::weapon_core,vostok::resources::unmanaged_intrusive_base>,survarium::inventory_item,vostok::resources::unmanaged_intrusive_base>(
        (const vostok::resources::resource_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base> *)&profile->slots[12].id
      + weapon_slots[i],
        (vostok::resources::resource_ptr<survarium::weapon_core,vostok::resources::unmanaged_intrusive_base> *)&v26);
      m_object = v26.m_object;
      LOWORD(v7) = *v5;
      survarium::inventory_item::set_amount(v7, (int)&v26.m_object->vostok::resources::unmanaged_resource);
      BYTE3(m_object[3].m_reconstruction_info_actuality_tick) = 1;
      vostok::intrusive_ptr<survarium::empty_hands,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v26);
    }
  }
  for ( j = 0; j < 8; ++j )
  {
    v8 = 16 * ammunition_slots[j];
    v9 = (_DWORD *)(v8 + a4 + 72);
    if ( *(_DWORD *)(v8 + a4 + 80) && *v9 )
    {
      survarium::inventory_item::set_amount(
        (survarium::inventory_item *)(v9[1] + (*v9 < v9[1] ? *v9 - v9[1] : 0)),
        *(&profile->slots[12].id + ammunition_slots[j]));
      v9[1] -= v10;
    }
  }
  for ( k = 0; k < 13; ++k )
  {
    v11 = item_slots[k];
    v12 = *(_DWORD *)(16 * v11 + a4 + 80) == 0;
    v27 = 16 * v11 + a4 + 72;
    if ( !v12 )
    {
      vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
        (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v26,
        (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&profile->slots[12].id
      + v11);
      v13 = v26.m_object;
      if ( v26.m_object
        && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
      {
        v14 = (unsigned int *)v27;
        if ( survarium::items_dictionary::item_by_id(
               (survarium::items_dictionary *)profile->slots[12].amount_in_inventory,
               (survarium::items_dictionary_vtbl *)*(unsigned __int16 *)(v27 + 12))->is_stack )
        {
          survarium::inventory_item::set_amount(
            (survarium::inventory_item *)(v14[1] + ((*v14 - v14[1]) & ((*v14 - (unsigned __int64)v14[1]) >> 32))),
            (int)v13);
          v14[1] -= v16;
        }
        else
        {
          LOWORD(v15) = *(_WORD *)v14;
          survarium::inventory_item::set_amount(v15, (int)v13);
        }
        v13->on_player_model_removed(v13);
      }
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v26);
    }
  }
  v21 = 13;
  while ( 1 )
  {
    v17 = *(&profile->slots[12].id + v21);
    if ( !v17 || (*(int (__thiscall **)(int))(*(_DWORD *)v17 + 68))(v17) )
      break;
    if ( ++v21 >= 0x13u )
      goto LABEL_26;
  }
  v18 = survarium::player_params_modifiers_container::apply_modifier(
          (survarium::player_params_modifiers_container *)(a4 + 448),
          artefact_slots_modifier,
          a2,
          0.0,
          1.0);
  v19 = vostok::math::floor(v18);
  LOBYTE(profile->slots[18].id) = 19 - v21 + (v19 < (unsigned __int8)(19 - v21) ? v19 - (19 - v21) : 0);
  profile->slots[18].amount_in_inventory = (unsigned int)(&profile->slots[12].id + v21);
LABEL_26:
  for ( m = 0; m < LOBYTE(profile->slots[18].id); ++m )
  {
    v20 = (_DWORD *)(profile->slots[18].amount_in_inventory + 4 * m);
    if ( *v20
      && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      (*(void (__thiscall **)(_DWORD))(*(_DWORD *)*v20 + 48))(*v20);
    }
  }
  LOBYTE(profile->slots[20].amount_in_inventory) = 1;
}
