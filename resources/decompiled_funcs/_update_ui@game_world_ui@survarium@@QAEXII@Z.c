// local variable allocation has failed, the output may be wrong!
void __usercall survarium::game_world_ui::update_ui(
        survarium::game_world_ui *this@<ecx>,
        survarium::game_world_ui *a2@<edi>,
        int a3@<esi>)
{
  survarium::flash_movie *movie; // eax
  float (__thiscall *Advance)(Scaleform::GFx::Movie *, float, unsigned int, bool); // eax
  survarium::base_network_client *m_network_client; // esi
  survarium::match_options *(__thiscall *match_options)(survarium::base_network_client *); // edx
  unsigned __int8 v7; // bl
  vostok::resources::unmanaged_resource *v8; // eax
  survarium::match_options *(__thiscall *v9)(survarium::base_network_client *); // edx
  survarium::game_world_ui *v10; // ecx
  survarium::base_network_client *v11; // ecx
  survarium::game_world_ui *v12; // ecx
  survarium::profile_slot_enum *M_start; // esi
  survarium::profile_slot_enum *j; // ebx
  bool v15; // [esp+2Fh] [ebp-9h]
  vostok::resources::unmanaged_intrusive_base *i; // [esp+30h] [ebp-8h] OVERLAPPED BYREF
  float v17; // [esp+34h] [ebp-4h]
  int vars0; // [esp+38h] [ebp+0h]

  movie = a2->m_game_hud_ui.m_object->movie;
  v17 = *(float *)&this;
  Advance = movie->m_movie->Advance;
  v17 = (double)(unsigned int)this * 0.001;
  ((void (__stdcall *)(_DWORD, _DWORD, int, int))Advance)(LODWORD(v17), 0, 1, a3);
  if ( a2->m_players_list_visible )
  {
    m_network_client = a2->m_game_world->m_game->m_network_client;
    match_options = m_network_client->match_options;
    v7 = 0;
    LOBYTE(v17) = 0;
    if ( match_options(m_network_client)->players_count )
    {
      do
      {
        v15 = *(_DWORD *)((int (__thiscall *)(survarium::base_network_client *, vostok::resources::unmanaged_intrusive_base **, float))m_network_client->get_player)(
                           m_network_client,
                           &i,
                           COERCE_FLOAT(LODWORD(v17))) != 0;
        if ( i && !_InterlockedExchangeAdd(&i[62].m_reference_count, 0xFFFFFFFF) )
        {
          if ( i )
            v8 = (vostok::resources::unmanaged_resource *)&i[36];
          else
            v8 = 0;
          vostok::resources::unmanaged_intrusive_base::destroy(i + 62, v8);
        }
        if ( v15 )
          survarium::game_world_ui::set_player_online_status(
            v7,
            a2,
            *((_BYTE *)&m_network_client[549].m_linear_speed_graph + 8 * v7));
        v9 = m_network_client->match_options;
        LOBYTE(v17) = ++v7;
      }
      while ( v7 < v9(m_network_client)->players_count );
    }
  }
  ((void (__stdcall *)(int, _DWORD))a2->m_game_world->m_game->m_chat_handler->m_chat_ui.m_object->movie->m_movie->Advance)(
    vars0,
    0);
  LOBYTE(v10) = (_BYTE)is_ui_minimap_rotable_old;
  if ( (_BYTE)is_ui_minimap_rotable_old != is_ui_minimap_rotable )
    survarium::game_world_ui::reset_map_rotatable(v10, (int)a2);
  survarium::game_world_ui::update_minimap_local_player(v10, a2);
  v11 = a2->m_game_world->m_game->m_network_client;
  if ( v11->has_bandwidth(v11) )
    survarium::game_world_ui::update_minimap_players(v12, a2);
  if ( a2->m_slots_to_update._M_impl._M_finish - a2->m_slots_to_update._M_impl._M_start )
  {
    M_start = a2->m_slots_to_update._M_impl._M_start;
    for ( j = a2->m_slots_to_update._M_impl._M_finish; M_start != j; ++M_start )
      survarium::game_world_ui::update_quick_slot(*M_start, a2);
  }
}
