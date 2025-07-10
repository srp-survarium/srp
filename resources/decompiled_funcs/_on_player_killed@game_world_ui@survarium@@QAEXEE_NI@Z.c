void __thiscall survarium::game_world_ui::on_player_killed(
        survarium::game_world_ui *this,
        survarium::game_world_ui *victim_id,
        int killer_id,
        int is_headshot,
        bool item_dict_id,
        unsigned int combat_log_icon)
{
  survarium::game_world_ui *v6; // esi
  survarium::base_network_client *m_network_client; // ebp
  survarium::player *m_object; // eax
  const wchar_t *v9; // edi
  survarium::flash_movie_resource *v10; // ecx
  survarium::flash_movie_resource *v11; // ecx
  survarium::player *v12; // eax
  char v13; // bl
  int v14; // esi
  survarium::player *v15; // eax
  survarium::player *v16; // esi
  survarium::player *v17; // ecx
  int v18; // edi
  survarium::player *v19; // eax
  int v20; // esi
  survarium::player *v21; // ebp
  survarium::player *v22; // esi
  survarium::player *v23; // ecx
  int v24; // ebp
  unsigned __int8 v25; // bl
  vostok::resources::unmanaged_resource *v26; // eax
  vostok::resources::unmanaged_resource *v27; // eax
  vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base> victim; // [esp+C8h] [ebp-40h] BYREF
  vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base> killer; // [esp+CCh] [ebp-3Ch] BYREF
  vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base> v30; // [esp+D0h] [ebp-38h] BYREF
  const wchar_t *victim_name; // [esp+D4h] [ebp-34h]
  survarium::flash_value out_event_property; // [esp+D8h] [ebp-30h] BYREF
  survarium::flash_value out_event; // [esp+F0h] [ebp-18h] BYREF
  unsigned __int8 combat_log_icona; // [esp+11Ch] [ebp+14h]

  v6 = victim_id;
  v30.m_object = 0;
  m_network_client = victim_id->m_game_world->m_game->m_network_client;
  m_object = m_network_client->m_current_player.m_object;
  if ( m_object
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr
    && m_object->id == (_BYTE)killer_id )
  {
    Scaleform::GFx::Movie::Invoke(
      victim_id->m_game_hud_ui.m_object->movie->m_movie,
      "root.reset_damage_indicator",
      0,
      0,
      0);
  }
  m_network_client->get_player(m_network_client, &killer, is_headshot);
  m_network_client->get_player(m_network_client, &victim, killer_id);
  v9 = (const wchar_t *)((char *)&unk_10F38 + (unsigned int)killer.m_object);
  victim_name = (const wchar_t *)((char *)&unk_10F38 + (unsigned int)victim.m_object);
  if ( combat_log_icon )
  {
    v6 = victim_id;
    combat_log_icona = survarium::items_dictionary::item_by_id(
                         victim_id->m_game_world->m_game->m_items_dictionary.m_object,
                         combat_log_icon)[281].gap0;
  }
  else
  {
    combat_log_icona = 0;
  }
  v10 = v6->m_game_hud_ui.m_object;
  *(_DWORD *)out_event.body = 0;
  *(_DWORD *)&out_event.body[4] = 0;
  Scaleform::GFx::Movie::CreateObject(v10->movie->m_movie, (Scaleform::GFx::Value *)&out_event, 0, 0, 0);
  v11 = v6->m_game_hud_ui.m_object;
  *(_DWORD *)out_event_property.body = 0;
  *(_DWORD *)&out_event_property.body[4] = 0;
  Scaleform::GFx::Movie::CreateObject(v11->movie->m_movie, (Scaleform::GFx::Value *)&out_event_property, 0, 0, 0);
  if ( (out_event_property.body[4] & 0x40) != 0 )
  {
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)out_event_property.body + 8))(
      *(_DWORD *)out_event_property.body,
      &out_event_property,
      *(_DWORD *)&out_event_property.body[8]);
    *(_DWORD *)out_event_property.body = 0;
  }
  *(_DWORD *)&out_event_property.body[4] = 3;
  *(_DWORD *)&out_event_property.body[8] = ((_BYTE)killer_id == (unsigned __int8)is_headshot) + 1;
  (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)out_event.body + 20))(
    *(_DWORD *)out_event.body,
    *(_DWORD *)&out_event.body[8],
    "action_id",
    &out_event_property,
    (out_event.body[4] & 0x8F) == 10);
  survarium::flash_value::SetStringW(&out_event_property, v9);
  (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)out_event.body + 20))(
    *(_DWORD *)out_event.body,
    *(_DWORD *)&out_event.body[8],
    "who_name",
    &out_event_property,
    (out_event.body[4] & 0x8F) == 10);
  v12 = m_network_client->m_current_player.m_object;
  if ( v12
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr
    && v12->id == (_BYTE)is_headshot )
  {
    v13 = (char)v30.m_object;
    v14 = 2;
  }
  else
  {
    v15 = *(survarium::player **)&m_network_client[555].m_use_physics_controller_for_current;
    v16 = killer.m_object;
    v17 = 0;
    v13 = 1;
    v30.m_object = 0;
    if ( v15 )
    {
      v17 = v15;
      v30.m_object = v15;
      _InterlockedExchangeAdd(&v15->m_reference_count, 1u);
    }
    v18 = v17->team(v17);
    v14 = v16->team(v16) != v18;
  }
  if ( (out_event_property.body[4] & 0x40) != 0 )
  {
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)out_event_property.body + 8))(
      *(_DWORD *)out_event_property.body,
      &out_event_property,
      *(_DWORD *)&out_event_property.body[8]);
    *(_DWORD *)out_event_property.body = 0;
  }
  *(_DWORD *)&out_event_property.body[4] = 3;
  *(_DWORD *)&out_event_property.body[8] = v14;
  if ( (v13 & 1) != 0 )
  {
    v13 &= ~1u;
    vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base>(&v30);
  }
  (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)out_event.body + 20))(
    *(_DWORD *)out_event.body,
    *(_DWORD *)&out_event.body[8],
    "who_team",
    &out_event_property,
    (out_event.body[4] & 0x8F) == 10);
  survarium::flash_value::SetStringW(&out_event_property, victim_name);
  (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)out_event.body + 20))(
    *(_DWORD *)out_event.body,
    *(_DWORD *)&out_event.body[8],
    "victim_name",
    &out_event_property,
    (out_event.body[4] & 0x8F) == 10);
  v19 = m_network_client->m_current_player.m_object;
  if ( v19
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr
    && v19->id == (_BYTE)killer_id )
  {
    v20 = 2;
  }
  else
  {
    v21 = *(survarium::player **)&m_network_client[555].m_use_physics_controller_for_current;
    v22 = victim.m_object;
    v23 = 0;
    v13 |= 2u;
    v30.m_object = 0;
    if ( v21 )
    {
      v23 = v21;
      v30.m_object = v21;
      _InterlockedExchangeAdd(&v21->m_reference_count, 1u);
    }
    v24 = v23->team(v23);
    v20 = v22->team(v22) != v24;
  }
  if ( (out_event_property.body[4] & 0x40) != 0 )
  {
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)out_event_property.body + 8))(
      *(_DWORD *)out_event_property.body,
      &out_event_property,
      *(_DWORD *)&out_event_property.body[8]);
    *(_DWORD *)out_event_property.body = 0;
  }
  *(_DWORD *)&out_event_property.body[4] = 3;
  *(_DWORD *)&out_event_property.body[8] = v20;
  if ( (v13 & 2) != 0 )
    vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base>(&v30);
  (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)out_event.body + 20))(
    *(_DWORD *)out_event.body,
    *(_DWORD *)&out_event.body[8],
    "victim_team",
    &out_event_property,
    (out_event.body[4] & 0x8F) == 10);
  if ( (out_event_property.body[4] & 0x40) != 0 )
  {
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)out_event_property.body + 8))(
      *(_DWORD *)out_event_property.body,
      &out_event_property,
      *(_DWORD *)&out_event_property.body[8]);
    *(_DWORD *)out_event_property.body = 0;
  }
  *(_DWORD *)&out_event_property.body[8] = combat_log_icona;
  *(_DWORD *)&out_event_property.body[4] = 3;
  (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)out_event.body + 20))(
    *(_DWORD *)out_event.body,
    *(_DWORD *)&out_event.body[8],
    "object_icon",
    &out_event_property,
    (out_event.body[4] & 0x8F) == 10);
  if ( (_BYTE)killer_id == (_BYTE)is_headshot )
    v25 = 4;
  else
    v25 = item_dict_id;
  if ( (out_event_property.body[4] & 0x40) != 0 )
  {
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)out_event_property.body + 8))(
      *(_DWORD *)out_event_property.body,
      &out_event_property,
      *(_DWORD *)&out_event_property.body[8]);
    *(_DWORD *)out_event_property.body = 0;
  }
  *(_DWORD *)&out_event_property.body[8] = v25;
  *(_DWORD *)&out_event_property.body[4] = 3;
  (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)out_event.body + 20))(
    *(_DWORD *)out_event.body,
    *(_DWORD *)&out_event.body[8],
    "extra_icon",
    &out_event_property,
    (out_event.body[4] & 0x8F) == 10);
  if ( (out_event_property.body[4] & 0x40) != 0 )
  {
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)out_event_property.body + 8))(
      *(_DWORD *)out_event_property.body,
      &out_event_property,
      *(_DWORD *)&out_event_property.body[8]);
    *(_DWORD *)out_event_property.body = 0;
  }
  *(_DWORD *)&out_event_property.body[4] = 3;
  *(_DWORD *)&out_event_property.body[8] = 0;
  (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)out_event.body + 20))(
    *(_DWORD *)out_event.body,
    *(_DWORD *)&out_event.body[8],
    "mastery_icon",
    &out_event_property,
    (out_event.body[4] & 0x8F) == 10);
  Scaleform::GFx::Movie::Invoke(
    victim_id->m_game_hud_ui.m_object->movie->m_movie,
    "root.add_log_message",
    0,
    (const Scaleform::GFx::Value *)&out_event,
    1u);
  if ( (out_event_property.body[4] & 0x40) != 0 )
  {
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)out_event_property.body + 8))(
      *(_DWORD *)out_event_property.body,
      &out_event_property,
      *(_DWORD *)&out_event_property.body[8]);
    *(_DWORD *)out_event_property.body = 0;
  }
  *(_DWORD *)&out_event_property.body[4] = 0;
  if ( (out_event.body[4] & 0x40) != 0 )
  {
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)out_event.body + 8))(
      *(_DWORD *)out_event.body,
      &out_event,
      *(_DWORD *)&out_event.body[8]);
    *(_DWORD *)out_event.body = 0;
  }
  *(_DWORD *)&out_event.body[4] = 0;
  if ( victim.m_object && !_InterlockedExchangeAdd(&victim.m_object->m_reference_count, 0xFFFFFFFF) )
  {
    if ( victim.m_object )
      v26 = &victim.m_object->vostok::resources::unmanaged_resource;
    else
      v26 = 0;
    vostok::resources::unmanaged_intrusive_base::destroy(
      &victim.m_object->vostok::resources::unmanaged_intrusive_base,
      v26);
  }
  if ( killer.m_object && !_InterlockedExchangeAdd(&killer.m_object->m_reference_count, 0xFFFFFFFF) )
  {
    if ( killer.m_object )
      v27 = &killer.m_object->vostok::resources::unmanaged_resource;
    else
      v27 = 0;
    vostok::resources::unmanaged_intrusive_base::destroy(
      &killer.m_object->vostok::resources::unmanaged_intrusive_base,
      v27);
  }
}
