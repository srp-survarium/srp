char __thiscall sequence_id_predicate::operator()(
        sequence_id_predicate *this,
        vostok::network_core::udp_match_packet *packet,
        vostok::memory::single_size_buffer_allocator<140,vostok::threading::simple_lock>::node *a3)
{
  vostok::memory::single_size_buffer_allocator<140,vostok::threading::simple_lock>::node *v3; // esi
  vostok::circular_buffer<vostok::network_core::sequence_number<unsigned short>,8> *v4; // ebx
  vostok::circular_buffer<vostok::network_core::sequence_number<unsigned short>,8>::iterator v6; // [esp-10h] [ebp-28h]
  vostok::network_core::buffer_reader v7; // [esp-10h] [ebp-28h]
  vostok::circular_buffer<vostok::network_core::sequence_number<unsigned short>,8>::iterator v8; // [esp-8h] [ebp-20h]
  _DWORD v9[2]; // [esp+10h] [ebp-8h] BYREF

  v3 = a3;
  v8.m_index = (unsigned int)&packet->ordered_multipackets_hook.right_;
  v4 = *(vostok::circular_buffer<vostok::network_core::sequence_number<unsigned short>,8> **)&a3->data[92];
  v6.m_index = (unsigned int)&a3->data[72];
  v8.m_container = v4;
  v6.m_container = *(vostok::circular_buffer<vostok::network_core::sequence_number<unsigned short>,8> **)&a3->data[96];
  stlp_std::priv::__find<vostok::circular_buffer<vostok::network_core::sequence_number<unsigned short>,8>::iterator,vostok::network_core::sequence_number<unsigned short>>(
    v9,
    (vostok::circular_buffer<vostok::network_core::sequence_number<unsigned short>,8>::iterator *)&a3->data[72],
    v6,
    v8);
  if ( (vostok::circular_buffer<vostok::network_core::sequence_number<unsigned short>,8> *)v9[1] == v4 )
    return 0;
  v7.m_buffer = (const unsigned __int8 *)(*(_DWORD *)&v3[9].data[68] + 12);
  v7.m_pointer = v7.m_buffer;
  v7.m_buffer_size = *(_DWORD *)&v3[9].data[76] - 12;
  vostok::network_core::udp_match_connection::time_in_ms(v3->data[102], v7, 0);
  vostok::network_core::delete_udp_match_packet(
    (vostok::memory::single_size_buffer_allocator<1364,vostok::threading::multi_threading_policy> *)packet->ordered_multipackets_hook.parent_,
    &a3);
  return 1;
}
