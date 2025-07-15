void __thiscall survarium::lobby_client::on_error(
        survarium::lobby_client *this,
        vostok::network_core::client_error_codes_enum __formal,
        boost::system::error_code a3)
{
  survarium::lobby_client *v3; // edi
  bool has_passed_filters; // al
  survarium::lobby_client *v5; // [esp-4h] [ebp-34h]
  char v6; // [esp+Ch] [ebp-24h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v7; // [esp+10h] [ebp-20h] BYREF

  v6 = 0;
  v3 = this;
  if ( !vostok::core::g_log_filter_tree
    || (has_passed_filters = vostok::logging::has_passed_filters(
                               (vostok::logging::filter_tree *)"game",
                               (const char *)2),
        this = v5,
        has_passed_filters) )
  {
    boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
      (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)this,
      &v7);
    v6 = 1;
    vostok::logging::append(
      &v7,
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      ".\\lobby_client.cpp",
      0x73u,
      "void __thiscall survarium::lobby_client::on_error(enum vostok::network_core::client_error_codes_enum,class boost::"
      "system::error_code)",
      "game",
      error,
      "lobby client error. reconnecting...");
  }
  if ( (v6 & 1) != 0 )
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)this,
      (int *)&v7);
  survarium::lobby_client::disconnect(this, (int)v3);
  if ( v3->m_status <= (unsigned int)in_match_making )
  {
    ++v3->m_connection_info.connection_error_count;
    v3->m_connection_info.need_resolve = 1;
  }
}
