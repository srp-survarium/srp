void __thiscall vostok::network::match_client::on_disconnect(
        vostok::network::match_client *this,
        vostok::network_core::tcp_packet *type)
{
  vostok::memory::doug_lea_allocator *v2; // eax
  boost::_bi::bind_t<void,boost::_mfi::mf3<void,vostok::network_core::tcp_packet_socket<boost::asio::basic_stream_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp> > >,vostok::network_core::tcp_packet const *,boost::system::error_code const &,unsigned int>,boost::_bi::list4<boost::_bi::value<vostok::network_core::tcp_packet_socket<boost::asio::basic_stream_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp> > > *>,boost::_bi::value<vostok::network_core::tcp_packet *>,boost::arg<1>,boost::arg<2> > > v4; // [esp+8h] [ebp-7Ch]
  int *_Where; // [esp+40h] [ebp-44h]
  char v6; // [esp+4Ch] [ebp-38h]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_voice,void *>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_voice *>,boost::_bi::value<void *> > > result; // [esp+50h] [ebp-34h] BYREF
  boost::function<void __cdecl(void)> f; // [esp+5Ch] [ebp-28h] BYREF
  vostok::network::response *v9; // [esp+80h] [ebp-4h]

  v6 = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  _Where = vostok::memory::doug_lea_allocator::malloc_impl(v2, 0x28u);
  v9 = (vostok::network::response *)operator new(0x28u, _Where);
  if ( v9 )
  {
    v4 = *boost::bind<void,vostok::network::match_client,vostok::network_core::udp_network_flow_emulator_options const *,vostok::network::match_client *,vostok::network_core::udp_network_flow_emulator_options const *>(
            (boost::_bi::bind_t<void,boost::_mfi::mf3<void,vostok::network_core::tcp_packet_socket<boost::asio::basic_stream_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp> > >,vostok::network_core::tcp_packet const *,boost::system::error_code const &,unsigned int>,boost::_bi::list4<boost::_bi::value<vostok::network_core::tcp_packet_socket<boost::asio::basic_stream_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp> > > *>,boost::_bi::value<vostok::network_core::tcp_packet *>,boost::arg<1>,boost::arg<2> > > *)&result,
            (void (__thiscall *)(vostok::sound::sound_voice *, void *))vostok::network::match_client::on_disconnect_impl,
            (vostok::sound::sound_voice *)this,
            type);
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)v4.l_.a1_.t_,
      &f);
    if ( boost::detail::function::basic_vtable1<void,char const *>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::network::tcp_packet_client,char const *,unsigned short>,boost::_bi::list3<boost::_bi::value<vostok::network::tcp_packet_client *>,boost::arg<1>,boost::_bi::value<unsigned short>>>>(
           (boost::detail::function::basic_vtable0<void> *)&`boost::function0<void>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::network::match_client,enum vostok::network_core::disconnect_event_types_enum>,boost::_bi::list2<boost::_bi::value<vostok::network::match_client *>,boost::_bi::value<enum vostok::network_core::disconnect_event_types_enum>>>>'::`2'::stored_vtable,
           (boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::bullet_manager,survarium::bullet_manager::bullet_functor *>,boost::_bi::list2<boost::_bi::value<survarium::bullet_manager *>,boost::_bi::value<survarium::bullet_manager::bullet_functor *> > >)v4,
           &f.functor) )
    {
      f.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function0<void>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::network::match_client,enum vostok::network_core::disconnect_event_types_enum>,boost::_bi::list2<boost::_bi::value<vostok::network::match_client *>,boost::_bi::value<enum vostok::network_core::disconnect_event_types_enum>>>>'::`2'::stored_vtable.base.manager
                                                        + 1);
    }
    else
    {
      f.vtable = 0;
    }
    v6 = 1;
    v9->__vftable = (vostok::network::response_vtbl *)&vostok::network::response::`vftable';
    v9->__vftable = (vostok::network::response_vtbl *)&vostok::network::functor_response::`vftable';
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      (boost::function<void __cdecl(void)> *)&v9[1],
      &f);
    vostok::network::network_world::add_response(this->m_world, v9);
  }
  else
  {
    vostok::network::network_world::add_response(this->m_world, 0);
  }
  if ( (v6 & 1) != 0 )
    boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&f);
}
