void __thiscall vostok::sound::sound_voice::on_buffer_start(
        vostok::sound::sound_voice *this,
        vostok::network_core::tcp_packet *buffer_context)
{
  boost::function0<void> *p_m_next_for_orders; // [esp+18h] [ebp-50h]
  boost::_bi::bind_t<void,boost::_mfi::mf3<void,vostok::network_core::tcp_packet_socket<boost::asio::basic_stream_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp> > >,vostok::network_core::tcp_packet const *,boost::system::error_code const &,unsigned int>,boost::_bi::list4<boost::_bi::value<vostok::network_core::tcp_packet_socket<boost::asio::basic_stream_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp> > > *>,boost::_bi::value<vostok::network_core::tcp_packet *>,boost::arg<1>,boost::arg<2> > > v4; // [esp+1Ch] [ebp-4Ch]
  char v5; // [esp+30h] [ebp-38h]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_voice,void *>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_voice *>,boost::_bi::value<void *> > > result; // [esp+34h] [ebp-34h] BYREF
  boost::function0<void> f; // [esp+40h] [ebp-28h] BYREF
  vostok::sound::sound_order *v8; // [esp+64h] [ebp-4h]

  v5 = 0;
  if ( this->m_conv_state == 1 )
  {
    _InterlockedExchange(&this->m_conv_state, 2);
    vostok::sound::voice_bridge::flush_source_buffers(this->m_voice);
    v8 = (vostok::sound::sound_order *)vostok::memory::pthreads3_allocator::malloc_impl(
                                         &vostok::memory::g_mt_allocator,
                                         0x30u);
    if ( v8 )
    {
      v4 = *boost::bind<void,vostok::network::match_client,vostok::network_core::udp_network_flow_emulator_options const *,vostok::network::match_client *,vostok::network_core::udp_network_flow_emulator_options const *>(
              (boost::_bi::bind_t<void,boost::_mfi::mf3<void,vostok::network_core::tcp_packet_socket<boost::asio::basic_stream_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp> > >,vostok::network_core::tcp_packet const *,boost::system::error_code const &,unsigned int>,boost::_bi::list4<boost::_bi::value<vostok::network_core::tcp_packet_socket<boost::asio::basic_stream_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp> > > *>,boost::_bi::value<vostok::network_core::tcp_packet *>,boost::arg<1>,boost::arg<2> > > *)&result,
              vostok::sound::sound_voice::on_buffer_start_impl,
              this,
              buffer_context);
      f.vtable = 0;
      if ( boost::detail::function::basic_vtable0<void>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_voice,void *>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_voice *>,boost::_bi::value<void *>>>>(
             &`boost::function0<void>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_voice,void *>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_voice *>,boost::_bi::value<void *>>>>'::`2'::stored_vtable,
             (boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_voice,void *>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_voice *>,boost::_bi::value<void *> > >)v4,
             &f.functor) )
      {
        f.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function0<void>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_voice,void *>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_voice *>,boost::_bi::value<void *>>>>'::`2'::stored_vtable.base.manager
                                                          + 1);
      }
      else
      {
        f.vtable = 0;
      }
      v5 = 1;
      vostok::sound::sound_order::sound_order(v8);
      v8->__vftable = (vostok::sound::sound_order_vtbl *)&vostok::sound::functor_command<vostok::sound::sound_order>::`vftable';
      p_m_next_for_orders = (boost::function0<void> *)&v8[1].m_next_for_orders;
      v8[1].m_next_for_orders = 0;
      boost::function0<void>::assign_to_own(p_m_next_for_orders, &f);
      vostok::sound::sound_world::add_xaudio_order(this->m_proxy->m_user->m_owner_world, v8);
    }
    else
    {
      vostok::sound::sound_world::add_xaudio_order(this->m_proxy->m_user->m_owner_world, 0);
    }
    if ( (v5 & 1) != 0 )
      boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&f);
  }
  else if ( this->m_conv_state == 4 )
  {
    _InterlockedExchange(&this->m_conv_state, 0);
  }
}
