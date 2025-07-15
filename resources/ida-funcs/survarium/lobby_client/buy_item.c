void __thiscall survarium::lobby_client::buy_item(
        survarium::lobby_client *this,
        const vostok::network_core::tcp_packet *item_dict_id,
        unsigned int count,
        int faction_id,
        const bool use_premium_money)
{
  vostok::network_core::buffer_writer *v5; // ecx
  vostok::network_core::buffer_writer *v6; // ecx
  vostok::network_core::buffer_writer *v7; // ecx
  vostok::network_core::buffer_writer *v8; // ecx
  vostok::network_core::buffer_writer *v9; // ecx
  vostok::network_core::buffer_writer *v10; // ecx
  vostok::network::tcp_packet_client *v11; // ecx
  vostok::network_core::buffer_writer *v12; // ecx
  vostok::network_core::mutable_buffer *v13; // ecx
  vostok::network_core::tcp_packet v14; // [esp+8h] [ebp-30h] BYREF
  bool v15; // [esp+30h] [ebp-8h] BYREF
  unsigned __int8 v16; // [esp+37h] [ebp-1h] BYREF

  v15 = 0;
  vostok::network_core::tcp_packet::tcp_packet(
    (vostok::network_core::tcp_packet *)&vostok::memory::g_mt_allocator,
    (int)&v14);
  v16 = 36;
  vostok::network_core::buffer_writer::w(v5, &v14.m_writer.serialization_operations_descriptors.m_size, &v16, 1u);
  v16 = 0;
  vostok::network_core::buffer_writer::w(v6, &v14.m_writer.serialization_operations_descriptors.m_size, &v16, 1u);
  vostok::network_core::buffer_writer::w(
    v7,
    &v14.m_writer.serialization_operations_descriptors.m_size,
    (unsigned __int8 *)&count,
    2u);
  vostok::network_core::buffer_writer::w(
    v8,
    &v14.m_writer.serialization_operations_descriptors.m_size,
    (unsigned __int8 *)&faction_id,
    4u);
  vostok::network_core::buffer_writer::w(
    v9,
    &v14.m_writer.serialization_operations_descriptors.m_size,
    (unsigned __int8 *)&use_premium_money,
    1u);
  vostok::network_core::buffer_writer::w<bool>(&v15, v10, &v14.m_writer);
  vostok::network::tcp_packet_client::send(v11, item_dict_id + 5, &v14);
  vostok::network_core::buffer_writer::~buffer_writer(v12, &v14.m_writer.serialization_operations_descriptors);
  vostok::network_core::mutable_buffer::~mutable_buffer(v13, &v14);
}
