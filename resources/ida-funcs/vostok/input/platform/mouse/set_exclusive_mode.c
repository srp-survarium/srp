void __thiscall vostok::input::platform::mouse::set_exclusive_mode(vostok::input::platform::mouse *this, bool value)
{
  volatile int *p_m_busy; // ecx
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v4; // ecx
  bool has_passed_filters; // al
  const char *v6; // ebx
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v7; // [esp+0h] [ebp-3Ch]
  char v8; // [esp+14h] [ebp-28h]
  volatile __int32 *v9; // [esp+18h] [ebp-24h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v10; // [esp+1Ch] [ebp-20h] BYREF

  v8 = 0;
  p_m_busy = &this->m_busy;
  this->m_exclusive_mode = value;
  v9 = p_m_busy;
  while ( !_InterlockedCompareExchange(p_m_busy, 1, 0) )
    ;
  this->m_device->Unacquire(this->m_device);
  this->m_device->SetCooperativeLevel(this->m_device, this->m_window_handle, (!this->m_exclusive_mode + 1) | 4);
  this->m_device->Acquire(this->m_device);
  if ( !vostok::core::g_log_filter_tree
    || (has_passed_filters = vostok::logging::has_passed_filters(
                               (vostok::logging::filter_tree *)"input",
                               (const char *)4),
        v4 = v7,
        has_passed_filters) )
  {
    v6 = "ON";
    if ( !value )
      v6 = "OFF";
    boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
      v4,
      &v10);
    v8 = 1;
    vostok::logging::append(
      &v10,
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      ".\\platform_mouse_win.cpp",
      0xB2u,
      "void __thiscall vostok::input::platform::mouse::set_exclusive_mode(bool)",
      "input",
      info,
      "mouse exclusive mode is %s",
      v6);
  }
  if ( (v8 & 1) != 0 )
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v4,
      (int *)&v10);
  _InterlockedExchange(v9, 0);
}
