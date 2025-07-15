void __thiscall survarium::lobby_client::sign_in_on_packet_received(
        survarium::lobby_client *this,
        boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *reader)
{
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v3; // ecx
  bool v4; // al
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v5; // ecx
  bool has_passed_filters; // al
  bool v7; // zf
  int v8; // ecx
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v9; // [esp-4h] [ebp-5Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v10; // [esp-4h] [ebp-5Ch]
  unsigned __int8 manager; // [esp+13h] [ebp-45h]
  char v12; // [esp+14h] [ebp-44h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v13; // [esp+18h] [ebp-40h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v14; // [esp+38h] [ebp-20h] BYREF

  v3 = reader;
  manager = (unsigned __int8)(&reader->vtable)[1]->manager;
  v12 = 0;
  ++(&reader->vtable)[1];
  if ( manager == 48 )
  {
    this->m_connection_info.connection_error_count = 0;
    boost::function<void __cdecl (boost::system::error_code)>::operator=(
      &this->m_on_packet_received,
      (boost::function1<void,vostok::physics::contact_point const &> *)&this->m_packet_client);
    if ( !vostok::core::g_log_filter_tree
      || (has_passed_filters = vostok::logging::has_passed_filters(
                                 (vostok::logging::filter_tree *)"game",
                                 (const char *)4),
          v5 = v10,
          has_passed_filters) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        v5,
        &v14);
      v12 = 1;
      vostok::logging::append(
        &v14,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\lobby_client.cpp",
        0x98u,
        "void __thiscall survarium::lobby_client::sign_in_on_packet_received(class vostok::network_core::buffer_reader &)",
        "game",
        info,
        "Lobby client: signed in!");
    }
    if ( (v12 & 1) != 0 )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v5,
        (int *)&v14);
    v7 = !this->m_discard_playing_order_on_connected;
    this->m_net_client_connected = 1;
    if ( !v7 )
    {
      survarium::lobby_client::discard_playing_order((survarium::lobby_client *)v5, (int)this);
      this->m_discard_playing_order_on_connected = 0;
    }
    v8 = -(this->m_on_connected.vtable != 0);
    if ( ((unsigned int)vostok::memory::process_allocator::finalize_impl & v8) != 0 )
      boost::function0<void>::operator()((boost::function0<bool> *)v8, &this->m_on_connected.vtable);
  }
  else
  {
    if ( !vostok::core::g_log_filter_tree
      || (v4 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"game", (const char *)2), v3 = v9, v4) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        v3,
        &v13);
      v12 = 2;
      vostok::logging::append(
        &v13,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\lobby_client.cpp",
        0xA5u,
        "void __thiscall survarium::lobby_client::sign_in_on_packet_received(class vostok::network_core::buffer_reader &)",
        "game",
        error,
        "Lobby client received unknown SignIn message:%d",
        manager);
    }
    if ( (v12 & 2) != 0 )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v3,
        (int *)&v13);
  }
}
