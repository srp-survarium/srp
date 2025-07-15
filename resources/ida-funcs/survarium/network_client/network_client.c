void __thiscall survarium::network_client::network_client(
        survarium::network_client *this,
        survarium::game *g,
        survarium::game *is_spectator,
        unsigned __int8 a4)
{
  vostok::command_line::key *v4; // ecx
  vostok::network_core::udp_match_stats *v5; // ecx
  survarium::game_statistics_handler *v6; // ecx
  vostok::journaling::journal_usage_enum v7; // eax
  vostok::memory::doug_lea_allocator *v8; // esi
  char *v9; // eax
  vostok::memory::doug_lea_allocator *v10; // ecx
  char *v11; // eax
  int v12; // eax
  char *v13; // eax
  vostok::memory::doug_lea_allocator *v14; // ecx
  char *v15; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v16; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v17; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v18; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v19; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v20; // ecx
  vostok::console_commands::cc_delegate *v21; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v22; // ecx
  vostok::console_commands::cc_delegate *v23; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v24; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,survarium::network_client>,boost::_bi::list1<boost::_bi::value<survarium::network_client *> > > v25; // [esp-14h] [ebp-68h]
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,survarium::network_client>,boost::_bi::list1<boost::_bi::value<survarium::network_client *> > > v26; // [esp-14h] [ebp-68h]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::base_network_client,char const *>,boost::_bi::list2<boost::_bi::value<survarium::network_client *>,boost::arg<1> > > v27; // [esp-14h] [ebp-68h]
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,survarium::base_network_client>,boost::_bi::list1<boost::_bi::value<survarium::network_client *> > > v28; // [esp-14h] [ebp-68h]
  const char *v29; // [esp+0h] [ebp-54h]
  const char *v30; // [esp+4h] [ebp-50h]
  unsigned int v31; // [esp+8h] [ebp-4Ch]
  boost::function<void __cdecl(void)> f; // [esp+10h] [ebp-44h] BYREF
  boost::function<void __cdecl(vostok::network_core::buffer_reader &)> v33; // [esp+30h] [ebp-24h] BYREF

  survarium::base_network_client::base_network_client(this, is_spectator);
  g->vostok::engine_user::world::__vftable = (survarium::game_vtbl *)&survarium::network_client::`vftable';
  vostok::network::login_client::login_client(
    (vostok::network::network_world *)is_spectator->m_network_world,
    v4,
    (vostok::network::login_client *)&g->m_timer.m_stop_floating_ticks);
  survarium::lobby_client::lobby_client(
    is_spectator,
    (survarium::lobby_client *)&g->m_game_world.m_target_quality_level);
  *(_DWORD *)&g->m_game_world.m_third_person_game_effect_presenters[11188] = 0;
  survarium::messaging_client::messaging_client(
    is_spectator,
    (survarium::messaging_client *)&g->m_game_world.m_third_person_game_effect_presenters[11196]);
  vostok::network::http_client::http_client(
    (vostok::network::http_client *)&g->m_network_client_options.m_buffer[188],
    (vostok::network::network_world *)is_spectator->m_network_world);
  vostok::network_core::udp_match_stats::udp_match_stats(v5, &g->m_network_client_options.m_buffer[300]);
  survarium::game_statistics_handler::game_statistics_handler(
    v6,
    (unsigned int)&g->m_network_client_options.m_buffer[428]);
  *(_DWORD *)&g[1].m_game_world.m_third_person_game_effect_presenters[2940] = 0;
  *(_DWORD *)&g[1].m_game_world.m_third_person_game_effect_presenters[2944] = 0;
  *(_DWORD *)&g[1].m_game_world.m_third_person_game_effect_presenters[2948] = 0;
  *(_DWORD *)&g[1].m_game_world.m_third_person_game_effect_presenters[2952] = 0;
  *(_DWORD *)&g[1].m_game_world.m_third_person_game_effect_presenters[2956] = 0;
  *(_DWORD *)&g[1].m_game_world.m_third_person_game_effect_presenters[2960] = 0;
  *(_DWORD *)&g[1].m_game_world.m_third_person_game_effect_presenters[2964] = 0;
  g[1].m_game_world.m_third_person_game_effect_presenters[2972] = a4;
  v7 = vostok::core::journal_usage();
  v8 = survarium::g_allocator;
  if ( v7 == replay_journal )
  {
    v9 = type_info::raw_name(&vostok::journaling::match_client `RTTI Type Descriptor');
    v11 = vostok::memory::doug_lea_allocator::malloc_impl(v10, (int)v8, 0x7A88u, v9, v29, v30, v31);
    if ( v11 )
      vostok::journaling::match_client::match_client(
        (vostok::journaling::match_client *)is_spectator,
        (vostok::network::world *)v11,
        (int)is_spectator->m_network_world);
    else
      v12 = 0;
    *(_DWORD *)&g[1].m_game_world.m_third_person_game_effect_presenters[2968] = 0;
  }
  else
  {
    v13 = type_info::raw_name(&survarium::match_client `RTTI Type Descriptor');
    v15 = vostok::memory::doug_lea_allocator::malloc_impl(v14, (int)v8, 0x75D0u, v13, v29, v30, v31);
    if ( v15 )
      survarium::match_client::match_client(
        (survarium::match_client *)is_spectator,
        (int)v15,
        (vostok::network_core::udp_match_packets_orderer *)is_spectator->m_network_world);
    else
      v12 = 0;
  }
  *(_DWORD *)&g->m_game_world.m_third_person_game_effect_presenters[11188] = v12;
  v33.functor.vostok_pointer_size_alignment[2] = survarium::network_client::on_match_packet_received;
  v33.functor.vostok_pointer_size_alignment[3] = 0;
  v33.functor.bound_memfunc_ptr.obj_ptr = g;
  f.functor.vostok_pointer_size_alignment[2] = survarium::network_client::on_match_packet_received;
  f.functor.vostok_pointer_size_alignment[3] = 0;
  *((_QWORD *)&f.functor.data + 2) = __PAIR64__(
                                       (unsigned int)v33.functor.vostok_pointer_size_alignment[5],
                                       (unsigned int)g);
  if ( Scaleform::Render::RenderEvent::GetListenerStatus(0) )
  {
    v33.vtable = 0;
  }
  else
  {
    *(_QWORD *)&v33.functor.obj_ptr = *((_QWORD *)&f.functor.data + 1);
    *((_QWORD *)&v33.functor.data + 1) = *((_QWORD *)&f.functor.data + 2);
    v33.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function2<void,unsigned char,vostok::network_core::buffer_reader &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::network_client,unsigned char,vostok::network_core::buffer_reader &>,boost::_bi::list3<boost::_bi::value<survarium::network_client *>,boost::arg<1>,boost::arg<2>>>>'::`2'::stored_vtable
                                                        + 1);
  }
  (*(void (__thiscall **)(_DWORD, boost::function<void __cdecl(vostok::network_core::buffer_reader &)> *))(**(_DWORD **)&g->m_game_world.m_third_person_game_effect_presenters[11188] + 16))(
    *(_DWORD *)&g->m_game_world.m_third_person_game_effect_presenters[11188],
    &v33);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v16,
    (int *)&v33);
  v33.functor.vostok_pointer_size_alignment[2] = survarium::network_client::on_lobby_packet_received;
  v33.functor.vostok_pointer_size_alignment[3] = 0;
  v33.functor.bound_memfunc_ptr.obj_ptr = g;
  f.functor.vostok_pointer_size_alignment[2] = survarium::network_client::on_lobby_packet_received;
  f.functor.vostok_pointer_size_alignment[3] = 0;
  *((_QWORD *)&f.functor.data + 2) = __PAIR64__(
                                       (unsigned int)v33.functor.vostok_pointer_size_alignment[5],
                                       (unsigned int)g);
  if ( Scaleform::Render::RenderEvent::GetListenerStatus(0) )
  {
    v33.vtable = 0;
  }
  else
  {
    *(_QWORD *)&v33.functor.obj_ptr = *((_QWORD *)&f.functor.data + 1);
    *((_QWORD *)&v33.functor.data + 1) = *((_QWORD *)&f.functor.data + 2);
    v33.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function1<void,vostok::network_core::buffer_reader &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::network_client,vostok::network_core::buffer_reader &>,boost::_bi::list2<boost::_bi::value<survarium::network_client *>,boost::arg<1>>>>'::`2'::stored_vtable
                                                        + 1);
  }
  boost::function<void __cdecl (boost::system::error_code)>::operator=(
    &v33,
    (boost::function1<void,vostok::physics::contact_point const &> *)&g->m_game_world.game_ui.m_hud_state.player_kd_stats[2].online);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v17,
    (int *)&v33);
  v33.functor.vostok_pointer_size_alignment[2] = survarium::network_client::on_connected_to_lobby;
  v33.functor.vostok_pointer_size_alignment[3] = 0;
  v33.functor.bound_memfunc_ptr.obj_ptr = g;
  HIDWORD(v25.f_.f_) = survarium::network_client::on_connected_to_lobby;
  *(_QWORD *)&v25.l_.a1_.t_ = __PAIR64__((unsigned int)g, 0);
  LODWORD(v25.f_.f_) = &f;
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    0,
    v25,
    (int)v33.functor.vostok_pointer_size_alignment[5]);
  boost::function<void __cdecl (void)>::operator=(
    &f,
    (boost::function1<void,vostok::physics::contact_point const &> *)&g->m_game_world.game_ui.m_hud_state.player_kd_stats[6].online);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v18,
    (int *)&f);
  v33.functor.vostok_pointer_size_alignment[2] = survarium::network_client::on_disconnected_from_lobby;
  v33.functor.vostok_pointer_size_alignment[3] = 0;
  v33.functor.bound_memfunc_ptr.obj_ptr = g;
  HIDWORD(v26.f_.f_) = survarium::network_client::on_disconnected_from_lobby;
  *(_QWORD *)&v26.l_.a1_.t_ = __PAIR64__((unsigned int)g, 0);
  LODWORD(v26.f_.f_) = &f;
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    0,
    v26,
    (int)v33.functor.vostok_pointer_size_alignment[5]);
  boost::function<void __cdecl (void)>::operator=(
    &f,
    (boost::function1<void,vostok::physics::contact_point const &> *)&g->m_game_world.game_ui.m_hud_state.player_kd_stats[10].online);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v19,
    (int *)&f);
  v33.functor.vostok_pointer_size_alignment[2] = survarium::network_client::on_http_error;
  v33.functor.vostok_pointer_size_alignment[3] = 0;
  v33.functor.bound_memfunc_ptr.obj_ptr = g;
  f.functor.vostok_pointer_size_alignment[2] = survarium::network_client::on_http_error;
  f.functor.vostok_pointer_size_alignment[3] = 0;
  *((_QWORD *)&f.functor.data + 2) = __PAIR64__(
                                       (unsigned int)v33.functor.vostok_pointer_size_alignment[5],
                                       (unsigned int)g);
  if ( Scaleform::Render::RenderEvent::GetListenerStatus(0) )
  {
    v33.vtable = 0;
  }
  else
  {
    *(_QWORD *)&v33.functor.obj_ptr = *((_QWORD *)&f.functor.data + 1);
    *((_QWORD *)&v33.functor.data + 1) = *((_QWORD *)&f.functor.data + 2);
    v33.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function1<void,boost::system::error_code>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::network_client,boost::system::error_code>,boost::_bi::list2<boost::_bi::value<survarium::network_client *>,boost::arg<1>>>>'::`2'::stored_vtable
                                                        + 1);
  }
  boost::function<void __cdecl (boost::system::error_code)>::operator=(
    &v33,
    (boost::function1<void,vostok::physics::contact_point const &> *)&g->m_network_client_options.m_buffer[228]);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v20,
    (int *)&v33);
  if ( g[1].m_game_world.m_third_person_game_effect_presenters[2972] )
  {
    if ( (_S9_7 & 1) == 0 )
    {
      _S9_7 |= 1u;
      v33.functor.vostok_pointer_size_alignment[2] = survarium::base_network_client::attach_to_player_cc;
      v33.functor.vostok_pointer_size_alignment[3] = 0;
      v33.functor.bound_memfunc_ptr.obj_ptr = g;
      HIDWORD(v27.f_.f_) = survarium::base_network_client::attach_to_player_cc;
      *(_QWORD *)&v27.l_.a1_.t_ = __PAIR64__((unsigned int)g, 0);
      LODWORD(v27.f_.f_) = &f;
      boost::function<void __cdecl (char const *)>::function<void __cdecl (char const *)>(
        0,
        v27,
        (int)v33.functor.vostok_pointer_size_alignment[5]);
      vostok::console_commands::cc_delegate::cc_delegate(
        v21,
        (int)&s_attach_to_player,
        "attach_to_player",
        (boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)&f,
        1,
        command_type_engine_internal);
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        v22,
        (int *)&f);
      atexit((int (__cdecl *)())survarium::network_client::network_client_::_9_::_dynamic_atexit_destructor_for__s_attach_to_player__);
    }
    if ( (_S9_7 & 2) == 0 )
    {
      _S9_7 |= 2u;
      v33.functor.vostok_pointer_size_alignment[2] =  __thiscall survarium::base_network_client::`vcall'{92,{flat}};
      v33.functor.vostok_pointer_size_alignment[3] = 0;
      v33.functor.bound_memfunc_ptr.obj_ptr = g;
      HIDWORD(v28.f_.f_) =  __thiscall survarium::base_network_client::`vcall'{92,{flat}};
      *(_QWORD *)&v28.l_.a1_.t_ = __PAIR64__((unsigned int)g, 0);
      LODWORD(v28.f_.f_) = &f;
      boost::function<void __cdecl (char const *)>::function<void __cdecl (char const *)>(
        0,
        v28,
        (int)v33.functor.vostok_pointer_size_alignment[5]);
      vostok::console_commands::cc_delegate::cc_delegate(
        v23,
        (int)&s_detach_to_player,
        "detach_from_player",
        (boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)&f,
        0,
        command_type_engine_internal);
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        v24,
        (int *)&f);
      atexit((int (__cdecl *)())survarium::network_client::network_client_::_9_::_dynamic_atexit_destructor_for__s_detach_to_player__);
    }
  }
}
