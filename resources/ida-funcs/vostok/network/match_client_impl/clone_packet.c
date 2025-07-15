vostok::memory::single_size_buffer_allocator<1364,vostok::threading::multi_threading_policy>::node *__usercall vostok::network::match_client_impl::clone_packet@<eax>(
        vostok::network::match_client_impl *this@<eax>,
        const vostok::network_core::udp_match_packet *packet@<edi>)
{
  vostok::memory::single_size_buffer_allocator<1364,vostok::threading::multi_threading_policy>::node *matched; // eax
  unsigned __int8 *m_buffer; // edx
  unsigned int m_size; // ebx
  vostok::memory::single_size_buffer_allocator<1364,vostok::threading::multi_threading_policy>::node *v5; // esi
  char v6; // cl
  vostok::network_core::buffer_writer *v7; // ecx

  matched = vostok::network_core::new_udp_match_packet((vostok::memory::single_size_buffer_allocator<1364,vostok::threading::multi_threading_policy> *)((char *)this + (_DWORD)&loc_553FD + 3));
  m_buffer = packet->m_buffer.m_buffer;
  m_size = packet->m_buffer.m_size;
  v5 = matched;
  *(_WORD *)&matched->data[104] = packet->specific_port;
  matched->data[102] = packet->message_type;
  matched->data[107] ^= (*((_BYTE *)packet + 107) ^ matched->data[107]) & 0x3F;
  v6 = matched->data[107] ^ (matched->data[107] ^ *((_BYTE *)packet + 107)) & 0x40;
  matched->data[107] = v6;
  LOBYTE(matched) = *((_BYTE *)packet + 107) ^ (v6 ^ *((_BYTE *)packet + 107)) & 0x7F;
  v5->data[107] = (char)matched;
  v5->data[107] = *((_BYTE *)packet + 107) ^ ((unsigned __int8)matched ^ *((_BYTE *)packet + 107)) & 0x7F;
  v7 = *(vostok::network_core::buffer_writer **)&v5->data[1328];
  v5->data[16] = packet->message_part_id;
  v5->data[103] = packet->message_parts_count;
  LOBYTE(v7->serialization_operations_descriptors.m_size) = *packet->m_buffer.m_buffer;
  vostok::network_core::buffer_writer::w(v7, &v5->data[1340], m_buffer + 12, m_size - 12);
  return v5;
}
