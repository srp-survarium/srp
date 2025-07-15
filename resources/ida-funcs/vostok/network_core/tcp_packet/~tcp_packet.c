void __thiscall vostok::network_core::tcp_packet::~tcp_packet(vostok::network_core::tcp_packet *this)
{
  unsigned __int8 *m_buffer; // eax
  bool v2; // zf
  unsigned __int8 *v3; // eax
  vostok::memory::base_allocator *m_allocator; // ecx

  m_buffer = this->m_buffer;
  if ( this->m_buffer )
  {
    v2 = m_buffer == (unsigned __int8 *)3;
    v3 = m_buffer - 3;
    m_allocator = this->m_allocator;
    if ( !v2 )
      m_allocator->call_free(m_allocator, v3);
  }
}
