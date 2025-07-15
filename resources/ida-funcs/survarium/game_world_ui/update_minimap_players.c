void __thiscall survarium::game_world_ui::update_minimap_players(
        survarium::game_world_ui *this,
        survarium::game_world_ui *thisa)
{
  survarium::base_network_client *m_network_client; // edi
  survarium::player *m_object; // esi
  survarium::flash_movie_resource *v4; // ecx
  survarium::player *v5; // ecx
  int v6; // edi
  bool v7; // zf
  survarium::flash_movie_resource *v8; // eax
  float v9; // xmm0_4
  Scaleform::GFx::Movie *m_movie; // ecx
  survarium::flash_movie_resource *v11; // eax
  vostok::math::float4x4 *v12; // ecx
  survarium::game_team_id v13; // esi
  unsigned int v14; // esi
  vostok::resources::unmanaged_resource *v15; // eax
  vostok::math::float3 *v16; // [esp+A4h] [ebp-88h]
  vostok::math::axis_rotation_order v17; // [esp+A8h] [ebp-84h]
  bool v18; // [esp+B3h] [ebp-79h]
  vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base> current_player; // [esp+B4h] [ebp-78h] BYREF
  int i; // [esp+B8h] [ebp-74h]
  int v21; // [esp+BCh] [ebp-70h]
  unsigned int in_array_index; // [esp+C0h] [ebp-6Ch] BYREF
  __int64 client; // [esp+C4h] [ebp-68h]
  float position_y; // [esp+CCh] [ebp-60h]
  float y; // [esp+D0h] [ebp-5Ch]
  survarium::player *v26; // [esp+D4h] [ebp-58h]
  survarium::flash_value player_descr_value_property; // [esp+E4h] [ebp-48h] BYREF
  survarium::flash_value player_descr_value; // [esp+FCh] [ebp-30h] BYREF
  survarium::flash_value players_array; // [esp+114h] [ebp-18h] BYREF

  m_network_client = thisa->m_game_world->m_game->m_network_client;
  m_object = m_network_client->m_current_player.m_object;
  LODWORD(client) = m_network_client;
  in_array_index = 0;
  v26 = m_object;
  if ( !m_object )
  {
    vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base>((vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base> *)&in_array_index);
    return;
  }
  _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  v4 = thisa->m_game_hud_ui.m_object;
  *(_DWORD *)players_array.body = 0;
  *(_DWORD *)&players_array.body[4] = 0;
  Scaleform::GFx::Movie::CreateArray(v4->movie->m_movie, (Scaleform::GFx::Value *)&players_array);
  in_array_index = 0;
  LOBYTE(i) = 0;
  v21 = 0;
  do
  {
    m_network_client->get_player(m_network_client, &current_player, i);
    v5 = current_player.m_object;
    if ( !current_player.m_object )
      goto LABEL_31;
    if ( current_player.m_object->m_has_been_inserted )
    {
      v6 = ((int (*)(void))current_player.m_object->team)();
      if ( m_object->team(m_object) == v6 )
      {
        v7 = current_player.m_object->m_inventory.m_object->m_victory_item == 0;
        HIDWORD(client) = LODWORD(current_player.m_object->m_current.transform.c.x);
        v8 = thisa->m_game_hud_ui.m_object;
        v9 = -current_player.m_object->m_current.transform.c.z;
        *(_DWORD *)player_descr_value.body = 0;
        *(_DWORD *)&player_descr_value.body[4] = 0;
        m_movie = v8->movie->m_movie;
        v18 = !v7;
        position_y = v9;
        Scaleform::GFx::Movie::CreateObject(m_movie, (Scaleform::GFx::Value *)&player_descr_value, 0, 0, 0);
        v11 = thisa->m_game_hud_ui.m_object;
        *(_DWORD *)player_descr_value_property.body = 0;
        *(_DWORD *)&player_descr_value_property.body[4] = 0;
        Scaleform::GFx::Movie::CreateObject(
          v11->movie->m_movie,
          (Scaleform::GFx::Value *)&player_descr_value_property,
          0,
          0,
          0);
        if ( (player_descr_value_property.body[4] & 0x40) != 0 )
        {
          (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)player_descr_value_property.body
                                                                           + 8))(
            *(_DWORD *)player_descr_value_property.body,
            &player_descr_value_property,
            *(_DWORD *)&player_descr_value_property.body[8]);
          *(_DWORD *)player_descr_value_property.body = 0;
        }
        *(_DWORD *)&player_descr_value_property.body[8] = v21;
        *(_DWORD *)&player_descr_value_property.body[4] = 4;
        (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)player_descr_value.body
                                                                                             + 20))(
          *(_DWORD *)player_descr_value.body,
          *(_DWORD *)&player_descr_value.body[8],
          "player_id",
          &player_descr_value_property,
          (player_descr_value.body[4] & 0x8F) == 10);
        if ( (player_descr_value_property.body[4] & 0x40) != 0 )
        {
          (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)player_descr_value_property.body
                                                                           + 8))(
            *(_DWORD *)player_descr_value_property.body,
            &player_descr_value_property,
            *(_DWORD *)&player_descr_value_property.body[8]);
          *(_DWORD *)player_descr_value_property.body = 0;
        }
        *(_DWORD *)&player_descr_value_property.body[4] = 5;
        *(double *)&player_descr_value_property.body[8] = *((float *)&client + 1);
        (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)player_descr_value.body
                                                                                             + 20))(
          *(_DWORD *)player_descr_value.body,
          *(_DWORD *)&player_descr_value.body[8],
          "player_pos_x",
          &player_descr_value_property,
          (player_descr_value.body[4] & 0x8F) == 10);
        if ( (player_descr_value_property.body[4] & 0x40) != 0 )
        {
          (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)player_descr_value_property.body
                                                                           + 8))(
            *(_DWORD *)player_descr_value_property.body,
            &player_descr_value_property,
            *(_DWORD *)&player_descr_value_property.body[8]);
          *(_DWORD *)player_descr_value_property.body = 0;
        }
        *(_DWORD *)&player_descr_value_property.body[4] = 5;
        *(double *)&player_descr_value_property.body[8] = position_y;
        (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)player_descr_value.body
                                                                                             + 20))(
          *(_DWORD *)player_descr_value.body,
          *(_DWORD *)&player_descr_value.body[8],
          "player_pos_y",
          &player_descr_value_property,
          (player_descr_value.body[4] & 0x8F) == 10);
        y = vostok::math::float4x4::get_angles(v12, v16, v17)->y;
        if ( (player_descr_value_property.body[4] & 0x40) != 0 )
        {
          (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)player_descr_value_property.body
                                                                           + 8))(
            *(_DWORD *)player_descr_value_property.body,
            &player_descr_value_property,
            *(_DWORD *)&player_descr_value_property.body[8]);
          *(_DWORD *)player_descr_value_property.body = 0;
        }
        *(_DWORD *)&player_descr_value_property.body[4] = 5;
        *(double *)&player_descr_value_property.body[8] = y;
        (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)player_descr_value.body
                                                                                             + 20))(
          *(_DWORD *)player_descr_value.body,
          *(_DWORD *)&player_descr_value.body[8],
          "player_rotation_in_rad",
          &player_descr_value_property,
          (player_descr_value.body[4] & 0x8F) == 10);
        v13 = current_player.m_object->team(current_player.m_object);
        if ( (player_descr_value_property.body[4] & 0x40) != 0 )
        {
          (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)player_descr_value_property.body
                                                                           + 8))(
            *(_DWORD *)player_descr_value_property.body,
            &player_descr_value_property,
            *(_DWORD *)&player_descr_value_property.body[8]);
          *(_DWORD *)player_descr_value_property.body = 0;
        }
        *(_DWORD *)&player_descr_value_property.body[4] = 4;
        *(_DWORD *)&player_descr_value_property.body[8] = v13;
        (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)player_descr_value.body
                                                                                             + 20))(
          *(_DWORD *)player_descr_value.body,
          *(_DWORD *)&player_descr_value.body[8],
          "team",
          &player_descr_value_property,
          (player_descr_value.body[4] & 0x8F) == 10);
        if ( (player_descr_value_property.body[4] & 0x40) != 0 )
        {
          (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)player_descr_value_property.body
                                                                           + 8))(
            *(_DWORD *)player_descr_value_property.body,
            &player_descr_value_property,
            *(_DWORD *)&player_descr_value_property.body[8]);
          *(_DWORD *)player_descr_value_property.body = 0;
        }
        player_descr_value_property.body[8] = v18;
        *(_DWORD *)&player_descr_value_property.body[4] = 2;
        (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)player_descr_value.body
                                                                                             + 20))(
          *(_DWORD *)player_descr_value.body,
          *(_DWORD *)&player_descr_value.body[8],
          "is_carrying_item",
          &player_descr_value_property,
          (player_descr_value.body[4] & 0x8F) == 10);
        v14 = in_array_index;
        (*(void (__thiscall **)(_DWORD, _DWORD, unsigned int, survarium::flash_value *))(**(_DWORD **)players_array.body
                                                                                       + 52))(
          *(_DWORD *)players_array.body,
          *(_DWORD *)&players_array.body[8],
          in_array_index,
          &player_descr_value);
        in_array_index = v14 + 1;
        if ( (player_descr_value_property.body[4] & 0x40) != 0 )
        {
          (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)player_descr_value_property.body
                                                                           + 8))(
            *(_DWORD *)player_descr_value_property.body,
            &player_descr_value_property,
            *(_DWORD *)&player_descr_value_property.body[8]);
          *(_DWORD *)player_descr_value_property.body = 0;
        }
        *(_DWORD *)&player_descr_value_property.body[4] = 0;
        if ( (player_descr_value.body[4] & 0x40) != 0 )
        {
          (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)player_descr_value.body + 8))(
            *(_DWORD *)player_descr_value.body,
            &player_descr_value,
            *(_DWORD *)&player_descr_value.body[8]);
          *(_DWORD *)player_descr_value.body = 0;
        }
        *(_DWORD *)&player_descr_value.body[4] = 0;
        vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base>(&current_player);
        m_object = v26;
        m_network_client = (survarium::base_network_client *)client;
        goto LABEL_31;
      }
      v5 = current_player.m_object;
      m_network_client = (survarium::base_network_client *)client;
    }
    if ( v5 && !_InterlockedExchangeAdd(&v5->m_reference_count, 0xFFFFFFFF) )
    {
      if ( current_player.m_object )
        v15 = &current_player.m_object->vostok::resources::unmanaged_resource;
      else
        v15 = 0;
      vostok::resources::unmanaged_intrusive_base::destroy(
        &current_player.m_object->vostok::resources::unmanaged_intrusive_base,
        v15);
    }
LABEL_31:
    ++v21;
    LOBYTE(i) = i + 1;
  }
  while ( (unsigned __int8)i < 0x14u );
  Scaleform::GFx::Movie::Invoke(
    thisa->m_game_hud_ui.m_object->movie->m_movie,
    "root.update_players",
    0,
    (const Scaleform::GFx::Value *)&players_array,
    1u);
  if ( (players_array.body[4] & 0x40) != 0 )
  {
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)players_array.body + 8))(
      *(_DWORD *)players_array.body,
      &players_array,
      *(_DWORD *)&players_array.body[8]);
    *(_DWORD *)players_array.body = 0;
  }
  *(_DWORD *)&players_array.body[4] = 0;
  if ( !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &m_object->vostok::resources::unmanaged_intrusive_base,
      &m_object->vostok::resources::unmanaged_resource);
}
