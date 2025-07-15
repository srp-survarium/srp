void __thiscall survarium::network_client::on_connected_to_login(
        survarium::network_client *this,
        vostok::connection_error_types_enum connection_error,
        vostok::handshaking_error_types_enum handshaking_error,
        vostok::socket_error_types_enum socket_error,
        vostok::login_server_message_types_enum message_type)
{
  __int16 v5; // bx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v6; // ecx
  void (__cdecl *v7)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  void (__cdecl *v8)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  void (__cdecl *v9)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  void (__cdecl *v10)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  void (__cdecl *v11)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  int *p_log_callback; // esi
  void (__cdecl *v13)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  void (__cdecl *v14)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  void (__cdecl *v15)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  void (__cdecl *v16)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v17; // ecx
  void (__cdecl *v18)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v19; // ecx
  void (__cdecl *v20)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v21; // ecx
  void (__cdecl *v22)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v23; // ecx
  void (__cdecl *v24)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v25; // ecx
  void (__cdecl *v26)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v27; // ecx
  void (__cdecl *v28)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v29; // ecx
  void (__cdecl *v30)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  void (__cdecl *v31)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+10h] [ebp-108h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v34; // [esp+30h] [ebp-E8h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v35; // [esp+50h] [ebp-C8h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v36; // [esp+70h] [ebp-A8h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v37; // [esp+90h] [ebp-88h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v38; // [esp+B0h] [ebp-68h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v39; // [esp+D0h] [ebp-48h] BYREF
  int v40; // [esp+F4h] [ebp-24h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v41; // [esp+F8h] [ebp-20h] BYREF

  v5 = 0;
  v40 = 0;
  if ( connection_error )
  {
    if ( connection_error == cannot_connect )
    {
      if ( !vostok::core::g_log_filter_tree
        || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "game:", error) )
      {
        v9 = vostok::core::g_log_callback;
        v34.vtable = 0;
        if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
          `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
            &v34.functor,
            &v34.functor,
            destroy_functor_tag);
        if ( v9 )
        {
          v34.functor.obj_ptr = v9;
          v34.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                              + 1);
        }
        else
        {
          v34.vtable = 0;
        }
        LOBYTE(v5) = 1;
        vostok::logging::append(
          &v34,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\network_client.cpp",
          0xD8u,
          "void __thiscall survarium::network_client::on_connected_to_login(const enum vostok::connection_error_types_enu"
          "m,const enum vostok::handshaking_error_types_enum,const enum vostok::socket_error_types_enum,const enum vostok"
          "::login_server_message_types_enum)",
          "game:",
          error,
          "game: cannot connect to login server");
      }
      if ( (v5 & 1) != 0 && v34.vtable )
      {
        if ( ((int)v34.vtable & 1) == 0 )
        {
          v10 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)v34.vtable & 0xFFFFFFFE);
          if ( v10 )
            v10(&v34.functor, &v34.functor, 2);
        }
        v34.vtable = 0;
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
          0xDFu,
          "void __thiscall survarium::network_client::on_connected_to_login(const enum vostok::connection_error_types_enu"
          "m,const enum vostok::handshaking_error_types_enum,const enum vostok::socket_error_types_enum,const enum vostok"
          "::login_server_message_types_enum)",
          "game:",
          error,
          "game: unexpected socket error type");
      }
      if ( (v5 & 2) != 0 && log_callback.vtable )
      {
        if ( ((int)log_callback.vtable & 1) == 0 )
        {
          v8 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
          if ( v8 )
            v8(&log_callback.functor, &log_callback.functor, 2);
        }
        log_callback.vtable = 0;
      }
    }
    goto LABEL_176;
  }
  if ( handshaking_error )
  {
    if ( handshaking_error == cannot_handshake )
    {
      if ( !vostok::core::g_log_filter_tree
        || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "game:", error) )
      {
        v13 = vostok::core::g_log_callback;
        log_callback.vtable = 0;
        if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
          `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
            &log_callback.functor,
            &log_callback.functor,
            destroy_functor_tag);
        if ( v13 )
        {
          log_callback.functor.obj_ptr = v13;
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
          0xECu,
          "void __thiscall survarium::network_client::on_connected_to_login(const enum vostok::connection_error_types_enu"
          "m,const enum vostok::handshaking_error_types_enum,const enum vostok::socket_error_types_enum,const enum vostok"
          "::login_server_message_types_enum)",
          "game:",
          error,
          "game: SSL certificate verification failed");
      }
      if ( (v5 & 4) == 0 )
        goto LABEL_176;
      p_log_callback = (int *)&log_callback;
LABEL_175:
      boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
        v6,
        p_log_callback);
