void __usercall survarium::messaging_client::disconnect(survarium::messaging_client *this@<ecx>, int a2@<eax>)
{
  vostok::network::tcp_packet_client *v2; // esi
  void (__cdecl *v3)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::function<void __cdecl(vostok::network_core::packet_reader &)> on_packet_received; // [esp+8h] [ebp-24h] BYREF

  if ( *(_DWORD *)(a2 + 136) != 1 )
  {
    v2 = (vostok::network::tcp_packet_client *)(a2 + 144);
    *(_DWORD *)(a2 + 136) = 1;
    vostok::network::tcp_packet_client::disconnect((vostok::network::tcp_packet_client *)(a2 + 144));
    on_packet_received.vtable = 0;
    vostok::network::tcp_packet_client::set_on_packet_received(
      v2,
      (boost::function<void __cdecl(unsigned int,unsigned int)> *)&on_packet_received);
    if ( on_packet_received.vtable )
    {
      if ( ((int)on_packet_received.vtable & 1) == 0 )
      {
        v3 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)on_packet_received.vtable & 0xFFFFFFFE);
        if ( v3 )
          v3(&on_packet_received.functor, &on_packet_received.functor, 2);
      }
    }
  }
}
