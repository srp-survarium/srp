void __thiscall survarium::inventory::unload_to_profile(
        survarium::inventory *this,
        survarium::player_profile *profile,
        int a3)
{
  int v3; // edi
  __int32 v4; // ecx
  _DWORD *v5; // ebx
  survarium::empty_hands *m_object; // esi
  survarium::weapon_core *v7; // ecx
  __int32 v8; // ecx
  _DWORD *v9; // ebx
  survarium::empty_hands *v10; // edx
  __int32 v11; // ecx
  _DWORD *v12; // esi
  int *v13; // ebx
  bool v14; // zf
  int v15; // eax
  unsigned int i; // [esp+10h] [ebp-8h]
  unsigned int j; // [esp+10h] [ebp-8h]
  unsigned int k; // [esp+10h] [ebp-8h]
  vostok::intrusive_ptr<survarium::empty_hands,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v19; // [esp+14h] [ebp-4h] BYREF

  for ( i = 0; i < 2; ++i )
  {
    v3 = a3;
    v4 = 16 * weapon_slots[i];
    v5 = (_DWORD *)(v4 + a3 + 72);
    if ( *(_DWORD *)(v4 + a3 + 80) )
    {
      vostok::static_cast_resource_ptr<vostok::resources::resource_ptr<survarium::weapon_core,vostok::resources::unmanaged_intrusive_base>,survarium::inventory_item,vostok::resources::unmanaged_intrusive_base>(
        (const vostok::resources::resource_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base> *)&profile->slots[12].id
      + weapon_slots[i],
        (vostok::resources::resource_ptr<survarium::weapon_core,vostok::resources::unmanaged_intrusive_base> *)&v19);
      m_object = v19.m_object;
      survarium::weapon_core::unload_ammo(v7, (survarium::weapon_core *)v19.m_object);
      *v5 = LOWORD(m_object->m_transform.lines[1].x);
      vostok::intrusive_ptr<survarium::empty_hands,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v19);
    }
  }
  for ( j = 0; j < 8; ++j )
  {
    v8 = 16 * ammunition_slots[j];
    v9 = (_DWORD *)(v8 + v3 + 72);
    if ( *(_DWORD *)(v8 + v3 + 80) && *v9 )
    {
      vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
        (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v19,
        (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&profile->slots[12].id
      + ammunition_slots[j]);
      v10 = v19.m_object;
      v9[1] += LOWORD(v19.m_object->m_transform.i.x);
      survarium::inventory_item::set_amount(0, (int)v10);
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v19);
      v3 = a3;
    }
  }
  for ( k = 0; k < 13; ++k )
  {
    v11 = 16 * item_slots[k];
    v12 = (_DWORD *)(v11 + v3 + 72);
    if ( *(_DWORD *)(v11 + v3 + 80) )
    {
      v13 = (int *)(&profile->slots[12].id + item_slots[k]);
      if ( *v13 )
      {
        if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
        {
          v14 = !survarium::items_dictionary::item_by_id(
                   (survarium::items_dictionary *)profile->slots[12].amount_in_inventory,
                   (survarium::items_dictionary_vtbl *)*(unsigned __int16 *)(v11 + v3 + 84))->is_stack;
          v15 = *(unsigned __int16 *)(*v13 + 280);
          if ( v14 )
          {
            *v12 = v15;
          }
          else
          {
            v12[1] += v15;
            survarium::inventory_item::set_amount(0, *v13);
          }
        }
      }
    }
  }
  profile->slots[18].amount_in_inventory = 0;
  *(_DWORD *)&profile->slots[18].dict_id = 23;
  LOBYTE(profile->slots[18].id) = 0;
  LOBYTE(profile->slots[20].amount_in_inventory) = 1;
}
