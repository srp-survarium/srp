void __thiscall vostok::network_core::udp_match_client::connect(
        vostok::network_core::udp_match_client *this,
        vostok::network_core::udp_match_packet *host,
        char *port,
        vostok::network_core::udp_match_packet *packet,
        vostok::network_core::udp_match_connection *current_time_in_ms,
        boost::function<void __cdecl(vostok::network_core::udp_match_packet &,boost::function<void __cdecl(vostok::network_core::udp_match_packet &,boost::system::error_code const &,unsigned int)> const &)> *time_in_ms)
{
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v7; // ecx
  bool has_passed_filters; // al
  boost::asio::basic_socket<boost::asio::ip::udp,boost::asio::datagram_socket_service<boost::asio::ip::udp> > *v9; // ecx
  boost::asio::ip::basic_endpoint<boost::asio::ip::udp> *v10; // eax
  unsigned __int16 v11; // si
  boost::asio::basic_socket<boost::asio::ip::udp,boost::asio::datagram_socket_service<boost::asio::ip::udp> > *v12; // ecx
  boost::asio::ip::basic_endpoint<boost::asio::ip::udp> *v13; // eax
  boost::asio::ip::address *v14; // eax
  vostok::timing::timer *v15; // ecx
  vostok::network_core::udp_match_client *v16; // ecx
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v17; // [esp-4h] [ebp-C0h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v18; // [esp-4h] [ebp-C0h]
  boost::asio::detail::win_iocp_socket_service<boost::asio::ip::udp>::implementation_type *v19; // [esp+0h] [ebp-BCh]
  int v20; // [esp+0h] [ebp-BCh]
  int v21; // [esp+4h] [ebp-B8h]
  int v22; // [esp+8h] [ebp-B4h]
  int v23; // [esp+Ch] [ebp-B0h]
  boost::asio::ip::basic_endpoint<boost::asio::ip::udp> v24; // [esp+10h] [ebp-ACh] BYREF
  boost::asio::ip::basic_endpoint<boost::asio::ip::udp> v25; // [esp+2Ch] [ebp-90h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v26; // [esp+48h] [ebp-74h] BYREF
  boost::asio::ip::address result; // [esp+6Ch] [ebp-50h] BYREF
  boost::system::error_code v28; // [esp+88h] [ebp-34h] BYREF
  boost::asio::ip::detail::endpoint v29; // [esp+90h] [ebp-2Ch] BYREF
  boost::asio::ip::udp v30; // [esp+ACh] [ebp-10h] BYREF
  boost::system::error_code ec; // [esp+B0h] [ebp-Ch] BYREF
  char packeta; // [esp+C4h] [ebp+8h]

  packeta = 0;
  if ( *(_DWORD *)&host[2].m_raw_buffer.elems[112] != -1 )
    boost::asio::basic_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp>>::close(
      (boost::asio::basic_socket<boost::asio::ip::udp,boost::asio::datagram_socket_service<boost::asio::ip::udp> > *)this,
      (int)&host[2].m_raw_buffer.elems[108]);
  ec.m_val = 0;
  v30.family_ = 2;
  ec.m_cat = boost::system::system_category();
  boost::asio::detail::win_iocp_socket_service<boost::asio::ip::udp>::open(
    (boost::asio::detail::win_iocp_socket_service_base *)&host[2].m_raw_buffer.elems[112],
    &v30,
    (boost::system::error_code *)(*(_DWORD *)&host[2].m_raw_buffer.elems[108] + 20),
    &v28,
    &ec);
  if ( (ec.m_val != 0 ? (unsigned int)vostok::memory::process_allocator::finalize_impl : 0) != 0 )
    boost::asio::detail::do_throw_error(&ec, "open");
  memset(&v29, 0, sizeof(v29));
  *(_QWORD *)&v29.data_.base.sa_family = 2;
  ec.m_val = 0;
  ec.m_cat = boost::system::system_category();
  boost::asio::datagram_socket_service<boost::asio::ip::udp>::bind(
    (const boost::asio::ip::basic_endpoint<boost::asio::ip::udp> *)&v29,
    &ec,
    &v28,
    (int)host,
    (boost::asio::datagram_socket_service<boost::asio::ip::udp> *)&host[2].m_raw_buffer.elems[112],
    v19);
  if ( (ec.m_val != 0 ? (unsigned int)vostok::memory::process_allocator::finalize_impl : 0) != 0 )
    boost::asio::detail::do_throw_error(&ec, "bind");
  ec.m_val = 0;
  v30.family_ = (int)&loc_20000;
  ec.m_cat = boost::system::system_category();
  boost::asio::detail::socket_ops::setsockopt(
    &host[2].m_raw_buffer.elems[116],
    &ec,
    *(_DWORD *)&host[2].m_raw_buffer.elems[112],
    0xFFFF,
    4098,
    &v30,
    4u);
  if ( (ec.m_val != 0 ? (unsigned int)vostok::memory::process_allocator::finalize_impl : 0) != 0 )
    boost::asio::detail::do_throw_error(&ec, "set_option");
  ec.m_val = 0;
  v30.family_ = (int)&loc_20000;
  ec.m_cat = boost::system::system_category();
  boost::asio::detail::socket_ops::setsockopt(
    &host[2].m_raw_buffer.elems[116],
    &ec,
    *(_DWORD *)&host[2].m_raw_buffer.elems[112],
    0xFFFF,
    4097,
    &v30,
    4u);
  if ( (ec.m_val != 0 ? (unsigned int)vostok::memory::process_allocator::finalize_impl : 0) != 0 )
  {
    boost::asio::detail::do_throw_error(&ec, "set_option");
    v7 = v17;
  }
  if ( !vostok::core::g_log_filter_tree
    || (has_passed_filters = vostok::logging::has_passed_filters(
                               (vostok::logging::filter_tree *)"network_core",
                               (const char *)4),
        v7 = v18,
        has_passed_filters) )
  {
    boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
      v7,
      &v26);
    packeta = 3;
    v10 = boost::asio::basic_socket<boost::asio::ip::udp,boost::asio::datagram_socket_service<boost::asio::ip::udp>>::local_endpoint(
            v9,
            (boost::asio::ip::basic_endpoint<boost::asio::ip::udp> *)&host[2].m_raw_buffer.elems[108],
            &v25);
    v11 = ((int (__stdcall *)(_DWORD, int, int, int, int))(&off_8E3A98 + 6))(
            v10->impl_.data_.v4.sin_port,
            v20,
            v21,
            v22,
            v23);
    v13 = boost::asio::basic_socket<boost::asio::ip::udp,boost::asio::datagram_socket_service<boost::asio::ip::udp>>::local_endpoint(
            v12,
            (boost::asio::ip::basic_endpoint<boost::asio::ip::udp> *)&host[2].m_raw_buffer.elems[108],
            &v24);
    boost::asio::ip::detail::endpoint::address((boost::asio::ip::detail::endpoint *)&result, (int)v13, &result);
    v14 = boost::asio::ip::address::to_string((boost::asio::ip::address *)&v29.data_.v6.sin6_flowinfo, (int)&result);
    vostok::logging::append(
      &v26,
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      ".\\udp_match_client.cpp",
      0xA9u,
      "void __thiscall vostok::network_core::udp_match_client::connect(const char *,unsigned short,class vostok::network_"
      "core::udp_match_packet *,unsigned int)",
      "network_core",
      info,
      "connecting from %s:%d to %s:%d",
      *(const char **)&v14->ipv6_address_.addr_.u.Word[6],
      v11,
      port,
      (unsigned __int16)packet);
  }
  if ( (packeta & 2) != 0 )
  {
    packeta &= ~2u;
    stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_deallocate_block((stlp_std::priv::_String_base<char,stlp_std::allocator<char> > *)&v29.data_.v6.sin6_flowinfo);
  }
  if ( (packeta & 1) != 0 )
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v7,
      (int *)&v26);
  ec.m_val = 0;
  ec.m_cat = boost::system::system_category();
  boost::asio::ip::address::from_string(&result, port, &ec);
  if ( (ec.m_val != 0 ? (unsigned int)vostok::memory::process_allocator::finalize_impl : 0) != 0 )
    boost::asio::detail::do_throw_error(&ec);
  boost::asio::ip::detail::endpoint::endpoint(&result, &v29, (int)packet);
  qmemcpy(&host[2].m_raw_buffer.elems[176], &v29, 0x1Cu);
  boost::asio::ip::detail::endpoint::address(
    (boost::asio::ip::detail::endpoint *)&result,
    (int)&host[2].m_raw_buffer.elems[176],
    &result);
  host[2].m_raw_buffer.elems[14] = result.type_ == ipv4;
  *(_WORD *)&host[4].m_raw_buffer.elems[28] = (_WORD)packet;
  *(_WORD *)&host[4].m_raw_buffer.elems[30] = (_WORD)packet;
  *(_DWORD *)&host[2].m_raw_buffer.elems[232] = (unsigned __int16)packet;
  *(_DWORD *)&host[2].m_raw_buffer.elems[236] = (unsigned __int16)packet;
  vostok::network_core::udp_match_connection::connect(
    (vostok::network_core::udp_match_connection *)&host[2].m_raw_buffer.elems[232],
    host,
    current_time_in_ms);
  vostok::network_core::udp_match_client::start_receiving((vostok::network_core::udp_match_client *)host);
  *(_DWORD *)&host[4].m_raw_buffer.elems[24] = time_in_ms;
  vostok::timing::timer::start(v15, (LARGE_INTEGER *)&host[2].m_raw_buffer.elems[84]);
  vostok::network_core::udp_match_client::send_queued_packets_impl(v16, (unsigned int)host, time_in_ms);
}
