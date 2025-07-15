void __userpurge vostok::network_core::udp_match_client::enqueue(
        vostok::network_core::udp_match_client *this@<ecx>,
        int a2@<eax>,
        vostok::network_core::buffer_reader *message_type,
        vostok::network_core::udp_match_packet *reader)
{
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v4; // ecx
  bool has_passed_filters; // al
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v6; // [esp-4h] [ebp-34h]
  char v7; // [esp+Ch] [ebp-24h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v8; // [esp+10h] [ebp-20h] BYREF

  v4 = 0;
  v7 = 0;
  if ( *(_DWORD *)(a2 + 2820) )
  {
    if ( !vostok::core::g_log_filter_tree
      || (has_passed_filters = vostok::logging::has_passed_filters(
                                 (vostok::logging::filter_tree *)"network_core",
                                 (const char *)2),
          v4 = v6,
          has_passed_filters) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        v4,
        &v8);
      v7 = 1;
      vostok::logging::append(
        &v8,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\udp_match_client.cpp",
        0xF6u,
        "void __thiscall vostok::network_core::udp_match_client::enqueue(const unsigned char,class vostok::network_core::"
        "buffer_reader &)",
        "network_core",
        error,
        "disconnection initiated but new packet has been enqueued");
    }
    if ( (v7 & 1) != 0 )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v4,
        (int *)&v8);
  }
  else
  {
    vostok::network_core::udp_match_connection::enqueue(0, a2, message_type, reader);
  }
}


void __thiscall vostok::network_core::udp_match_client::enqueue(
        vostok::network_core::udp_match_client *this,
        vostok::network_core::udp_match_packet *packet,
        vostok::network_core::udp_match_packet *packeta)
{
  bool has_passed_filters; // al
  vostok::network_core::udp_match_client *v4; // [esp-4h] [ebp-34h]
  char v5; // [esp+Ch] [ebp-24h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v6; // [esp+10h] [ebp-20h] BYREF

  v5 = 0;
  if ( packet[2].sequence_ids.m_head )
  {
    if ( !vostok::core::g_log_filter_tree
      || (has_passed_filters = vostok::logging::has_passed_filters(
                                 (vostok::logging::filter_tree *)"network_core",
                                 (const char *)2),
          this = v4,
          has_passed_filters) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)this,
        &v6);
      v5 = 1;
      vostok::logging::append(
        &v6,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\udp_match_client.cpp",
        0xE8u,
        "void __thiscall vostok::network_core::udp_match_client::enqueue(class vostok::network_core::udp_match_packet *)",
        "network_core",
        error,
        "disconnection initiated but new packet has been enqueued");
    }
    if ( (v5 & 1) != 0 )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)this,
        (int *)&v6);
    vostok::network_core::delete_udp_match_packet(
      (vostok::memory::single_size_buffer_allocator<1364,vostok::threading::multi_threading_policy> *)packet[2].client_session,
      (vostok::memory::single_size_buffer_allocator<140,vostok::threading::simple_lock>::node **)&packeta);
  }
  else
  {
    vostok::network_core::udp_match_connection::enqueue(
      &this->m_connection,
      (int)packet,
      (vostok::network_core::udp_match_connection *)packeta);
  }
}
