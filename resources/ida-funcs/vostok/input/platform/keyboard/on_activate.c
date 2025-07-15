void __thiscall vostok::input::platform::keyboard::on_activate(vostok::input::platform::keyboard *this)
{
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v2; // ecx
  bool has_passed_filters; // al
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v4; // [esp-4h] [ebp-34h]
  char v5; // [esp+Ch] [ebp-24h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v6; // [esp+10h] [ebp-20h] BYREF

  v5 = 0;
  if ( this->m_device->Acquire(this->m_device) < 0 )
  {
    if ( !vostok::core::g_log_filter_tree
      || (has_passed_filters = vostok::logging::has_passed_filters(
                                 (vostok::logging::filter_tree *)"input",
                                 (const char *)2),
          v2 = v4,
          has_passed_filters) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        v2,
        &v6);
      v5 = 1;
      vostok::logging::append(
        &v6,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\platform_keyboard_win.cpp",
        0x4Eu,
        "void __thiscall vostok::input::platform::keyboard::on_activate(void)",
        "input",
        error,
        "KeyboardDevice Acquire FAILED");
    }
    if ( (v5 & 1) != 0 )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v2,
        (int *)&v6);
  }
  memset((int)this->m_current_key_state, 0, sizeof(this->m_current_key_state));
}
