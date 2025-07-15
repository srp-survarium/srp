void __thiscall survarium::lobby_client::query_elo_players(
        survarium::lobby_client *this,
        const vostok::network_core::tcp_packet *from,
        int count,
        unsigned __int8 a4)
{
  vostok::network_core::buffer_writer *v4; // ecx
  vostok::network_core::buffer_writer *v5; // ecx
  vostok::network_core::buffer_writer *v6; // ecx
  vostok::network_core::buffer_writer *v7; // ecx
  vostok::network::tcp_packet_client *v8; // ecx
  vostok::network_core::buffer_writer *v9; // ecx
  vostok::network_core::mutable_buffer *v10; // ecx
  vostok::network_core::tcp_packet v11; // [esp+4h] [ebp-30h] BYREF
  unsigned __int8 v12[5]; // [esp+2Fh] [ebp-5h] BYREF

  vostok::network_core::tcp_packet::tcp_packet(
    (vostok::network_core::tcp_packet *)&vostok::memory::g_mt_allocator,
    (int)&v11);
  v12[0] = 33;
  vostok::network_core::buffer_writer::w(v4, &v11.m_writer.serialization_operations_descriptors.m_size, v12, 1u);
  v12[0] = 13;
  vostok::network_core::buffer_writer::w(v5, &v11.m_writer.serialization_operations_descriptors.m_size, v12, 1u);
  vostok::network_core::buffer_writer::w(
    v6,
    &v11.m_writer.serialization_operations_descriptors.m_size,
    (unsigned __int8 *)&count,
    4u);
  vostok::network_core::buffer_writer::w(v7, &v11.m_writer.serialization_operations_descriptors.m_size, &a4, 1u);
  vostok::network::tcp_packet_client::send(v8, from + 5, &v11);
  vostok::network_core::buffer_writer::~buffer_writer(v9, &v11.m_writer.serialization_operations_descriptors);
  vostok::network_core::mutable_buffer::~mutable_buffer(v10, &v11);
}
