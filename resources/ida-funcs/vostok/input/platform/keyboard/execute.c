void __thiscall vostok::input::platform::keyboard::execute(vostok::input::platform::keyboard *this)
{
  IDirectInputDevice8A *m_device; // eax
  int v3; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v4; // ecx
  bool has_passed_filters; // al
  bool v6; // al
  bool v7; // zf
  bool v8; // al
  bool v9; // al
  int v10; // esi
  bool v11; // al
  unsigned int v12; // eax
  unsigned int v13; // edx
  unsigned int *p_dwData; // ecx
  int v15; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v16; // [esp+1Ch] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v17; // [esp+1Ch] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v18; // [esp+1Ch] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v19; // [esp+1Ch] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v20; // [esp+1Ch] [ebp-3Ch]
  char v21; // [esp+2Ch] [ebp-2Ch]
  unsigned int v22; // [esp+30h] [ebp-28h] BYREF
  int v23; // [esp+34h] [ebp-24h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v24; // [esp+38h] [ebp-20h] BYREF

  m_device = this->m_device;
  v22 = 64;
  v21 = 0;
  v3 = m_device->GetDeviceData(m_device, 20u, this->m_current_events, &v22, 0);
  v23 = v3;
  if ( v3 >= 0 )
    goto LABEL_25;
  switch ( v3 )
  {
    case -2147024866:
      if ( !vostok::core::g_log_filter_tree
        || (has_passed_filters = vostok::logging::has_passed_filters(
                                   (vostok::logging::filter_tree *)"input",
                                   (const char *)2),
            v4 = v16,
            has_passed_filters) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v4,
          &v24);
        v21 = 1;
        vostok::logging::append(
          &v24,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\platform_keyboard_win.cpp",
          0x6Bu,
          "void __thiscall vostok::input::platform::keyboard::execute(void)",
          "input",
          error,
          "DIERR_INPUTLOST");
      }
      if ( (v21 & 1) != 0 )
      {
        v21 &= ~1u;
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
          (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v4,
          (int *)&v24);
      }
      goto LABEL_27;
    case -2147024809:
      if ( !vostok::core::g_log_filter_tree
        || (v6 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"input", (const char *)2),
            v4 = v17,
            v6) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v4,
          &v24);
        v21 = 2;
        vostok::logging::append(
          &v24,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\platform_keyboard_win.cpp",
          0x6Fu,
          "void __thiscall vostok::input::platform::keyboard::execute(void)",
          "input",
          error,
          "DIERR_INVALIDPARAM");
      }
      v7 = (v21 & 2) == 0;
      goto LABEL_33;
    case -2147024884:
      goto LABEL_25;
    case -2147024875:
      if ( !vostok::core::g_log_filter_tree
        || (v8 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"input", (const char *)2),
            v4 = v18,
            v8) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v4,
          &v24);
        v21 = 4;
        vostok::logging::append(
          &v24,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\platform_keyboard_win.cpp",
          0x77u,
          "void __thiscall vostok::input::platform::keyboard::execute(void)",
          "input",
          error,
          "DIERR_NOTINITIALIZED");
      }
      v7 = (v21 & 4) == 0;
      goto LABEL_33;
  }
  if ( v3 != -2147483638 )
  {
LABEL_25:
    if ( v3 != -2147024866 && v3 != -2147024884 )
    {
      if ( v3 < 0 )
        return;
LABEL_36:
      v12 = v22;
      v13 = 0;
      this->m_current_events_count = v22;
      if ( v12 )
      {
        p_dwData = &this->m_current_events[0].dwData;
        do
        {
          v15 = *(p_dwData - 1);
          if ( *(char *)p_dwData >= 0 )
          {
            switch ( v15 )
            {
              case 29:
              case 157:
                this->m_modifiers &= ~2u;
                break;
              case 42:
              case 54:
                this->m_modifiers &= ~1u;
                break;
              case 56:
              case 184:
                this->m_modifiers &= ~4u;
                break;
            }
          }
          else
          {
            switch ( v15 )
            {
              case 29:
              case 157:
                this->m_modifiers |= 2u;
                break;
              case 42:
              case 54:
                this->m_modifiers |= 1u;
                break;
              case 56:
              case 184:
                this->m_modifiers |= 4u;
                break;
            }
          }
          ++v13;
          this->m_current_key_state[v15] = *p_dwData & 0x80;
          p_dwData += 5;
        }
        while ( v13 < this->m_current_events_count );
      }
      if ( (GetKeyState(20) & 1) != 0 )
        this->m_modifiers |= 8u;
      else
        this->m_modifiers &= ~8u;
      return;
    }
LABEL_27:
    v10 = this->m_device->Acquire(this->m_device);
    memset((int)this->m_current_key_state, 0, sizeof(this->m_current_key_state));
    if ( v10 < 0 )
      return;
    if ( this->m_device->GetDeviceData(this->m_device, 20u, this->m_current_events, &v22, 0) < 0 )
    {
      if ( !vostok::core::g_log_filter_tree
        || (v11 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"input", (const char *)2),
            v4 = v20,
            v11) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v4,
          &v24);
        v21 |= 0x10u;
        vostok::logging::append(
          &v24,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\platform_keyboard_win.cpp",
          0x8Fu,
          "void __thiscall vostok::input::platform::keyboard::execute(void)",
          "input",
          error,
          "can't get mouse keyboard");
      }
      v7 = (v21 & 0x10) == 0;
LABEL_33:
      if ( !v7 )
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
          (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v4,
          (int *)&v24);
      return;
    }
    goto LABEL_36;
  }
  if ( !vostok::core::g_log_filter_tree
    || (v9 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"input", (const char *)2), v4 = v19, v9) )
  {
    boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
      v4,
      &v24);
    v21 = 8;
    vostok::logging::append(
      &v24,
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      ".\\platform_keyboard_win.cpp",
      0x7Bu,
      "void __thiscall vostok::input::platform::keyboard::execute(void)",
      "input",
      error,
      "E_PENDING");
  }
  if ( (v21 & 8) != 0 )
  {
    v21 &= ~8u;
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v4,
      (int *)&v24);
    v3 = v23;
    goto LABEL_25;
  }
}
