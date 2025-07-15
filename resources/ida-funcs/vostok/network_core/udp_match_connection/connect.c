void __thiscall vostok::network_core::udp_match_connection::connect(
        vostok::network_core::udp_match_connection *this,
        vostok::network_core::udp_match_packet *packet,
        vostok::network_core::udp_match_connection *a3)
{
  bool has_passed_filters; // al
  vostok::network_core::udp_match_connection *v5; // [esp-4h] [ebp-34h]
  vostok::network_core::udp_match_packet *v6; // [esp+0h] [ebp-30h]
  bool *v7; // [esp+4h] [ebp-2Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v8; // [esp+10h] [ebp-20h] BYREF
  char v9; // [esp+38h] [ebp+8h]

  v9 = 0;
  if ( !vostok::core::g_log_filter_tree
    || (has_passed_filters = vostok::logging::has_passed_filters(
                               (vostok::logging::filter_tree *)"network_core",
                               (const char *)2),
        this = v5,
        has_passed_filters) )
  {
    boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
      (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)this,
      &v8);
    v9 = 1;
    vostok::logging::append(
      &v8,
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      ".\\udp_match_connection.cpp",
      0x224u,
      "void __thiscall vostok::network_core::udp_match_connection::connect(class vostok::network_core::udp_match_packet *)",
      "network_core",
      error,
      "--connect");
  }
  if ( (v9 & 1) != 0 )
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)this,
      (int *)&v8);
  packet[2].sequence_ids.m_head = 0;
  if ( a3 )
    vostok::network_core::udp_match_connection::enqueue_impl(a3, (int)packet, v6, v7);
}
