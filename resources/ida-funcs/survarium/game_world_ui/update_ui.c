void __thiscall survarium::game_world_ui::update_ui(
        survarium::game_world_ui *this,
        unsigned int frame_delta_ms,
        vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> current_time_in_ms,
        float force_advance,
        vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> a5)
{
  survarium::flash_movie *v6; // ecx
  survarium::flash_movie *v7; // ecx
  unsigned int v8; // eax
  survarium::game_world_ui *v9; // ecx
  int v10; // esi
  survarium::game_world_ui *v11; // ecx
  survarium::game_world_ui *v12; // ecx
  int v13; // eax
  survarium::text_translator *v14; // ecx
  survarium::game_world_ui *v15; // ecx
  survarium::game_world_ui *v16; // ecx
  survarium::game_world_ui *v17; // ecx
  survarium::game_world_ui *v18; // ecx
  survarium::flash_movie *v19; // ecx
  survarium::flash_movie *v20; // ecx
  int v21; // [esp+14h] [ebp-Ch]
  float delta_time; // [esp+18h] [ebp-8h]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v23; // [esp+1Ch] [ebp-4h] BYREF
  float __formal; // [esp+28h] [ebp+8h]
  unsigned __int8 __formala; // [esp+28h] [ebp+8h]

  survarium::game_world_ui::update_icons(
    this,
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>)frame_delta_ms);
  __formal = (double)(unsigned int)current_time_in_ms.m_object * 0.001;
  survarium::flash_movie::Advance(v6, *(_DWORD *)(*(_DWORD *)(frame_delta_ms + 16) + 264), __formal, 0);
  v8 = LODWORD(force_advance) - *(_DWORD *)(frame_delta_ms + 580);
  if ( v8 >= 0x19 )
  {
    a5.m_object = (vostok::particle::particle_system_instance_impl *)(LODWORD(force_advance)
                                                                    - *(_DWORD *)(frame_delta_ms + 580));
    delta_time = (double)v8 * 0.001;
    a5.m_object = (vostok::particle::particle_system_instance_impl *)boost::detail::crc_helper<32,1>::reflect(0xFFFFFFFF);
    boost::detail::crc_table_t<32,79764919,1>::init_table();
    boost::crc_optimal<32,79764919,0,0,1,0>::process_block(
      (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1> *)&a5,
      (char *)(frame_delta_ms + 28),
      (char *)(frame_delta_ms + 488));
    v10 = ~(int)a5.m_object;
    v21 = ~(int)a5.m_object;
    if ( ~(int)a5.m_object != *(_DWORD *)(frame_delta_ms + 496) )
    {
      if ( *(_BYTE *)(frame_delta_ms + 336) )
      {
        survarium::game_world_ui::show_pregame(v9, frame_delta_ms, 1);
        survarium::game_world_ui::set_pregame(
          *(_DWORD *)(frame_delta_ms + 168),
          (survarium::game_world_ui *)frame_delta_ms,
          (char *)(frame_delta_ms + 40));
      }
      else
      {
        survarium::game_world_ui::show_pregame(v9, frame_delta_ms, 0);
        survarium::game_world_ui::set_match_time(
          *(_DWORD *)(frame_delta_ms + 32),
          (survarium::game_world_ui *)frame_delta_ms);
        survarium::base_network_client::get_current_player(
          *(survarium::base_network_client **)(*(_DWORD *)(*(_DWORD *)(frame_delta_ms + 20) + 160) + 13912),
          &a5);
        if ( a5.m_object
          && (v12 = (survarium::game_world_ui *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr) != 0 )
        {
          v13 = *(_DWORD *)(a5.m_object[88].m_is_playing + 440);
        }
        else
        {
          v13 = 0;
        }
        survarium::game_world_ui::set_victory_points(
          v12,
          frame_delta_ms,
          *(_BYTE *)(frame_delta_ms + 172),
          (survarium::game_team_id)*(unsigned __int8 *)(frame_delta_ms + 173),
          v13);
        survarium::game_world_ui::set_local_respawn_time(
          *(_DWORD *)(frame_delta_ms + 36),
          v14,
          (survarium::game_world_ui *)frame_delta_ms);
        vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&a5);
      }
      if ( *(_BYTE *)(frame_delta_ms + 174) )
      {
        for ( __formala = 0; ; ++__formala )
        {
          vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
            &current_time_in_ms,
            (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(*(_DWORD *)(frame_delta_ms + 20) + 13604));
          HIBYTE(a5.m_object) = __formala < *(_BYTE *)(LODWORD(current_time_in_ms.m_object->m_lods[0].m_time_fade_out)
                                                     + 29772);
          vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&current_time_in_ms);
          if ( !HIBYTE(a5.m_object) )
            break;
          vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
            &v23,
            (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(*(_DWORD *)(frame_delta_ms + 20) + 13604));
          survarium::game_world_ui::set_player_online_status(
            (survarium::game_world_ui *)LODWORD(v23.m_object->m_lods[0].m_time_fade_out),
            frame_delta_ms,
            (const char (*)[64])(1488 * __formala + LODWORD(v23.m_object->m_lods[0].m_time_fade_out) + 8),
            *(_BYTE *)(frame_delta_ms + 8 * __formala + 180));
          vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v23);
          survarium::game_world_ui::set_player_stats_info(v15, frame_delta_ms, __formala);
        }
        v10 = v21;
      }
      survarium::game_world_ui::update_minimap_objects(v11, frame_delta_ms);
      *(_DWORD *)(frame_delta_ms + 496) = v10;
    }
    if ( is_ui_minimap_fixed_old != is_ui_minimap_fixed )
      survarium::game_world_ui::reset_map_rotatable(v9, frame_delta_ms);
    survarium::game_world_ui::update_minimap_local_player(v9, frame_delta_ms);
    survarium::game_world_ui::update_minimap_players(
      v16,
      (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>)frame_delta_ms);
    survarium::game_world_ui::update_current_player(v17, (survarium::profile_slot_enum)frame_delta_ms);
    survarium::game_world_ui::update_current_object(v18, frame_delta_ms);
    survarium::flash_movie::Advance(v19, *(_DWORD *)(*(_DWORD *)(frame_delta_ms + 8) + 264), delta_time, 0);
    if ( *(_BYTE *)(frame_delta_ms + 492) )
      survarium::flash_movie::Advance(v20, *(_DWORD *)(*(_DWORD *)(frame_delta_ms + 12) + 264), delta_time, 0);
    *(float *)(frame_delta_ms + 580) = force_advance;
  }
  else if ( LOBYTE(a5.m_object) )
  {
    survarium::flash_movie::Advance(v7, *(_DWORD *)(*(_DWORD *)(frame_delta_ms + 8) + 264), __formal, 0);
  }
}
