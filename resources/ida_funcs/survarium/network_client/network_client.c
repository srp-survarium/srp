void __thiscall survarium::network_client::network_client(
        survarium::network_client *this,
        survarium::network_client *g,
        survarium::game *is_spectator,
        bool is_spectatora)
{
  survarium::match_options *v4; // ecx
  vostok::network_core::udp_match_stats *v5; // ecx
  survarium::stats_row *v6; // ecx
  survarium::stats_row *v7; // ecx
  survarium::stats_row *v8; // ecx
  survarium::stats_row *v9; // ecx
  survarium::stats_row *v10; // ecx
  survarium::stats_row *v11; // ecx
  boost::function2<void,unsigned char,vostok::network_core::packet_reader &> *v12; // ecx
  __int64 v13; // xmm0_8
  boost::function1<void,vostok::network_core::packet_reader &> *v14; // ecx
  void (__cdecl *v15)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::function0<void> *v16; // ecx
  void (__cdecl *v17)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::function0<void> *v18; // ecx
  void (__cdecl *v19)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::function1<void,boost::system::error_code> *v20; // ecx
  void (__cdecl *v21)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::function1<void,char const *> *v22; // ecx
  void (__cdecl *v23)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  void (__cdecl *v24)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::network_client,unsigned char,vostok::network_core::packet_reader &>,boost::_bi::list3<boost::_bi::value<survarium::network_client *>,boost::arg<1>,boost::arg<2> > > v25; // [esp-10h] [ebp-40h]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::network_client,vostok::network_core::packet_reader &>,boost::_bi::list2<boost::_bi::value<survarium::network_client *>,boost::arg<1> > > v26; // [esp-10h] [ebp-40h]
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,survarium::network_client>,boost::_bi::list1<boost::_bi::value<survarium::network_client *> > > v27; // [esp-10h] [ebp-40h]
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,survarium::network_client>,boost::_bi::list1<boost::_bi::value<survarium::network_client *> > > v28; // [esp-10h] [ebp-40h]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::network_client,boost::system::error_code>,boost::_bi::list2<boost::_bi::value<survarium::network_client *>,boost::arg<1> > > v29; // [esp-10h] [ebp-40h]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::base_network_client,char const *>,boost::_bi::list2<boost::_bi::value<survarium::network_client *>,boost::arg<1> > > v30; // [esp-10h] [ebp-40h]
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,survarium::base_network_client>,boost::_bi::list1<boost::_bi::value<survarium::network_client *> > > v31; // [esp-10h] [ebp-40h]
  int v32; // [esp+0h] [ebp-30h]
  int v33; // [esp+0h] [ebp-30h]
  int v34; // [esp+0h] [ebp-30h]
  int v35; // [esp+0h] [ebp-30h]
  int v36; // [esp+0h] [ebp-30h]
  int v37; // [esp+0h] [ebp-30h]
  boost::function<void __cdecl(unsigned int,unsigned int)> v38; // [esp+10h] [ebp-20h] BYREF

  survarium::base_network_client::base_network_client(g, is_spectator);
  g->__vftable = (survarium::network_client_vtbl *)&survarium::network_client::`vftable';
  vostok::network::login_client::login_client(
    &g->m_login_client,
    (vostok::network::network_world *)is_spectator->m_network_world);
  survarium::lobby_client::lobby_client(&g->m_lobby_client, is_spectator);
  vostok::network::match_client::match_client(
    &g->m_match_client.m_client,
    is_spectator->m_network_world,
    &g->m_match_client.m_packets_orderer,
    0);
  g->m_match_client.m_packets_orderer.__vftable = (survarium::network_packets_orderer<enum vostok::match_client_message_types_enum,enum vostok::match_server_message_types_enum>_vtbl *)&survarium::network_packets_orderer<enum vostok::match_client_message_types_enum,enum vostok::match_server_message_types_enum>::`vftable';
  survarium::match_options::match_options(v4, (int)&g->m_match_client.m_match_options);
  g->m_match_client.m_last_send_queed_packets_time_in_ms = 0;
  g->m_match_client.m_are_there_any_packets_to_send = 0;
  survarium::messaging_client::messaging_client(&g->m_messaging_client, is_spectator);
  vostok::network::http_client::http_client(&g->m_http_client, is_spectator->m_network_world);
  vostok::network_core::udp_match_stats::udp_match_stats(v5, &g->m_previous_stats.sent.packets.count);
  g->m_player_inputs.m_begin = (survarium::client_player_update *)g->m_player_inputs.m_buffer;
  g->m_player_inputs.m_end = (survarium::client_player_update *)g->m_player_inputs.m_buffer;
  `vector constructor iterator'(
    (char *)&g->m_net_players,
    8u,
    20,
    (void *(__thiscall *)(void *))survarium::player_desc::player_desc);
  g->m_local_player.m_object = 0;
  survarium::stats_row::stats_row(v6, (int)&g->m_sent);
  survarium::stats_row::stats_row(v7, (int)&g->m_sent_low_level);
  survarium::stats_row::stats_row(v8, (int)&g->m_resent);
  survarium::stats_row::stats_row(v9, (int)&g->m_received);
  survarium::stats_row::stats_row(v10, (int)&g->m_received_low_level);
  survarium::stats_row::stats_row(v11, (int)&g->m_received_duplicated);
  g->m_max_local_sequence_difference_caption.text_impl = 0;
  g->m_max_local_sequence_difference_caption.owner = 0;
  g->m_max_local_sequence_difference_caption.visible = 0;
  g->m_max_local_sequence_difference_value.text_impl = 0;
  g->m_max_local_sequence_difference_value.owner = 0;
  g->m_max_local_sequence_difference_value.visible = 0;
  g->m_unacknowledged_packets_caption.text_impl = 0;
  g->m_unacknowledged_packets_caption.owner = 0;
  g->m_unacknowledged_packets_caption.visible = 0;
  g->m_unacknowledged_packets_value.text_impl = 0;
  g->m_unacknowledged_packets_value.owner = 0;
  g->m_unacknowledged_packets_value.visible = 0;
  g->m_last_tick_time_in_ms = 0;
  g->m_last_sync_request_time = 0;
  g->m_last_player_input_send_time_in_ms = 0;
  g->m_last_send_queued_packets_time_in_ms = 0;
  g->m_server_latency = 0;
  g->m_game_status = game_status_inactive;
  LOBYTE(v12) = is_spectatora;
  v38.vtable = (boost::detail::function::vtable_base *)survarium::network_client::on_match_packet_received;
  (&v38.vtable)[1] = 0;
  v25.f_.f_ = (void (__thiscall *__ptr64)(survarium::network_client *, unsigned __int8, vostok::network_core::packet_reader *))(unsigned int)survarium::network_client::on_match_packet_received;
  v38.functor.obj_ptr = g;
  v13 = *(_QWORD *)&v38.functor.obj_ptr;
  g->m_is_spectator = is_spectatora;
  g->m_is_player_ticked = 0;
  g->m_is_time_synchronized_first_time = 0;
  *(_QWORD *)&v25.l_.a1_.t_ = v13;
  boost::function2<void,unsigned char,vostok::network_core::packet_reader &>::function2<void,unsigned char,vostok::network_core::packet_reader &>(
    v12,
    (int)&v38,
    (int)is_spectator,
    v25,
    v32);
  boost::function<void __cdecl (unsigned char,vostok::network_core::packet_reader &)>::operator=(
    &v38,
    (boost::function2<void,unsigned int,unsigned int> *)&g->m_match_client.m_client.m_on_packet_received);
  if ( v38.vtable )
  {
    if ( ((int)v38.vtable & 1) == 0 )
    {
      v15 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)v38.vtable & 0xFFFFFFFE);
      if ( v15 )
        v15(&v38.functor, &v38.functor, 2);
    }
  }
  v38.vtable = (boost::detail::function::vtable_base *)survarium::network_client::on_lobby_packet_received;
  (&v38.vtable)[1] = 0;
  v26.f_.f_ = (void (__thiscall *__ptr64)(survarium::network_client *, vostok::network_core::packet_reader *))(unsigned int)survarium::network_client::on_lobby_packet_received;
  v38.functor.obj_ptr = g;
  *(_QWORD *)&v26.l_.a1_.t_ = *(_QWORD *)&v38.functor.obj_ptr;
  boost::function1<void,vostok::network_core::packet_reader &>::function1<void,vostok::network_core::packet_reader &>(
    v14,
    (int)&v38,
    (int)is_spectator,
    v26,
    v33);
  boost::function<void __cdecl (unsigned char,vostok::network_core::packet_reader &)>::operator=(
    &v38,
    (boost::function2<void,unsigned int,unsigned int> *)&g->m_lobby_client.m_on_packet_received);
  if ( v38.vtable )
  {
    if ( ((int)v38.vtable & 1) == 0 )
    {
      v17 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)v38.vtable & 0xFFFFFFFE);
      if ( v17 )
        v17(&v38.functor, &v38.functor, 2);
    }
  }
  v38.vtable = (boost::detail::function::vtable_base *)survarium::network_client::on_connected_to_lobby;
  (&v38.vtable)[1] = 0;
  v27.f_.f_ = (void (__thiscall *__ptr64)(survarium::network_client *))(unsigned int)survarium::network_client::on_connected_to_lobby;
  v38.functor.obj_ptr = g;
  *(_QWORD *)&v27.l_.a1_.t_ = *(_QWORD *)&v38.functor.obj_ptr;
  boost::function0<void>::function0<void>(v16, (int)&v38, (int)is_spectator, v27, v34);
  boost::function<void __cdecl (void)>::operator=(
    &g->m_lobby_client.m_on_connected,
    (const boost::function<void __cdecl(void)> *)&v38);
  if ( v38.vtable )
  {
    if ( ((int)v38.vtable & 1) == 0 )
    {
      v19 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)v38.vtable & 0xFFFFFFFE);
      if ( v19 )
        v19(&v38.functor, &v38.functor, 2);
    }
  }
  v38.vtable = (boost::detail::function::vtable_base *)survarium::network_client::on_disconnected_from_lobby;
  (&v38.vtable)[1] = 0;
  v28.f_.f_ = (void (__thiscall *__ptr64)(survarium::network_client *))(unsigned int)survarium::network_client::on_disconnected_from_lobby;
  v38.functor.obj_ptr = g;
  *(_QWORD *)&v28.l_.a1_.t_ = *(_QWORD *)&v38.functor.obj_ptr;
  boost::function0<void>::function0<void>(v18, (int)&v38, (int)is_spectator, v28, v35);
  boost::function<void __cdecl (void)>::operator=(
    &g->m_lobby_client.m_on_disconnected,
    (const boost::function<void __cdecl(void)> *)&v38);
  if ( v38.vtable )
  {
    if ( ((int)v38.vtable & 1) == 0 )
    {
      v21 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)v38.vtable & 0xFFFFFFFE);
      if ( v21 )
        v21(&v38.functor, &v38.functor, 2);
    }
  }
  v38.vtable = (boost::detail::function::vtable_base *)survarium::network_client::on_http_error;
  (&v38.vtable)[1] = 0;
  v29.f_.f_ = (void (__thiscall *__ptr64)(survarium::network_client *, boost::system::error_code))(unsigned int)survarium::network_client::on_http_error;
  v38.functor.obj_ptr = g;
  *(_QWORD *)&v29.l_.a1_.t_ = *(_QWORD *)&v38.functor.obj_ptr;
  boost::function1<void,boost::system::error_code>::function1<void,boost::system::error_code>(
    v20,
    (int)&v38,
    (int)is_spectator,
    v29,
    v36);
  boost::function<void __cdecl (boost::system::error_code)>::operator=(
    &g->m_http_client.m_on_error,
    (const boost::function<void __cdecl(boost::system::error_code)> *)&v38);
  boost::function1<void,vostok::vfs::base_node<1> *>::~function1<void,vostok::vfs::base_node<1> *>((boost::function<void __cdecl(vostok::vfs::vfs_iterator &)> *)&v38);
  if ( g->m_is_spectator )
  {
    if ( (_S6_10 & 1) == 0 )
    {
      _S6_10 |= 1u;
      v38.vtable = (boost::detail::function::vtable_base *)survarium::base_network_client::attach_to_player_cc;
      (&v38.vtable)[1] = 0;
      v30.f_.f_ = (void (__thiscall *__ptr64)(survarium::base_network_client *, const char *))(unsigned int)survarium::base_network_client::attach_to_player_cc;
      v38.functor.obj_ptr = g;
      *(_QWORD *)&v30.l_.a1_.t_ = *(_QWORD *)&v38.functor.obj_ptr;
      boost::function1<void,char const *>::function1<void,char const *>(v22, (int)&v38, (int)is_spectator, v30, v37);
      vostok::console_commands::cc_delegate::cc_delegate(
        &s_attach_to_player,
        "attach_to_player",
        (const boost::function<void __cdecl(char const *)> *)&v38,
        1,
        command_type_engine_internal);
      if ( v38.vtable )
      {
        if ( ((int)v38.vtable & 1) == 0 )
        {
          v23 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)v38.vtable & 0xFFFFFFFE);
          if ( v23 )
            v23(&v38.functor, &v38.functor, 2);
        }
      }
      atexit(survarium::network_client::network_client_::_5_::_dynamic_atexit_destructor_for__s_attach_to_player__);
    }
    if ( (_S6_10 & 2) == 0 )
    {
      _S6_10 |= 2u;
      v38.vtable = (boost::detail::function::vtable_base *)survarium::base_network_client::detach_from_player;
      (&v38.vtable)[1] = 0;
      v31.f_.f_ = (void (__thiscall *__ptr64)(survarium::base_network_client *))(unsigned int)survarium::base_network_client::detach_from_player;
      v38.functor.obj_ptr = g;
      *(_QWORD *)&v31.l_.a1_.t_ = *(_QWORD *)&v38.functor.obj_ptr;
      boost::function1<void,char const *>::function1<void,char const *>(v22, (int)&v38, (int)is_spectator, v31, v37);
      vostok::console_commands::cc_delegate::cc_delegate(
        &s_detach_to_player,
        "detach_from_player",
        (const boost::function<void __cdecl(char const *)> *)&v38,
        0,
        command_type_engine_internal);
      if ( v38.vtable && ((int)v38.vtable & 1) == 0 )
      {
        v24 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)v38.vtable & 0xFFFFFFFE);
        if ( v24 )
          v24(&v38.functor, &v38.functor, 2);
      }
      atexit(survarium::network_client::network_client_::_5_::_dynamic_atexit_destructor_for__s_detach_to_player__);
    }
  }
}
