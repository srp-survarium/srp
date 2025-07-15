void __usercall survarium::messaging_client::query_for_friends_status(
        survarium::messaging_client *this@<ecx>,
        int a2@<eax>)
{
  vostok::network_core::buffer_writer *v3; // ecx
  vostok::network_core::buffer_writer *v4; // ecx
  vostok::network::tcp_packet_client *v5; // ecx
  vostok::network_core::buffer_writer *v6; // ecx
  vostok::network_core::mutable_buffer *v7; // ecx
  unsigned __int8 v8; // [esp+Fh] [ebp-29h] BYREF
  vostok::network_core::tcp_packet v9; // [esp+10h] [ebp-28h] BYREF

  if ( *(_DWORD *)(a2 + 136) == 3 )
  {
    vostok::network_core::tcp_packet::tcp_packet(
      (vostok::network_core::tcp_packet *)&vostok::memory::g_mt_allocator,
      (int)&v9);
    v8 = -60;
    vostok::network_core::buffer_writer::w(v3, &v9.m_writer.serialization_operations_descriptors.m_size, &v8, 1u);
    v8 = 9;
    vostok::network_core::buffer_writer::w(v4, &v9.m_writer.serialization_operations_descriptors.m_size, &v8, 1u);
    vostok::network::tcp_packet_client::send(v5, (const vostok::network_core::tcp_packet *)(a2 + 144), &v9);
    vostok::network_core::buffer_writer::~buffer_writer(v6, &v9.m_writer.serialization_operations_descriptors);
    vostok::network_core::mutable_buffer::~mutable_buffer(v7, &v9);
  }
}
