void __thiscall survarium::game_world_ui::update_minimap_objects(
        survarium::game_world_ui *this,
        survarium::game_world_ui *thisa)
{
  survarium::game_world_ui *v2; // esi
  unsigned __int8 v3; // bl
  survarium::base_network_client *m_network_client; // edi
  survarium::flash_movie_resource *m_object; // ecx
  survarium::player *v6; // eax
  survarium::simple_game_project *v7; // ecx
  survarium::simple_game_project *v8; // eax
  survarium::simple_game_project *v9; // ecx
  survarium::simple_game_project *v10; // eax
  bool v11; // bl
  survarium::victory_items_container **v12; // ebx
  survarium::game_team_id v13; // eax
  survarium::flash_movie_resource *v14; // ecx
  vostok::math::float4x4 *transform; // eax
  survarium::usable_object *v16; // ecx
  vostok::math::float4x4 *v17; // eax
  unsigned __int8 m_container_id; // bl
  const char *v19; // edi
  int v20; // ecx
  survarium::game_world *m_game_world; // eax
  vostok::resources::resource_ptr<survarium::victory_item,vostok::resources::unmanaged_intrusive_base> *M_start; // edi
  float x; // xmm0_4
  survarium::victory_item *v24; // ecx
  vostok::math::float4x4 *(__thiscall *get_transform)(survarium::victory_item_core *, vostok::math::float4x4 *); // eax
  int v26; // eax
  int v27; // esi
  int v28; // ecx
  survarium::player *v29; // eax
  vostok::resources::unmanaged_intrusive_base *v30; // ecx
  unsigned __int8 v31; // [esp+82h] [ebp-B6h]
  char v32; // [esp+83h] [ebp-B5h]
  survarium::flash_value level_object_val_prop; // [esp+84h] [ebp-B4h] BYREF
  survarium::victory_items_container **it; // [esp+9Ch] [ebp-9Ch]
  survarium::flash_value level_object_val; // [esp+A0h] [ebp-98h] BYREF
  float position_x; // [esp+B8h] [ebp-80h]
  survarium::game_team_id local_player_team; // [esp+BCh] [ebp-7Ch]
  float position_y; // [esp+C0h] [ebp-78h]
  vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base> current_player; // [esp+C4h] [ebp-74h]
  int v40; // [esp+C8h] [ebp-70h] BYREF
  int v41; // [esp+CCh] [ebp-6Ch]
  const char *v42; // [esp+D0h] [ebp-68h]
  survarium::flash_value level_objects; // [esp+E0h] [ebp-58h] BYREF
  vostok::math::float4x4 result; // [esp+F8h] [ebp-40h] BYREF

  v2 = thisa;
  v3 = 0;
  m_network_client = thisa->m_game_world->m_game->m_network_client;
  local_player_team = team_1;
  LOBYTE(it) = 0;
  while ( !m_network_client->is_player_local(m_network_client, (const unsigned __int8)it) )
  {
    LOBYTE(it) = ++v3;
    if ( v3 >= 0x14u )
      goto LABEL_6;
  }
  local_player_team = m_network_client->match_options(m_network_client)->player_profiles[v3].team;
LABEL_6:
  m_object = thisa->m_game_hud_ui.m_object;
  *(_DWORD *)level_objects.body = 0;
  *(_DWORD *)&level_objects.body[4] = 0;
  Scaleform::GFx::Movie::CreateArray(m_object->movie->m_movie, (Scaleform::GFx::Value *)&level_objects);
  *(_DWORD *)level_object_val_prop.body = 0;
  *(_DWORD *)&level_object_val_prop.body[4] = 0;
  v6 = m_network_client->m_current_player.m_object;
  v31 = 0;
  current_player.m_object = 0;
  if ( !v6
    || (current_player.m_object = v6,
        _InterlockedExchangeAdd(&v6->m_reference_count, 1u),
        v32 = 1,
        !v6->m_inventory.m_object->m_victory_item) )
  {
    v32 = 0;
  }
  v7 = thisa->m_game_world->m_game_project.m_object;
  v8 = 0;
  if ( v7 )
  {
    v8 = thisa->m_game_world->m_game_project.m_object;
    _InterlockedExchangeAdd(&v7->m_reference_count, 1u);
  }
  it = (survarium::victory_items_container **)v8->m_victory_items_containers._M_impl._M_start;
  if ( !_InterlockedExchangeAdd(&v8->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v8->vostok::resources::unmanaged_intrusive_base, v8);
  while ( 1 )
  {
    v9 = thisa->m_game_world->m_game_project.m_object;
    v10 = 0;
    if ( v9 )
    {
      v10 = thisa->m_game_world->m_game_project.m_object;
      _InterlockedExchangeAdd(&v9->m_reference_count, 1u);
    }
    v11 = it != (survarium::victory_items_container **)v10->m_victory_items_containers._M_impl._M_finish;
    if ( !_InterlockedExchangeAdd(&v10->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(&v10->vostok::resources::unmanaged_intrusive_base, v10);
    if ( !v11 )
      break;
    v12 = it;
    v13 = (*it)->team(*it);
    if ( v13 == local_player_team )
    {
      v14 = thisa->m_game_hud_ui.m_object;
      *(_DWORD *)level_object_val.body = 0;
      *(_DWORD *)&level_object_val.body[4] = 0;
      Scaleform::GFx::Movie::CreateObject(v14->movie->m_movie, (Scaleform::GFx::Value *)&level_object_val, 0, 0, 0);
      transform = survarium::usable_object::get_transform(*v12, &result);
      v16 = *v12;
      position_x = transform->c.x;
      v17 = survarium::usable_object::get_transform(v16, &result);
      m_container_id = (*v12)->m_container_id;
      position_y = -v17->c.z;
      if ( (level_object_val_prop.body[4] & 0x40) != 0 )
      {
        (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)level_object_val_prop.body + 8))(
          *(_DWORD *)level_object_val_prop.body,
          &level_object_val_prop,
          *(_DWORD *)&level_object_val_prop.body[8]);
        *(_DWORD *)level_object_val_prop.body = 0;
      }
      *(_DWORD *)&level_object_val_prop.body[8] = m_container_id;
      *(_DWORD *)&level_object_val_prop.body[4] = 4;
      (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)level_object_val.body
                                                                                           + 20))(
        *(_DWORD *)level_object_val.body,
        *(_DWORD *)&level_object_val.body[8],
        "id",
        &level_object_val_prop,
        (level_object_val.body[4] & 0x8F) == 10);
      v19 = "base_highlighted";
      if ( !v32 )
        v19 = "base";
      v20 = 0;
      v40 = 0;
      v41 = 6;
      v42 = v19;
      if ( (level_object_val_prop.body[4] & 0x40) != 0 )
      {
        (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)level_object_val_prop.body + 8))(
          *(_DWORD *)level_object_val_prop.body,
          &level_object_val_prop,
          *(_DWORD *)&level_object_val_prop.body[8]);
        v20 = v40;
        *(_DWORD *)level_object_val_prop.body = 0;
      }
      *(_DWORD *)&level_object_val_prop.body[4] = 6;
      *(_DWORD *)&level_object_val_prop.body[8] = v19;
      if ( (v41 & 0x40) != 0 )
        (*(void (__thiscall **)(int, int *, const char *))(*(_DWORD *)v20 + 8))(v20, &v40, v42);
      (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)level_object_val.body
                                                                                           + 20))(
        *(_DWORD *)level_object_val.body,
        *(_DWORD *)&level_object_val.body[8],
        "type",
        &level_object_val_prop,
        (level_object_val.body[4] & 0x8F) == 10);
      if ( (level_object_val_prop.body[4] & 0x40) != 0 )
      {
        (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)level_object_val_prop.body + 8))(
          *(_DWORD *)level_object_val_prop.body,
          &level_object_val_prop,
          *(_DWORD *)&level_object_val_prop.body[8]);
        *(_DWORD *)level_object_val_prop.body = 0;
      }
      *(_DWORD *)&level_object_val_prop.body[4] = 5;
      *(double *)&level_object_val_prop.body[8] = position_x;
      (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)level_object_val.body
                                                                                           + 20))(
        *(_DWORD *)level_object_val.body,
        *(_DWORD *)&level_object_val.body[8],
        "pos_x",
        &level_object_val_prop,
        (level_object_val.body[4] & 0x8F) == 10);
      if ( (level_object_val_prop.body[4] & 0x40) != 0 )
      {
        (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)level_object_val_prop.body + 8))(
          *(_DWORD *)level_object_val_prop.body,
          &level_object_val_prop,
          *(_DWORD *)&level_object_val_prop.body[8]);
        *(_DWORD *)level_object_val_prop.body = 0;
      }
      *(_DWORD *)&level_object_val_prop.body[4] = 5;
      *(double *)&level_object_val_prop.body[8] = position_y;
      (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)level_object_val.body
                                                                                           + 20))(
        *(_DWORD *)level_object_val.body,
        *(_DWORD *)&level_object_val.body[8],
        "pos_y",
        &level_object_val_prop,
        (level_object_val.body[4] & 0x8F) == 10);
      (*(void (__thiscall **)(_DWORD, _DWORD, survarium::flash_value *))(**(_DWORD **)level_objects.body + 60))(
        *(_DWORD *)level_objects.body,
        *(_DWORD *)&level_objects.body[8],
        &level_object_val);
      ++v31;
      if ( (level_object_val.body[4] & 0x40) != 0 )
        (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)level_object_val.body + 8))(
          *(_DWORD *)level_object_val.body,
          &level_object_val,
          *(_DWORD *)&level_object_val.body[8]);
      v12 = it;
    }
    it = v12 + 1;
  }
  m_game_world = thisa->m_game_world;
  M_start = m_game_world->m_victory_items._M_impl._M_start;
  if ( M_start != m_game_world->m_victory_items._M_impl._M_finish )
  {
    do
    {
      if ( M_start->m_object->m_spoted_to_team == local_player_team )
      {
        *(_DWORD *)level_object_val.body = 0;
        *(_DWORD *)&level_object_val.body[4] = 0;
        Scaleform::GFx::Movie::CreateObject(
          v2->m_game_hud_ui.m_object->movie->m_movie,
          (Scaleform::GFx::Value *)&level_object_val,
          0,
          0,
          0);
        x = M_start->m_object->get_transform(M_start->m_object, &result)->c.x;
        v24 = M_start->m_object;
        get_transform = M_start->m_object->get_transform;
        position_y = x;
        v26 = (int)get_transform(v24, &result);
        v27 = v31 + M_start->m_object->id;
        position_x = -*(float *)(v26 + 56);
        if ( (level_object_val_prop.body[4] & 0x40) != 0 )
        {
          (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)level_object_val_prop.body + 8))(
            *(_DWORD *)level_object_val_prop.body,
            &level_object_val_prop,
            *(_DWORD *)&level_object_val_prop.body[8]);
          *(_DWORD *)level_object_val_prop.body = 0;
        }
        *(_DWORD *)&level_object_val_prop.body[4] = 4;
        *(_DWORD *)&level_object_val_prop.body[8] = v27;
        (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)level_object_val.body
                                                                                             + 20))(
          *(_DWORD *)level_object_val.body,
          *(_DWORD *)&level_object_val.body[8],
          "id",
          &level_object_val_prop,
          (level_object_val.body[4] & 0x8F) == 10);
        v28 = 0;
        v40 = 0;
        v41 = 6;
        v42 = "artifact";
        if ( (level_object_val_prop.body[4] & 0x40) != 0 )
        {
          (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)level_object_val_prop.body + 8))(
            *(_DWORD *)level_object_val_prop.body,
            &level_object_val_prop,
            *(_DWORD *)&level_object_val_prop.body[8]);
          v28 = v40;
          *(_DWORD *)level_object_val_prop.body = 0;
        }
        *(_DWORD *)&level_object_val_prop.body[4] = 6;
        *(_DWORD *)&level_object_val_prop.body[8] = "artifact";
        if ( (v41 & 0x40) != 0 )
          (*(void (__thiscall **)(int, int *, const char *))(*(_DWORD *)v28 + 8))(v28, &v40, v42);
        (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)level_object_val.body
                                                                                             + 20))(
          *(_DWORD *)level_object_val.body,
          *(_DWORD *)&level_object_val.body[8],
          "type",
          &level_object_val_prop,
          (level_object_val.body[4] & 0x8F) == 10);
        if ( (level_object_val_prop.body[4] & 0x40) != 0 )
        {
          (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)level_object_val_prop.body + 8))(
            *(_DWORD *)level_object_val_prop.body,
            &level_object_val_prop,
            *(_DWORD *)&level_object_val_prop.body[8]);
          *(_DWORD *)level_object_val_prop.body = 0;
        }
        *(_DWORD *)&level_object_val_prop.body[4] = 5;
        *(double *)&level_object_val_prop.body[8] = position_y;
        (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)level_object_val.body
                                                                                             + 20))(
          *(_DWORD *)level_object_val.body,
          *(_DWORD *)&level_object_val.body[8],
          "pos_x",
          &level_object_val_prop,
          (level_object_val.body[4] & 0x8F) == 10);
        if ( (level_object_val_prop.body[4] & 0x40) != 0 )
        {
          (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)level_object_val_prop.body + 8))(
            *(_DWORD *)level_object_val_prop.body,
            &level_object_val_prop,
            *(_DWORD *)&level_object_val_prop.body[8]);
          *(_DWORD *)level_object_val_prop.body = 0;
        }
        *(_DWORD *)&level_object_val_prop.body[4] = 5;
        *(double *)&level_object_val_prop.body[8] = position_x;
        (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)level_object_val.body
                                                                                             + 20))(
          *(_DWORD *)level_object_val.body,
          *(_DWORD *)&level_object_val.body[8],
          "pos_y",
          &level_object_val_prop,
          (level_object_val.body[4] & 0x8F) == 10);
        (*(void (__thiscall **)(_DWORD, _DWORD, survarium::flash_value *))(**(_DWORD **)level_objects.body + 60))(
          *(_DWORD *)level_objects.body,
          *(_DWORD *)&level_objects.body[8],
          &level_object_val);
        if ( (level_object_val.body[4] & 0x40) != 0 )
          (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)level_object_val.body + 8))(
            *(_DWORD *)level_object_val.body,
            &level_object_val,
            *(_DWORD *)&level_object_val.body[8]);
        v2 = thisa;
      }
      ++M_start;
    }
    while ( M_start != v2->m_game_world->m_victory_items._M_impl._M_finish );
  }
  Scaleform::GFx::Movie::Invoke(
    v2->m_game_hud_ui.m_object->movie->m_movie,
    "root.update_objects",
    0,
    (const Scaleform::GFx::Value *)&level_objects,
    1u);
  v29 = current_player.m_object;
  if ( current_player.m_object )
  {
    v30 = &current_player.m_object->vostok::resources::unmanaged_intrusive_base;
    if ( !_InterlockedExchangeAdd(&current_player.m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(v30, &v29->vostok::resources::unmanaged_resource);
  }
  if ( (level_object_val_prop.body[4] & 0x40) != 0 )
  {
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)level_object_val_prop.body + 8))(
      *(_DWORD *)level_object_val_prop.body,
      &level_object_val_prop,
      *(_DWORD *)&level_object_val_prop.body[8]);
    *(_DWORD *)level_object_val_prop.body = 0;
  }
  *(_DWORD *)&level_object_val_prop.body[4] = 0;
  if ( (level_objects.body[4] & 0x40) != 0 )
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)level_objects.body + 8))(
      *(_DWORD *)level_objects.body,
      &level_objects,
      *(_DWORD *)&level_objects.body[8]);
}
