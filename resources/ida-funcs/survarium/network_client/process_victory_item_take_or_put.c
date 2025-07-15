void __userpurge survarium::network_client::process_victory_item_take_or_put(
        vostok::network_core::packet_reader *packet@<eax>,
        survarium::network_client *this)
{
  const unsigned __int8 *m_pointer; // ecx
  char v3; // dl
  unsigned __int8 v4; // dl
  char v5; // bl
  survarium::network_client *v6; // ebp
  unsigned __int8 v7; // bl
  const unsigned __int8 *v8; // ecx
  bool v9; // zf
  const vostok::intrusive_ptr<survarium::victory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v10; // edi
  survarium::simple_game_project *m_object; // eax
  vostok::resources::unmanaged_resource *v12; // edx
  vostok::resources::resource_base *m_next_in_memory_type; // eax
  vostok::resources::resource_base *m_prev_in_memory_type; // edi
  vostok::resources::resource_base_vtbl *v15; // esi
  vostok::resources::resource_base_vtbl *v16; // ecx
  char v17; // bl
  int v18; // eax
  void (__thiscall *v19)(struct vostok::resources::resource_base *); // edx
  int v20; // eax
  survarium::network_client *v21; // ebx
  survarium::game_world_ui *v22; // ecx
  survarium::player *v23; // eax
  survarium::player *v24; // eax
  survarium::game_team_id v25; // eax
  int v26; // edx
  _DWORD *v27; // eax
  unsigned __int8 v28; // [esp+0h] [ebp-68h]
  char v29; // [esp+10h] [ebp-58h]
  vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base> current_player; // [esp+14h] [ebp-54h] BYREF
  bool is_base; // [esp+18h] [ebp-50h]
  vostok::resources::resource_base_vtbl *v32; // [esp+1Ch] [ebp-4Ch]
  vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base> team_1_points; // [esp+20h] [ebp-48h] BYREF
  int v34; // [esp+24h] [ebp-44h]
  vostok::math::float4x4 item_transform; // [esp+28h] [ebp-40h] BYREF

  m_pointer = packet->m_pointer;
  v3 = *m_pointer++;
  packet->m_pointer = m_pointer++;
  v29 = v3;
  v4 = *(m_pointer - 1);
  packet->m_pointer = m_pointer;
  v5 = *m_pointer++;
  packet->m_pointer = m_pointer;
  v6 = this;
  is_base = v5;
  v7 = *m_pointer;
  v8 = m_pointer + 1;
  v9 = !is_base;
  LOBYTE(this) = v7;
  packet->m_pointer = v8;
  if ( v9 && v7 == 0xFF )
    packet->m_pointer = v8 + 12;
  v10 = &v6->m_game->m_game_world.m_victory_items._M_impl._M_start[v4];
  this = 0;
  v34 = 4 * v4;
  vostok::intrusive_ptr<survarium::victory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    (vostok::intrusive_ptr<survarium::victory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this,
    v10);
  m_object = v6->m_game->m_game_world.m_game_project.m_object;
  v12 = 0;
  if ( m_object )
  {
    v12 = v6->m_game->m_game_world.m_game_project.m_object;
    _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
  m_next_in_memory_type = v12[1].m_next_in_memory_type;
  m_prev_in_memory_type = v12[1].m_prev_in_memory_type;
  v15 = 0;
  v32 = 0;
  if ( m_next_in_memory_type != m_prev_in_memory_type )
  {
    while ( 1 )
    {
      v16 = m_next_in_memory_type->__vftable;
      if ( LOBYTE(m_next_in_memory_type->__vftable[1].is_increasing_quality) == v7 )
        break;
      m_next_in_memory_type = (vostok::resources::resource_base *)((char *)m_next_in_memory_type + 4);
      if ( m_next_in_memory_type == m_prev_in_memory_type )
        goto LABEL_11;
    }
    v32 = m_next_in_memory_type->__vftable;
    v15 = v16;
  }
LABEL_11:
  if ( !_InterlockedExchangeAdd(&v12->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v12->vostok::resources::unmanaged_intrusive_base, v12);
  if ( v15 )
  {
    v17 = 2 * !is_base - 1;
    v18 = (*((int (__thiscall **)(vostok::resources::resource_base_vtbl *))v15->~vostok::resources::resource_base + 10))(v15);
    v19 = v15->~vostok::resources::resource_base;
    LOBYTE(team_1_points.m_object) = v18 == 0 ? v17 : 0;
    LOBYTE(current_player.m_object) = (*((int (__thiscall **)(vostok::resources::resource_base_vtbl *))v19 + 10))(v15) == 1
                                    ? v17
                                    : 0;
    survarium::game_world_ui::add_victory_points(
      (survarium::game_world_ui *)current_player.m_object,
      (char)team_1_points.m_object,
      (char)current_player.m_object);
  }
  if ( is_base )
  {
    v20 = (int)v6->get_player(v6, &team_1_points, v29);
    v21 = this;
    survarium::inventory::set_victory_item(
      *(survarium::inventory **)(*(_DWORD *)v20 + 8),
      (survarium::victory_item_core *)this);
    vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base>(&team_1_points);
    v23 = v6->m_current_player.m_object;
    if ( v23 )
    {
      if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
      {
        LOBYTE(v22) = v29;
        if ( v23->id == v29 )
          survarium::game_world_ui::show_item_container(v22, v28);
      }
    }
    if ( v15 )
    {
      (*((void (__thiscall **)(vostok::resources::resource_base_vtbl *))v15->~vostok::resources::resource_base + 9))(v15);
    }
    else
    {
      ((void (__thiscall *)(survarium::network_client *))v21->fill_current_player_stats)(v21);
      *(_DWORD *)&v21->m_login_client.m_server_host[28] = 3;
    }
  }
  else
  {
    v6->get_player(v6, &current_player, v29);
    survarium::inventory::set_victory_item(current_player.m_object->m_inventory.m_object, 0);
    v24 = v6->m_current_player.m_object;
    if ( v24
      && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr
      && v24->id == v29 )
    {
      Scaleform::GFx::Movie::Invoke(
        v6->m_game->m_game_world.game_ui.m_game_hud_ui.m_object->movie->m_movie,
        "root.hide_container_icon",
        0,
        0,
        0);
    }
    if ( v15 )
    {
      v21 = this;
      *(_DWORD *)&this->m_login_client.m_server_host[28] = 3;
      (*((void (__thiscall **)(vostok::resources::resource_base_vtbl *, survarium::network_client *))v15->~vostok::resources::resource_base
       + 8))(
        v15,
        v21);
    }
    else
    {
      v25 = current_player.m_object->team(current_player.m_object);
      v21 = this;
      v26 = v34;
      *(_DWORD *)&this->m_login_client.m_server_host[28] = v25;
      v27 = &v6->m_game->m_game_world.__vftable;
      qmemcpy((void *)&item_transform, &current_player.m_object->m_current.transform, sizeof(item_transform));
      (*(void (__thiscall **)(_DWORD, _DWORD, vostok::math::float4x4 *, int))(**(_DWORD **)(v26 + v27[177]) + 52))(
        *(_DWORD *)(v26 + v27[177]),
        v27[44],
        &item_transform,
        v27[42] + 896);
    }
    vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base>(&current_player);
  }
  survarium::game_world_ui::on_victory_item_put_take(
    &v6->m_game->m_game_world.game_ui,
    LOBYTE(v6->m_game) + 108,
    v29,
    is_base);
  if ( v21 )
  {
    if ( !_InterlockedExchangeAdd(
            (volatile signed __int32 *)&v21->m_login_client.m_on_sign_up.functor.bound_memfunc_ptr.obj_ptr,
            0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        (vostok::resources::unmanaged_intrusive_base *)&v21->m_login_client.m_on_sign_up.functor.data + 2,
        (vostok::resources::unmanaged_resource *)&v21->m_login_client);
  }
}
