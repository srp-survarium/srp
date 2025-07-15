void __userpurge survarium::lobby_client::lobby_client(survarium::game *g@<eax>, survarium::lobby_player_profile *this)
{
  vostok::memory::doug_lea_allocator *v3; // ecx
  boost::function<void __cdecl(void)> *v4; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v5; // ecx
  boost::function<void __cdecl(void)> *v6; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v7; // ecx
  vostok::particle::particle_action *v8; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v9; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,survarium::lobby_client>,boost::_bi::list1<boost::_bi::value<survarium::lobby_client *> > > v10; // [esp-8h] [ebp-44h]
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,survarium::lobby_client>,boost::_bi::list1<boost::_bi::value<survarium::lobby_client *> > > v11; // [esp-8h] [ebp-44h]
  int v12; // [esp+0h] [ebp-3Ch]
  int v13; // [esp+0h] [ebp-3Ch]
  boost::function<void __cdecl(void)> v14; // [esp+10h] [ebp-2Ch] BYREF
  __int64 v15; // [esp+30h] [ebp-Ch]
  survarium::lobby_player_profile *p_m_last; // [esp+44h] [ebp+8h]

  *(_DWORD *)&this->profile_name[56] = g;
  vostok::network::tcp_packet_client::tcp_packet_client(
    (vostok::network::tcp_packet_client *)&this->slots[8],
    (vostok::network::network_world *)g->m_network_world);
  this->slots[16].id = 0;
  this->slots[18].id = 0;
  this->slots[20].id = 0;
  this->slots[22].id = 3;
  LODWORD(this->modifiers.m_static_modifiers[0]) = 3;
  LOBYTE(this->slots[22].dict_id) = 0;
  this->modifiers.m_static_modifiers[1] = 0.0;
  this->modifiers.m_static_modifiers[2] = 0.0;
  this->modifiers.m_static_modifiers[3] = 0.0;
  this->modifiers.m_static_modifiers[4] = 0.0;
  this->team = -1;
  *(_DWORD *)&this->is_local = -1;
  LODWORD(this->modifiers.m_static_modifiers[5]) = &this->modifiers.m_static_modifiers[8];
  LODWORD(this->modifiers.m_static_modifiers[6]) = &this->modifiers.m_static_modifiers[8];
  LODWORD(this->modifiers.m_static_modifiers[7]) = &this->modifiers.m_modifiers.elems[1].gap20;
  LOBYTE(this->modifiers.m_static_modifiers[8]) = 0;
  LOBYTE(this->modifiers.m_static_modifiers[8]) = 0;
  this->modifiers.m_modifiers.elems[1].gap20 = 0;
  p_m_last = (survarium::lobby_player_profile *)&this->modifiers.m_modifiers.elems[1].m_last;
  HIDWORD(v15) = 7;
  do
  {
    survarium::lobby_player_profile::lobby_player_profile(p_m_last++);
    --HIDWORD(v15);
  }
  while ( v15 >= 0 );
  v3 = survarium::g_allocator;
  this[8].modifiers.m_modifiers.elems[1].m_last = 0;
  *((_DWORD *)&this[8].modifiers.m_modifiers.elems[1].m_last + 1) = 0;
  this[8].modifiers.m_modifiers.elems[2].m_size = (unsigned int)v3;
  *((_DWORD *)&this[8].modifiers.m_modifiers.elems[2].vostok::size_policy + 1) = 0;
  LODWORD(this[8].modifiers.m_modifiers.elems[2].m_mutex.m_mutex[0]) = 0;
  BYTE4(this[8].modifiers.m_modifiers.elems[2].m_mutex.m_mutex[0]) = 0;
  LODWORD(this[8].modifiers.m_modifiers.elems[2].m_mutex.m_mutex[1]) = 0;
  BYTE4(this[8].modifiers.m_modifiers.elems[2].m_mutex.m_mutex[1]) = 0;
  LODWORD(this[8].modifiers.m_modifiers.elems[5].m_mutex.m_mutex[0]) = 0;
  HIDWORD(this[8].modifiers.m_modifiers.elems[5].m_mutex.m_mutex[0]) = 0;
  LOBYTE(this[8].modifiers.m_modifiers.elems[5].m_mutex.m_mutex[1]) = 0;
  HIDWORD(this[8].modifiers.m_modifiers.elems[5].m_mutex.m_mutex[1]) = (char *)this + 12896;
  LODWORD(this[8].modifiers.m_modifiers.elems[5].m_mutex.m_mutex[2]) = (char *)this + 12896;
  HIDWORD(this[8].modifiers.m_modifiers.elems[5].m_mutex.m_mutex[2]) = (char *)this + 13136;
  *(_DWORD *)&this[8].modifiers.m_modifiers.elems[10].gap20 = -1;
  LOBYTE(this[8].modifiers.m_modifiers.elems[10].m_first) = 0;
  this[8].modifiers.m_modifiers.elems[10].m_last = 0;
  *((_BYTE *)&this[8].modifiers.m_modifiers.elems[10].m_last + 4) = 0;
  this[8].modifiers.m_modifiers.elems[11].m_size = 0;
  *((_DWORD *)&this[8].modifiers.m_modifiers.elems[11].vostok::size_policy + 1) = 0;
  LODWORD(this[8].modifiers.m_modifiers.elems[11].m_mutex.m_mutex[0]) = v3;
  HIDWORD(this[8].modifiers.m_modifiers.elems[11].m_mutex.m_mutex[0]) = 0;
  LOWORD(this->slots[0].condition_or_stack) = 0;
  BYTE4(this[8].modifiers.m_modifiers.elems[11].m_mutex.m_mutex[2]) = 0;
  *(_DWORD *)&this[8].modifiers.m_modifiers.elems[11].gap20 = 0;
  this[8].modifiers.m_modifiers.elems[11].m_first = 0;
  LOBYTE(this[8].modifiers.m_modifiers.elems[11].m_last) = 0;
  *(_DWORD *)&this->profile_name[60] = -1;
  BYTE2(this->slots[0].condition_or_stack) = 0;
  LOBYTE(this->slots[7].id) = 1;
  this->slots[7].amount_in_inventory = 0;
  memset((int)&this[8].modifiers.m_modifiers.elems[2].m_mutex.m_mutex[2], 0, 0x80u);
  v10.l_.a1_.t_ = (survarium::lobby_client *)this;
  v10.f_.f_ = survarium::lobby_client::on_connected;
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    v4,
    (boost::_bi::bind_t<void,boost::_mfi::mf0<void,survarium::lobby_client>,boost::_bi::list1<boost::_bi::value<survarium::lobby_client *> > > *)&v14,
    v10,
    v12);
  boost::function<void __cdecl (void)>::operator=(
    &v14,
    (boost::function1<void,vostok::physics::contact_point const &> *)&this->slots[10]);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v5,
    (int *)&v14);
  v11.l_.a1_.t_ = (survarium::lobby_client *)this;
  v11.f_.f_ = survarium::lobby_client::on_disconnected;
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    v6,
    (boost::_bi::bind_t<void,boost::_mfi::mf0<void,survarium::lobby_client>,boost::_bi::list1<boost::_bi::value<survarium::lobby_client *> > > *)&v14,
    v11,
    v13);
  boost::function<void __cdecl (void)>::operator=(
    &v14,
    (boost::function1<void,vostok::physics::contact_point const &> *)&this->slots[12]);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v7,
    (int *)&v14);
  LODWORD(v15) = survarium::lobby_client::on_error;
  HIDWORD(v15) = this;
  if ( Scaleform::Render::RenderEvent::GetListenerStatus(v8) )
  {
    v14.vtable = 0;
  }
  else
  {
    *(_QWORD *)&v14.functor.obj_ptr = v15;
    v14.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function2<void,enum vostok::network_core::client_error_codes_enum,boost::system::error_code>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::lobby_client,enum vostok::network_core::client_error_codes_enum,boost::system::error_code>,boost::_bi::list3<boost::_bi::value<survarium::lobby_client *>,boost::arg<1>,boost::arg<2>>>>'::`2'::stored_vtable
                                                        + 1);
  }
  boost::function<void __cdecl (boost::system::error_code)>::operator=(
    (boost::function<void __cdecl(vostok::network_core::buffer_reader &)> *)&v14,
    (boost::function1<void,vostok::physics::contact_point const &> *)&this->slots[14]);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v9,
    (int *)&v14);
}
