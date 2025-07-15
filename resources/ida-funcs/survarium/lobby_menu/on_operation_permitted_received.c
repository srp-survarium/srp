void __userpurge survarium::lobby_menu::on_operation_permitted_received(
        survarium::lobby_menu *this@<ecx>,
        survarium::lobby_menu *a2@<eax>,
        vostok::lobby::client::messages_enum op_type)
{
  bool has_passed_filters; // al
  survarium::lobby_client *v5; // eax
  survarium::lobby_client *v6; // ecx
  unsigned __int8 m_selected_profile_idx; // bl
  survarium::lobby_client *v8; // eax
  survarium::lobby_menu *v9; // ecx
  survarium::lobby_client *v10; // eax
  survarium::lobby_client *v11; // ecx
  survarium::lobby_menu *v12; // [esp-4h] [ebp-40h]
  int v13; // [esp-4h] [ebp-40h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v14; // [esp+10h] [ebp-2Ch] BYREF
  int v15; // [esp+34h] [ebp-8h]

  v15 = 0;
  if ( op_type == set_status_ready_for_match )
  {
    survarium::lobby_menu::request_status_from_server(this, a2, 0x3E8u);
  }
  else if ( op_type == inventory_action )
  {
    m_selected_profile_idx = a2->m_selected_profile_idx;
    v8 = survarium::lobby_menu::lobby_client(this, (int)a2);
    v9 = (survarium::lobby_menu *)(1512 * m_selected_profile_idx);
    v13 = *(unsigned int *)((char *)&v8->m_profiles[0].profile_id + (_DWORD)v9);
    v10 = survarium::lobby_menu::lobby_client(v9, (int)a2);
    survarium::lobby_client::query_profile_contents(v11, (const vostok::network_core::tcp_packet *)v10, v13);
  }
  else if ( op_type != shop_action )
  {
    if ( op_type == squad_action )
    {
      v5 = survarium::lobby_menu::lobby_client(this, (int)a2);
      survarium::lobby_client::query_squad_info(v6, (int)v5);
    }
    else
    {
      if ( !vostok::core::g_log_filter_tree
        || (has_passed_filters = vostok::logging::has_passed_filters(
                                   (vostok::logging::filter_tree *)"game",
                                   (const char *)2),
            this = v12,
            has_passed_filters) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)this,
          &v14);
        v15 = 1;
        vostok::logging::append(
          &v14,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\lobby_menu.cpp",
          0x1DCu,
          "void __thiscall survarium::lobby_menu::on_operation_permitted_received(enum vostok::lobby::client::messages_enum)",
          "game",
          error,
          "Unknown (operation permitted) type received %d",
          op_type);
      }
      if ( (v15 & 1) != 0 )
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
          (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)this,
          (int *)&v14);
    }
  }
}
