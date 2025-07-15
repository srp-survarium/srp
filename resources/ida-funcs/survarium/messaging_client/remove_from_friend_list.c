void __userpurge survarium::messaging_client::remove_from_friend_list(
        survarium::messaging_client *this@<ecx>,
        int a2@<eax>,
        const unsigned int account_id)
{
  vostok::network_core::buffer_writer *v4; // ecx
  vostok::network_core::buffer_writer *v5; // ecx
  vostok::network_core::buffer_writer *v6; // ecx
  vostok::network::tcp_packet_client *v7; // ecx
  vostok::network_core::buffer_writer *v8; // ecx
  vostok::network_core::mutable_buffer *v9; // ecx
  vostok::network_core::tcp_packet v10; // [esp+Ch] [ebp-30h] BYREF
  unsigned __int8 v11[5]; // [esp+37h] [ebp-5h] BYREF

  if ( *(_DWORD *)(a2 + 136) == 3 )
  {
    vostok::network_core::tcp_packet::tcp_packet(
      (vostok::network_core::tcp_packet *)&vostok::memory::g_mt_allocator,
      (int)&v10);
    v11[0] = -60;
    vostok::network_core::buffer_writer::w(v4, &v10.m_writer.serialization_operations_descriptors.m_size, v11, 1u);
    v11[0] = 2;
    vostok::network_core::buffer_writer::w(v5, &v10.m_writer.serialization_operations_descriptors.m_size, v11, 1u);
    vostok::network_core::buffer_writer::w(
      v6,
      &v10.m_writer.serialization_operations_descriptors.m_size,
      (unsigned __int8 *)&account_id,
      4u);
    vostok::network::tcp_packet_client::send(v7, (const vostok::network_core::tcp_packet *)(a2 + 144), &v10);
    vostok::network_core::buffer_writer::~buffer_writer(v8, &v10.m_writer.serialization_operations_descriptors);
    vostok::network_core::mutable_buffer::~mutable_buffer(v9, &v10);
  }
}
