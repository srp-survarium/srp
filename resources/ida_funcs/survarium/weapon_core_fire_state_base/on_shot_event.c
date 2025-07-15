vostok::animation::callback_return_type_enum __thiscall survarium::weapon_core_fire_state_base::on_shot_event(
        survarium::weapon_core_fire_state_base *this,
        vostok::animation::animation_callback_params *params)
{
  survarium::game_camera *v2; // ecx
  survarium::weapon_core *m_weapon; // ecx
  survarium::game_camera *v5; // ecx
  int m_bullets_in_queue; // [esp+12h] [ebp-32h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+1Ch] [ebp-28h] BYREF
  char v9; // [esp+42h] [ebp-2h]
  char v10; // [esp+43h] [ebp-1h]

  params->interrupt_animation_player_tick = 1;
  v10 = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  v9 = 0;
  survarium::weapon_user_dead_state::finalize(v2);
  m_weapon = this->m_weapon;
  m_bullets_in_queue = m_weapon->m_bullets_in_queue;
  if ( (_WORD)m_bullets_in_queue )
  {
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)m_weapon);
    survarium::weapon_core::instant_fire(this->m_weapon, params->callback_time_in_ms);
    survarium::weapon_user_dead_state::finalize(v5);
    return 0;
  }
  else
  {
    if ( !vostok::core::g_log_filter_tree
      || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "game_core:", error) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>((boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)m_weapon);
      BYTE2(m_bullets_in_queue) |= 1u;
      vostok::logging::append(
        &log_callback,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\weapon_core_fire_state_base.cpp",
        0x52u,
        "enum vostok::animation::callback_return_type_enum __thiscall survarium::weapon_core_fire_state_base::on_shot_eve"
        "nt(struct vostok::animation::animation_callback_params &)",
        "game_core:",
        error,
        "!m_weapon.get_bullets_in_queue()");
    }
    if ( (m_bullets_in_queue & 0x10000) != 0 )
      boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
        (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)m_weapon,
        (int *)&log_callback);
    return 0;
  }
}
