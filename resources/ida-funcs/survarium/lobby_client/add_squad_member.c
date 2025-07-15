void __userpurge survarium::lobby_client::add_squad_member(
        survarium::lobby_client *this@<ecx>,
        int a2@<eax>,
        const char (*name)[64])
{
  vostok::network_core::buffer_writer *v4; // ecx
  vostok::network_core::buffer_writer *v5; // ecx
  vostok::network_core::buffer_writer *v6; // ecx
  vostok::network::tcp_packet_client *v7; // ecx
  vostok::network_core::buffer_writer *v8; // ecx
  vostok::network_core::mutable_buffer *v9; // ecx
  vostok::network_core::tcp_packet v10; // [esp+Ch] [ebp-30h] BYREF
  unsigned __int8 v11[5]; // [esp+37h] [ebp-5h] BYREF

  if ( *(_BYTE *)(a2 + 436) )
  {
    vostok::network_core::tcp_packet::tcp_packet(
      (vostok::network_core::tcp_packet *)&vostok::memory::g_mt_allocator,
      (int)&v10);
    v11[0] = 42;
    vostok::network_core::buffer_writer::w(v4, &v10.m_writer.serialization_operations_descriptors.m_size, v11, 1u);
    v11[0] = 2;
    vostok::network_core::buffer_writer::w(v5, &v10.m_writer.serialization_operations_descriptors.m_size, v11, 1u);
    vostok::network_core::buffer_writer::w_string(v6, (char *)&v10.m_writer, (int)name);
    vostok::network::tcp_packet_client::send(v7, (const vostok::network_core::tcp_packet *)(a2 + 200), &v10);
    vostok::network_core::buffer_writer::~buffer_writer(v8, &v10.m_writer.serialization_operations_descriptors);
    vostok::network_core::mutable_buffer::~mutable_buffer(v9, &v10);
  }
}
