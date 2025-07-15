void __thiscall vostok::network::tcp_packet_client::create_client(vostok::network::tcp_packet_client *this)
{
  survarium::game_camera *v1; // ecx
  vostok::memory::doug_lea_allocator *v2; // eax
  vostok::network_core::tcp_packet_client *v3; // eax
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v4; // ecx
  boost::function2<bool,char const *,enum survarium::hit_affects_type_enum> *v5; // eax
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v6; // ecx
  boost::function2<bool,char const *,enum survarium::hit_affects_type_enum> *p_m_packet_socket; // [esp-4h] [ebp-178h]
  vostok::network_core::tcp_packet_client *v8; // [esp+8h] [ebp-16Ch]
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::network::tcp_packet_client,enum vostok::network_core::client_error_codes_enum,boost::system::error_code>,boost::_bi::list3<boost::_bi::value<vostok::network::tcp_packet_client *>,boost::arg<1>,boost::arg<2> > > v10; // [esp+34h] [ebp-140h]
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::network::tcp_packet_client>,boost::_bi::list1<boost::_bi::value<vostok::network::tcp_packet_client *> > > v11; // [esp+60h] [ebp-114h]
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::network::tcp_packet_client>,boost::_bi::list1<boost::_bi::value<vostok::network::tcp_packet_client *> > > v12; // [esp+8Ch] [ebp-E8h]
  boost::_bi::value<boost::function<void __cdecl(enum vostok::handshaking_error_types_enum)> > v13; // [esp+98h] [ebp-DCh] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::network::tcp_packet_client,vostok::network_core::tcp_packet const &>,boost::_bi::list2<boost::_bi::value<vostok::network::tcp_packet_client *>,boost::arg<1> > > f; // [esp+B8h] [ebp-BCh]
  boost::asio::io_service *io_service; // [esp+C0h] [ebp-B4h]
  void *_Where; // [esp+C4h] [ebp-B0h]
  vostok::memory::doug_lea_allocator *v17; // [esp+C8h] [ebp-ACh]
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::sound::sound_debug_stats>,boost::_bi::list1<boost::_bi::value<vostok::sound::sound_debug_stats *> > > v18; // [esp+CCh] [ebp-A8h] BYREF
  boost::function2<void,enum vostok::network_core::client_error_codes_enum,boost::system::error_code> v19; // [esp+D4h] [ebp-A0h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::sound::sound_debug_stats>,boost::_bi::list1<boost::_bi::value<vostok::sound::sound_debug_stats *> > > v20; // [esp+F4h] [ebp-80h] BYREF
  boost::function0<void> v21; // [esp+FCh] [ebp-78h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::sound::sound_debug_stats>,boost::_bi::list1<boost::_bi::value<vostok::sound::sound_debug_stats *> > > v22; // [esp+11Ch] [ebp-58h] BYREF
  boost::function0<void> v23; // [esp+124h] [ebp-50h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::sound::sound_debug_stats>,boost::_bi::list1<boost::_bi::value<vostok::sound::sound_debug_stats *> > > result; // [esp+144h] [ebp-30h] BYREF
  boost::function1<void,vostok::network_core::tcp_packet const &> v25; // [esp+14Ch] [ebp-28h] BYREF
  vostok::network_core::tcp_packet_client *v26; // [esp+16Ch] [ebp-8h]
  char v27; // [esp+173h] [ebp-1h]

  v27 = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  survarium::weapon_user_dead_state::finalize(v1);
  v17 = v2;
  _Where = vostok::memory::doug_lea_allocator::malloc_impl(v2, 0x988u);
  v26 = (vostok::network_core::tcp_packet_client *)operator new(0x988u, _Where);
  if ( v26 )
  {
    io_service = this->m_world->m_io_service;
    vostok::network_core::tcp_packet_client::tcp_packet_client(v26, io_service);
    v8 = v3;
  }
  else
  {
    v8 = 0;
  }
  this->m_client = v8;
  f = (boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::network::tcp_packet_client,vostok::network_core::tcp_packet const &>,boost::_bi::list2<boost::_bi::value<vostok::network::tcp_packet_client *>,boost::arg<1> > >)*boost::bind<void,vostok::sound::sound_debug_stats,vostok::sound::sound_debug_stats *>((boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::ai::working_memory,vostok::ai::game_object const &>,boost::_bi::list2<boost::_bi::value<vostok::ai::working_memory *>,boost::arg<1> > > *)&result, (void (__thiscall *)(vostok::sound::sound_debug_stats *))vostok::network::tcp_packet_client::on_packet_received, (vostok::sound::sound_debug_stats *)this);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v4, &v25);
  boost::function1<void,vostok::network_core::tcp_packet const &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::network::tcp_packet_client,vostok::network_core::tcp_packet const &>,boost::_bi::list2<boost::_bi::value<vostok::network::tcp_packet_client *>,boost::arg<1>>>>(
    &v25,
    f);
  p_m_packet_socket = (boost::function2<bool,char const *,enum survarium::hit_affects_type_enum> *)&this->m_client->m_packet_socket;
  boost::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>(
    &v13,
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v25);
  boost::function1<unsigned int,char const *>::swap(v5, p_m_packet_socket);
  boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&v13);
  boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&v25);
  v12 = (boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::network::tcp_packet_client>,boost::_bi::list1<boost::_bi::value<vostok::network::tcp_packet_client *> > >)*boost::bind<void,vostok::sound::sound_debug_stats,vostok::sound::sound_debug_stats *>((boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::ai::working_memory,vostok::ai::game_object const &>,boost::_bi::list2<boost::_bi::value<vostok::ai::working_memory *>,boost::arg<1> > > *)&v22, (void (__thiscall *)(vostok::sound::sound_debug_stats *))vostok::network::tcp_packet_client::on_connected, (vostok::sound::sound_debug_stats *)this);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)v12.f_.f_,
    &v23);
  boost::function0<void>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::network::tcp_packet_client>,boost::_bi::list1<boost::_bi::value<vostok::network::tcp_packet_client *>>>>(
    &v23,
    v12);
  boost::function<void __cdecl (void)>::operator=(
    &this->m_client->m_on_connected,
    (const boost::function<void __cdecl(void)> *)&v23);
  boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&v23);
  v11 = (boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::network::tcp_packet_client>,boost::_bi::list1<boost::_bi::value<vostok::network::tcp_packet_client *> > >)*boost::bind<void,vostok::sound::sound_debug_stats,vostok::sound::sound_debug_stats *>((boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::ai::working_memory,vostok::ai::game_object const &>,boost::_bi::list2<boost::_bi::value<vostok::ai::working_memory *>,boost::arg<1> > > *)&v20, (void (__thiscall *)(vostok::sound::sound_debug_stats *))vostok::network::tcp_packet_client::on_disconnected, (vostok::sound::sound_debug_stats *)this);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)v11.f_.f_,
    &v21);
  boost::function0<void>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::network::tcp_packet_client>,boost::_bi::list1<boost::_bi::value<vostok::network::tcp_packet_client *>>>>(
    &v21,
    v11);
  boost::function<void __cdecl (void)>::operator=(
    &this->m_client->m_on_disconnected,
    (const boost::function<void __cdecl(void)> *)&v21);
  boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&v21);
  v10 = (boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::network::tcp_packet_client,enum vostok::network_core::client_error_codes_enum,boost::system::error_code>,boost::_bi::list3<boost::_bi::value<vostok::network::tcp_packet_client *>,boost::arg<1>,boost::arg<2> > >)*boost::bind<void,vostok::sound::sound_debug_stats,vostok::sound::sound_debug_stats *>((boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::ai::working_memory,vostok::ai::game_object const &>,boost::_bi::list2<boost::_bi::value<vostok::ai::working_memory *>,boost::arg<1> > > *)&v18, (void (__thiscall *)(vostok::sound::sound_debug_stats *))vostok::network::tcp_packet_client::on_error, (vostok::sound::sound_debug_stats *)this);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)v10.f_.f_,
    &v19);
  boost::function2<void,enum vostok::network_core::client_error_codes_enum,boost::system::error_code>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::network::tcp_packet_client,enum vostok::network_core::client_error_codes_enum,boost::system::error_code>,boost::_bi::list3<boost::_bi::value<vostok::network::tcp_packet_client *>,boost::arg<1>,boost::arg<2>>>>(
    &v19,
    v10);
  boost::function<void __cdecl (unsigned char,vostok::network_core::packet_reader &)>::operator=(
    (boost::function<void __cdecl(unsigned int,unsigned int)> *)&v19,
    (boost::function2<void,unsigned int,unsigned int> *)&this->m_client->m_on_error);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v6,
    (int *)&v19);
}