LABEL_176:
      survarium::game::switch_to_login((survarium::game *)v6, (int)this->m_game, login_menu_status_error_connection);
      return;
    }
    if ( handshaking_error != no_handshake )
    {
      if ( !vostok::core::g_log_filter_tree
        || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "game:", error) )
      {
        v11 = vostok::core::g_log_callback;
        v34.vtable = 0;
        if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
          `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
            &v34.functor,
            &v34.functor,
            destroy_functor_tag);
        if ( v11 )
        {
          v34.functor.obj_ptr = v11;
          v34.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                              + 1);
        }
        else
        {
          v34.vtable = 0;
        }
        LOBYTE(v5) = 8;
        vostok::logging::append(
          &v34,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\network_client.cpp",
          0xF6u,
          "void __thiscall survarium::network_client::on_connected_to_login(const enum vostok::connection_error_types_enu"
          "m,const enum vostok::handshaking_error_types_enum,const enum vostok::socket_error_types_enum,const enum vostok"
          "::login_server_message_types_enum)",
          "game:",
          error,
          "game: unexpected SSL error");
      }
      if ( (v5 & 8) == 0 )
        goto LABEL_176;
      p_log_callback = (int *)&v34;
      goto LABEL_175;
    }
  }
  if ( socket_error )
  {
    if ( socket_error == unable_to_write_to_socket )
    {
      if ( !vostok::core::g_log_filter_tree
        || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "game:", error) )
      {
        v16 = vostok::core::g_log_callback;
        v35.vtable = 0;
        if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
          `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
            &v35.functor,
            &v35.functor,
            destroy_functor_tag);
        if ( v16 )
        {
          v35.functor.obj_ptr = v16;
          v35.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                              + 1);
        }
        else
        {
          v35.vtable = 0;
        }
        LOBYTE(v5) = 16;
        vostok::logging::append(
          &v35,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\network_client.cpp",
          0x103u,
          "void __thiscall survarium::network_client::on_connected_to_login(const enum vostok::connection_error_types_enu"
          "m,const enum vostok::handshaking_error_types_enum,const enum vostok::socket_error_types_enum,const enum vostok"
          "::login_server_message_types_enum)",
          "game:",
          error,
          "game: unable to write to socket");
      }
      if ( (v5 & 0x10) == 0 )
        goto LABEL_176;
      p_log_callback = (int *)&v35;
    }
    else if ( socket_error == unable_to_read_from_socket )
    {
      if ( !vostok::core::g_log_filter_tree
        || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "game:", error) )
      {
        v15 = vostok::core::g_log_callback;
        log_callback.vtable = 0;
        if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
          `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
            &log_callback.functor,
            &log_callback.functor,
            destroy_functor_tag);
        if ( v15 )
        {
          log_callback.functor.obj_ptr = v15;
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
          0x10Au,
          "void __thiscall survarium::network_client::on_connected_to_login(const enum vostok::connection_error_types_enu"
          "m,const enum vostok::handshaking_error_types_enum,const enum vostok::socket_error_types_enum,const enum vostok"
          "::login_server_message_types_enum)",
          "game:",
          error,
          "game: unable to read from socket");
      }
      if ( (v5 & 0x20) == 0 )
        goto LABEL_176;
      p_log_callback = (int *)&log_callback;
    }
    else
    {
      if ( !vostok::core::g_log_filter_tree
        || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "game:", error) )
      {
        v14 = vostok::core::g_log_callback;
        v34.vtable = 0;
        if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
          `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
            &v34.functor,
            &v34.functor,
            destroy_functor_tag);
        if ( v14 )
        {
          v34.functor.obj_ptr = v14;
          v34.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                              + 1);
        }
        else
        {
          v34.vtable = 0;
        }
        LOBYTE(v5) = 64;
        vostok::logging::append(
          &v34,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\network_client.cpp",
          0x111u,
          "void __thiscall survarium::network_client::on_connected_to_login(const enum vostok::connection_error_types_enu"
          "m,const enum vostok::handshaking_error_types_enum,const enum vostok::socket_error_types_enum,const enum vostok"
          "::login_server_message_types_enum)",
          "game:",
          error,
          "game: unexpected socket error type");
      }
      if ( (v5 & 0x40) == 0 )
        goto LABEL_176;
      p_log_callback = (int *)&v34;
    }
    goto LABEL_175;
  }
  switch ( message_type )
  {
    case servers_connection_info_message_type:
      if ( !vostok::core::g_log_filter_tree
        || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "game:", info) )
      {
        v18 = vostok::core::g_log_callback;
        v35.vtable = 0;
        if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
          `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
            &v35.functor,
            &v35.functor,
            destroy_functor_tag);
        if ( v18 )
        {
          v35.functor.obj_ptr = v18;
          v35.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                              + 1);
        }
        else
        {
          v35.vtable = 0;
        }
        LOBYTE(v5) = 0x80;
        vostok::logging::append(
          &v35,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\network_client.cpp",
          0x11Bu,
          "void __thiscall survarium::network_client::on_connected_to_login(const enum vostok::connection_error_types_enu"
          "m,const enum vostok::handshaking_error_types_enum,const enum vostok::socket_error_types_enum,const enum vostok"
          "::login_server_message_types_enum)",
          "game:",
          info,
          "on_connected_to_login.");
      }
      if ( (v5 & 0x80u) != 0 )
        boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
          v17,
          (int *)&v35);
      survarium::game::switch_to_lobby((survarium::game *)v17, (int)this->m_game);
      break;
    case invalid_user_name_or_password_message_type:
      if ( !vostok::core::g_log_filter_tree
        || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "game:", error) )
      {
        v24 = vostok::core::g_log_callback;
        v38.vtable = 0;
        if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
          `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
            &v38.functor,
            &v38.functor,
            destroy_functor_tag);
        if ( v24 )
        {
          v38.functor.obj_ptr = v24;
          v38.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                              + 1);
        }
        else
        {
          v38.vtable = 0;
        }
        v5 = 1024;
        vostok::logging::append(
          &v38,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\network_client.cpp",
          0x12Eu,
          "void __thiscall survarium::network_client::on_connected_to_login(const enum vostok::connection_error_types_enu"
          "m,const enum vostok::handshaking_error_types_enum,const enum vostok::socket_error_types_enum,const enum vostok"
          "::login_server_message_types_enum)",
          "game:",
          error,
          "sign in: invalid user name or password");
      }
      if ( (v5 & 0x400) != 0 )
        boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
          v23,
          (int *)&v38);
      survarium::game::switch_to_login(
        (survarium::game *)v23,
        (int)this->m_game,
        login_menu_status_invalid_user_or_password);
      break;
    case sign_in_attempt_interval_violated_message_type:
      if ( !vostok::core::g_log_filter_tree
        || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "game:", error) )
      {
        v30 = vostok::core::g_log_callback;
        v39.vtable = 0;
        if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
          `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
            &v39.functor,
            &v39.functor,
            destroy_functor_tag);
        if ( v30 )
        {
          v39.functor.obj_ptr = v30;
          v39.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                              + 1);
        }
        else
        {
          v39.vtable = 0;
        }
        v5 = 0x2000;
        vostok::logging::append(
          &v39,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\network_client.cpp",
          0x140u,
          "void __thiscall survarium::network_client::on_connected_to_login(const enum vostok::connection_error_types_enu"
          "m,const enum vostok::handshaking_error_types_enum,const enum vostok::socket_error_types_enum,const enum vostok"
          "::login_server_message_types_enum)",
          "game:",
          error,
          "sign in: attempt interval is violated");
      }
      if ( (v5 & 0x2000) != 0 )
        boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
          v29,
          (int *)&v39);
      survarium::game::switch_to_login(
        (survarium::game *)v29,
        (int)this->m_game,
        login_menu_status_sign_in_attempt_interval_violated);
      break;
    case user_banned_message_type:
      if ( !vostok::core::g_log_filter_tree
        || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "game:", error) )
      {
        v26 = vostok::core::g_log_callback;
        v36.vtable = 0;
        if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
          `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
            &v36.functor,
            &v36.functor,
            destroy_functor_tag);
        if ( v26 )
        {
          v36.functor.obj_ptr = v26;
          v36.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                              + 1);
        }
        else
        {
          v36.vtable = 0;
        }
        v5 = 2048;
        vostok::logging::append(
          &v36,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\network_client.cpp",
          0x134u,
          "void __thiscall survarium::network_client::on_connected_to_login(const enum vostok::connection_error_types_enu"
          "m,const enum vostok::handshaking_error_types_enum,const enum vostok::socket_error_types_enum,const enum vostok"
          "::login_server_message_types_enum)",
          "game:",
          error,
          "sign in: user banned");
      }
      if ( (v5 & 0x800) != 0 )
        boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
          v25,
          (int *)&v36);
      survarium::game::switch_to_login((survarium::game *)v25, (int)this->m_game, login_menu_status_user_banned);
      break;
    case user_restricted_by_access_level_message_type:
      if ( !vostok::core::g_log_filter_tree
        || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "game:", error) )
      {
        v28 = vostok::core::g_log_callback;
        v37.vtable = 0;
        if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
          `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
            &v37.functor,
            &v37.functor,
            destroy_functor_tag);
        if ( v28 )
        {
          v37.functor.obj_ptr = v28;
          v37.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                              + 1);
        }
        else
        {
          v37.vtable = 0;
        }
        v5 = 4096;
        vostok::logging::append(
          &v37,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\network_client.cpp",
          0x13Au,
          "void __thiscall survarium::network_client::on_connected_to_login(const enum vostok::connection_error_types_enu"
          "m,const enum vostok::handshaking_error_types_enum,const enum vostok::socket_error_types_enum,const enum vostok"
          "::login_server_message_types_enum)",
          "game:",
          error,
          "sign in: user access level restriction");
      }
      if ( (v5 & 0x1000) != 0 )
        boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
          v27,
          (int *)&v37);
      survarium::game::switch_to_login(
        (survarium::game *)v27,
        (int)this->m_game,
        login_menu_status_access_level_restriction);
      break;
    case sign_in_user_already_signed_in:
      if ( !vostok::core::g_log_filter_tree
        || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "game:", error) )
      {
        v20 = vostok::core::g_log_callback;
        v34.vtable = 0;
        if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
          `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
            &v34.functor,
            &v34.functor,
            destroy_functor_tag);
        if ( v20 )
        {
          v34.functor.obj_ptr = v20;
          v34.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                              + 1);
        }
        else
        {
          v34.vtable = 0;
        }
        v5 = 256;
        vostok::logging::append(
          &v34,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\network_client.cpp",
          0x122u,
          "void __thiscall survarium::network_client::on_connected_to_login(const enum vostok::connection_error_types_enu"
          "m,const enum vostok::handshaking_error_types_enum,const enum vostok::socket_error_types_enum,const enum vostok"
          "::login_server_message_types_enum)",
          "game:",
          error,
          "sign in: user already signed in");
      }
      if ( (v5 & 0x100) != 0 )
        boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
          v19,
          (int *)&v34);
      survarium::game::switch_to_login(
        (survarium::game *)v19,
        (int)this->m_game,
        login_menu_status_sign_in_already_online);
      break;
    case sign_in_invalid_version:
      if ( !vostok::core::g_log_filter_tree
        || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "game:", error) )
      {
        v22 = vostok::core::g_log_callback;
        log_callback.vtable = 0;
        if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
          `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
            &log_callback.functor,
            &log_callback.functor,
            destroy_functor_tag);
        if ( v22 )
        {
          log_callback.functor.obj_ptr = v22;
          log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                       + 1);
        }
        else
        {
          log_callback.vtable = 0;
        }
        v5 = 512;
        vostok::logging::append(
          &log_callback,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\network_client.cpp",
          0x128u,
          "void __thiscall survarium::network_client::on_connected_to_login(const enum vostok::connection_error_types_enu"
          "m,const enum vostok::handshaking_error_types_enum,const enum vostok::socket_error_types_enum,const enum vostok"
          "::login_server_message_types_enum)",
          "game:",
          error,
          "sign in: invalid version");
      }
      if ( (v5 & 0x200) != 0 )
        boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
          v21,
          (int *)&log_callback);
      survarium::game::switch_to_login((survarium::game *)v21, (int)this->m_game, login_menu_status_invalid_version);
      break;
    default:
      if ( !vostok::core::g_log_filter_tree
        || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "game:", error) )
      {
        v31 = vostok::core::g_log_callback;
        v41.vtable = 0;
        if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
          `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
            &v41.functor,
            &v41.functor,
            destroy_functor_tag);
        if ( v31 )
        {
          v41.functor.obj_ptr = v31;
          v41.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                              + 1);
        }
        else
        {
          v41.vtable = 0;
        }
        v5 = 0x4000;
        vostok::logging::append(
          &v41,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\network_client.cpp",
          0x147u,
          "void __thiscall survarium::network_client::on_connected_to_login(const enum vostok::connection_error_types_enu"
          "m,const enum vostok::handshaking_error_types_enum,const enum vostok::socket_error_types_enum,const enum vostok"
          "::login_server_message_types_enum)",
          "game:",
          error,
          "sign in: unexpected message type");
      }
      if ( (v5 & 0x4000) == 0 )
        goto LABEL_176;
      p_log_callback = (int *)&v41;
      goto LABEL_175;
  }
}
