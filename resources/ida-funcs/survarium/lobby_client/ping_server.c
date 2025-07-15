void __usercall survarium::lobby_client::ping_server(survarium::lobby_client *this@<ecx>, int a2@<eax>)
{
  vostok::network_core::buffer_writer *v3; // ecx
  vostok::network_core::buffer_writer *v4; // ecx
  vostok::network::tcp_packet_client *v5; // ecx
  vostok::network_core::buffer_writer *v6; // ecx
  vostok::network_core::mutable_buffer *v7; // ecx
  unsigned __int8 v8; // [esp+Bh] [ebp-2Dh] BYREF
  int v9; // [esp+Ch] [ebp-2Ch] BYREF
  vostok::network_core::tcp_packet v10; // [esp+10h] [ebp-28h] BYREF

  if ( *(_BYTE *)(a2 + 436) )
  {
    vostok::network_core::tcp_packet::tcp_packet(
      (vostok::network_core::tcp_packet *)&vostok::memory::g_mt_allocator,
      (int)&v10);
    v8 = 40;
    vostok::network_core::buffer_writer::w(v3, &v10.m_writer.serialization_operations_descriptors.m_size, &v8, 1u);
    v9 = *(_DWORD *)(*(_DWORD *)(a2 + 64) + 13968);
    vostok::network_core::buffer_writer::w(
      v4,
      &v10.m_writer.serialization_operations_descriptors.m_size,
      (unsigned __int8 *)&v9,
      4u);
    vostok::network::tcp_packet_client::send(v5, (const vostok::network_core::tcp_packet *)(a2 + 200), &v10);
    vostok::network_core::buffer_writer::~buffer_writer(v6, &v10.m_writer.serialization_operations_descriptors);
    vostok::network_core::mutable_buffer::~mutable_buffer(v7, &v10);
  }
}
