void __userpurge vostok::network_core::tcp_packet::clone(
        vostok::network_core::tcp_packet *this@<ecx>,
        vostok::network_core::mutable_buffer *a2@<eax>,
        const vostok::network_core::tcp_packet *other)
{
  vostok::network_core::mutable_buffer::resize(a2, other->m_buffer.m_size);
  memcpy(a2->m_buffer, other->m_buffer.m_buffer, other->m_buffer.m_size);
}
