void __thiscall survarium::network_client::on_disconnected_from_lobby(survarium::network_client *this)
{
  survarium::network_client *v1; // ebx
  bool has_passed_filters; // al
  int m_lobby_menu; // esi
  survarium::lobby_menu *v4; // ecx
  survarium::network_client *v5; // [esp-4h] [ebp-34h]
  char v6; // [esp+Ch] [ebp-24h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v7; // [esp+10h] [ebp-20h] BYREF

  v6 = 0;
  v1 = this;
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
      ".\\network_client_lobby.cpp",
      0x105u,
      "void __thiscall survarium::network_client::on_disconnected_from_lobby(void)",
      "game",
      error,
      "network_client::on_disconnected_from_lobby");
  }
  if ( (v6 & 1) != 0 )
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)this,
      (int *)&v7);
  m_lobby_menu = (int)v1->m_game->m_lobby_menu;
  if ( !survarium::lobby_menu::lobby_client((survarium::lobby_menu *)this, m_lobby_menu)->m_net_client_connected )
    survarium::lobby_menu::show_disconnected_message(v4, m_lobby_menu, 1);
}
