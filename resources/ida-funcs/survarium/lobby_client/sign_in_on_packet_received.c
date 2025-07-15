void __thiscall survarium::lobby_client::sign_in_on_packet_received(
        survarium::lobby_client *this,
        vostok::network_core::packet_reader *reader)
{
  const unsigned __int8 *m_pointer; // eax
  char v4; // bl
  void (__cdecl *v5)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  void (__cdecl *v6)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  survarium::lobby_client *v7; // ecx
  void (__cdecl *v8)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // ebx
  void (__cdecl *v9)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  bool v10; // zf
  boost::function<void __cdecl(void)> *p_m_on_connected; // esi
  unsigned __int8 v12; // [esp+13h] [ebp-45h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v13; // [esp+18h] [ebp-40h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+38h] [ebp-20h] BYREF

  m_pointer = reader->m_pointer;
  v4 = 0;
  v12 = *m_pointer;
  reader->m_pointer = m_pointer + 1;
  if ( v12 == 48 )
  {
    this->m_connection_info.connection_error_count = 0;
    vostok::network::tcp_packet_client::set_on_packet_received(&this->m_packet_client, &this->m_on_packet_received);
    if ( !vostok::core::g_log_filter_tree
      || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "game:", info) )
    {
      v8 = vostok::core::g_log_callback;
      v13.vtable = 0;
      if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
        `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
          &v13.functor,
          &v13.functor,
          destroy_functor_tag);
      if ( v8 )
      {
        v13.functor.obj_ptr = v8;
        v13.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                            + 1);
      }
      else
      {
        v13.vtable = 0;
      }
      v4 = 1;
      vostok::logging::append(
        &v13,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\lobby_client.cpp",
        0x8Du,
        "void __thiscall survarium::lobby_client::sign_in_on_packet_received(class vostok::network_core::packet_reader &)",
        "game:",
        info,
        "Lobby client: signed in!");
    }
    if ( (v4 & 1) != 0 && v13.vtable )
    {
      if ( ((int)v13.vtable & 1) == 0 )
      {
        v9 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)v13.vtable & 0xFFFFFFFE);
        if ( v9 )
          v9(&v13.functor, &v13.functor, 2);
      }
      v13.vtable = 0;
    }
    v10 = !this->m_discard_playing_order_on_connected;
    this->m_net_client_connected = 1;
    if ( !v10 )
    {
      survarium::lobby_client::discard_playing_order(v7, (int)this);
      this->m_discard_playing_order_on_connected = 0;
    }
    p_m_on_connected = &this->m_on_connected;
    if ( boost::function0<void>::operator void (__thiscall boost::function0<void>::dummy::*)(void)(p_m_on_connected) )
      boost::function0<void>::operator()(p_m_on_connected);
  }
  else
  {
    if ( !vostok::core::g_log_filter_tree
      || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "game:", error) )
    {
      v5 = vostok::core::g_log_callback;
      log_callback.vtable = 0;
      if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
        `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
          &log_callback.functor,
          &log_callback.functor,
          destroy_functor_tag);
      if ( v5 )
      {
        log_callback.functor.obj_ptr = v5;
        log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                     + 1);
      }
      else
      {
        log_callback.vtable = 0;
      }
      v4 = 2;
      vostok::logging::append(
        &log_callback,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\lobby_client.cpp",
        0x9Au,
        "void __thiscall survarium::lobby_client::sign_in_on_packet_received(class vostok::network_core::packet_reader &)",
        "game:",
        error,
        "Lobby client received unknown SignIn message:%d",
        v12);
    }
    if ( (v4 & 2) != 0 && log_callback.vtable && ((int)log_callback.vtable & 1) == 0 )
    {
      v6 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
      if ( v6 )
        v6(&log_callback.functor, &log_callback.functor, 2);
    }
  }
}
