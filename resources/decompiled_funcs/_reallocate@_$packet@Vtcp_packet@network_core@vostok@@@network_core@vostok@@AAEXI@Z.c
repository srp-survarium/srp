void __usercall vostok::network_core::packet<vostok::network_core::tcp_packet>::reallocate(
        vostok::network_core::packet<vostok::network_core::tcp_packet> *this@<esi>,
        unsigned int new_size@<edx>)
{
  unsigned int *p_m_buffer_size; // eax
  unsigned __int8 *v3; // eax

  p_m_buffer_size = &this[1].m_buffer_size;
  this[1].m_buffer_size = new_size;
  if ( new_size >= this->m_buffer_size )
    p_m_buffer_size = &this->m_buffer_size;
  this->m_buffer_size = *p_m_buffer_size;
  if ( this->m_buffer )
    v3 = this->m_buffer - 3;
  else
    v3 = 0;
  this->m_buffer = (unsigned __int8 *)((*(int (__thiscall **)(unsigned __int8 *, unsigned __int8 *, unsigned int))(*(_DWORD *)this[1].m_buffer + 20))(
                                         this[1].m_buffer,
                                         v3,
                                         new_size + 3)
                                     + 3);
}
