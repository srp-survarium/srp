void __thiscall survarium::network_client::on_world_sync_request(
        survarium::network_client *this,
        survarium::network_client *thisa)
{
  survarium::network_client *v2; // edi
  unsigned __int8 v3; // bl
  survarium::player *v4; // ecx
  survarium::player *m_object; // eax
  survarium::inventory *v6; // ecx
  bool v7; // zf
  vostok::resources::unmanaged_resource *v8; // eax
  survarium::simple_game_project *v9; // ecx
  vostok::resources::unmanaged_resource *v10; // eax
  vostok::resources::resource_base *m_next_in_memory_type; // ebp
  survarium::simple_game_project *v12; // ecx
  vostok::resources::unmanaged_resource *v13; // eax
  bool v14; // bl
  void **link_child_resource; // eax
  void **log_string; // ecx
  int p_log_string; // esi
  void **v18; // edi
  survarium::game *m_game; // eax
  vostok::resources::resource_ptr<survarium::victory_item,vostok::resources::unmanaged_intrusive_base> *M_start; // esi
  vostok::network_core::udp_match_packet *v21; // eax
  vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base> player; // [esp+18h] [ebp-8h] BYREF
  int id; // [esp+1Ch] [ebp-4h]

  v2 = thisa;
  v3 = 0;
  thisa->m_player_inputs.m_end = thisa->m_player_inputs.m_begin;
  LOBYTE(id) = 0;
  do
  {
    thisa->get_player(thisa, &player, id);
    if ( !player.m_object )
      goto LABEL_14;
    if ( !player.m_object->m_has_been_inserted )
    {
      v7 = _InterlockedExchangeAdd(&player.m_object->m_reference_count, 0xFFFFFFFF) == 0;
LABEL_9:
      if ( v7 )
      {
        if ( player.m_object )
          v8 = &player.m_object->vostok::resources::unmanaged_resource;
        else
          v8 = 0;
        vostok::resources::unmanaged_intrusive_base::destroy(
          &player.m_object->vostok::resources::unmanaged_intrusive_base,
          v8);
      }
      goto LABEL_14;
    }
    survarium::player::remove(v4);
    m_object = player.m_object;
    v6 = player.m_object->m_inventory.m_object;
    if ( v6->m_victory_item )
    {
      survarium::inventory::set_victory_item(v6, 0);
      m_object = player.m_object;
    }
    if ( m_object )
    {
      v7 = _InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) == 0;
      goto LABEL_9;
    }
LABEL_14:
    LOBYTE(id) = ++v3;
  }
  while ( v3 < 0x14u );
  v9 = thisa->m_game->m_game_world.m_game_project.m_object;
  v10 = 0;
  if ( v9 )
  {
    v10 = thisa->m_game->m_game_world.m_game_project.m_object;
    _InterlockedExchangeAdd(&v9->m_reference_count, 1u);
  }
  m_next_in_memory_type = v10[1].m_next_in_memory_type;
  if ( !_InterlockedExchangeAdd(&v10->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v10->vostok::resources::unmanaged_intrusive_base, v10);
  while ( 1 )
  {
    v12 = v2->m_game->m_game_world.m_game_project.m_object;
    v13 = 0;
    if ( v12 )
    {
      v13 = v2->m_game->m_game_world.m_game_project.m_object;
      _InterlockedExchangeAdd(&v12->m_reference_count, 1u);
    }
    v14 = m_next_in_memory_type != v13[1].m_prev_in_memory_type;
    if ( !_InterlockedExchangeAdd(&v13->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(&v13->vostok::resources::unmanaged_intrusive_base, v13);
    if ( !v14 )
      break;
    link_child_resource = (void **)m_next_in_memory_type->__vftable[1].link_child_resource;
    log_string = (void **)m_next_in_memory_type->__vftable[1].log_string;
    p_log_string = (int)&m_next_in_memory_type->__vftable[1].log_string;
    if ( log_string != link_child_resource )
    {
      v18 = stlp_std::priv::__copy_ptrs<void * *,void * *>(link_child_resource, link_child_resource, log_string);
      stlp_std::_Destroy<vostok::fs_new::virtual_path_string>();
      *(_DWORD *)(p_log_string + 4) = v18;
      v2 = thisa;
    }
    m_next_in_memory_type = (vostok::resources::resource_base *)((char *)m_next_in_memory_type + 4);
  }
  m_game = v2->m_game;
  M_start = m_game->m_game_world.m_victory_items._M_impl._M_start;
  if ( M_start != m_game->m_game_world.m_victory_items._M_impl._M_finish )
  {
    do
    {
      if ( M_start->m_object->m_is_inserted )
        M_start->m_object->take(M_start->m_object);
      ++M_start;
    }
    while ( M_start != v2->m_game->m_game_world.m_victory_items._M_impl._M_finish );
  }
  v21 = vostok::network::match_client::new_packet(&v2->m_match_client.m_client, 0x4Au);
  vostok::network::match_client::enqueue(&v2->m_match_client.m_client, v21);
  v2->m_match_client.m_are_there_any_packets_to_send = 1;
}
