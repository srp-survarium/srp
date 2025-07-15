void __thiscall survarium::player_input_handler::process_toggle_action(
        survarium::player_input_handler *this,
        const survarium::game_action_id action_id,
        survarium::game_action_id value)
{
  char *v4; // esi
  int v5; // ebx
  char *v6; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v7; // ecx
  bool has_passed_filters; // al
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v9; // [esp-4h] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v10; // [esp-4h] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v11; // [esp+10h] [ebp-28h] BYREF
  survarium::game_action_id *v12; // [esp+34h] [ebp-4h] BYREF
  char v13; // [esp+40h] [ebp+8h]

  v13 = 0;
  v4 = *(char **)(action_id + 684);
  v5 = action_id + 680;
  v6 = stlp_std::find<vostok::render::render_output_window * *,vostok::render::render_output_window *>(
         *(char **)v5,
         (int *)&value,
         v4);
  v7 = v9;
  v12 = (survarium::game_action_id *)v6;
  if ( v6 == v4 )
  {
    if ( (unsigned int)((*(_DWORD *)(v5 + 4) - *(_DWORD *)v5) >> 2) >= 0x20 )
    {
      if ( !vostok::core::g_log_filter_tree
        || (has_passed_filters = vostok::logging::has_passed_filters(
                                   (vostok::logging::filter_tree *)"game",
                                   (const char *)2),
            v7 = v10,
            has_passed_filters) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v7,
          &v11);
        v13 = 1;
        vostok::logging::append(
          &v11,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\player_input_handler.cpp",
          0xB0u,
          "void __thiscall survarium::player_input_handler::process_toggle_action(const enum survarium::game_action_id)",
          "game",
          error,
          "m_game_toggle_actions.size() == %d",
          (*(_DWORD *)(v5 + 4) - *(_DWORD *)v5) >> 2);
      }
      if ( (v13 & 1) != 0 )
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
          (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v7,
          (int *)&v11);
    }
    vostok::buffer_vector<enum survarium::game_action_id>::push_back(
      (vostok::buffer_vector<enum survarium::game_action_id> *)v7,
      v5,
      &value);
  }
  else
  {
    vostok::buffer_vector<vostok::render::sky_ambient_occlusion *>::erase(
      (vostok::buffer_vector<enum survarium::game_action_id> *)v5,
      &v12);
  }
}
