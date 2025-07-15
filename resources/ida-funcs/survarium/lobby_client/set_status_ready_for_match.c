void __thiscall survarium::lobby_client::set_status_ready_for_match(
        survarium::lobby_client *this,
        const vostok::network_core::tcp_packet *profile_id,
        unsigned __int8 a3)
{
  vostok::network_core::buffer_writer *v3; // ecx
  vostok::network_core::buffer_writer *v4; // ecx
  vostok::network::tcp_packet_client *v5; // ecx
  vostok::network_core::buffer_writer *v6; // ecx
  vostok::network_core::mutable_buffer *v7; // ecx
  vostok::network_core::tcp_packet v8; // [esp+4h] [ebp-2Ch] BYREF
  unsigned __int8 v9; // [esp+2Fh] [ebp-1h] BYREF

  vostok::network_core::tcp_packet::tcp_packet(
    (vostok::network_core::tcp_packet *)&vostok::memory::g_mt_allocator,
    (int)&v8);
  v9 = 32;
  vostok::network_core::buffer_writer::w(v3, &v8.m_writer.serialization_operations_descriptors.m_size, &v9, 1u);
  vostok::network_core::buffer_writer::w(v4, &v8.m_writer.serialization_operations_descriptors.m_size, &a3, 4u);
  vostok::network::tcp_packet_client::send(v5, profile_id + 5, &v8);
  vostok::network_core::buffer_writer::~buffer_writer(v6, &v8.m_writer.serialization_operations_descriptors);
  vostok::network_core::mutable_buffer::~mutable_buffer(v7, &v8);
}
