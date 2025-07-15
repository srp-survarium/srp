void __usercall ppmd_compressor_impl::rcEncNormalize(
        ppmd_compressor_impl *this@<eax>,
        compression::ppmd::stream *stream@<edx>)
{
  unsigned int m_low; // ecx
  unsigned int m_range; // esi

  while ( 1 )
  {
    m_low = this->m_low;
    m_range = this->m_range;
    if ( (m_low ^ (m_low + m_range)) < (unsigned int)&s_ui_commands_allocator.m_buffer[2035360] )
      goto LABEL_4;
    if ( m_range >= 0x8000 )
      break;
    this->m_range = -m_low & 0x7FFF;
LABEL_4:
    *stream->m_pointer++ = HIBYTE(m_low);
    this->m_range <<= 8;
    this->m_low <<= 8;
  }
}
