void __thiscall survarium::network_client::on_connected_to_login(
        survarium::network_client *this,
        const vostok::connection_error_types_enum connection_error,
        const vostok::handshaking_error_types_enum handshaking_error,
        const vostok::socket_error_types_enum socket_error,
        unsigned int message_type)
{
  bool has_passed_filters; // al
  bool v6; // zf
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v7; // esi
  char v8; // bl
  bool v9; // al
  bool v10; // al
  char v11; // bl
  bool v12; // al
  bool v13; // al
  bool v14; // al
  bool v15; // al
  bool v16; // al
  bool v17; // al
  bool v18; // al
  bool v19; // al
  bool v20; // al
  bool v21; // al
  bool v22; // al
  unsigned int v23; // [esp-14h] [ebp-10Ch]
  unsigned int v24; // [esp-14h] [ebp-10Ch]
  survarium::network_client *v25; // [esp-4h] [ebp-FCh]
  survarium::login_menu_status_enum v26; // [esp-4h] [ebp-FCh]
  survarium::network_client *v27; // [esp-4h] [ebp-FCh]
  char *v28; // [esp-4h] [ebp-FCh]
  survarium::network_client *v29; // [esp-4h] [ebp-FCh]
  survarium::network_client *v30; // [esp-4h] [ebp-FCh]
  char *v31; // [esp-4h] [ebp-FCh]
  survarium::network_client *v32; // [esp-4h] [ebp-FCh]
  survarium::network_client *v33; // [esp-4h] [ebp-FCh]
  survarium::network_client *v34; // [esp-4h] [ebp-FCh]
  survarium::network_client *v35; // [esp-4h] [ebp-FCh]
  survarium::network_client *v36; // [esp-4h] [ebp-FCh]
  survarium::network_client *v37; // [esp-4h] [ebp-FCh]
  survarium::network_client *v38; // [esp-4h] [ebp-FCh]
  survarium::network_client *v39; // [esp-4h] [ebp-FCh]
  survarium::network_client *v40; // [esp-4h] [ebp-FCh]
  survarium::network_client *v41; // [esp-4h] [ebp-FCh]
  __int16 v42; // [esp+10h] [ebp-E8h]
  survarium::network_client *v43; // [esp+14h] [ebp-E4h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v44; // [esp+18h] [ebp-E0h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v45; // [esp+38h] [ebp-C0h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v46; // [esp+58h] [ebp-A0h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v47; // [esp+78h] [ebp-80h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v48; // [esp+98h] [ebp-60h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v49; // [esp+B8h] [ebp-40h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v50; // [esp+D8h] [ebp-20h] BYREF

  v43 = this;
  v42 = 0;
  if ( connection_error )
  {
    if ( connection_error != cannot_connect )
    {
      if ( !vostok::core::g_log_filter_tree
        || (has_passed_filters = vostok::logging::has_passed_filters(
                                   (vostok::logging::filter_tree *)"game",
                                   (const char *)2),
            this = v25,
            has_passed_filters) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)this,
          &v44);
        LOBYTE(v42) = 2;
        vostok::logging::append(
          &v44,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\network_client.cpp",
          0xD4u,
          "void __thiscall survarium::network_client::on_connected_to_login(const enum vostok::connection_error_types_enu"
          "m,const enum vostok::handshaking_error_types_enum,const enum vostok::socket_error_types_enum,const unsigned int)",
          "game",
          error,
          "game: unexpected socket error type");
      }
      v6 = (v42 & 2) == 0;
LABEL_7:
      if ( !v6 )
      {
        v7 = &v44;
LABEL_9:
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
          (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)this,
          (int *)v7);
        goto LABEL_10;
      }
      goto LABEL_10;
    }
    v8 = 1;
    if ( vostok::core::g_log_filter_tree )
    {
      v9 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"game", (const char *)2);
      this = v27;
      if ( !v9 )
      {
LABEL_15:
        if ( ((unsigned __int8)v8 & (unsigned __int8)v42) == 0 )
          goto LABEL_10;
        v7 = &v45;
        goto LABEL_9;
      }
    }
    boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
      (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)this,
      &v45);
    v28 = "game: cannot connect to login server";
    v23 = 205;
