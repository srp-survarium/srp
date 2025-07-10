void __thiscall survarium::network_client::on_connected_to_match(
        survarium::network_client *this,
        vostok::connection_error_types_enum connection_error,
        vostok::handshaking_error_types_enum handshaking_error,
        vostok::socket_error_types_enum socket_error,
        vostok::lobby_server_message_types_enum message_type)
{
  __int16 v5; // bx
  void (__cdecl *v7)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  void (__cdecl *v8)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  void (__cdecl *v9)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  void (__cdecl *v10)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v11; // ecx
  void (__cdecl *v12)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v13; // ecx
  void (__cdecl *v14)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  void (__cdecl *v15)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  void (__cdecl *v16)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v17; // ecx
  void (__cdecl *v18)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  void (__cdecl *v19)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  void (__cdecl *v20)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  void (__cdecl *v21)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  survarium::lobby_client *v22; // eax
  survarium::lobby_client *v23; // ecx
  survarium::match_client *p_m_match_client; // esi
  vostok::network_core::udp_match_packet *v25; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+10h] [ebp-60h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v27; // [esp+30h] [ebp-40h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v28; // [esp+50h] [ebp-20h] BYREF

  v5 = 0;
  if ( connection_error )
  {
    if ( connection_error == cannot_connect )
    {
      if ( !vostok::core::g_log_filter_tree
        || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "game:", error) )
      {
        v9 = vostok::core::g_log_callback;
        v27.vtable = 0;
        if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
          `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
            &v27.functor,
            &v27.functor,
            destroy_functor_tag);
        if ( v9 )
        {
          v27.functor.obj_ptr = v9;
          v27.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                              + 1);
        }
        else
        {
          v27.vtable = 0;
        }
        LOBYTE(v5) = 1;
        vostok::logging::append(
          &v27,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\network_client.cpp",
          0x70u,
          "void __thiscall survarium::network_client::on_connected_to_match(const enum vostok::connection_error_types_enu"
          "m,const enum vostok::handshaking_error_types_enum,const enum vostok::socket_error_types_enum,const enum vostok"
          "::lobby_server_message_types_enum)",
          "game:",
          error,
          "game: cannot connect to server");
      }
      if ( (v5 & 1) != 0 )
      {
        if ( v27.vtable )
        {
          if ( ((int)v27.vtable & 1) == 0 )
          {
            v10 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)v27.vtable & 0xFFFFFFFE);
            if ( v10 )
              v10(&v27.functor, &v27.functor, 2);
          }
        }
      }
    }
    else
    {
      if ( !vostok::core::g_log_filter_tree
        || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "game:", error) )
      {
        v7 = vostok::core::g_log_callback;
        log_callback.vtable = 0;
        if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
          `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
            &log_callback.functor,
            &log_callback.functor,
            destroy_functor_tag);
        if ( v7 )
        {
          log_callback.functor.obj_ptr = v7;
          log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                       + 1);
        }
        else
        {
          log_callback.vtable = 0;
        }
        LOBYTE(v5) = 2;
        vostok::logging::append(
          &log_callback,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\network_client.cpp",
          0x76u,
          "void __thiscall survarium::network_client::on_connected_to_match(const enum vostok::connection_error_types_enu"
          "m,const enum vostok::handshaking_error_types_enum,const enum vostok::socket_error_types_enum,const enum vostok"
          "::lobby_server_message_types_enum)",
          "game:",
          error,
          "game: unexpected socket error type");
      }
      if ( (v5 & 2) != 0 && log_callback.vtable && ((int)log_callback.vtable & 1) == 0 )
      {
        v8 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
        if ( v8 )
          v8(&log_callback.functor, &log_callback.functor, 2);
      }
    }
    return;
  }
  switch ( handshaking_error )
  {
    case successfully_handshaked:
      goto LABEL_52;
    case cannot_handshake:
      if ( !vostok::core::g_log_filter_tree
        || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "game:", error) )
      {
        v14 = vostok::core::g_log_callback;
        log_callback.vtable = 0;
        if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
          `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
            &log_callback.functor,
            &log_callback.functor,
            destroy_functor_tag);
        if ( v14 )
        {
          log_callback.functor.obj_ptr = v14;
          log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                       + 1);
        }
        else
        {
          log_callback.vtable = 0;
        }
        LOBYTE(v5) = 4;
        vostok::logging::append(
          &log_callback,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\network_client.cpp",
          0x82u,
          "void __thiscall survarium::network_client::on_connected_to_match(const enum vostok::connection_error_types_enu"
          "m,const enum vostok::handshaking_error_types_enum,const enum vostok::socket_error_types_enum,const enum vostok"
          "::lobby_server_message_types_enum)",
          "game:",
          error,
          "game: SSL certificate verification failed");
      }
      if ( (v5 & 4) == 0 )
        return;
      goto LABEL_117;
    case no_handshake:
LABEL_52:
      if ( socket_error )
      {
        if ( socket_error != unable_to_write_to_socket )
        {
          if ( socket_error != unable_to_read_from_socket )
          {
            if ( !vostok::core::g_log_filter_tree
              || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "game:", error) )
            {
              v15 = vostok::core::g_log_callback;
              v27.vtable = 0;
              if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
                `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
                  &v27.functor,
                  &v27.functor,
                  destroy_functor_tag);
              if ( v15 )
              {
                v27.functor.obj_ptr = v15;
                v27.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                    + 1);
              }
              else
              {
                v27.vtable = 0;
              }
              LOBYTE(v5) = 64;
              vostok::logging::append(
                &v27,
                (void *const)vostok::core::g_log_flags,
                &vostok::core::g_log_format,
                ".\\network_client.cpp",
                0xA3u,
                "void __thiscall survarium::network_client::on_connected_to_match(const enum vostok::connection_error_typ"
                "es_enum,const enum vostok::handshaking_error_types_enum,const enum vostok::socket_error_types_enum,const"
                " enum vostok::lobby_server_message_types_enum)",
                "game:",
                error,
                "game: unexpected socket error type");
            }
            if ( (v5 & 0x40) != 0 )
              goto LABEL_107;
            return;
          }
          if ( !vostok::core::g_log_filter_tree
            || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "game:", error) )
          {
            v16 = vostok::core::g_log_callback;
            log_callback.vtable = 0;
            if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
              `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
                &log_callback.functor,
                &log_callback.functor,
                destroy_functor_tag);
            if ( v16 )
            {
              log_callback.functor.obj_ptr = v16;
              log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                           + 1);
            }
            else
            {
              log_callback.vtable = 0;
            }
            LOBYTE(v5) = 32;
            vostok::logging::append(
              &log_callback,
              (void *const)vostok::core::g_log_flags,
              &vostok::core::g_log_format,
              ".\\network_client.cpp",
              0x9Du,
              "void __thiscall survarium::network_client::on_connected_to_match(const enum vostok::connection_error_types"
              "_enum,const enum vostok::handshaking_error_types_enum,const enum vostok::socket_error_types_enum,const enu"
              "m vostok::lobby_server_message_types_enum)",
              "game:",
              error,
              "game: unable to read from socket");
          }
          if ( (v5 & 0x20) == 0 )
            return;
LABEL_117:
          boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
            v13,
            (int *)&log_callback);
          return;
        }
        if ( !vostok::core::g_log_filter_tree
          || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "game:", error) )
        {
          v18 = vostok::core::g_log_callback;
          v28.vtable = 0;
          if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
            `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
              &v28.functor,
              &v28.functor,
              destroy_functor_tag);
          if ( v18 )
          {
            v28.functor.obj_ptr = v18;
            v28.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                + 1);
          }
          else
          {
            v28.vtable = 0;
          }
          LOBYTE(v5) = 16;
          vostok::logging::append(
            &v28,
            (void *const)vostok::core::g_log_flags,
            &vostok::core::g_log_format,
            ".\\network_client.cpp",
            0x97u,
            "void __thiscall survarium::network_client::on_connected_to_match(const enum vostok::connection_error_types_e"
            "num,const enum vostok::handshaking_error_types_enum,const enum vostok::socket_error_types_enum,const enum vo"
            "stok::lobby_server_message_types_enum)",
            "game:",
            error,
            "game: unable to write to socket");
        }
        if ( (v5 & 0x10) == 0 )
          return;
      }
      else
      {
        switch ( message_type )
        {
          case connection_successful:
            if ( !this->m_is_spectator )
            {
              v22 = this->lobby_client(this);
              survarium::lobby_client::disconnect(v23, (int)v22);
            }
            this->m_player_inputs.m_end = this->m_player_inputs.m_begin;
            p_m_match_client = &this->m_match_client;
            v25 = vostok::network::match_client::new_packet(&p_m_match_client->m_client, 0x41u);
            vostok::network::match_client::enqueue(&p_m_match_client->m_client, v25);
            p_m_match_client->m_are_there_any_packets_to_send = 1;
            return;
          case invalid_session_id:
            if ( !vostok::core::g_log_filter_tree
              || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "game:", error) )
            {
              v21 = vostok::core::g_log_callback;
              log_callback.vtable = 0;
              if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
                `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
                  &log_callback.functor,
                  &log_callback.functor,
                  destroy_functor_tag);
              if ( v21 )
              {
                log_callback.functor.obj_ptr = v21;
                log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                             + 1);
              }
              else
              {
                log_callback.vtable = 0;
              }
              LOBYTE(v5) = 0x80;
              vostok::logging::append(
                &log_callback,
                (void *const)vostok::core::g_log_flags,
                &vostok::core::g_log_format,
                ".\\network_client.cpp",
                0xB5u,
                "void __thiscall survarium::network_client::on_connected_to_match(const enum vostok::connection_error_typ"
                "es_enum,const enum vostok::handshaking_error_types_enum,const enum vostok::socket_error_types_enum,const"
                " enum vostok::lobby_server_message_types_enum)",
                "game:",
                error,
                "game: invalid session id");
            }
            if ( (v5 & 0x80u) == 0 )
              return;
            goto LABEL_117;
          case invalid_password:
            if ( !vostok::core::g_log_filter_tree
              || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "game:", error) )
            {
              v20 = vostok::core::g_log_callback;
              v27.vtable = 0;
              if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
                `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
                  &v27.functor,
                  &v27.functor,
                  destroy_functor_tag);
              if ( v20 )
              {
                v27.functor.obj_ptr = v20;
                v27.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                    + 1);
              }
              else
              {
                v27.vtable = 0;
              }
              v5 = 256;
              vostok::logging::append(
                &v27,
                (void *const)vostok::core::g_log_flags,
                &vostok::core::g_log_format,
                ".\\network_client.cpp",
                0xBCu,
                "void __thiscall survarium::network_client::on_connected_to_match(const enum vostok::connection_error_typ"
                "es_enum,const enum vostok::handshaking_error_types_enum,const enum vostok::socket_error_types_enum,const"
                " enum vostok::lobby_server_message_types_enum)",
                "game:",
                error,
                "game: invalid password");
            }
            if ( (v5 & 0x100) != 0 )
              goto LABEL_107;
            return;
        }
        if ( !vostok::core::g_log_filter_tree
          || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "game:", error) )
        {
          v19 = vostok::core::g_log_callback;
          v28.vtable = 0;
          if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
            `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
              &v28.functor,
              &v28.functor,
              destroy_functor_tag);
          if ( v19 )
          {
            v28.functor.obj_ptr = v19;
            v28.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                + 1);
          }
          else
          {
            v28.vtable = 0;
          }
          v5 = 512;
          vostok::logging::append(
            &v28,
            (void *const)vostok::core::g_log_flags,
            &vostok::core::g_log_format,
            ".\\network_client.cpp",
            0xC3u,
            "void __thiscall survarium::network_client::on_connected_to_match(const enum vostok::connection_error_types_e"
            "num,const enum vostok::handshaking_error_types_enum,const enum vostok::socket_error_types_enum,const enum vo"
            "stok::lobby_server_message_types_enum)",
            "game:",
            error,
            "game: unexpected message type");
        }
        if ( (v5 & 0x200) == 0 )
          return;
      }
      boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
        v17,
        (int *)&v28);
      return;
  }
  if ( !vostok::core::g_log_filter_tree
    || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "game:", error) )
  {
    v12 = vostok::core::g_log_callback;
    v27.vtable = 0;
    if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
      `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
        &v27.functor,
        &v27.functor,
        destroy_functor_tag);
    if ( v12 )
    {
      v27.functor.obj_ptr = v12;
      v27.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                          + 1);
    }
    else
    {
      v27.vtable = 0;
    }
    LOBYTE(v5) = 8;
    vostok::logging::append(
      &v27,
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      ".\\network_client.cpp",
      0x8Bu,
      "void __thiscall survarium::network_client::on_connected_to_match(const enum vostok::connection_error_types_enum,co"
      "nst enum vostok::handshaking_error_types_enum,const enum vostok::socket_error_types_enum,const enum vostok::lobby_"
      "server_message_types_enum)",
      "game:",
      error,
      "game: unexpected SSL error");
  }
  if ( (v5 & 8) != 0 )
LABEL_107:
    boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
      v11,
      (int *)&v27);
}
