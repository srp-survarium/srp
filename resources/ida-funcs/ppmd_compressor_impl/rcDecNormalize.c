void __usercall ppmd_compressor_impl::rcDecNormalize(
        ppmd_compressor_impl *this@<ecx>,
        compression::ppmd::stream *stream@<esi>)
{
  unsigned int m_low; // eax
  unsigned int m_range; // edx
  unsigned __int8 *m_pointer; // eax
  int v5; // edx
  unsigned int m_code; // eax

  while ( 1 )
  {
    m_low = this->m_low;
    m_range = this->m_range;
    if ( (m_low ^ (m_low + m_range)) < (unsigned int)&vostok::memory::s_CRT_arena[5574200] )
      goto LABEL_4;
    if ( m_range >= 0x8000 )
      break;
    this->m_range = -m_low & 0x7FFF;
LABEL_4:
    m_pointer = stream->m_pointer;
    if ( m_pointer >= &stream->m_buffer[stream->m_buffer_size] )
    {
      v5 = -1;
    }
    else
    {
      v5 = *m_pointer;
      stream->m_pointer = m_pointer + 1;
    }
    m_code = this->m_code;
    this->m_range <<= 8;
    this->m_low <<= 8;
    this->m_code = v5 | (m_code << 8);
  }
}
