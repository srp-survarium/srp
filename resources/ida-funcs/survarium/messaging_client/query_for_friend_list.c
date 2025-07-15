void __usercall survarium::messaging_client::query_for_friend_list(
        survarium::messaging_client *this@<ecx>,
        int a2@<eax>)
{
  vostok::network_core::buffer_writer *v3; // ecx
  vostok::network_core::buffer_writer *v4; // ecx
  vostok::network::tcp_packet_client *v5; // ecx
  vostok::network_core::buffer_writer *v6; // ecx
  vostok::network_core::mutable_buffer *v7; // ecx
  vostok::network_core::tcp_packet v8; // [esp+Ch] [ebp-2Ch] BYREF
  unsigned __int8 v9; // [esp+37h] [ebp-1h] BYREF

  if ( *(_DWORD *)(a2 + 136) == 3 )
  {
    vostok::network_core::tcp_packet::tcp_packet(
      (vostok::network_core::tcp_packet *)&vostok::memory::g_mt_allocator,
      (int)&v8);
    v9 = -60;
    vostok::network_core::buffer_writer::w(v3, &v8.m_writer.serialization_operations_descriptors.m_size, &v9, 1u);
    v9 = 7;
    vostok::network_core::buffer_writer::w(v4, &v8.m_writer.serialization_operations_descriptors.m_size, &v9, 1u);
    vostok::network::tcp_packet_client::send(v5, (const vostok::network_core::tcp_packet *)(a2 + 144), &v8);
    vostok::network_core::buffer_writer::~buffer_writer(v6, &v8.m_writer.serialization_operations_descriptors);
    vostok::network_core::mutable_buffer::~mutable_buffer(v7, &v8);
  }
}
