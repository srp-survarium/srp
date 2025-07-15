void __thiscall vostok::network_core::udp_match_connection::handle_send(
        vostok::network_core::udp_match_connection *this,
        vostok::network_core::udp_match_packet *packet,
        const boost::system::error_code *error_code,
        unsigned int bytes_transferred)
{
  vostok::network_core::udp_match_packet *m_first; // eax
  vostok::network_core::udp_match_packet *v6; // ecx
  vostok::network_core::udp_match_packet *next; // edx
  vostok::network_core::udp_match_packet *v8; // eax
  vostok::network_core::udp_match_connection::state m_state; // ecx
  __m128i v10; // xmm0
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v11; // ecx
  bool has_passed_filters; // al
  bool v13; // zf
  bool v14; // al
  vostok::memory::single_size_buffer_allocator<1364,vostok::threading::multi_threading_policy> *m_packets_allocator; // [esp-8h] [ebp-60h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v16; // [esp-4h] [ebp-5Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v17; // [esp-4h] [ebp-5Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v18; // [esp-4h] [ebp-5Ch]
  char v19; // [esp+Ch] [ebp-4Ch]
  vostok::network_core::udp_match_packet *v20; // [esp+10h] [ebp-48h] BYREF
  unsigned int m_size; // [esp+14h] [ebp-44h]
  int v22; // [esp+18h] [ebp-40h] BYREF
  boost::random::uniform_smallint<int> *v23; // [esp+1Ch] [ebp-3Ch]
  stlp_std::priv::_String_base<char,stlp_std::allocator<char> > v24; // [esp+20h] [ebp-38h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v25; // [esp+38h] [ebp-20h] BYREF

  v19 = 0;
  --this->m_pending_operations_count;
  m_first = this->m_outgoing_packets.m_first;
  if ( m_first )
  {
    v6 = 0;
    while ( m_first != packet )
    {
      v6 = m_first;
      m_first = m_first->next;
      if ( !m_first )
      {
        if ( packet )
          goto LABEL_13;
        break;
      }
    }
    --this->m_outgoing_packets.m_size;
    next = m_first->next;
    if ( v6 )
      v6->next = next;
    else
      this->m_outgoing_packets.m_first = next;
    if ( !m_first->next )
    {
      v8 = v6;
      if ( !v6 )
        v8 = this->m_outgoing_packets.m_first;
      this->m_outgoing_packets.m_last = v8;
    }
  }
LABEL_13:
  v13 = (*((_BYTE *)packet + 107) & 0x40) == 0;
  m_size = packet->m_buffer.m_size;
  if ( v13
    || (m_state = this->m_state, m_state == connecting)
    || (v10 = _mm_loadl_epi64((const __m128i *)(packet->m_buffer.m_buffer + 4)),
        v23 = (boost::random::uniform_smallint<int> *)v10.m128i_i32[1],
        v22 = v10.m128i_i8[0] & 1,
        (v10.m128i_i8[0] & 1) != 0)
    || m_state && !vostok::network_core::udp_match_connection::is_low_level_packet(packet) )
  {
    m_packets_allocator = this->m_packets_allocator;
    v20 = packet;
    vostok::network_core::delete_udp_match_packet(
      m_packets_allocator,
      (vostok::memory::single_size_buffer_allocator<140,vostok::threading::simple_lock>::node **)&v20);
    v11 = v16;
  }
  else
  {
    *packet->m_buffer.m_buffer = (*((_DWORD *)packet->m_buffer.m_buffer + 1) & 1) != 0;
    this->m_packets_orderer->get_sending_message_info(
      this->m_packets_orderer,
      (vostok::network_core::udp_match_message_type_info *)&v20,
      packet->message_type);
    v22 = (unsigned __int16)v20 - BYTE2(v20);
    v23 = (boost::random::uniform_smallint<int> *)((unsigned __int16)v20 + BYTE2(v20));
    packet->next_send_time_in_ms = boost::random::uniform_smallint<int>::generate<boost::random::mersenne_twister_engine<unsigned int,32,624,397,31,2567483615,11,4294967295,7,2636928640,15,4022730752,18,1812433253>>(
                                     v23,
                                     (int)&v22,
                                     &this->m_random_generator,
                                     (boost::mpl::bool_<1>)m_size)
                                 + packet->last_send_time_in_ms;
    vostok::intrusive_list<vostok::network_core::udp_match_packet,vostok::network_core::udp_match_packet *,60,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::push_back(
      (vostok::intrusive_list<vostok::network_core::udp_match_packet,vostok::network_core::udp_match_packet *,60,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *)packet,
      &this->m_unacknowledged_packets.m_size);
  }
  if ( (error_code->m_val != 0 ? (unsigned int)vostok::memory::process_allocator::finalize_impl : 0) != 0 )
  {
    if ( !vostok::core::g_log_filter_tree
      || (has_passed_filters = vostok::logging::has_passed_filters(
                                 (vostok::logging::filter_tree *)"network_core",
                                 (const char *)2),
          v11 = v17,
          has_passed_filters) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        v11,
        &v25);
      v19 = 3;
      error_code->m_cat->message(
        error_code->m_cat,
        (stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)&v24,
        error_code->m_val);
      vostok::logging::append(
        &v25,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\udp_match_connection.cpp",
        0x91u,
        "void __thiscall vostok::network_core::udp_match_connection::handle_send(class vostok::network_core::udp_match_pa"
        "cket &,const class boost::system::error_code &,unsigned int)",
        "network_core",
        error,
        "error during writing to socket: %s\r\n",
        v24._M_start_of_storage._M_data);
    }
    if ( (v19 & 2) != 0 )
    {
      v19 &= ~2u;
      stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_deallocate_block(&v24);
    }
    v13 = (v19 & 1) == 0;
  }
  else
  {
    if ( bytes_transferred == m_size )
      return;
    if ( !vostok::core::g_log_filter_tree
      || (v14 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"network_core", (const char *)2),
          v11 = v18,
          v14) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        v11,
        &v25);
      v19 = 4;
      vostok::logging::append(
        &v25,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\udp_match_connection.cpp",
        0x97u,
        "void __thiscall vostok::network_core::udp_match_connection::handle_send(class vostok::network_core::udp_match_pa"
        "cket &,const class boost::system::error_code &,unsigned int)",
        "network_core",
        error,
        "unable to write to socket(%d => %d)\r\n",
        m_size,
        bytes_transferred);
    }
    v13 = (v19 & 4) == 0;
  }
  if ( !v13 )
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v11,
      (int *)&v25);
}
