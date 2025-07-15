vostok::network_core::tcp_packet *__thiscall vostok::network_core::tcp_packet_socket<boost::asio::basic_stream_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp>>>::new_packet(
        vostok::network_core::tcp_packet_socket<boost::asio::basic_stream_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp> > > *this)
{
  vostok::memory::base_allocator *v1; // eax
  vostok::memory::base_allocator *m_packet_allocator; // [esp+8h] [ebp-10h]
  void *_Where; // [esp+Ch] [ebp-Ch]
  char *v7; // [esp+14h] [ebp-4h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  _Where = vostok::memory::base_allocator::malloc_impl(v1, 0x10u);
  v7 = (char *)operator new(0x10u, _Where);
  if ( !v7 )
    return 0;
  m_packet_allocator = this->m_packet_allocator;
  *(_DWORD *)v7 = 0;
  *((_DWORD *)v7 + 1) = 0;
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)(v7 + 8));
  *((_DWORD *)v7 + 2) = m_packet_allocator;
  *((_DWORD *)v7 + 3) = 0;
  return (vostok::network_core::tcp_packet *)v7;
}
