void __thiscall vostok::sound::sound_voice::on_buffer_end(
        vostok::sound::sound_voice *this,
        vostok::network_core::tcp_packet *buffer_context)
{
  boost::function0<void> *p_m_next_for_orders; // [esp+14h] [ebp-78h]
  boost::_bi::bind_t<void,boost::_mfi::mf3<void,vostok::network_core::tcp_packet_socket<boost::asio::basic_stream_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp> > >,vostok::network_core::tcp_packet const *,boost::system::error_code const &,unsigned int>,boost::_bi::list4<boost::_bi::value<vostok::network_core::tcp_packet_socket<boost::asio::basic_stream_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp> > > *>,boost::_bi::value<vostok::network_core::tcp_packet *>,boost::arg<1>,boost::arg<2> > > v4; // [esp+18h] [ebp-74h]
  vostok::sound::encoded_sound_interface *v5; // [esp+34h] [ebp-58h]
  vostok::intrusive_ptr<vostok::sound::sound_spl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v6; // [esp+38h] [ebp-54h] BYREF
  vostok::resources::resource_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base> *p_m_current_sound_quality; // [esp+3Ch] [ebp-50h]
  vostok::sound::encoded_sound_interface *v8; // [esp+40h] [ebp-4Ch]
  vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v9; // [esp+44h] [ebp-48h] BYREF
  unsigned int new_sample_rate; // [esp+48h] [ebp-44h]
  vostok::sound::encoded_sound_interface *m_object; // [esp+4Ch] [ebp-40h]
  char v12; // [esp+53h] [ebp-39h]
  int v13; // [esp+54h] [ebp-38h]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_voice,void *>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_voice *>,boost::_bi::value<void *> > > result; // [esp+58h] [ebp-34h] BYREF
  boost::function0<void> f; // [esp+64h] [ebp-28h] BYREF
  vostok::sound::sound_order *v16; // [esp+88h] [ebp-4h]

  v13 = 0;
  if ( this->m_conv_state == 3 && !vostok::sound::voice_bridge::buffers_queued(this->m_voice) )
  {
    v12 = 0;
    m_object = this->m_target_sound_quality.m_object;
    new_sample_rate = m_object->m_samples_per_sec;
    vostok::sound::voice_bridge::set_sample_rate(this->m_voice, new_sample_rate);
    vostok::sound::voice_bridge::submit_source_buff(this->m_voice, this->m_conversion_buffer);
    _InterlockedExchangeAdd(&this->m_buffers_queued, 1u);
    _InterlockedExchange(&this->m_conv_state, 4);
    p_m_current_sound_quality = &this->m_current_sound_quality;
    v9.m_object = 0;
    vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      &v9,
      &this->m_target_sound_quality);
    v8 = v9.m_object;
    v9.m_object = this->m_current_sound_quality.m_object;
    this->m_current_sound_quality.m_object = v8;
    vostok::intrusive_ptr<vostok::sound::panning_lut,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::sound::panning_lut,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v9);
    v6.m_object = 0;
    vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      &v6,
      0);
    v5 = (vostok::sound::encoded_sound_interface *)v6.m_object;
    v6.m_object = (vostok::sound::sound_spl *)this->m_target_sound_quality.m_object;
    this->m_target_sound_quality.m_object = v5;
    vostok::intrusive_ptr<vostok::sound::panning_lut,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::sound::panning_lut,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v6);
  }
  v16 = (vostok::sound::sound_order *)vostok::memory::pthreads3_allocator::malloc_impl(
                                        &vostok::memory::g_mt_allocator,
                                        0x30u);
  if ( v16 )
  {
    v4 = *boost::bind<void,vostok::network::match_client,vostok::network_core::udp_network_flow_emulator_options const *,vostok::network::match_client *,vostok::network_core::udp_network_flow_emulator_options const *>(
            (boost::_bi::bind_t<void,boost::_mfi::mf3<void,vostok::network_core::tcp_packet_socket<boost::asio::basic_stream_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp> > >,vostok::network_core::tcp_packet const *,boost::system::error_code const &,unsigned int>,boost::_bi::list4<boost::_bi::value<vostok::network_core::tcp_packet_socket<boost::asio::basic_stream_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp> > > *>,boost::_bi::value<vostok::network_core::tcp_packet *>,boost::arg<1>,boost::arg<2> > > *)&result,
            vostok::sound::sound_voice::on_buffer_end_impl,
            this,
            buffer_context);
    f.vtable = 0;
    boost::function0<void>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_voice,void *>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_voice *>,boost::_bi::value<void *>>>>(
      &f,
      (boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_voice,void *>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_voice *>,boost::_bi::value<void *> > >)v4);
    v13 |= 1u;
    vostok::sound::sound_order::sound_order(v16);
    v16->__vftable = (vostok::sound::sound_order_vtbl *)&vostok::sound::functor_command<vostok::sound::sound_order>::`vftable';
    p_m_next_for_orders = (boost::function0<void> *)&v16[1].m_next_for_orders;
    v16[1].m_next_for_orders = 0;
    boost::function0<void>::assign_to_own(p_m_next_for_orders, &f);
    vostok::sound::sound_world::add_xaudio_order(this->m_world_user->m_owner_world, v16);
  }
  else
  {
    vostok::sound::sound_world::add_xaudio_order(this->m_world_user->m_owner_world, 0);
  }
  if ( (v13 & 1) != 0 )
  {
    v13 &= ~1u;
    boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&f);
  }
}
