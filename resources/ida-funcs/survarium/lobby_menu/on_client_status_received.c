void __userpurge survarium::lobby_menu::on_client_status_received(
        survarium::lobby_menu *this@<ecx>,
        survarium::lobby_menu *a2@<eax>,
        vostok::lobby::query_info_types type)
{
  int v4; // esi
  vostok::lobby::client_state_enum m_status; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v6; // ecx
  __int32 v7; // eax
  bool has_passed_filters; // al
  survarium::lobby_menu *v9; // ecx
  survarium::lobby_client *v10; // eax
  survarium::lobby_menu *v11; // ecx
  survarium::lobby_menu *v12; // ecx
  unsigned int m_match_order_avg_wait_sec; // esi
  survarium::lobby_menu *v14; // ecx
  unsigned int m_match_order_current_time_sec; // ebx
  survarium::lobby_menu *v16; // ecx
  survarium::lobby_menu *v17; // ecx
  survarium::lobby_client *v18; // eax
  survarium::text_translator *v19; // ecx
  survarium::lobby_menu *v20; // ecx
  unsigned __int8 m_profiles_count; // al
  survarium::lobby_menu *v22; // ecx
  int v23; // ebx
  survarium::lobby_menu *v24; // ecx
  survarium::lobby_client *v25; // eax
  survarium::lobby_client *v26; // ecx
  survarium::lobby_menu *v27; // ecx
  survarium::lobby_client *v28; // eax
  survarium::lobby_client *v29; // ecx
  bool v30; // al
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v31; // [esp-4h] [ebp-60h]
  unsigned int profile_id; // [esp-4h] [ebp-60h]
  survarium::lobby_menu *v33; // [esp-4h] [ebp-60h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v34; // [esp+10h] [ebp-4Ch] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v35; // [esp+30h] [ebp-2Ch] BYREF
  int v36; // [esp+54h] [ebp-8h]
  unsigned int orders_total; // [esp+64h] [ebp+8h]

  v4 = 0;
  v36 = 0;
  switch ( type )
  {
    case q_client_state:
      m_status = survarium::lobby_menu::lobby_client(this, (int)a2)->m_status;
      if ( m_status )
      {
        v7 = m_status - 1;
        if ( v7 )
        {
          if ( v7 != 1 )
          {
            if ( !vostok::core::g_log_filter_tree
              || (has_passed_filters = vostok::logging::has_passed_filters(
                                         (vostok::logging::filter_tree *)"game",
                                         (const char *)2),
                  v6 = v31,
                  has_passed_filters) )
            {
              boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
                v6,
                &v35);
              v36 = 1;
              v10 = survarium::lobby_menu::lobby_client(v9, (int)a2);
              vostok::logging::append(
                &v35,
                (void *const)vostok::core::g_log_flags,
                &vostok::core::g_log_format,
                ".\\lobby_menu.cpp",
                0x156u,
                "void __thiscall survarium::lobby_menu::on_client_status_received(enum vostok::lobby::query_info_types)",
                "game",
                error,
                "Unknown client state %d",
                v10->m_status);
            }
            if ( (v36 & 1) != 0 )
              boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
                (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v6,
                (int *)&v35);
          }
        }
        else
        {
          if ( !survarium::lobby_menu::lobby_client((survarium::lobby_menu *)v6, (int)a2)->m_profiles_count )
            survarium::lobby_menu::query_account_data(v11, (int)a2);
          survarium::lobby_menu::show_match_making(v11, (int)a2, 1);
          m_match_order_avg_wait_sec = survarium::lobby_menu::lobby_client(v12, (int)a2)->m_match_order_avg_wait_sec;
          m_match_order_current_time_sec = survarium::lobby_menu::lobby_client(v14, (int)a2)->m_match_order_current_time_sec;
          orders_total = survarium::lobby_menu::lobby_client(v16, (int)a2)->m_match_orders_total;
          v18 = survarium::lobby_menu::lobby_client(v17, (int)a2);
          survarium::lobby_menu::set_match_making_status(
            m_match_order_current_time_sec,
            v19,
            a2,
            v18->m_match_order_place,
            orders_total,
            m_match_order_avg_wait_sec);
          survarium::lobby_menu::request_status_from_server(v20, a2, 0x3E8u);
        }
      }
      else
      {
        if ( !a2->m_is_active )
          survarium::game::switch_to_lobby((survarium::game *)v6, a2->m_game);
        if ( !survarium::lobby_menu::lobby_client((survarium::lobby_menu *)v6, (int)a2)->m_profiles_count )
          survarium::lobby_menu::query_account_data((survarium::lobby_menu *)v6, (int)a2);
        if ( a2->m_is_in_match_making && !a2->m_game->m_game_world.m_is_loading )
          survarium::lobby_menu::show_match_making((survarium::lobby_menu *)v6, (int)a2, 0);
      }
      survarium::lobby_menu::update_status((survarium::lobby_menu *)v6, (int)a2);
      break;
    case q_enumerate_profiles:
      m_profiles_count = survarium::lobby_menu::lobby_client(this, (int)a2)->m_profiles_count;
      if ( m_profiles_count )
      {
        v23 = m_profiles_count;
        do
        {
          profile_id = survarium::lobby_menu::lobby_client(v22, (int)a2)->m_profiles[v4].profile_id;
          v25 = survarium::lobby_menu::lobby_client(v24, (int)a2);
          survarium::lobby_client::query_profile_contents(
            v26,
            (const vostok::network_core::tcp_packet *)v25,
            profile_id);
          ++v4;
          --v23;
        }
        while ( v23 );
      }
      survarium::lobby_menu::fill_profiles(v22, (int)a2);
      break;
    case q_profile_contents:
    case q_price_items:
    case q_last_played_match_stats:
    case q_player_elo_rating:
    case q_players_elo_list:
    case q_squad_member_profile_contents:
      return;
    case q_enumerate_inventory:
      survarium::lobby_menu::fill_inventory_contents(this, (int)a2);
      v28 = survarium::lobby_menu::lobby_client(v27, (int)a2);
      survarium::lobby_client::query_client_status(v29, (const vostok::network_core::tcp_packet *)v28, 1u);
      break;
    case q_account_money:
      survarium::lobby_menu::reset_account_money(this, (int)a2);
      break;
    case q_player_skills:
      survarium::lobby_menu::fill_character_data(this, (survarium::flash_value *)a2);
      break;
    case q_service_prices:
      survarium::lobby_menu::fill_service_prices(this, (int)a2);
      break;
    case q_player_reputations:
      survarium::lobby_menu::on_player_reputations_arrived(this, (int)a2);
      break;
    case q_shop_items:
      survarium::lobby_menu::on_shop_items_arrived(this, (int)a2);
      break;
    default:
      if ( !vostok::core::g_log_filter_tree
        || (v30 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"game", (const char *)2),
            this = v33,
            v30) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)this,
          &v34);
        v36 = 2;
        vostok::logging::append(
          &v34,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\lobby_menu.cpp",
          0x1A3u,
          "void __thiscall survarium::lobby_menu::on_client_status_received(enum vostok::lobby::query_info_types)",
          "game",
          error,
          "Unknown Client status received. type = %d",
          type);
      }
      if ( (v36 & 2) != 0 )
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
          (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)this,
          (int *)&v34);
      break;
  }
}
