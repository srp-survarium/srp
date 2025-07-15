void __usercall survarium::lobby_client::reroll_player_skills(
        survarium::lobby_client *this@<ecx>,
        const vostok::network_core::tcp_packet *a2@<eax>)
{
  vostok::network_core::buffer_writer *v3; // ecx
  vostok::network_core::buffer_writer *v4; // ecx
  vostok::network_core::buffer_writer *v5; // ecx
  vostok::network::tcp_packet_client *v6; // ecx
  vostok::network_core::buffer_writer *v7; // ecx
  vostok::network_core::mutable_buffer *v8; // ecx
  vostok::network_core::tcp_packet v9; // [esp+Ch] [ebp-2Ch] BYREF
  unsigned __int8 v10; // [esp+37h] [ebp-1h] BYREF

  vostok::network_core::tcp_packet::tcp_packet(
    (vostok::network_core::tcp_packet *)&vostok::memory::g_mt_allocator,
    (int)&v9);
  v10 = 37;
  vostok::network_core::buffer_writer::w(v3, &v9.m_writer.serialization_operations_descriptors.m_size, &v10, 1u);
  v10 = 1;
  vostok::network_core::buffer_writer::w(v4, &v9.m_writer.serialization_operations_descriptors.m_size, &v10, 1u);
  vostok::network_core::buffer_writer::w(
    v5,
    &v9.m_writer.serialization_operations_descriptors.m_size,
    &a2[15].m_writer.serialization_operations_descriptors.gap4
  + 1512 * *((unsigned __int8 *)a2[1].m_writer.serialization_operations_descriptors.m_first[432].file + 1604),
    4u);
  vostok::network::tcp_packet_client::send(v6, a2 + 5, &v9);
  vostok::network_core::buffer_writer::~buffer_writer(v7, &v9.m_writer.serialization_operations_descriptors);
  vostok::network_core::mutable_buffer::~mutable_buffer(v8, &v9);
}
