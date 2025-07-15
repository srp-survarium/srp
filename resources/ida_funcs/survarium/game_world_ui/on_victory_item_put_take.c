void __thiscall survarium::game_world_ui::on_victory_item_put_take(
        survarium::game_world_ui *this,
        survarium::game_world_ui *player_id,
        int is_taken,
        bool is_base,
        bool is_basea)
{
  survarium::base_network_client *m_network_client; // ebp
  survarium::game_team_id team; // edi
  unsigned __int8 v7; // bl
  survarium::flash_movie_resource *m_object; // eax
  const wchar_t *v9; // edi
  unsigned __int8 v10; // bl
  survarium::player *v11; // eax
  survarium::game_team_id v12; // esi
  survarium::player *v13; // ebp
  vostok::resources::unmanaged_resource *v14; // edi
  survarium::game_team_id v15; // esi
  unsigned __int8 v16; // [esp+BCh] [ebp-4Ch]
  unsigned __int8 v17; // [esp+C0h] [ebp-48h]
  unsigned int v18; // [esp+C4h] [ebp-44h]
  vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base> player; // [esp+CCh] [ebp-3Ch] BYREF
  int i; // [esp+D0h] [ebp-38h]
  survarium::flash_value out_event_property; // [esp+D4h] [ebp-34h] BYREF
  survarium::flash_value out_event; // [esp+ECh] [ebp-1Ch] BYREF

  survarium::game_world_ui::update_minimap_objects(this, player_id);
  m_network_client = player_id->m_game_world->m_game->m_network_client;
  m_network_client->get_player(m_network_client, &player, is_taken);
  team = team_1;
  v7 = 0;
  LOBYTE(i) = 0;
  while ( !m_network_client->is_player_local(m_network_client, i) )
  {
    LOBYTE(i) = ++v7;
    if ( v7 >= 0x14u )
      goto LABEL_6;
  }
  team = m_network_client->match_options(m_network_client)->player_profiles[v7].team;
LABEL_6:
  if ( player.m_object->team(player.m_object) == team )
  {
    m_object = player_id->m_game_hud_ui.m_object;
    *(_DWORD *)out_event.body = 0;
    *(_DWORD *)&out_event.body[4] = 0;
    v9 = (const wchar_t *)((char *)&unk_10F38 + (unsigned int)player.m_object);
    Scaleform::GFx::Movie::CreateObject(m_object->movie->m_movie, (Scaleform::GFx::Value *)&out_event, 0, 0, 0);
    *(_DWORD *)out_event_property.body = 0;
    *(_DWORD *)&out_event_property.body[4] = 0;
    if ( is_base )
    {
      v10 = 3;
      if ( m_network_client->is_player_local(m_network_client, is_taken) )
        survarium::game_world_ui::show_parametrized_message("st_bring_item_to_base", player_id, v16, v17, v18);
    }
    else
    {
      v10 = is_basea + 4;
    }
    if ( (out_event_property.body[4] & 0x40) != 0 )
    {
      (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)out_event_property.body + 8))(
        *(_DWORD *)out_event_property.body,
        &out_event_property,
        *(_DWORD *)&out_event_property.body[8]);
      *(_DWORD *)out_event_property.body = 0;
    }
    *(_DWORD *)&out_event_property.body[8] = v10;
    *(_DWORD *)&out_event_property.body[4] = 3;
    (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)out_event.body
                                                                                         + 20))(
      *(_DWORD *)out_event.body,
      *(_DWORD *)&out_event.body[8],
      "action_id",
      &out_event_property,
      (out_event.body[4] & 0x8F) == 10);
    survarium::flash_value::SetStringW(&out_event_property, v9);
    (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)out_event.body
                                                                                         + 20))(
      *(_DWORD *)out_event.body,
      *(_DWORD *)&out_event.body[8],
      "who_name",
      &out_event_property,
      (out_event.body[4] & 0x8F) == 10);
    v11 = m_network_client->m_current_player.m_object;
    if ( v11
      && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr
      && v11->id == (_BYTE)is_taken )
    {
      v12 = team_neutral;
    }
    else
    {
      v12 = player.m_object->team(player.m_object);
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
    *(_DWORD *)&out_event_property.body[8] = v12;
    (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)out_event.body
                                                                                         + 20))(
      *(_DWORD *)out_event.body,
      *(_DWORD *)&out_event.body[8],
      "who_team",
      &out_event_property,
      (out_event.body[4] & 0x8F) == 10);
    survarium::flash_value::SetStringW(&out_event_property, v9);
    (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)out_event.body
                                                                                         + 20))(
      *(_DWORD *)out_event.body,
      *(_DWORD *)&out_event.body[8],
      "victim_name",
      &out_event_property,
      (out_event.body[4] & 0x8F) == 10);
    v13 = m_network_client->m_current_player.m_object;
    v14 = 0;
    if ( v13
      && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr
      && v13->id == (_BYTE)is_taken )
    {
      v15 = team_neutral;
    }
    else
    {
      v15 = player.m_object->team(player.m_object);
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
    *(_DWORD *)&out_event_property.body[8] = v15;
    (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)out_event.body
                                                                                         + 20))(
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
    *(_DWORD *)&out_event_property.body[4] = 3;
    *(_DWORD *)&out_event_property.body[8] = 0;
    (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)out_event.body
                                                                                         + 20))(
      *(_DWORD *)out_event.body,
      *(_DWORD *)&out_event.body[8],
      "object_icon",
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
    (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)out_event.body
                                                                                         + 20))(
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
    (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)out_event.body
                                                                                         + 20))(
      *(_DWORD *)out_event.body,
      *(_DWORD *)&out_event.body[8],
      "mastery_icon",
      &out_event_property,
      (out_event.body[4] & 0x8F) == 10);
    Scaleform::GFx::Movie::Invoke(
      player_id->m_game_hud_ui.m_object->movie->m_movie,
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
    if ( player.m_object && !_InterlockedExchangeAdd(&player.m_object->m_reference_count, 0xFFFFFFFF) )
    {
      if ( player.m_object )
        v14 = &player.m_object->vostok::resources::unmanaged_resource;
      vostok::resources::unmanaged_intrusive_base::destroy(
        &player.m_object->vostok::resources::unmanaged_intrusive_base,
        v14);
    }
  }
  else
  {
    if ( is_base && is_basea )
      survarium::game_world_ui::show_parametrized_message("st_on_enemy_theft_item", player_id, v16, v17, v18);
    if ( player.m_object && !_InterlockedExchangeAdd(&player.m_object->m_reference_count, 0xFFFFFFFF) )
    {
      if ( player.m_object )
        vostok::resources::unmanaged_intrusive_base::destroy(
          &player.m_object->vostok::resources::unmanaged_intrusive_base,
          &player.m_object->vostok::resources::unmanaged_resource);
      else
        vostok::resources::unmanaged_intrusive_base::destroy((vostok::resources::unmanaged_intrusive_base *)0x1F0, 0);
    }
  }
}
