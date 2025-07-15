void __userpurge survarium::lobby_client::move_item(
        survarium::vector<survarium::relocate_item_descr> *items@<edi>,
        survarium::lobby_client *this,
        unsigned int profile_id)
{
  vostok::network_core::buffer_writer *v3; // ecx
  vostok::network_core::buffer_writer *v4; // ecx
  vostok::network_core::buffer_writer *v5; // ecx
  vostok::network_core::buffer_writer *v6; // ecx
  vostok::network_core::buffer_writer *v7; // ecx
  unsigned __int8 *i; // esi
  vostok::network_core::buffer_writer *v9; // ecx
  vostok::network_core::buffer_writer *v10; // ecx
  vostok::network_core::buffer_writer *v11; // ecx
  vostok::network_core::buffer_writer *v12; // ecx
  vostok::network_core::buffer_writer *v13; // ecx
  vostok::network_core::buffer_writer *v14; // ecx
  vostok::network_core::mutable_buffer *v15; // ecx
  vostok::network_core::tcp_packet v16; // [esp+4h] [ebp-2Ch] BYREF
  unsigned __int8 v17; // [esp+2Fh] [ebp-1h] BYREF

  vostok::network_core::tcp_packet::tcp_packet(
    (vostok::network_core::tcp_packet *)&vostok::memory::g_mt_allocator,
    (int)&v16);
  v17 = 35;
  vostok::network_core::buffer_writer::w(v3, &v16.m_writer.serialization_operations_descriptors.m_size, &v17, 1u);
  v17 = 0;
  vostok::network_core::buffer_writer::w(v4, &v16.m_writer.serialization_operations_descriptors.m_size, &v17, 1u);
  vostok::network_core::buffer_writer::w(
    v5,
    &v16.m_writer.serialization_operations_descriptors.m_size,
    (unsigned __int8 *)&profile_id,
    4u);
  HIBYTE(profile_id) = items->_M_impl._M_finish - items->_M_impl._M_start;
  vostok::network_core::buffer_writer::w(
    v6,
    &v16.m_writer.serialization_operations_descriptors.m_size,
    (unsigned __int8 *)&profile_id + 3,
    1u);
  for ( i = (unsigned __int8 *)items->_M_impl._M_start; i != (unsigned __int8 *)items->_M_impl._M_finish; i += 16 )
  {
    vostok::network_core::buffer_writer::w(v7, &v16.m_writer.serialization_operations_descriptors.m_size, i, 4u);
    vostok::network_core::buffer_writer::w(v9, &v16.m_writer.serialization_operations_descriptors.m_size, i + 4, 2u);
    vostok::network_core::buffer_writer::w(v10, &v16.m_writer.serialization_operations_descriptors.m_size, i + 6, 1u);
    vostok::network_core::buffer_writer::w(v11, &v16.m_writer.serialization_operations_descriptors.m_size, i + 7, 1u);
    vostok::network_core::buffer_writer::w(v12, &v16.m_writer.serialization_operations_descriptors.m_size, i + 8, 4u);
    vostok::network_core::buffer_writer::w(v13, &v16.m_writer.serialization_operations_descriptors.m_size, i + 12, 4u);
  }
  vostok::network::tcp_packet_client::send(
    (vostok::network::tcp_packet_client *)v7,
    (const vostok::network_core::tcp_packet *)&this->m_packet_client,
    &v16);
  vostok::network_core::buffer_writer::~buffer_writer(v14, &v16.m_writer.serialization_operations_descriptors);
  vostok::network_core::mutable_buffer::~mutable_buffer(v15, &v16);
}
