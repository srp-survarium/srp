void __thiscall survarium::lobby_client::disconnect(survarium::lobby_client *this, int a2)
{
  int v3; // ecx
  bool has_passed_filters; // al
  vostok::network::tcp_packet_client *v5; // ecx
  boost::function0<bool> *v6; // [esp-4h] [ebp-38h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v7; // [esp+10h] [ebp-24h] BYREF
  char v8; // [esp+3Ch] [ebp+8h]

  v8 = 0;
  v3 = -(*(_DWORD *)(a2 + 400) != 0);
  *(_BYTE *)(a2 + 436) = 0;
  if ( ((unsigned int)vostok::memory::process_allocator::finalize_impl & v3) != 0 )
    boost::function0<void>::operator()((boost::function0<bool> *)v3, (_DWORD *)(a2 + 400));
  if ( !vostok::core::g_log_filter_tree
    || (has_passed_filters = vostok::logging::has_passed_filters(
                               (vostok::logging::filter_tree *)"game",
                               (const char *)4),
        v3 = (int)v6,
        has_passed_filters) )
  {
    boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
      (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v3,
      &v7);
    v8 = 1;
    vostok::logging::append(
      &v7,
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      ".\\lobby_client.cpp",
      0x8Au,
      "void __thiscall survarium::lobby_client::disconnect(void)",
      "game",
      info,
      "lobby client initiate disconnect");
  }
  if ( (v8 & 1) != 0 )
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v3,
      (int *)&v7);
  survarium::lobby_client::clear_profile_info((survarium::lobby_client *)v3, a2);
  vostok::network::tcp_packet_client::disconnect(v5, a2 + 200);
}
