void __thiscall vostok::render::device::on_device_removed(vostok::render::device *this, int a2)
{
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v2; // ecx
  bool has_passed_filters; // al
  bool v4; // al
  bool v5; // al
  bool v6; // al
  bool v7; // al
  bool v8; // al
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v9; // [esp-4h] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v10; // [esp-4h] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v11; // [esp-4h] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v12; // [esp-4h] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v13; // [esp-4h] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v14; // [esp-4h] [ebp-3Ch]
  const char *v15; // [esp+0h] [ebp-38h]
  char v16; // [esp+10h] [ebp-28h]
  HRESULT v17; // [esp+14h] [ebp-24h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v18; // [esp+18h] [ebp-20h] BYREF

  v16 = 0;
  v17 = vostok::quasi_singleton<vostok::render::device>::pinst->m_device->GetDeviceRemovedReason(vostok::quasi_singleton<vostok::render::device>::pinst->m_device);
  if ( v17 == -2005270522 )
  {
    if ( !vostok::core::g_log_filter_tree
      || (has_passed_filters = vostok::logging::has_passed_filters(
                                 (vostok::logging::filter_tree *)&initiator_raw.initiator_tree,
                                 (const char *)2),
          v2 = v9,
          has_passed_filters) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        v2,
        &v18);
      v16 = 1;
      vostok::logging::append(
        &v18,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\device.cpp",
        0x2Eu,
        "void __thiscall vostok::render::device::on_device_removed(void)",
        (char *)&initiator_raw.initiator_tree,
        error,
        "Device remove reason: %s",
        "DXGI_ERROR_DEVICE_HUNG");
    }
    if ( (v16 & 1) == 0 )
      goto LABEL_37;
    v16 &= ~1u;
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v2,
      (int *)&v18);
  }
  if ( v17 == -2005270523 )
  {
    if ( !vostok::core::g_log_filter_tree
      || (v4 = vostok::logging::has_passed_filters(
                 (vostok::logging::filter_tree *)&initiator_raw.initiator_tree,
                 (const char *)2),
          v2 = v10,
          v4) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        v2,
        &v18);
      v16 |= 2u;
      vostok::logging::append(
        &v18,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\device.cpp",
        0x2Fu,
        "void __thiscall vostok::render::device::on_device_removed(void)",
        (char *)&initiator_raw.initiator_tree,
        error,
        "Device remove reason: %s",
        "DXGI_ERROR_DEVICE_REMOVED");
    }
    if ( (v16 & 2) == 0 )
      goto LABEL_37;
    v16 &= ~2u;
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v2,
      (int *)&v18);
  }
  if ( v17 == -2005270521 )
  {
    if ( !vostok::core::g_log_filter_tree
      || (v5 = vostok::logging::has_passed_filters(
                 (vostok::logging::filter_tree *)&initiator_raw.initiator_tree,
                 (const char *)2),
          v2 = v11,
          v5) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        v2,
        &v18);
      v16 |= 4u;
      vostok::logging::append(
        &v18,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\device.cpp",
        0x30u,
        "void __thiscall vostok::render::device::on_device_removed(void)",
        (char *)&initiator_raw.initiator_tree,
        error,
        "Device remove reason: %s",
        "DXGI_ERROR_DEVICE_RESET");
    }
    if ( (v16 & 4) == 0 )
      goto LABEL_37;
    v16 &= ~4u;
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v2,
      (int *)&v18);
  }
  if ( v17 == -2005270496 )
  {
    if ( !vostok::core::g_log_filter_tree
      || (v6 = vostok::logging::has_passed_filters(
                 (vostok::logging::filter_tree *)&initiator_raw.initiator_tree,
                 (const char *)2),
          v2 = v12,
          v6) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        v2,
        &v18);
      v16 |= 8u;
      vostok::logging::append(
        &v18,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\device.cpp",
        0x31u,
        "void __thiscall vostok::render::device::on_device_removed(void)",
        (char *)&initiator_raw.initiator_tree,
        error,
        "Device remove reason: %s",
        "DXGI_ERROR_DRIVER_INTERNAL_ERROR");
    }
    if ( (v16 & 8) == 0 )
      goto LABEL_37;
    v16 &= ~8u;
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v2,
      (int *)&v18);
  }
  if ( v17 != -2005270527 )
    goto LABEL_31;
  if ( !vostok::core::g_log_filter_tree
    || (v7 = vostok::logging::has_passed_filters(
               (vostok::logging::filter_tree *)&initiator_raw.initiator_tree,
               (const char *)2),
        v2 = v13,
        v7) )
  {
    boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
      v2,
      &v18);
    v16 |= 0x10u;
    vostok::logging::append(
      &v18,
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      ".\\device.cpp",
      0x32u,
      "void __thiscall vostok::render::device::on_device_removed(void)",
      (char *)&initiator_raw.initiator_tree,
      error,
      "Device remove reason: %s",
      "DXGI_ERROR_INVALID_CALL");
  }
  if ( (v16 & 0x10) != 0 )
  {
    v16 &= ~0x10u;
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v2,
      (int *)&v18);
LABEL_31:
    if ( !v17 )
    {
      if ( !vostok::core::g_log_filter_tree
        || (v8 = vostok::logging::has_passed_filters(
                   (vostok::logging::filter_tree *)&initiator_raw.initiator_tree,
                   (const char *)2),
            v2 = v14,
            v8) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v2,
          &v18);
        v16 |= 0x20u;
        vostok::logging::append(
          &v18,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\device.cpp",
          0x33u,
          "void __thiscall vostok::render::device::on_device_removed(void)",
          (char *)&initiator_raw.initiator_tree,
          error,
          "Device remove reason: %s",
          "S_OK");
      }
      if ( (v16 & 0x20) != 0 )
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
          (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v2,
          (int *)&v18);
    }
  }
LABEL_37:
  *(_BYTE *)(a2 + 358) = 1;
  if ( !debug_macro_helper_ignore_always_56 )
  {
    LOBYTE(a2) = 0;
    vostok::debug::on_error(
      (bool *)&a2,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      ".\\device.cpp",
      "vostok::render::device::on_device_removed",
      (const char *)0x37,
      "The Direct3D 11 device that was being used has been removed. Please restart the game.",
      v15);
    if ( vostok::debug::is_debugger_present() || (_BYTE)a2 )
      __debugbreak();
  }
}
