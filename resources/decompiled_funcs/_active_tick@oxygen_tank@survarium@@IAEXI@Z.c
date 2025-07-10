void __thiscall survarium::oxygen_tank::active_tick(survarium::oxygen_tank *this, unsigned int frame_time_ms)
{
  unsigned int v2; // ecx
  bool has_passed_filters; // al
  char v5; // [esp+10h] [ebp-2Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+14h] [ebp-28h] BYREF
  char v7; // [esp+3Bh] [ebp-1h]

  v5 = 0;
  v7 = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  v2 = this->m_amount_ms - vostok::math::min(this->m_amount_ms, frame_time_ms);
  this->m_amount_ms = v2;
  if ( !vostok::core::g_log_filter_tree
    || (has_passed_filters = vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "game_core:", info),
        (v2 = has_passed_filters) != 0) )
  {
    boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>((boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v2);
    v5 = 1;
    vostok::logging::append(
      &log_callback,
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      ".\\oxygen_tank.cpp",
      0x5Cu,
      "void __thiscall survarium::oxygen_tank::active_tick(const unsigned int)",
      "game_core:",
      info,
      "amount is: %dms",
      this->m_amount_ms);
  }
  if ( (v5 & 1) != 0 )
    boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
      (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)v2,
      (int *)&log_callback);
  if ( !this->m_amount_ms )
    survarium::oxygen_tank::set_active(this, 0);
}
