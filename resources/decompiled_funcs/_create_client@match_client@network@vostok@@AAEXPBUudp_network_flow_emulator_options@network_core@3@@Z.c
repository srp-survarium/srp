void __thiscall vostok::network::match_client::create_client(
        vostok::network::match_client *this,
        const vostok::network_core::udp_network_flow_emulator_options *options)
{
  survarium::game_camera *v2; // ecx
  vostok::memory::doug_lea_allocator *v3; // eax
  vostok::network::match_client_impl *v4; // eax
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v5; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v6; // ecx
  vostok::network::match_client_impl *v7; // [esp+8h] [ebp-D4h]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::network::match_client,enum vostok::network_core::disconnect_event_types_enum>,boost::_bi::list2<boost::_bi::value<vostok::network::match_client *>,boost::arg<1> > > v9; // [esp+54h] [ebp-88h]
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::jump_logic_state_landing,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::jump_logic_state_landing *>,boost::arg<1> > > f; // [esp+64h] [ebp-78h]
  int *_Where; // [esp+74h] [ebp-68h]
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::sound::sound_debug_stats>,boost::_bi::list1<boost::_bi::value<vostok::sound::sound_debug_stats *> > > v12; // [esp+7Ch] [ebp-60h] BYREF
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> v13; // [esp+84h] [ebp-58h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::sound::sound_debug_stats>,boost::_bi::list1<boost::_bi::value<vostok::sound::sound_debug_stats *> > > result; // [esp+A4h] [ebp-38h] BYREF
  boost::function<void __cdecl(unsigned char,vostok::network_core::packet_reader &)> on_packet_received; // [esp+ACh] [ebp-30h] BYREF
  vostok::network::match_client_impl *v16; // [esp+D0h] [ebp-Ch]
  char v17; // [esp+D7h] [ebp-5h]
  vostok::network::match_client_impl *temp; // [esp+D8h] [ebp-4h]

  v17 = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  survarium::weapon_user_dead_state::finalize(v2);
  _Where = vostok::memory::doug_lea_allocator::malloc_impl(v3, (unsigned int)&loc_258BA8);
  v16 = (vostok::network::match_client_impl *)operator new((unsigned int)&loc_258BA8, _Where);
  if ( v16 )
  {
    vostok::network::match_client_impl::match_client_impl(
      v16,
      this->m_world->m_io_service,
      this->m_packets_orderer,
      options);
    v7 = v4;
  }
  else
  {
    v7 = 0;
  }
  temp = v7;
  vostok::threading::interlocked_exchange_pointer((volatile int *)this->m_client, (int)v7);
  f = (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::jump_logic_state_landing,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::jump_logic_state_landing *>,boost::arg<1> > >)*boost::bind<void,vostok::sound::sound_debug_stats,vostok::sound::sound_debug_stats *>((boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::ai::working_memory,vostok::ai::game_object const &>,boost::_bi::list2<boost::_bi::value<vostok::ai::working_memory *>,boost::arg<1> > > *)&result, (void (__thiscall *)(vostok::sound::sound_debug_stats *))vostok::network::match_client::on_packet_received, (vostok::sound::sound_debug_stats *)this);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)f.f_.f_,
    &on_packet_received);
  if ( boost::detail::function::basic_vtable1<void,boost::system::error_code>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::network::http_client,boost::system::error_code>,boost::_bi::list2<boost::_bi::value<vostok::network::http_client *>,boost::arg<1>>>>(
         (boost::detail::function::basic_vtable1<enum vostok::animation::callback_return_type_enum,vostok::animation::animation_callback_params &> *)&`boost::function2<void,unsigned char,vostok::network_core::packet_reader &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::network::match_client,unsigned char,vostok::network_core::packet_reader &>,boost::_bi::list3<boost::_bi::value<vostok::network::match_client *>,boost::arg<1>,boost::arg<2>>>>'::`2'::stored_vtable,
         f,
         &on_packet_received.functor) )
  {
    on_packet_received.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function2<void,unsigned char,vostok::network_core::packet_reader &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::network::match_client,unsigned char,vostok::network_core::packet_reader &>,boost::_bi::list3<boost::_bi::value<vostok::network::match_client *>,boost::arg<1>,boost::arg<2>>>>'::`2'::stored_vtable.base.manager
                                                                       + 1);
  }
  else
  {
    on_packet_received.vtable = 0;
  }
  vostok::network::match_client_impl::set_on_packet_received(*this->m_client, &on_packet_received);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v5,
    (int *)&on_packet_received);
  v9 = (boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::network::match_client,enum vostok::network_core::disconnect_event_types_enum>,boost::_bi::list2<boost::_bi::value<vostok::network::match_client *>,boost::arg<1> > >)*boost::bind<void,vostok::sound::sound_debug_stats,vostok::sound::sound_debug_stats *>((boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::ai::working_memory,vostok::ai::game_object const &>,boost::_bi::list2<boost::_bi::value<vostok::ai::working_memory *>,boost::arg<1> > > *)&v12, (void (__thiscall *)(vostok::sound::sound_debug_stats *))vostok::network::match_client::on_disconnect, (vostok::sound::sound_debug_stats *)this);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)v9.f_.f_,
    &v13);
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::network::match_client,enum vostok::network_core::disconnect_event_types_enum>,boost::_bi::list2<boost::_bi::value<vostok::network::match_client *>,boost::arg<1>>>>(
    &v13,
    v9);
  boost::function<void __cdecl (unsigned char,vostok::network_core::packet_reader &)>::operator=(
    (boost::function<void __cdecl(unsigned int,unsigned int)> *)&v13,
    (boost::function2<void,unsigned int,unsigned int> *)((char *)&loc_25800F + (unsigned int)*this->m_client + 1));
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v6,
    (int *)&v13);
}
