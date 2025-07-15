void __thiscall vostok::network::match_client_impl::disconnect(vostok::network::match_client_impl *this)
{
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v1; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v2; // ecx
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::jump_logic_state_landing,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::jump_logic_state_landing *>,boost::arg<1> > > f; // [esp+4Ch] [ebp-44h]
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::sound::sound_debug_stats>,boost::_bi::list1<boost::_bi::value<vostok::sound::sound_debug_stats *> > > result; // [esp+68h] [ebp-28h] BYREF
  boost::function<void __cdecl(unsigned int,unsigned int)> v6; // [esp+70h] [ebp-20h] BYREF

  *(_DWORD *)&this->m_packets_storage.elems[0][(_DWORD)&loc_258B9D + 3] = 0;
  f = (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::jump_logic_state_landing,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::jump_logic_state_landing *>,boost::arg<1> > >)*boost::bind<void,vostok::sound::sound_debug_stats,vostok::sound::sound_debug_stats *>((boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::ai::working_memory,vostok::ai::game_object const &>,boost::_bi::list2<boost::_bi::value<vostok::ai::working_memory *>,boost::arg<1> > > *)&result, (void (__thiscall *)(vostok::sound::sound_debug_stats *))vostok::network::match_client_impl::on_packet_received, (vostok::sound::sound_debug_stats *)this);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v1, &v6);
  if ( boost::detail::function::basic_vtable1<void,boost::system::error_code>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::network::http_client,boost::system::error_code>,boost::_bi::list2<boost::_bi::value<vostok::network::http_client *>,boost::arg<1>>>>(
         (boost::detail::function::basic_vtable1<enum vostok::animation::callback_return_type_enum,vostok::animation::animation_callback_params &> *)&`boost::function2<void,unsigned char,vostok::network_core::packet_reader &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::network::match_client_impl,unsigned char,vostok::network_core::packet_reader &>,boost::_bi::list3<boost::_bi::value<vostok::network::match_client_impl *>,boost::arg<1>,boost::arg<2>>>>'::`2'::stored_vtable,
         f,
         &v6.functor) )
  {
    v6.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function2<void,unsigned char,vostok::network_core::packet_reader &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::network::match_client_impl,unsigned char,vostok::network_core::packet_reader &>,boost::_bi::list3<boost::_bi::value<vostok::network::match_client_impl *>,boost::arg<1>,boost::arg<2>>>>'::`2'::stored_vtable.base.manager
                                                       + 1);
  }
  else
  {
    v6.vtable = 0;
  }
  boost::function<void __cdecl (unsigned char,vostok::network_core::packet_reader &)>::operator=(
    &v6,
    (boost::function2<void,unsigned int,unsigned int> *)((char *)this + (_DWORD)&loc_25856F + 1));
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v2,
    (int *)&v6);
  vostok::network_core::udp_match_client::disconnect((vostok::network_core::udp_match_client *)((char *)this
                                                                                              + (_DWORD)&loc_258034
                                                                                              + 4));
}
