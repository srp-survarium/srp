void __thiscall survarium::game_world_ui::update_minimap_local_player(
        survarium::game_world_ui *this,
        survarium::game_world_ui *thisa)
{
  survarium::base_network_client *m_network_client; // ebx
  survarium::player *m_object; // eax
  survarium::flash_value *v4; // ecx
  vostok::math::float4x4 *v5; // ecx
  vostok::math::float3 *angles; // eax
  survarium::flash_value *v7; // ecx
  survarium::player *v8; // ecx
  unsigned __int8 v9; // bl
  survarium::flash_movie_resource *v10; // eax
  vostok::math::float3 *v11; // [esp+Ch] [ebp-C0h]
  vostok::math::axis_rotation_order v12; // [esp+10h] [ebp-BCh]
  vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base> current_player; // [esp+18h] [ebp-B4h] BYREF
  survarium::flash_value player_descr_value[4]; // [esp+1Ch] [ebp-B0h] BYREF
  vostok::math::float4x4 current_player_transform; // [esp+8Ch] [ebp-40h] BYREF

  m_network_client = thisa->m_game_world->m_game->m_network_client;
  m_object = m_network_client->m_current_player.m_object;
  if ( m_object )
  {
    current_player.m_object = m_network_client->m_current_player.m_object;
    _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
    if ( m_object->m_has_been_inserted )
    {
      qmemcpy((void *)&current_player_transform, &m_object->m_current.transform, sizeof(current_player_transform));
      `vector constructor iterator'(
        player_descr_value[0].body,
        0x18u,
        4,
        (void *(__thiscall *)(void *))survarium::flash_value::flash_value);
      v4 = (survarium::flash_value *)(*(_DWORD *)&player_descr_value[0].body[4] >> 6);
      if ( (player_descr_value[0].body[4] & 0x40) != 0 )
      {
        (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)player_descr_value[0].body + 8))(
          *(_DWORD *)player_descr_value[0].body,
          player_descr_value,
          *(_DWORD *)&player_descr_value[0].body[8]);
        *(_DWORD *)player_descr_value[0].body = 0;
      }
      *(double *)&player_descr_value[0].body[8] = current_player_transform.c.x;
      *(_DWORD *)&player_descr_value[0].body[4] = 5;
      survarium::flash_value::SetNumber(v4, (double *)player_descr_value[1].body, -current_player_transform.c.z);
      angles = vostok::math::float4x4::get_angles(v5, v11, v12);
      survarium::flash_value::SetNumber(v7, (double *)player_descr_value[2].body, angles->y);
      v8 = m_network_client->m_current_player.m_object;
      if ( v8 )
        v9 = v8->team(v8);
      else
        v9 = 2;
      if ( (player_descr_value[3].body[4] & 0x40) != 0 )
      {
        (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)player_descr_value[3].body + 8))(
          *(_DWORD *)player_descr_value[3].body,
          &player_descr_value[3],
          *(_DWORD *)&player_descr_value[3].body[8]);
        *(_DWORD *)player_descr_value[3].body = 0;
      }
      *(_DWORD *)&player_descr_value[3].body[8] = v9;
      v10 = thisa->m_game_hud_ui.m_object;
      *(_DWORD *)&player_descr_value[3].body[4] = 4;
      Scaleform::GFx::Movie::Invoke(
        v10->movie->m_movie,
        "root.update_local_player",
        0,
        (const Scaleform::GFx::Value *)player_descr_value,
        4u);
      `vector destructor iterator'(
        player_descr_value[0].body,
        0x18u,
        4,
        (void (__thiscall *)(void *))survarium::flash_value::~flash_value);
      vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base>(&current_player);
    }
    else if ( !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
    {
      vostok::resources::unmanaged_intrusive_base::destroy(
        &m_object->vostok::resources::unmanaged_intrusive_base,
        &m_object->vostok::resources::unmanaged_resource);
    }
  }
}
