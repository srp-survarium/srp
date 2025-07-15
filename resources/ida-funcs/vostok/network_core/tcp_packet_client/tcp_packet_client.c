void __userpurge vostok::network_core::tcp_packet_client::tcp_packet_client(
        vostok::network_core::tcp_packet_client *this@<ecx>,
        int a2@<edi>,
        boost::asio::io_service *io_service)
{
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v3; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v4; // ecx
  vostok::particle::particle_action *v5; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v6; // ecx
  boost::function<void __cdecl(vostok::memory::single_size_buffer_allocator<512,vostok::threading::multi_threading_policy> const &)> on_out_of_memory; // [esp+8h] [ebp-2Ch] BYREF
  __int64 v8; // [esp+28h] [ebp-Ch]

  boost::asio::basic_stream_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp>>::basic_stream_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp>>(
    io_service,
    (boost::asio::basic_stream_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp> > *)a2);
  HIDWORD(v8) = vostok::network_core::g_allocator;
  *(_DWORD *)(a2 + 72) = 0;
  *(_DWORD *)(a2 + 104) = 0;
  *(_DWORD *)(a2 + 136) = 0;
  on_out_of_memory.vtable = 0;
  vostok::memory::single_size_buffer_allocator<512,vostok::threading::multi_threading_policy>::single_size_buffer_allocator<512,vostok::threading::multi_threading_policy>(
    &on_out_of_memory,
    (vostok::memory::single_size_buffer_allocator<512,vostok::threading::multi_threading_policy> *)(a2 + 144),
    (vostok::memory::single_size_buffer_allocator<512,vostok::threading::multi_threading_policy>::node *)(a2 + 200),
    0x4000u);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v3,
    (int *)&on_out_of_memory);
  *(_DWORD *)(a2 + 16584) = HIDWORD(v8);
  *(_DWORD *)(a2 + 16588) = a2;
  *(_DWORD *)(a2 + 16600) = 0;
  *(_DWORD *)(a2 + 16604) = 0;
  *(_DWORD *)(a2 + 16608) = 0;
  *(_DWORD *)(a2 + 16616) = 0;
  *(_DWORD *)(a2 + 16648) = 0;
  *(_DWORD *)(a2 + 16680) = 0;
  on_out_of_memory.vtable = 0;
  vostok::memory::single_size_buffer_allocator<512,vostok::threading::multi_threading_policy>::single_size_buffer_allocator<512,vostok::threading::multi_threading_policy>(
    &on_out_of_memory,
    (vostok::memory::single_size_buffer_allocator<512,vostok::threading::multi_threading_policy> *)(a2 + 16688),
    (vostok::memory::single_size_buffer_allocator<512,vostok::threading::multi_threading_policy>::node *)(a2 + 16744),
    0x400u);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v4,
    (int *)&on_out_of_memory);
  *(_DWORD *)(a2 + 17768) = 0;
  *(_DWORD *)(a2 + 17772) = 0;
  *(_DWORD *)(a2 + 17776) = 0;
  *(_DWORD *)(a2 + 17808) = 0;
  *(_DWORD *)(a2 + 17840) = 0;
  *(_DWORD *)(a2 + 17872) = 0;
  *(_DWORD *)(a2 + 17904) = io_service;
  LODWORD(v8) = vostok::network_core::tcp_packet_client::on_error;
  HIDWORD(v8) = a2;
  if ( Scaleform::Render::RenderEvent::GetListenerStatus(v5) )
  {
    on_out_of_memory.vtable = 0;
  }
  else
  {
    *(_QWORD *)&on_out_of_memory.functor.obj_ptr = v8;
    on_out_of_memory.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function2<void,enum vostok::network_core::client_error_codes_enum,boost::system::error_code>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::network_core::tcp_packet_client,enum vostok::network_core::client_error_codes_enum,boost::system::error_code>,boost::_bi::list3<boost::_bi::value<vostok::network_core::tcp_packet_client *>,boost::arg<1>,boost::arg<2>>>>'::`2'::stored_vtable
                                                                     + 1);
  }
  boost::function<void __cdecl (boost::system::error_code)>::operator=(
    (boost::function<void __cdecl(vostok::network_core::buffer_reader &)> *)&on_out_of_memory,
    (boost::function1<void,vostok::physics::contact_point const &> *)(a2 + 104));
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v6,
    (int *)&on_out_of_memory);
}