LABEL_14:
    LOBYTE(v42) = v8;
    vostok::logging::append(
      &v45,
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      ".\\network_client.cpp",
      v23,
      "void __thiscall survarium::network_client::on_connected_to_login(const enum vostok::connection_error_types_enum,co"
      "nst enum vostok::handshaking_error_types_enum,const enum vostok::socket_error_types_enum,const unsigned int)",
      "game",
      error,
      v28);
    goto LABEL_15;
  }
  if ( handshaking_error )
  {
    if ( handshaking_error == cannot_handshake )
    {
      v11 = 4;
      if ( vostok::core::g_log_filter_tree )
      {
        v12 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"game", (const char *)2);
        this = v30;
        if ( !v12 )
          goto LABEL_27;
      }
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)this,
        &v44);
      v31 = "game: SSL certificate verification failed";
      v24 = 225;
      goto LABEL_26;
    }
    if ( handshaking_error != no_handshake )
    {
      v8 = 8;
      if ( vostok::core::g_log_filter_tree )
      {
        v10 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"game", (const char *)2);
        this = v29;
        if ( !v10 )
          goto LABEL_15;
      }
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)this,
        &v45);
      v28 = "game: unexpected SSL error";
      v23 = 235;
      goto LABEL_14;
    }
  }
  if ( socket_error )
  {
    if ( socket_error == unable_to_write_to_socket )
    {
      if ( !vostok::core::g_log_filter_tree
        || (v15 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"game", (const char *)2),
            this = v34,
            v15) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)this,
          &v46);
        LOBYTE(v42) = 16;
        vostok::logging::append(
          &v46,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\network_client.cpp",
          0xF8u,
          "void __thiscall survarium::network_client::on_connected_to_login(const enum vostok::connection_error_types_enu"
          "m,const enum vostok::handshaking_error_types_enum,const enum vostok::socket_error_types_enum,const unsigned int)",
          "game",
          error,
          "game: unable to write to socket");
      }
      if ( (v42 & 0x10) == 0 )
        goto LABEL_10;
      v7 = &v46;
      goto LABEL_9;
    }
    if ( socket_error != unable_to_read_from_socket )
    {
      v8 = 64;
      if ( vostok::core::g_log_filter_tree )
      {
        v13 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"game", (const char *)2);
        this = v32;
        if ( !v13 )
          goto LABEL_15;
      }
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)this,
        &v45);
      v28 = "game: unexpected socket error type";
      v23 = 262;
      goto LABEL_14;
    }
    v11 = 32;
    if ( vostok::core::g_log_filter_tree )
    {
      v14 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"game", (const char *)2);
      this = v33;
      if ( !v14 )
      {
LABEL_27:
        v6 = ((unsigned __int8)v11 & (unsigned __int8)v42) == 0;
        goto LABEL_7;
      }
    }
    boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
      (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)this,
      &v44);
    v31 = "game: unable to read from socket";
    v24 = 255;
