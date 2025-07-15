void __thiscall survarium::game_world::switch_to_free_fly_camera(survarium::game_world *this, _DWORD *a2)
{
  survarium::player_input_handler *v2; // ecx
  survarium::camera_director *v3; // esi
  survarium::game_camera *v4; // edi
  boost::function<survarium::game_effect_time __cdecl(survarium::game_effect_node const &,unsigned int,unsigned int)> *v5; // ecx
  survarium::game_effect_player *v6; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v7; // ecx
  int v8; // [esp+0h] [ebp-38h]
  bool v9; // [esp+Fh] [ebp-29h]
  unsigned int i; // [esp+10h] [ebp-28h]
  int v11[8]; // [esp+18h] [ebp-20h] BYREF

  v2 = (survarium::player_input_handler *)a2[3404];
  if ( v2 )
    survarium::player_input_handler::set_input_mode(v2, free_fly_mode);
  v3 = (survarium::camera_director *)a2[38];
  v4 = (survarium::game_camera *)a2[3402];
  v9 = v3->m_active_camera != v4;
  survarium::camera_director::switch_to_camera(v3, v4);
  if ( v9 )
  {
    for ( i = 0; i < a2[284]; ++i )
    {
      boost::function<survarium::game_effect_time __cdecl (survarium::game_effect_node const &,unsigned int,unsigned int)>::function<survarium::game_effect_time __cdecl (survarium::game_effect_node const &,unsigned int,unsigned int)>(
        v5,
        v11,
        0,
        v8);
      survarium::game_effect_player::add(
        v6,
        (const vostok::intrusive_ptr<survarium::game_effect,survarium::game_effect,vostok::threading::single_threading_policy> *)(a2[3402] + 152),
        (vostok::intrusive_ptr<survarium::game_effect,survarium::game_effect,vostok::threading::single_threading_policy> *)(a2[283] + 4 * i),
        *(_DWORD *)(a2[40] + 13956),
        (const boost::function<survarium::game_effect_time __cdecl(survarium::game_effect_node const &,unsigned int,unsigned int)> *)1,
        (const boost::function<survarium::game_effect_time __cdecl(survarium::game_effect_node const &,unsigned int,unsigned int)> *)v11);
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v7, v11);
    }
  }
}
