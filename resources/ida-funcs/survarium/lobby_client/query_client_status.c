void __thiscall survarium::lobby_client::query_client_status(
        survarium::lobby_client *this,
        const vostok::network_core::tcp_packet *type,
        unsigned __int8 a3)
{
  vostok::network_core::buffer_writer *v3; // ecx
  vostok::network_core::buffer_writer *v4; // ecx
  vostok::network::tcp_packet_client *v5; // ecx
  vostok::network_core::buffer_writer *v6; // ecx
  vostok::network_core::mutable_buffer *v7; // ecx
  unsigned __int8 v8; // [esp+7h] [ebp-29h] BYREF
  vostok::network_core::tcp_packet v9; // [esp+8h] [ebp-28h] BYREF

  vostok::network_core::tcp_packet::tcp_packet(
    (vostok::network_core::tcp_packet *)&vostok::memory::g_mt_allocator,
    (int)&v9);
  v8 = 33;
  vostok::network_core::buffer_writer::w(v3, &v9.m_writer.serialization_operations_descriptors.m_size, &v8, 1u);
  v8 = a3;
  vostok::network_core::buffer_writer::w(v4, &v9.m_writer.serialization_operations_descriptors.m_size, &v8, 1u);
  vostok::network::tcp_packet_client::send(v5, type + 5, &v9);
  vostok::network_core::buffer_writer::~buffer_writer(v6, &v9.m_writer.serialization_operations_descriptors);
  vostok::network_core::mutable_buffer::~mutable_buffer(v7, &v9);
}
