void __thiscall vostok::network_core::udp_match_client::handle_receive(
        vostok::network_core::udp_match_client *this,
        const boost::system::error_code *error_code,
        unsigned int bytes_transferred)
{
  vostok::network_core::udp_match_client *v3; // ebx
  bool has_passed_filters; // al
  bool v5; // zf
  bool v6; // al
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v7; // ecx
  vostok::network_core::udp_network_flow_emulator *m_network_flow_emulator; // esi
  bool v9; // al
  vostok::network_core::udp_match_client *v10; // [esp+0h] [ebp-54h]
  vostok::network_core::udp_match_client *v11; // [esp+0h] [ebp-54h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v12; // [esp+0h] [ebp-54h]
  int v13; // [esp+4h] [ebp-50h]
  int v14; // [esp+4h] [ebp-50h]
  vostok::network_core::socket_handler *v15; // [esp+4h] [ebp-50h]
  int v16; // [esp+4h] [ebp-50h]
  int v17; // [esp+8h] [ebp-4Ch]
  int v18; // [esp+8h] [ebp-4Ch]
  int v19; // [esp+8h] [ebp-4Ch]
  int v20; // [esp+8h] [ebp-4Ch]
  int v21; // [esp+Ch] [ebp-48h]
  int v22; // [esp+Ch] [ebp-48h]
  int v23; // [esp+Ch] [ebp-48h]
  int v24; // [esp+Ch] [ebp-48h]
  unsigned int time_in_ms; // [esp+10h] [ebp-44h]
  unsigned int time_in_msc; // [esp+10h] [ebp-44h]
  unsigned int time_in_msa; // [esp+10h] [ebp-44h]
  unsigned int time_in_msb; // [esp+10h] [ebp-44h]
  __int16 unacknowledged_packets_counta; // [esp+14h] [ebp-40h]
  unsigned int unacknowledged_packets_count; // [esp+14h] [ebp-40h]
  boost::asio::ip::address v31; // [esp+18h] [ebp-3Ch] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> a1; // [esp+34h] [ebp-20h] BYREF

  v3 = this;
  LOBYTE(time_in_ms) = 0;
  if ( (error_code->m_val != 0 ? (unsigned int)vostok::memory::process_allocator::finalize_impl : 0) != 0 )
  {
    this->m_is_receiving = 0;
    if ( !vostok::core::g_log_filter_tree
      || (has_passed_filters = vostok::logging::has_passed_filters(
                                 (vostok::logging::filter_tree *)"network_core",
                                 (const char *)2),
          this = v10,
          has_passed_filters) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)this,
        &a1);
      LOBYTE(time_in_ms) = 3;
      error_code->m_cat->message(
        error_code->m_cat,
        (stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)&v31,
        error_code->m_val);
      vostok::logging::append(
        &a1,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\udp_match_client.cpp",
        0x68u,
        "void __thiscall vostok::network_core::udp_match_client::handle_receive(const class boost::system::error_code &,c"
        "onst unsigned int)",
        "network_core",
        error,
        "error during reading from socket: %s\r\n",
        *(const char **)&v31.ipv6_address_.addr_.u.Word[6]);
    }
    if ( (time_in_ms & 2) != 0 )
    {
      LOBYTE(time_in_ms) = time_in_ms & 0xFD;
      stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_deallocate_block((stlp_std::priv::_String_base<char,stlp_std::allocator<char> > *)&v31);
    }
    v5 = (time_in_ms & 1) == 0;
