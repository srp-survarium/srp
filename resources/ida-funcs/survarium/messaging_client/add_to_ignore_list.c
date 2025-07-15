void __userpurge survarium::messaging_client::add_to_ignore_list(
        survarium::messaging_client *this@<ecx>,
        int a2@<eax>,
        const unsigned int account_id)
{
  _DWORD *i; // eax
  vostok::network_core::buffer_writer *v5; // ecx
  vostok::network_core::buffer_writer *v6; // ecx
  vostok::network_core::buffer_writer *v7; // ecx
  vostok::network::tcp_packet_client *v8; // ecx
  vostok::network_core::buffer_writer *v9; // ecx
  vostok::network_core::mutable_buffer *v10; // ecx
  vostok::network_core::tcp_packet v11; // [esp+Ch] [ebp-30h] BYREF
  unsigned __int8 v12[5]; // [esp+37h] [ebp-5h] BYREF

  if ( *(_DWORD *)(a2 + 136) == 3 )
  {
    for ( i = *(_DWORD **)(a2 + 368); i != *(_DWORD **)(a2 + 372); i += 18 )
    {
      if ( *i == account_id )
        return;
    }
    vostok::network_core::tcp_packet::tcp_packet(
      (vostok::network_core::tcp_packet *)&vostok::memory::g_mt_allocator,
      (int)&v11);
    v12[0] = -60;
    vostok::network_core::buffer_writer::w(v5, &v11.m_writer.serialization_operations_descriptors.m_size, v12, 1u);
    v12[0] = 3;
    vostok::network_core::buffer_writer::w(v6, &v11.m_writer.serialization_operations_descriptors.m_size, v12, 1u);
    vostok::network_core::buffer_writer::w(
      v7,
      &v11.m_writer.serialization_operations_descriptors.m_size,
      (unsigned __int8 *)&account_id,
      4u);
    vostok::network::tcp_packet_client::send(v8, (const vostok::network_core::tcp_packet *)(a2 + 144), &v11);
    vostok::network_core::buffer_writer::~buffer_writer(v9, &v11.m_writer.serialization_operations_descriptors);
    vostok::network_core::mutable_buffer::~mutable_buffer(v10, &v11);
  }
}
