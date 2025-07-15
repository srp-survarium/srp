void __usercall vostok::network_core::mutable_buffer::resize(
        vostok::network_core::mutable_buffer *this@<esi>,
        unsigned int new_size@<edi>)
{
  unsigned int *p_m_capacity; // ecx
  unsigned int m_capacity; // edx

  p_m_capacity = &this->m_capacity;
  m_capacity = this->m_capacity;
  if ( new_size > m_capacity )
  {
    if ( !m_capacity )
      m_capacity = new_size;
    while ( m_capacity < new_size )
      m_capacity *= 2;
    *p_m_capacity = m_capacity;
    if ( m_capacity >= this->m_size )
      p_m_capacity = &this->m_size;
    this->m_size = *p_m_capacity;
    this->m_buffer = (unsigned __int8 *)this->m_allocator->call_realloc(
                                          this->m_allocator,
                                          this->m_buffer,
                                          m_capacity,
                                          "network_core::mutable_buffer",
                                          "vostok::network_core::mutable_buffer::reallocate",
                                          "c:\\survarium.deploy\\sources\\vostok/network_core/mutable_buffer_inline.h",
                                          64);
  }
  this->m_size = new_size;
}