LABEL_26:
    LOBYTE(v42) = v11;
    vostok::logging::append(
      &v44,
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      ".\\network_client.cpp",
      v24,
      "void __thiscall survarium::network_client::on_connected_to_login(const enum vostok::connection_error_types_enum,co"
      "nst enum vostok::handshaking_error_types_enum,const enum vostok::socket_error_types_enum,const unsigned int)",
      "game",
      error,
      v31);
    goto LABEL_27;
  }
  if ( message_type > 0x12 )
  {
    switch ( message_type )
    {
      case 0x13u:
        if ( !vostok::core::g_log_filter_tree
          || (v22 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"game", (const char *)2),
              this = v41,
              v22) )
        {
          boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
            (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)this,
            &v50);
          LOBYTE(v42) = 0x80;
          vostok::logging::append(
            &v50,
            (void *const)vostok::core::g_log_flags,
            &vostok::core::g_log_format,
            ".\\network_client.cpp",
            0x11Eu,
            "void __thiscall survarium::network_client::on_connected_to_login(const enum vostok::connection_error_types_e"
            "num,const enum vostok::handshaking_error_types_enum,const enum vostok::socket_error_types_enum,const unsigned int)",
            "game",
            error,
            "sign in: user already signed in");
        }
        if ( (v42 & 0x80u) != 0 )
          boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
            (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)this,
            (int *)&v50);
        v26 = login_menu_status_sign_in_already_online;
        goto LABEL_94;
      case 0x14u:
        if ( !vostok::core::g_log_filter_tree
          || (v21 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"game", (const char *)2),
              this = v40,
              v21) )
        {
          boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
            (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)this,
            &v48);
          v42 = 256;
          vostok::logging::append(
            &v48,
            (void *const)vostok::core::g_log_flags,
            &vostok::core::g_log_format,
            ".\\network_client.cpp",
            0x124u,
            "void __thiscall survarium::network_client::on_connected_to_login(const enum vostok::connection_error_types_e"
            "num,const enum vostok::handshaking_error_types_enum,const enum vostok::socket_error_types_enum,const unsigned int)",
            "game",
            error,
            "sign in: invalid version");
        }
        if ( (v42 & 0x100) != 0 )
          boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
            (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)this,
            (int *)&v48);
        v26 = login_menu_status_invalid_version;
        goto LABEL_94;
      case 0x15u:
        survarium::game::switch_to_login(
          (survarium::game *)this,
          this->m_game,
          login_menu_status_sign_in_eula_check_failed);
        return;
    }
  }
  else
  {
    switch ( message_type )
    {
      case 0x12u:
        if ( !vostok::core::g_log_filter_tree
          || (v19 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"game", (const char *)2),
              this = v38,
              v19) )
        {
          boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
            (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)this,
            &v49);
          v42 = 2048;
          vostok::logging::append(
            &v49,
            (void *const)vostok::core::g_log_flags,
            &vostok::core::g_log_format,
            ".\\network_client.cpp",
            0x136u,
            "void __thiscall survarium::network_client::on_connected_to_login(const enum vostok::connection_error_types_e"
            "num,const enum vostok::handshaking_error_types_enum,const enum vostok::socket_error_types_enum,const unsigned int)",
            "game",
            error,
            "sign in: user access level restriction");
        }
        if ( (v42 & 0x800) != 0 )
          boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
            (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)this,
            (int *)&v49);
        v26 = login_menu_status_access_level_restriction;
        goto LABEL_94;
      case 8u:
        survarium::game::switch_to_lobby((survarium::game *)this, this->m_game);
        return;
      case 0xAu:
        if ( !vostok::core::g_log_filter_tree
          || (v18 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"game", (const char *)2),
              this = v37,
              v18) )
        {
          boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
            (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)this,
            &v44);
          v42 = 512;
          vostok::logging::append(
            &v44,
            (void *const)vostok::core::g_log_flags,
            &vostok::core::g_log_format,
            ".\\network_client.cpp",
            0x12Au,
            "void __thiscall survarium::network_client::on_connected_to_login(const enum vostok::connection_error_types_e"
            "num,const enum vostok::handshaking_error_types_enum,const enum vostok::socket_error_types_enum,const unsigned int)",
            "game",
            error,
            "sign in: invalid user name or password");
        }
        if ( (v42 & 0x200) != 0 )
          boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
            (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)this,
            (int *)&v44);
        v26 = login_menu_status_invalid_user_or_password;
        goto LABEL_94;
      case 0xCu:
        if ( !vostok::core::g_log_filter_tree
          || (v17 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"game", (const char *)2),
              this = v36,
              v17) )
        {
          boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
            (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)this,
            &v45);
          v42 = 4096;
          vostok::logging::append(
            &v45,
            (void *const)vostok::core::g_log_flags,
            &vostok::core::g_log_format,
            ".\\network_client.cpp",
            0x13Cu,
            "void __thiscall survarium::network_client::on_connected_to_login(const enum vostok::connection_error_types_e"
            "num,const enum vostok::handshaking_error_types_enum,const enum vostok::socket_error_types_enum,const unsigned int)",
            "game",
            error,
            "sign in: attempt interval is violated");
        }
        if ( (v42 & 0x1000) != 0 )
          boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
            (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)this,
            (int *)&v45);
        v26 = login_menu_status_sign_in_attempt_interval_violated;
        goto LABEL_94;
      case 0x11u:
        if ( !vostok::core::g_log_filter_tree
          || (v16 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"game", (const char *)2),
              this = v35,
              v16) )
        {
          boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
            (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)this,
            &v46);
          v42 = 1024;
          vostok::logging::append(
            &v46,
            (void *const)vostok::core::g_log_flags,
            &vostok::core::g_log_format,
            ".\\network_client.cpp",
            0x130u,
            "void __thiscall survarium::network_client::on_connected_to_login(const enum vostok::connection_error_types_e"
            "num,const enum vostok::handshaking_error_types_enum,const enum vostok::socket_error_types_enum,const unsigned int)",
            "game",
            error,
            "sign in: user banned");
        }
        if ( (v42 & 0x400) != 0 )
          boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
            (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)this,
            (int *)&v46);
        v26 = login_menu_status_user_banned;
        goto LABEL_94;
    }
  }
  if ( !vostok::core::g_log_filter_tree
    || (v20 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"game", (const char *)2),
        this = v39,
        v20) )
  {
    boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
      (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)this,
      &v47);
    v42 = 0x2000;
    vostok::logging::append(
      &v47,
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      ".\\network_client.cpp",
      0x143u,
      "void __thiscall survarium::network_client::on_connected_to_login(const enum vostok::connection_error_types_enum,co"
      "nst enum vostok::handshaking_error_types_enum,const enum vostok::socket_error_types_enum,const unsigned int)",
      "game",
      error,
      "sign in: unexpected message type");
  }
  if ( (v42 & 0x2000) != 0 )
  {
    v7 = &v47;
    goto LABEL_9;
  }
LABEL_10:
  v26 = login_menu_status_error_connection;
LABEL_94:
  survarium::game::switch_to_login((survarium::game *)this, v43->m_game, v26);
}
