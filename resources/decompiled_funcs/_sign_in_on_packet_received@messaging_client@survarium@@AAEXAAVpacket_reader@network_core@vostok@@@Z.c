void __thiscall survarium::messaging_client::sign_in_on_packet_received(
        survarium::messaging_client *this,
        vostok::network_core::packet_reader *reader)
{
  const unsigned __int8 *m_pointer; // eax
  unsigned __int8 v3; // bl
  const unsigned __int8 *v4; // eax
  void (__cdecl *v6)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  void (__cdecl *v7)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  unsigned int v8; // ebx
  boost::function1<void,vostok::network_core::packet_reader &> *v9; // ecx
  void (__cdecl *v10)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  void (__cdecl *v11)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  char v12; // bl
  void (__cdecl *v13)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  survarium::messaging_client *v14; // ecx
  survarium::messaging_client *v15; // ecx
  survarium::messaging_client *v16; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::messaging_client,vostok::network_core::packet_reader &>,boost::_bi::list2<boost::_bi::value<survarium::messaging_client *>,boost::arg<1> > > v17; // [esp-8h] [ebp-78h]
  char v18; // [esp+Ch] [ebp-64h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v19; // [esp+10h] [ebp-60h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+30h] [ebp-40h] BYREF
  boost::function<void __cdecl(vostok::network_core::packet_reader &)> on_packet_received; // [esp+50h] [ebp-20h] BYREF

  m_pointer = reader->m_pointer;
  v3 = *m_pointer;
  v4 = m_pointer + 1;
  v18 = 0;
  reader->m_pointer = v4;
  if ( v3 == 0xCB )
  {
    v8 = *v4;
    reader->m_pointer = v4 + 1;
    memcpy((unsigned __int8 *)this->m_local_name, (unsigned __int8 *)v4 + 1, v8);
    reader->m_pointer += v8;
    this->m_local_name[v8] = 0;
    v17.l_.a1_.t_ = this;
    v17.f_.f_ = survarium::messaging_client::on_packet_received;
    this->m_connection_info.connection_error_count = 0;
    this->m_connection_state = client_connected;
    on_packet_received.vtable = 0;
    boost::function1<void,vostok::network_core::packet_reader &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::messaging_client,vostok::network_core::packet_reader &>,boost::_bi::list2<boost::_bi::value<survarium::messaging_client *>,boost::arg<1>>>>(
      v9,
      (boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::messaging_client,vostok::network_core::packet_reader &>,boost::_bi::list2<boost::_bi::value<survarium::messaging_client *>,boost::arg<1> > > *)&on_packet_received,
      v17);
    vostok::network::tcp_packet_client::set_on_packet_received(
      &this->m_network_client,
      (boost::function<void __cdecl(unsigned int,unsigned int)> *)&on_packet_received);
    if ( on_packet_received.vtable )
    {
      if ( ((int)on_packet_received.vtable & 1) == 0 )
      {
        v10 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)on_packet_received.vtable & 0xFFFFFFFE);
        if ( v10 )
          v10(&on_packet_received.functor, &on_packet_received.functor, 2);
      }
      on_packet_received.vtable = 0;
    }
    if ( vostok::core::g_log_filter_tree
      && !vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "game:", info) )
    {
      v12 = 0;
    }
    else
    {
      v11 = vostok::core::g_log_callback;
      v19.vtable = 0;
      if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
        `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
          &v19.functor,
          &v19.functor,
          destroy_functor_tag);
      if ( v11 )
      {
        v19.functor.obj_ptr = v11;
        v19.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                            + 1);
      }
      else
      {
        v19.vtable = 0;
      }
      v12 = 1;
      vostok::logging::append(
        &v19,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\messaging_client_sign_in.cpp",
        0x1Bu,
        "void __thiscall survarium::messaging_client::sign_in_on_packet_received(class vostok::network_core::packet_reader &)",
        "game:",
        info,
        "Messaging client: signed in!");
    }
    if ( (v12 & 1) != 0 && v19.vtable )
    {
      if ( ((int)v19.vtable & 1) == 0 )
      {
        v13 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)v19.vtable & 0xFFFFFFFE);
        if ( v13 )
          v13(&v19.functor, &v19.functor, 2);
      }
      v19.vtable = 0;
    }
    survarium::chat_handler::set_local_player_name(this->m_local_name, this->m_chat_handler);
    survarium::chat_handler::add_message(
      this->m_chat_handler,
      this->m_chat_handler,
      (survarium::flash_value *)2,
      L"Connected to messaging server.",
      L"System");
    survarium::messaging_client::update_channel_subscriptions(v14, (int)this);
    survarium::messaging_client::query_for_friend_list(v15, (int)this);
    survarium::messaging_client::query_for_ignore_list(v16, (int)this);
  }
  else
  {
    if ( !vostok::core::g_log_filter_tree
      || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "game:", error) )
    {
      v6 = vostok::core::g_log_callback;
      log_callback.vtable = 0;
      if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
        `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
          &log_callback.functor,
          &log_callback.functor,
          destroy_functor_tag);
      if ( v6 )
      {
        log_callback.functor.obj_ptr = v6;
        log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                     + 1);
      }
      else
      {
        log_callback.vtable = 0;
      }
      v18 = 2;
      vostok::logging::append(
        &log_callback,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\messaging_client_sign_in.cpp",
        0x28u,
        "void __thiscall survarium::messaging_client::sign_in_on_packet_received(class vostok::network_core::packet_reader &)",
        "game:",
        error,
        "messaging_client received unknown message:%d",
        v3);
    }
    if ( (v18 & 2) != 0 && log_callback.vtable && ((int)log_callback.vtable & 1) == 0 )
    {
      v7 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
      if ( v7 )
        v7(&log_callback.functor, &log_callback.functor, 2);
    }
  }
}
