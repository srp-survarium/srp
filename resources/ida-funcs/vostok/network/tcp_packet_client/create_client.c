void __thiscall vostok::network::tcp_packet_client::create_client(vostok::network::tcp_packet_client *this)
{
  vostok::memory::doug_lea_allocator *v1; // esi
  char *v3; // eax
  vostok::memory::doug_lea_allocator *v4; // ecx
  char *v5; // eax
  vostok::particle::particle_action *v6; // ecx
  int v7; // eax
  int v8; // esi
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v9; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v10; // ecx
  boost::function<void __cdecl(void)> *v11; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v12; // ecx
  boost::function<void __cdecl(void)> *v13; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v14; // ecx
  vostok::particle::particle_action *v15; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v16; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::network::tcp_packet_client>,boost::_bi::list1<boost::_bi::value<vostok::network::tcp_packet_client *> > > v17; // [esp-8h] [ebp-60h]
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::network::tcp_packet_client>,boost::_bi::list1<boost::_bi::value<vostok::network::tcp_packet_client *> > > v18; // [esp-8h] [ebp-60h]
  const char *v19; // [esp+0h] [ebp-58h]
  int v20; // [esp+0h] [ebp-58h]
  int v21; // [esp+0h] [ebp-58h]
  const char *v22; // [esp+4h] [ebp-54h]
  unsigned int v23; // [esp+8h] [ebp-50h]
  __int64 v24; // [esp+10h] [ebp-48h]
  __int64 v25; // [esp+10h] [ebp-48h]
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> v26; // [esp+18h] [ebp-40h] BYREF
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> f; // [esp+38h] [ebp-20h] BYREF

  v1 = vostok::network::g_allocator;
  v3 = type_info::raw_name(&vostok::network_core::tcp_packet_client `RTTI Type Descriptor');
  v5 = vostok::memory::doug_lea_allocator::malloc_impl(v4, (int)v1, 0x45F8u, v3, v19, v22, v23);
  if ( v5 )
  {
    vostok::network_core::tcp_packet_client::tcp_packet_client(
      (vostok::network_core::tcp_packet_client *)this->m_world,
      (int)v5,
      this->m_world->m_io_service);
    v8 = v7;
  }
  else
  {
    v8 = 0;
  }
  LODWORD(v24) = vostok::network::tcp_packet_client::on_packet_received;
  this->m_client = (vostok::network_core::tcp_packet_client *)v8;
  HIDWORD(v24) = this;
  if ( Scaleform::Render::RenderEvent::GetListenerStatus(v6) )
  {
    v26.vtable = 0;
  }
  else
  {
    *(_QWORD *)&v26.functor.obj_ptr = v24;
    v26.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function1<void,vostok::network_core::tcp_packet const &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::network::tcp_packet_client,vostok::network_core::tcp_packet const &>,boost::_bi::list2<boost::_bi::value<vostok::network::tcp_packet_client *>,boost::arg<1>>>>'::`2'::stored_vtable
                                                        + 1);
  }
  boost::function1<void,boost::system::error_code>::function1<void,boost::system::error_code>(&v26, &f);
  boost::function4<void,char const *,enum survarium::hit_type_enum,float &,float &>::swap(
    (boost::function1<void,vostok::physics::contact_point const &> *)(v8 + 72),
    (boost::function1<void,vostok::physics::contact_point const &> *)&f);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v9, (int *)&f);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v10,
    (int *)&v26);
  v17.l_.a1_.t_ = this;
  v17.f_.f_ = vostok::network::tcp_packet_client::on_connected;
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    v11,
    (boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::network::tcp_packet_client>,boost::_bi::list1<boost::_bi::value<vostok::network::tcp_packet_client *> > > *)&f,
    v17,
    v20);
  boost::function<void __cdecl (void)>::operator=(
    (boost::function<void __cdecl(void)> *)&f,
    (boost::function1<void,vostok::physics::contact_point const &> *)&this->m_client->m_on_connected);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v12,
    (int *)&f);
  v18.l_.a1_.t_ = this;
  v18.f_.f_ = vostok::network::tcp_packet_client::on_disconnected;
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    v13,
    (boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::network::tcp_packet_client>,boost::_bi::list1<boost::_bi::value<vostok::network::tcp_packet_client *> > > *)&f,
    v18,
    v21);
  boost::function<void __cdecl (void)>::operator=(
    (boost::function<void __cdecl(void)> *)&f,
    (boost::function1<void,vostok::physics::contact_point const &> *)&this->m_client->m_on_disconnected);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v14,
    (int *)&f);
  LODWORD(v25) = vostok::network::tcp_packet_client::on_error;
  HIDWORD(v25) = this;
  if ( Scaleform::Render::RenderEvent::GetListenerStatus(v15) )
  {
    v26.vtable = 0;
  }
  else
  {
    *(_QWORD *)&v26.functor.obj_ptr = v25;
    v26.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function2<void,enum vostok::network_core::client_error_codes_enum,boost::system::error_code>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::network::tcp_packet_client,enum vostok::network_core::client_error_codes_enum,boost::system::error_code>,boost::_bi::list3<boost::_bi::value<vostok::network::tcp_packet_client *>,boost::arg<1>,boost::arg<2>>>>'::`2'::stored_vtable
                                                        + 1);
  }
  boost::function<void __cdecl (boost::system::error_code)>::operator=(
    (boost::function<void __cdecl(vostok::network_core::buffer_reader &)> *)&v26,
    (boost::function1<void,vostok::physics::contact_point const &> *)&this->m_client->m_on_error);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v16,
    (int *)&v26);
}
