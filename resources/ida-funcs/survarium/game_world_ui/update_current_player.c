void __usercall survarium::game_world_ui::update_current_player(survarium::game_world_ui *this@<ecx>, __int32 a2@<eax>)
{
  vostok::particle::particle_system_instance_impl *m_object; // edi
  const vostok::resources::resource_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base> *m_size; // ebx
  int *v5; // eax
  survarium::game_world_ui *v6; // ecx
  survarium::game_world_ui *v7; // ecx
  survarium::game_world_ui *v8; // ecx
  char v9; // dl
  survarium::game_world_ui *v10; // ecx
  survarium::game_world_ui *v11; // ecx
  survarium::game_world_ui *v12; // ecx
  survarium::game_world_ui *v13; // ecx
  int v14; // [esp+Ch] [ebp-Ch]
  survarium::inventory_item_props **v15; // [esp+10h] [ebp-8h]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v16; // [esp+14h] [ebp-4h] BYREF

  survarium::base_network_client::get_current_player(
    *(survarium::base_network_client **)(*(_DWORD *)(*(_DWORD *)(a2 + 20) + 160) + 13912),
    &v16);
  m_object = v16.m_object;
  if ( v16.m_object )
  {
    m_size = (const vostok::resources::resource_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base> *)v16.m_object->m_lods[0].m_emitter_instance_list.m_size;
    v5 = (int *)((int (__thiscall *)(vostok::particle::lod_entry *))v16.m_object->m_lods[0].m_template.m_object->m_flags.m_flags)(v16.m_object->m_lods);
    survarium::game_world_ui::update_from_damage_model(v6, (const survarium::damage_model *)a2, *v5);
    v15 = (survarium::inventory_item_props **)quick_slots_0;
    v14 = 6;
    do
    {
      survarium::game_world_ui::update_quick_slot(
        v7,
        (survarium::profile_slot_enum)a2,
        &m_size[(_DWORD)*v15 + 68],
        *v15);
      ++v15;
      --v14;
    }
    while ( v14 );
    survarium::game_world_ui::update_back_slot((survarium::game_world_ui *)a2, m_size + 71);
    LOBYTE(v8) = m_object->m_skeleton_model.m_object;
    v9 = *(_BYTE *)(a2 + 493);
    *(_BYTE *)(a2 + 493) = (_BYTE)v8;
    if ( (_BYTE)v8 != v9 )
    {
      if ( (_BYTE)v8 )
      {
        survarium::game_world_ui::show_quick_slots(v8, a2, 1);
        survarium::game_world_ui::show_stamina(v10, a2, 1);
        survarium::game_world_ui::initialize_quick_slots(v11, (survarium::profile_slot_enum)a2);
      }
      else
      {
        survarium::game_world_ui::show_quick_slots(v8, a2, 0);
        survarium::game_world_ui::show_oxygene(v12, a2, 0);
        survarium::game_world_ui::show_stamina(v13, a2, 0);
      }
    }
  }
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v16);
}
