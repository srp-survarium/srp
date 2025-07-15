unsigned int __userpurge survarium::network_client::try_send_all@<eax>(
        survarium::network_client *this@<ecx>,
        int a2@<edi>,
        unsigned int game_time_in_ms,
        const bool can_send_hashes)
{
  unsigned int elapsed_msec; // ebx
  int v5; // eax
  int v6; // ecx
  const survarium::pvp_match_core *v7; // esi
  _DWORD *v8; // eax
  survarium::game_world_core *v9; // ecx
  int v10; // esi
  survarium::game_world_core *v11; // ecx
  int v12; // esi
  survarium::game_state_history_item *v13; // ebx
  survarium::game_state_history_item *v14; // ecx
  int v15; // esi
  vostok::network_core::buffer_writer *v16; // ecx
  vostok::network_core::buffer_writer *v17; // ecx
  int v18; // eax
  survarium::pvp_match_core *v19; // ecx
  int v20; // ebx
  vostok::timing::floating_timer *v21; // ecx
  vostok::network_core::buffer_writer *v22; // ecx
  int v23; // ecx
  char v25; // [esp+Fh] [ebp-11h]
  char v26; // [esp+10h] [ebp-10h]
  unsigned int v27; // [esp+14h] [ebp-Ch]
  survarium::packet_sender result; // [esp+18h] [ebp-8h] BYREF

  v26 = 0;
  elapsed_msec = vostok::timing::timer::get_elapsed_msec((vostok::timing::timer *)this, *(_DWORD *)(a2 + 24) + 64);
  v5 = *(_DWORD *)(a2 + 20696);
  v27 = elapsed_msec;
  if ( !v5
    || !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr
    || (v6 = *(_DWORD *)(a2 + 4)) == 0
    || !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr
    || (v26 = 1,
        !survarium::pvp_match_core::active_player_ptr(
           (survarium::pvp_match_core *)&result,
           v5,
           (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&result,
           *(_BYTE *)(v6 + 304))->m_object)
    || (v25 = 1,
        !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr) )
  {
    v25 = 0;
  }
  if ( (v26 & 1) != 0 )
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&result);
  if ( v25 )
  {
    v7 = *(const survarium::pvp_match_core **)(a2 + 20696);
    result.m_match_client = (survarium::base_match_client *)(*(int (__thiscall **)(int))(*(_DWORD *)a2 + 64))(a2);
    v8 = *(_DWORD **)(*(_DWORD *)(a2 + 20696) + 312);
    v9 = (survarium::game_world_core *)(v8[12798] - v8[12795]);
    result.m_match = v7;
    survarium::game_world_core::synchronize<survarium::packet_sender>(
      v9,
      v8,
      (unsigned int)v9,
      game_time_in_ms,
      &result);
  }
  if ( can_send_hashes && *(_DWORD *)(a2 + 20708) + 100 <= elapsed_msec )
  {
    v10 = *(_DWORD *)(a2 + 20696);
    *(_DWORD *)(a2 + 20708) = 100 * (elapsed_msec / 0x64);
    if ( v10 )
    {
      if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr
        && survarium::pvp_match_core::is_there_event_horizon_item((survarium::pvp_match_core *)0x64, v10) )
      {
        v12 = *(_DWORD *)(v10 + 312);
        v13 = survarium::game_world_core::event_horizon_history_item(v11, v12);
        result.m_match = (const survarium::pvp_match_core *)survarium::game_state_history_item::hash(
                                                              v14,
                                                              (const survarium::fixed_history<survarium::players_mask_history_item,40> *)v13,
                                                              (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)(v12 + 24272));
        result.m_match_client = *(survarium::base_match_client **)&v13->players.elems[0].player_state.m_raw_buffer.elems[(_DWORD)&loc_B9937 + 1];
        if ( s_force_hash_mismatch )
        {
          result.m_match = (const survarium::pvp_match_core *)-1;
          s_force_hash_mismatch = 0;
        }
        v15 = (*(int (__thiscall **)(_DWORD, int))(**(_DWORD **)(a2 + 13768) + 24))(*(_DWORD *)(a2 + 13768), 71);
        vostok::network_core::buffer_writer::w(v16, (_DWORD *)(v15 + 1340), (unsigned __int8 *)&result, 4u);
        vostok::network_core::buffer_writer::w(v17, (_DWORD *)(v15 + 1340), (unsigned __int8 *)&result.m_match, 4u);
        (*(void (__thiscall **)(_DWORD, int))(**(_DWORD **)(a2 + 13768) + 28))(*(_DWORD *)(a2 + 13768), v15);
        elapsed_msec = v27;
      }
    }
  }
  if ( *(_DWORD *)(a2 + 20712) + 1000 <= elapsed_msec )
  {
    *(_DWORD *)(a2 + 20712) = elapsed_msec;
    v18 = *(_DWORD *)(a2 + 20696);
    if ( v18 )
    {
      if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
      {
        v19 = *(survarium::pvp_match_core **)(v18 + 312);
        if ( v19[30].m_next_in_global_delay_delete_list )
        {
          if ( survarium::pvp_match_core::is_there_event_horizon_item(v19, v18) )
          {
            v20 = (*(int (__thiscall **)(_DWORD, int))(**(_DWORD **)(a2 + 13768) + 24))(*(_DWORD *)(a2 + 13768), 69);
            result.m_match_client = (survarium::base_match_client *)vostok::timing::floating_timer::get_elapsed_msec(
                                                                      v21,
                                                                      (vostok::timing::floating_timer *)(*(_DWORD *)(a2 + 24) + 16));
            vostok::network_core::buffer_writer::w(v22, (_DWORD *)(v20 + 1340), (unsigned __int8 *)&result, 4u);
            (*(void (__thiscall **)(_DWORD, int))(**(_DWORD **)(a2 + 13768) + 28))(*(_DWORD *)(a2 + 13768), v20);
            elapsed_msec = v27;
          }
        }
      }
    }
  }
  v23 = *(_DWORD *)(a2 + 13768);
  if ( *(_BYTE *)(v23 + 8) || *(_DWORD *)(v23 + 12) + 10 <= elapsed_msec )
    (*(void (__thiscall **)(int, unsigned int))(*(_DWORD *)v23 + 32))(v23, elapsed_msec);
  return elapsed_msec;
}
