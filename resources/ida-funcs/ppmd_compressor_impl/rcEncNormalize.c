void __usercall ppmd_compressor_impl::rcEncNormalize(
        ppmd_compressor_impl *this@<eax>,
        compression::ppmd::stream *stream@<esi>)
{
  unsigned int m_low; // ecx
  unsigned int m_range; // edx

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
    *stream->m_pointer++ = HIBYTE(m_low);
    this->m_range <<= 8;
    this->m_low <<= 8;
  }
}
