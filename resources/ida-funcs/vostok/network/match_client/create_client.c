void __thiscall vostok::network::match_client::create_client(
        vostok::network::match_client *this,
        const vostok::network_core::udp_network_flow_emulator_options *options)
{
  vostok::memory::doug_lea_allocator *v2; // esi
  char *v4; // eax
  vostok::memory::doug_lea_allocator *v5; // ecx
  vostok::memory::single_size_buffer_allocator<1364,vostok::threading::multi_threading_policy>::node *v6; // eax
  __int32 v7; // eax
  vostok::network::match_client_impl **m_client; // ecx
  vostok::network::match_client_impl *v9; // esi
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v10; // ecx
  vostok::particle::particle_action *v11; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v12; // ecx
  const char *v13; // [esp+0h] [ebp-38h]
  const char *v14; // [esp+4h] [ebp-34h]
  unsigned int v15; // [esp+8h] [ebp-30h]
  boost::function<void __cdecl(void)> v16; // [esp+18h] [ebp-20h] BYREF

  v2 = vostok::network::g_allocator;
  v4 = type_info::raw_name(&vostok::network::match_client_impl `RTTI Type Descriptor');
  v6 = (vostok::memory::single_size_buffer_allocator<1364,vostok::threading::multi_threading_policy>::node *)vostok::memory::doug_lea_allocator::malloc_impl(v5, (int)v2, (unsigned int)&loc_6EF84 + 4, v4, v13, v14, v15);
  if ( v6 )
    vostok::network::match_client_impl::match_client_impl(
      (vostok::network::match_client_impl *)this->m_world->m_io_service,
      v6,
      (vostok::memory::single_size_buffer_allocator<1364,vostok::threading::multi_threading_policy> *)this->m_world->m_io_service,
      (vostok::network_core::udp_network_flow_emulator *)this->m_packets_orderer,
      options);
  else
    v7 = 0;
  m_client = this->m_client;
  _InterlockedExchange((volatile __int32 *)m_client, v7);
  if ( Scaleform::Render::RenderEvent::GetListenerStatus((vostok::particle::particle_action *)m_client) )
  {
    v16.vtable = 0;
  }
  else
  {
    v16.functor.obj_ptr = vostok::network::match_client::on_packet_received;
    v16.functor.vostok_pointer_size_alignment[1] = this;
    v16.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function2<void,unsigned char,vostok::network_core::buffer_reader &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::network::match_client,unsigned char,vostok::network_core::buffer_reader &>,boost::_bi::list3<boost::_bi::value<vostok::network::match_client *>,boost::arg<1>,boost::arg<2>>>>'::`2'::stored_vtable
                                                        + 1);
  }
  v9 = *this->m_client;
  boost::function<void __cdecl (void)>::operator=(
    &v16,
    (boost::function1<void,vostok::physics::contact_point const &> *)((char *)&loc_6EF60 + (_DWORD)v9));
  if ( *(_DWORD *)((char *)&loc_6EF80 + (_DWORD)v9) == 2 )
    boost::function<void __cdecl (void)>::operator=(
      (boost::function<void __cdecl(void)> *)((char *)&loc_6EF60 + (_DWORD)v9),
      (boost::function1<void,vostok::physics::contact_point const &> *)((char *)&loc_55F88 + (_DWORD)v9));
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v10,
    (int *)&v16);
  if ( Scaleform::Render::RenderEvent::GetListenerStatus(v11) )
  {
    v16.vtable = 0;
  }
  else
  {
    v16.functor.obj_ptr = vostok::network::match_client::on_disconnect;
    v16.functor.vostok_pointer_size_alignment[1] = this;
    v16.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function1<void,enum vostok::network_core::disconnect_event_types_enum>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::network::match_client,enum vostok::network_core::disconnect_event_types_enum>,boost::_bi::list2<boost::_bi::value<vostok::network::match_client *>,boost::arg<1>>>>'::`2'::stored_vtable
                                                        + 1);
  }
  boost::function<void __cdecl (enum vostok::network_core::disconnect_event_types_enum)>::operator=(
    (boost::function<void __cdecl(unsigned char,short)> *)&v16,
    (boost::function1<void,vostok::physics::contact_point const &> *)((char *)&off_55438 + (unsigned int)*this->m_client));
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v12,
    (int *)&v16);
}
