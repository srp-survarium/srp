char __thiscall vostok::sound::sound_world::initialize_xaudio(vostok::sound::sound_world *this)
{
  int v3; // [esp+A4h] [ebp-D68h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+ACh] [ebp-D60h] BYREF
  boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> v5; // [esp+CCh] [ebp-D40h] BYREF
  boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> v6; // [esp+ECh] [ebp-D20h] BYREF
  boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> v7; // [esp+10Ch] [ebp-D00h] BYREF
  boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> v8; // [esp+12Ch] [ebp-CE0h] BYREF
  char v9; // [esp+153h] [ebp-CB9h]
  boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> v10; // [esp+154h] [ebp-CB8h] BYREF
  boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> v11; // [esp+174h] [ebp-C98h] BYREF
  unsigned int i; // [esp+194h] [ebp-C78h]
  XAUDIO2_DEBUG_CONFIGURATION dc; // [esp+198h] [ebp-C74h] BYREF
  int preferred_device_id; // [esp+1B0h] [ebp-C5Ch]
  unsigned int channelMask; // [esp+1B4h] [ebp-C58h]
  unsigned int device_count; // [esp+1B8h] [ebp-C54h] BYREF
  vostok::fixed_string<2048> device_role; // [esp+1BCh] [ebp-C50h] BYREF
  unsigned int creation_flags; // [esp+9D0h] [ebp-43Ch]
  XAUDIO2_DEVICE_DETAILS deviceDetails; // [esp+9D4h] [ebp-438h] BYREF
  HRESULT res; // [esp+E08h] [ebp-4h]

  v3 = 0;
  if ( !vostok::core::g_log_filter_tree
    || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "sound:", info) )
  {
    v11.vtable = 0;
    boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
      &v11,
      vostok::core::g_log_callback);
    v3 = 1;
    vostok::logging::append(
      (const boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)&v11,
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      ".\\sound_world.cpp",
      0xD2u,
      "bool __thiscall vostok::sound::sound_world::initialize_xaudio(void)",
      "sound:",
      info,
      "Sound initialization...");
  }
  if ( (v3 & 1) != 0 )
  {
    v3 &= ~1u;
    boost::function<void __cdecl (void)>::~function<void __cdecl (void)>(&v11);
  }
  creation_flags = 0;
  if ( vostok::command_line::key::is_set(&s_debug_audio) )
    creation_flags |= 1u;
  res = XAudio2Create(&this->m_xaudio, creation_flags, XAUDIO2_ANY_PROCESSOR);
  if ( res < 0 && vostok::command_line::key::is_set(&s_debug_audio) )
  {
    creation_flags = 0;
    res = XAudio2Create(&this->m_xaudio, 0, XAUDIO2_ANY_PROCESSOR);
  }
  if ( res < 0 )
  {
    if ( !vostok::core::g_log_filter_tree
      || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "sound:", error) )
    {
      v10.vtable = 0;
      boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        &v10,
        vostok::core::g_log_callback);
      v3 |= 2u;
      vostok::logging::append(
        (const boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)&v10,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\sound_world.cpp",
        0xE2u,
        "bool __thiscall vostok::sound::sound_world::initialize_xaudio(void)",
        "sound:",
        error,
        "Sound initialization FAILED. Can not create XAudio2 interface. %d",
        res);
    }
    if ( (v3 & 2) != 0 )
    {
      v3 &= ~2u;
      boost::function<void __cdecl (void)>::~function<void __cdecl (void)>(&v10);
    }
    v9 = 0;
  }
  device_count = 0;
  this->m_xaudio->GetDeviceCount(this->m_xaudio, &device_count);
  if ( !vostok::core::g_log_filter_tree
    || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "sound:", info) )
  {
    v8.vtable = 0;
    boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
      &v8,
      vostok::core::g_log_callback);
    v3 |= 4u;
    vostok::logging::append(
      (const boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)&v8,
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      ".\\sound_world.cpp",
      0xE8u,
      "bool __thiscall vostok::sound::sound_world::initialize_xaudio(void)",
      "sound:",
      info,
      "devices count: %d",
      device_count);
  }
  if ( (v3 & 4) != 0 )
  {
    v3 &= ~4u;
    if ( v8.vtable )
    {
      if ( ((int)v8.vtable & 1) == 0 )
        boost::detail::function::basic_vtable9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::clear(
          (boost::detail::function::basic_vtable9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)((int)v8.vtable & 0xFFFFFFFE),
          &v8.functor);
      v8.vtable = 0;
    }
  }
  if ( device_count )
  {
    if ( vostok::command_line::key::is_set(&s_debug_audio) )
    {
      dc.TraceMask = 2;
      dc.BreakMask = 0;
      dc.LogThreadID = 1;
      memset(&dc.LogFileline, 0, 12);
      this->m_xaudio->SetDebugConfiguration(this->m_xaudio, &dc, 0);
    }
    preferred_device_id = -1;
    vostok::fixed_string<2048>::fixed_string<2048>(&device_role);
    for ( i = 0; i < device_count; ++i )
    {
      this->m_xaudio->GetDeviceDetails(this->m_xaudio, i, &deviceDetails);
      vostok::fixed_string<2048>::operator=(&device_role, (char *)&buf);
      if ( !vostok::core::g_log_filter_tree
        || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "sound:", info) )
      {
        v6.vtable = 0;
        boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          &v6,
          vostok::core::g_log_callback);
        v3 |= 0x10u;
        vostok::logging::append(
          (const boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)&v6,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\sound_world.cpp",
          0x106u,
          "bool __thiscall vostok::sound::sound_world::initialize_xaudio(void)",
          "sound:",
          info,
          "%d: %S",
          i,
          deviceDetails.DisplayName);
      }
      if ( (v3 & 0x10) != 0 )
      {
        v3 &= ~0x10u;
        if ( v6.vtable )
        {
          if ( ((int)v6.vtable & 1) == 0 )
            boost::detail::function::basic_vtable9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::clear(
              (boost::detail::function::basic_vtable9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)((int)v6.vtable & 0xFFFFFFFE),
              &v6.functor);
          v6.vtable = 0;
        }
      }
      vostok::sound::role_to_string((const XAUDIO2_DEVICE_ROLE)deviceDetails.Role, &device_role);
      if ( !vostok::core::g_log_filter_tree
        || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "sound:", info) )
      {
        v5.vtable = 0;
        boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          &v5,
          vostok::core::g_log_callback);
        v3 |= 0x20u;
        vostok::logging::append(
          (const boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)&v5,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\sound_world.cpp",
          0x108u,
          "bool __thiscall vostok::sound::sound_world::initialize_xaudio(void)",
          "sound:",
          info,
          "role: %s",
          device_role.m_begin);
      }
      if ( (v3 & 0x20) != 0 )
      {
        v3 &= ~0x20u;
        boost::function<void __cdecl (void)>::~function<void __cdecl (void)>(&v5);
      }
      if ( (deviceDetails.Role & 2) != 0 )
        preferred_device_id = i;
    }
    if ( preferred_device_id == -1 )
    {
      if ( !vostok::core::g_log_filter_tree
        || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "sound:", error) )
      {
        log_callback.vtable = 0;
        if ( boost::detail::function::basic_vtable9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
               &`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable,
               vostok::core::g_log_callback,
               &log_callback.functor) )
        {
          log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                       + 1);
        }
        else
        {
          log_callback.vtable = 0;
        }
        LOBYTE(v3) = v3 | 0x40;
        vostok::logging::append(
          &log_callback,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\sound_world.cpp",
          0x10Fu,
          "bool __thiscall vostok::sound::sound_world::initialize_xaudio(void)",
          "sound:",
          error,
          "There is no Default Multimedia Device in system");
      }
      if ( (v3 & 0x40) != 0 )
        boost::function<void __cdecl (void)>::~function<void __cdecl (void)>(&log_callback);
      return 0;
    }
    else
    {
      res = this->m_xaudio->CreateMasteringVoice(
              this->m_xaudio,
              &this->m_master_voice,
              0,
              44100u,
              0,
              preferred_device_id,
              0);
      this->m_xaudio->GetDeviceDetails(this->m_xaudio, preferred_device_id, &deviceDetails);
      channelMask = deviceDetails.OutputFormat.dwChannelMask;
      _X3DAudioInitialize(deviceDetails.OutputFormat.dwChannelMask, 343.5, this->m_x3d_instance);
      return 1;
    }
  }
  else
  {
    if ( !vostok::core::g_log_filter_tree
      || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "sound:", error) )
    {
      v7.vtable = 0;
      boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        &v7,
        vostok::core::g_log_callback);
      LOBYTE(v3) = v3 | 8;
      vostok::logging::append(
        (const boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)&v7,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\sound_world.cpp",
        0xEDu,
        "bool __thiscall vostok::sound::sound_world::initialize_xaudio(void)",
        "sound:",
        error,
        "No audio device avalible");
    }
    if ( (v3 & 8) != 0 && v7.vtable )
    {
      if ( ((int)v7.vtable & 1) == 0 )
        boost::detail::function::basic_vtable9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::clear(
          (boost::detail::function::basic_vtable9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)((int)v7.vtable & 0xFFFFFFFE),
          &v7.functor);
      v7.vtable = 0;
    }
    return 0;
  }
}
