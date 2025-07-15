void __thiscall survarium::player::insert(survarium::player *this, survarium::player *is_alive, bool is_alivea)
{
  bool v3; // zf
  int v4; // eax
  survarium::flash_text_manager *v5; // ecx
  survarium::flash_text *text_w; // eax
  int v7; // ecx
  int v8; // ecx
  vostok::animation::animation_player *v9; // ecx
  survarium::inventory *m_object; // ecx
  vostok::resources::resource_ptr<survarium::interactive_object,vostok::resources::unmanaged_intrusive_base> *p_m_current_active_object; // esi
  survarium::interactive_object *v12; // edi
  survarium::interactive_object *v13; // eax
  vostok::resources::unmanaged_resource *v14; // edx
  survarium::engine *v15; // eax
  survarium::engine *v16; // eax
  survarium::player *v17; // ecx
  wchar_t *v18; // [esp+0h] [ebp-18h]
  char v19[12]; // [esp+Ch] [ebp-Ch] BYREF

  v3 = byte_10F80[(_DWORD)is_alive] == 0;
  is_alive->m_has_been_inserted = 1;
  if ( v3 )
  {
    v4 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(*(int *)((char *)&dword_10F04 + (_DWORD)is_alive) + 952) + 52))(*(_DWORD *)(*(int *)((char *)&dword_10F04 + (_DWORD)is_alive) + 952));
    survarium::inventory::setup_from_profile(
      is_alive->m_inventory.m_object,
      (survarium::player_profile *)(v4 + 440 * (unsigned __int8)is_alive->id),
      *(const survarium::items_dictionary **)(*(int *)((char *)&dword_10F04 + (_DWORD)is_alive) + 948));
  }
  else
  {
    survarium::inventory::setup_demo_profile(is_alive->m_inventory.m_object);
  }
  if ( byte_10F35[(_DWORD)is_alive] )
    byte_10F35[(_DWORD)is_alive] = 0;
  if ( !byte_10F80[(_DWORD)is_alive] )
  {
    text_w = survarium::flash_text_manager::create_text_w(
               v5,
               *(_DWORD *)(*(int *)((char *)&dword_10F00 + (_DWORD)is_alive) + 164),
               (int)v19,
               (survarium::flash_text *)((char *)&unk_10F38 + (_DWORD)is_alive),
               v18);
    *(_QWORD *)&is_alive->m_text.text_impl = *(_QWORD *)&text_w->text_impl;
    v7 = *(_DWORD *)&text_w->visible;
    *(int *)((char *)&dword_10EEC + (_DWORD)is_alive) = v7;
    if ( (_BYTE)v7 )
    {
      v8 = *(int *)((char *)&dword_10EE4 + (_DWORD)is_alive);
      *((_BYTE *)&dword_10EEC + (_DWORD)is_alive) = 0;
      (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v8 + 152))(v8, 0);
      *(_BYTE *)(*(int *)((char *)&dword_10EE8 + (_DWORD)is_alive) + 4) = 1;
    }
    (*(void (__thiscall **)(_DWORD, int, _DWORD, int))(**(_DWORD **)((char *)&dword_10EE4 + (_DWORD)is_alive) + 36))(
      *(int *)((char *)&dword_10EE4 + (_DWORD)is_alive),
      -16711936,
      0,
      -1);
    *(_BYTE *)(*(int *)((char *)&dword_10EE8 + (_DWORD)is_alive) + 4) = 1;
  }
  *(int *)((char *)&dword_10F0C + (_DWORD)is_alive) = *(_DWORD *)(*(int *)((char *)&dword_10F04 + (_DWORD)is_alive)
                                                                + 1012);
  vostok::animation::animation_player::reset(
    &is_alive->m_target.animation_player,
    &is_alive->m_target.animation_player,
    1);
  vostok::animation::animation_player::reset(v9, &is_alive->m_current.animation_player, 1);
  m_object = is_alive->m_inventory.m_object;
  if ( m_object->m_slots[7].item.m_object
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    survarium::inventory::action(m_object, weapon1_slot, 1);
  }
  else if ( m_object->m_slots[10].item.m_object
         && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    survarium::inventory::action(m_object, weapon2_slot, 1);
  }
  else
  {
    vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base>::operator=(
      (vostok::resources::resource_ptr<vostok::animation::skeleton,vostok::resources::unmanaged_intrusive_base> *)((char *)&dword_10F08 + (_DWORD)is_alive),
      &is_alive->m_target_active_object.m_object);
  }
  p_m_current_active_object = &is_alive->m_current_active_object;
  is_alive->on_before_active_object_changed(
    is_alive,
    &is_alive->m_current_active_object,
    &is_alive->m_target_active_object);
  v12 = is_alive->m_target_active_object.m_object;
  v13 = 0;
  if ( v12 )
  {
    v13 = is_alive->m_target_active_object.m_object;
    _InterlockedExchangeAdd(&v12->m_reference_count, 1u);
  }
  v14 = p_m_current_active_object->m_object;
  p_m_current_active_object->m_object = v13;
  if ( v14 && !_InterlockedExchangeAdd(&v14->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v14->vostok::resources::unmanaged_intrusive_base, v14);
  v15 = *(survarium::engine **)((char *)&dword_10F00 + (_DWORD)is_alive);
  if ( v15 )
    v16 = v15 + 3;
  else
    v16 = 0;
  p_m_current_active_object->m_object->activate(p_m_current_active_object->m_object, is_alive, v16);
  if ( is_alivea )
    survarium::player::insert_alive(v17, is_alive);
  byte_10F34[(_DWORD)is_alive] = 1;
  survarium::player::add_models_to_scene(v17, (int)is_alive);
  is_alive->m_force_animation_selection = 1;
  byte_10F81[(_DWORD)is_alive] = 1;
}
