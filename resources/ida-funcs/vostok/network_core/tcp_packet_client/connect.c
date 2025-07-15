void __thiscall vostok::network_core::tcp_packet_client::connect(
        vostok::network_core::tcp_packet_client *this,
        char *host,
        unsigned __int16 port)
{
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v3; // ecx
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::jump_logic_state_landing,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::jump_logic_state_landing *>,boost::arg<1> > > f; // [esp+4h] [ebp-54h]
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::sound::sound_debug_stats>,boost::_bi::list1<boost::_bi::value<vostok::sound::sound_debug_stats *> > > result; // [esp+30h] [ebp-28h] BYREF
  boost::function<void __cdecl(void)> on_connected; // [esp+38h] [ebp-20h] BYREF

  f = (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::jump_logic_state_landing,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::jump_logic_state_landing *>,boost::arg<1> > >)*boost::bind<void,vostok::sound::sound_debug_stats,vostok::sound::sound_debug_stats *>((boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::ai::working_memory,vostok::ai::game_object const &>,boost::_bi::list2<boost::_bi::value<vostok::ai::working_memory *>,boost::arg<1> > > *)&result, (void (__thiscall *)(vostok::sound::sound_debug_stats *))vostok::network_core::tcp_packet_client::on_connected, (vostok::sound::sound_debug_stats *)this);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v3, &on_connected);
  if ( boost::detail::function::basic_vtable1<void,boost::system::error_code>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::network::http_client,boost::system::error_code>,boost::_bi::list2<boost::_bi::value<vostok::network::http_client *>,boost::arg<1>>>>(
         (boost::detail::function::basic_vtable1<enum vostok::animation::callback_return_type_enum,vostok::animation::animation_callback_params &> *)&`boost::function0<void>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::network_core::tcp_packet_client>,boost::_bi::list1<boost::_bi::value<vostok::network_core::tcp_packet_client *>>>>'::`2'::stored_vtable,
         f,
         &on_connected.functor) )
  {
    on_connected.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function0<void>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::network_core::tcp_packet_client>,boost::_bi::list1<boost::_bi::value<vostok::network_core::tcp_packet_client *>>>>'::`2'::stored_vtable.base.manager
                                                                 + 1);
  }
  else
  {
    on_connected.vtable = 0;
  }
  vostok::network_core::async_connector::connect(
    &this->m_async_connector,
    &this->m_socket,
    host,
    port,
    &on_connected,
    (boost::function<void __cdecl(unsigned int,unsigned int)> *)&this->m_on_error);
  boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&on_connected);
}
