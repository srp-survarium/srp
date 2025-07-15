void __userpurge survarium::messaging_client::messaging_client(
        survarium::game *g@<eax>,
        survarium::messaging_client *this)
{
  vostok::memory::doug_lea_allocator *v2; // eax
  boost::function<void __cdecl(void)> *v3; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v4; // ecx
  boost::function<void __cdecl(void)> *v5; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v6; // ecx
  vostok::particle::particle_action *v7; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v8; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,survarium::messaging_client>,boost::_bi::list1<boost::_bi::value<survarium::messaging_client *> > > v9; // [esp-8h] [ebp-44h]
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,survarium::messaging_client>,boost::_bi::list1<boost::_bi::value<survarium::messaging_client *> > > v10; // [esp-8h] [ebp-44h]
  int v11; // [esp+0h] [ebp-3Ch]
  int v12; // [esp+0h] [ebp-3Ch]
  boost::function<void __cdecl(void)> v13; // [esp+10h] [ebp-2Ch] BYREF
  __int64 v14; // [esp+30h] [ebp-Ch]

  this->m_game = g;
  this->m_chat_handler = g->m_chat_handler;
  this->m_connection_state = client_disconnected;
  vostok::network::tcp_packet_client::tcp_packet_client(
    &this->m_network_client,
    (vostok::network::network_world *)g->m_network_world);
  this->m_match_channel_id_ = -1;
  v2 = survarium::g_allocator;
  this->m_game_team_id = team_undefined;
  this->m_friend_list._M_impl._M_start = 0;
  this->m_friend_list._M_impl._M_finish = 0;
  this->m_friend_list._M_impl._M_end_of_storage.m_allocator = v2;
  this->m_friend_list._M_impl._M_end_of_storage._M_data = 0;
  this->m_ignore_list._M_impl._M_start = 0;
  this->m_ignore_list._M_impl._M_finish = 0;
  this->m_ignore_list._M_impl._M_end_of_storage.m_allocator = v2;
  this->m_ignore_list._M_impl._M_end_of_storage._M_data = 0;
  this->m_found_players_list._M_impl._M_start = 0;
  this->m_found_players_list._M_impl._M_finish = 0;
  this->m_found_players_list._M_impl._M_end_of_storage.m_allocator = v2;
  this->m_found_players_list._M_impl._M_end_of_storage._M_data = 0;
  this->m_important_messages._M_impl._M_start = 0;
  this->m_important_messages._M_impl._M_finish = 0;
  this->m_important_messages._M_impl._M_end_of_storage._M_data = 0;
  this->m_connection_info.session_id = -1;
  *(_DWORD *)&this->m_scheduler_identifier &= ~0x80000000;
  this->m_connection_info.port = 0;
  this->m_localization_group_channel = russian_lang_channel;
  this->m_connection_info.host[0] = 0;
  this->m_connection_info.need_resolve = 1;
  this->m_connection_info.connection_error_count = 0;
  strcpy_s(this->m_local_name, 0x40u, "local");
  v9.l_.a1_.t_ = this;
  v9.f_.f_ = survarium::messaging_client::on_connected;
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    v3,
    (boost::_bi::bind_t<void,boost::_mfi::mf0<void,survarium::messaging_client>,boost::_bi::list1<boost::_bi::value<survarium::messaging_client *> > > *)&v13,
    v9,
    v11);
  boost::function<void __cdecl (void)>::operator=(
    &v13,
    (boost::function1<void,vostok::physics::contact_point const &> *)&this->m_network_client.m_on_connected);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v4,
    (int *)&v13);
  v10.l_.a1_.t_ = this;
  v10.f_.f_ = survarium::messaging_client::on_disconnected;
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    v5,
    (boost::_bi::bind_t<void,boost::_mfi::mf0<void,survarium::messaging_client>,boost::_bi::list1<boost::_bi::value<survarium::messaging_client *> > > *)&v13,
    v10,
    v12);
  boost::function<void __cdecl (void)>::operator=(
    &v13,
    (boost::function1<void,vostok::physics::contact_point const &> *)&this->m_network_client.m_on_disconnected);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v6,
    (int *)&v13);
  LODWORD(v14) = survarium::messaging_client::on_error;
  HIDWORD(v14) = this;
  if ( Scaleform::Render::RenderEvent::GetListenerStatus(v7) )
  {
    v13.vtable = 0;
  }
  else
  {
    *(_QWORD *)&v13.functor.obj_ptr = v14;
    v13.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function2<void,enum vostok::network_core::client_error_codes_enum,boost::system::error_code>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::messaging_client,enum vostok::network_core::client_error_codes_enum,boost::system::error_code>,boost::_bi::list3<boost::_bi::value<survarium::messaging_client *>,boost::arg<1>,boost::arg<2>>>>'::`2'::stored_vtable
                                                        + 1);
  }
  boost::function<void __cdecl (boost::system::error_code)>::operator=(
    (boost::function<void __cdecl(vostok::network_core::buffer_reader &)> *)&v13,
    (boost::function1<void,vostok::physics::contact_point const &> *)&this->m_network_client.m_on_error);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v8,
    (int *)&v13);
}
