void __cdecl _LN157_0(D3D_FEATURE_LEVEL level)
{
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v1; // ecx
  bool v3; // al
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v4; // esi
  bool v5; // al
  bool v6; // al
  bool v7; // al
  bool v8; // al
  bool v9; // al
  bool has_passed_filters; // al
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v11; // [esp-4h] [ebp-F8h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v12; // [esp-4h] [ebp-F8h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v13; // [esp-4h] [ebp-F8h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v14; // [esp-4h] [ebp-F8h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v15; // [esp-4h] [ebp-F8h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v16; // [esp-4h] [ebp-F8h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v17; // [esp-4h] [ebp-F8h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v18; // [esp+10h] [ebp-E4h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v19; // [esp+30h] [ebp-C4h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v20; // [esp+50h] [ebp-A4h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v21; // [esp+70h] [ebp-84h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v22; // [esp+90h] [ebp-64h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v23; // [esp+B0h] [ebp-44h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v24; // [esp+D0h] [ebp-24h] BYREF
  char v25; // [esp+FCh] [ebp+8h]

  v25 = 0;
  switch ( level )
  {
    case D3D_FEATURE_LEVEL_9_1:
      if ( !vostok::core::g_log_filter_tree
        || (has_passed_filters = vostok::logging::has_passed_filters(
                                   (vostok::logging::filter_tree *)&initiator_raw.initiator_tree,
                                   (const char *)4),
            v1 = v17,
            has_passed_filters) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v1,
          &v18);
        v25 = 32;
        vostok::logging::append(
          &v18,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\device.cpp",
          0xEDu,
          "void __cdecl vostok::render::print_feature_level_str(enum D3D_FEATURE_LEVEL)",
          (char *)&initiator_raw.initiator_tree,
          info,
          "Feature level is %s",
          "D3D_FEATURE_LEVEL_9_1");
      }
      if ( (v25 & 0x20) != 0 )
      {
        v4 = &v18;
        goto LABEL_42;
      }
      break;
    case D3D_FEATURE_LEVEL_9_2:
      if ( !vostok::core::g_log_filter_tree
        || (v9 = vostok::logging::has_passed_filters(
                   (vostok::logging::filter_tree *)&initiator_raw.initiator_tree,
                   (const char *)4),
            v1 = v16,
            v9) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v1,
          &v20);
        v25 = 16;
        vostok::logging::append(
          &v20,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\device.cpp",
          0xECu,
          "void __cdecl vostok::render::print_feature_level_str(enum D3D_FEATURE_LEVEL)",
          (char *)&initiator_raw.initiator_tree,
          info,
          "Feature level is %s",
          "D3D_FEATURE_LEVEL_9_2");
      }
      if ( (v25 & 0x10) != 0 )
      {
        v4 = &v20;
        goto LABEL_42;
      }
      break;
    case D3D_FEATURE_LEVEL_9_3:
      if ( !vostok::core::g_log_filter_tree
        || (v8 = vostok::logging::has_passed_filters(
                   (vostok::logging::filter_tree *)&initiator_raw.initiator_tree,
                   (const char *)4),
            v1 = v15,
            v8) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v1,
          &v22);
        v25 = 8;
        vostok::logging::append(
          &v22,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\device.cpp",
          0xEBu,
          "void __cdecl vostok::render::print_feature_level_str(enum D3D_FEATURE_LEVEL)",
          (char *)&initiator_raw.initiator_tree,
          info,
          "Feature level is %s",
          "D3D_FEATURE_LEVEL_9_3");
      }
      if ( (v25 & 8) != 0 )
      {
        v4 = &v22;
        goto LABEL_42;
      }
      break;
    case D3D_FEATURE_LEVEL_10_0:
      if ( !vostok::core::g_log_filter_tree
        || (v7 = vostok::logging::has_passed_filters(
                   (vostok::logging::filter_tree *)&initiator_raw.initiator_tree,
                   (const char *)4),
            v1 = v14,
            v7) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v1,
          &v24);
        v25 = 4;
        vostok::logging::append(
          &v24,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\device.cpp",
          0xEAu,
          "void __cdecl vostok::render::print_feature_level_str(enum D3D_FEATURE_LEVEL)",
          (char *)&initiator_raw.initiator_tree,
          info,
          "Feature level is %s",
          "D3D_FEATURE_LEVEL_10_0");
      }
      if ( (v25 & 4) != 0 )
      {
        v4 = &v24;
        goto LABEL_42;
      }
      break;
    case D3D_FEATURE_LEVEL_10_1:
      if ( !vostok::core::g_log_filter_tree
        || (v6 = vostok::logging::has_passed_filters(
                   (vostok::logging::filter_tree *)&initiator_raw.initiator_tree,
                   (const char *)4),
            v1 = v13,
            v6) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v1,
          &v21);
        v25 = 2;
        vostok::logging::append(
          &v21,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\device.cpp",
          0xE9u,
          "void __cdecl vostok::render::print_feature_level_str(enum D3D_FEATURE_LEVEL)",
          (char *)&initiator_raw.initiator_tree,
          info,
          "Feature level is %s",
          "D3D_FEATURE_LEVEL_10_1");
      }
      if ( (v25 & 2) != 0 )
      {
        v4 = &v21;
        goto LABEL_42;
      }
      break;
    case D3D_FEATURE_LEVEL_11_0:
      if ( !vostok::core::g_log_filter_tree
        || (v5 = vostok::logging::has_passed_filters(
                   (vostok::logging::filter_tree *)&initiator_raw.initiator_tree,
                   (const char *)4),
            v1 = v12,
            v5) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v1,
          &v19);
        v25 = 1;
        vostok::logging::append(
          &v19,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\device.cpp",
          0xE8u,
          "void __cdecl vostok::render::print_feature_level_str(enum D3D_FEATURE_LEVEL)",
          (char *)&initiator_raw.initiator_tree,
          info,
          "Feature level is %s",
          "D3D_FEATURE_LEVEL_11_0");
      }
      if ( (v25 & 1) != 0 )
      {
        v4 = &v19;
        goto LABEL_42;
      }
      break;
    default:
      if ( !vostok::core::g_log_filter_tree
        || (v3 = vostok::logging::has_passed_filters(
                   (vostok::logging::filter_tree *)&initiator_raw.initiator_tree,
                   (const char *)2),
            v1 = v11,
            v3) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v1,
          &v23);
        v25 = 64;
        vostok::logging::append(
          &v23,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\device.cpp",
          0xEEu,
          "void __cdecl vostok::render::print_feature_level_str(enum D3D_FEATURE_LEVEL)",
          (char *)&initiator_raw.initiator_tree,
          error,
          "Using unknown feature level is %d",
          level);
      }
      if ( (v25 & 0x40) != 0 )
      {
        v4 = &v23;
LABEL_42:
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
          (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v1,
          (int *)v4);
      }
      break;
  }
}