LABEL_8:
    if ( !v5 )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)this,
        (int *)&a1);
    vostok::network_core::udp_match_connection::instant_disconnect(
      &this->m_connection,
      (int)v3,
      (const vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> *)1);
    return;
  }
  if ( !bytes_transferred )
  {
    this->m_is_receiving = 0;
    if ( !vostok::core::g_log_filter_tree
      || (v6 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"network_core", (const char *)2),
          this = v11,
          v6) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)this,
        &a1);
      LOBYTE(time_in_ms) = 4;
      vostok::logging::append(
        &a1,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\udp_match_client.cpp",
        0x71u,
        "void __thiscall vostok::network_core::udp_match_client::handle_receive(const class boost::system::error_code &,c"
        "onst unsigned int)",
        "network_core",
        error,
        "unable to read from socket\r\n");
    }
    v5 = (time_in_ms & 4) == 0;
    goto LABEL_8;
  }
  if ( this->m_is_receiving )
  {
    this->m_is_receiving = 0;
    boost::asio::ip::detail::endpoint::address(
      (boost::asio::ip::detail::endpoint *)this,
      (int)&this->m_remote_endpoint,
      &v31);
    boost::asio::ip::detail::endpoint::address(
      (boost::asio::ip::detail::endpoint *)&a1,
      (int)&v3->m_server_endpoint,
      (boost::asio::ip::address *)&a1);
    if ( boost::asio::ip::operator==((const boost::asio::ip::address *)&a1, &v31)
      && ((unacknowledged_packets_counta = ((int (__stdcall *)(_DWORD, int, int, int, _DWORD))(&off_8E3A98 + 6))(
                                             v3->m_remote_endpoint.impl_.data_.v4.sin_port,
                                             v13,
                                             v17,
                                             v21,
                                             0),
           unacknowledged_packets_counta == ((unsigned __int16 (__stdcall *)(_DWORD, int, int, int, unsigned int))(&off_8E3A98 + 6))(
                                              v3->m_server_endpoint.impl_.data_.v4.sin_port,
                                              v14,
                                              v18,
                                              v22,
                                              time_in_msc))
       || ((unsigned __int16 (__stdcall *)(_DWORD, vostok::network_core::socket_handler *, int, int, unsigned int))(&off_8E3A98 + 6))(
            v3->m_remote_endpoint.impl_.data_.v4.sin_port,
            v15,
            v19,
            v23,
            time_in_msa) >= v3->m_first_port_in_range
       && ((unsigned __int16 (__stdcall *)(_DWORD, int, int, int, unsigned int))(&off_8E3A98 + 6))(
            v3->m_remote_endpoint.impl_.data_.v4.sin_port,
            v16,
            v20,
            v24,
            time_in_ms) <= v3->m_last_port_in_range) )
    {
      m_network_flow_emulator = v3->m_network_flow_emulator;
      if ( m_network_flow_emulator )
      {
        unacknowledged_packets_count = v3->m_connection.m_unacknowledged_packets.m_size;
        time_in_msb = v3->m_time_in_ms;
        if ( vostok::math::random32::random_f(&m_network_flow_emulator->m_lost_packets_random, 1.0) > m_network_flow_emulator->m_lost_packet_probability )
          vostok::network_core::udp_network_flow_emulator::add_packet(
            time_in_msb,
            m_network_flow_emulator,
            v3->m_receive_buffer.elems,
            bytes_transferred,
            &v3->m_remote_endpoint,
            unacknowledged_packets_count,
            v15);
      }
      else
      {
        v31.type_ = (boost::asio::ip::address::<unnamed_type_type_>)&v3->m_receive_buffer;
        v31.ipv4_address_.addr_.S_un.S_addr = (unsigned int)v3->m_receive_buffer.elems;
        *(_DWORD *)v31.ipv6_address_.addr_.u.Byte = bytes_transferred;
        vostok::network_core::udp_match_client::process_incoming_packet(
          v3,
          (vostok::network_core::buffer_reader *)&v31,
          &v3->m_remote_endpoint,
          0);
      }
    }
    else
    {
      if ( !vostok::core::g_log_filter_tree
        || (v9 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"network_core", (const char *)2),
            v7 = v12,
            v9) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v7,
          &a1);
        LOBYTE(time_in_ms) = 8;
        vostok::logging::append(
          &a1,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\udp_match_client.cpp",
          0x7Cu,
          "void __thiscall vostok::network_core::udp_match_client::handle_receive(const class boost::system::error_code &"
          ",const unsigned int)",
          "network_core",
          error,
          "unexpected sender\r\n");
      }
      if ( (time_in_ms & 8) != 0 )
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
          (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v7,
          (int *)&a1);
    }
    if ( v3->m_connection.m_state != connecting )
      vostok::network_core::udp_match_client::start_receiving(v3);
  }
}
