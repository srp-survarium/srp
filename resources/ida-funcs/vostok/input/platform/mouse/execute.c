void __thiscall vostok::input::platform::mouse::execute(vostok::input::platform::mouse *this)
{
  volatile int *p_m_busy; // ecx
  int v3; // eax
  int v4; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v5; // ecx
  bool has_passed_filters; // al
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v7; // [esp+8h] [ebp-54h]
  volatile __int32 *v8; // [esp+1Ch] [ebp-40h]
  char v9; // [esp+24h] [ebp-38h]
  _DIMOUSESTATE2 v10; // [esp+28h] [ebp-34h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v11; // [esp+3Ch] [ebp-20h] BYREF

  v9 = 0;
  p_m_busy = &this->m_busy;
  v8 = p_m_busy;
  while ( !_InterlockedCompareExchange(p_m_busy, 1, 0) )
    ;
  this->m_previous_state.x = this->m_current_state.x;
  this->m_previous_state.y = this->m_current_state.y;
  this->m_previous_state.z = this->m_current_state.z;
  *(_DWORD *)&this->m_previous_state.buttons = *(_DWORD *)&this->m_current_state.buttons;
  v3 = this->m_device->GetDeviceState(this->m_device, 20u, &v10);
  if ( v3 >= 0 )
    goto LABEL_4;
  if ( (v3 == -2147024884 || v3 == -2147024866) && this->m_device->Acquire(this->m_device) >= 0 )
  {
    v4 = this->m_device->GetDeviceState(this->m_device, 20u, &v10);
    if ( v4 >= 0 )
    {
LABEL_4:
      fill_state(&this->m_current_state, &v10);
      goto LABEL_16;
    }
    if ( v4 == -2147024884 || v4 == -2147024866 )
    {
      if ( !vostok::core::g_log_filter_tree
        || (has_passed_filters = vostok::logging::has_passed_filters(
                                   (vostok::logging::filter_tree *)"input",
                                   (const char *)4),
            v5 = v7,
            has_passed_filters) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v5,
          &v11);
        v9 = 1;
        vostok::logging::append(
          &v11,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\platform_mouse_win.cpp",
          0xA2u,
          "void __thiscall vostok::input::platform::mouse::execute(void)",
          "input",
          info,
          "mouse device is lost");
      }
      if ( (v9 & 1) != 0 )
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
          (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v5,
          (int *)&v11);
    }
  }
LABEL_16:
  _InterlockedExchange(v8, 0);
}
