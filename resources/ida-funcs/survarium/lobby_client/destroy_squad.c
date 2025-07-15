void __thiscall survarium::lobby_client::destroy_squad(
        survarium::lobby_client *this,
        const vostok::network_core::tcp_packet *a2)
{
  vostok::network_core::buffer_writer *v2; // ecx
  vostok::network_core::buffer_writer *v3; // ecx
  vostok::network::tcp_packet_client *v4; // ecx
  vostok::network_core::buffer_writer *v5; // ecx
  vostok::network_core::mutable_buffer *v6; // ecx
  vostok::network_core::tcp_packet v7; // [esp+4h] [ebp-30h] BYREF
  unsigned __int8 v8[5]; // [esp+2Fh] [ebp-5h] BYREF

  vostok::network_core::tcp_packet::tcp_packet(
    (vostok::network_core::tcp_packet *)&vostok::memory::g_mt_allocator,
    (int)&v7);
  v8[0] = 42;
  vostok::network_core::buffer_writer::w(v2, &v7.m_writer.serialization_operations_descriptors.m_size, v8, 1u);
  v8[0] = 1;
  vostok::network_core::buffer_writer::w(v3, &v7.m_writer.serialization_operations_descriptors.m_size, v8, 1u);
  vostok::network::tcp_packet_client::send(v4, a2 + 5, &v7);
  vostok::network_core::buffer_writer::~buffer_writer(v5, &v7.m_writer.serialization_operations_descriptors);
  vostok::network_core::mutable_buffer::~mutable_buffer(v6, &v7);
}
