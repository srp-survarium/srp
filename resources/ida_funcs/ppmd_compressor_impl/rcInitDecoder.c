void __usercall ppmd_compressor_impl::rcInitDecoder(
        ppmd_compressor_impl *this@<ecx>,
        compression::ppmd::stream *stream@<eax>)
{
  unsigned __int8 *m_pointer; // edx
  int v3; // esi
  unsigned __int8 *v4; // edx
  int v5; // esi
  unsigned __int8 *v6; // edx
  int v7; // esi
  unsigned __int8 *v8; // edx
  int v9; // esi

  this->m_code = 0;
  this->m_low = 0;
  this->m_range = -1;
  m_pointer = stream->m_pointer;
  if ( m_pointer >= &stream->m_buffer[stream->m_buffer_size] )
  {
    v3 = -1;
  }
  else
  {
    v3 = *m_pointer;
    stream->m_pointer = m_pointer + 1;
  }
  this->m_code = v3 | (this->m_code << 8);
  v4 = stream->m_pointer;
  if ( v4 >= &stream->m_buffer[stream->m_buffer_size] )
  {
    v5 = -1;
  }
  else
  {
    v5 = *v4;
    stream->m_pointer = v4 + 1;
  }
  this->m_code = v5 | (this->m_code << 8);
  v6 = stream->m_pointer;
  if ( v6 >= &stream->m_buffer[stream->m_buffer_size] )
  {
    v7 = -1;
  }
  else
  {
    v7 = *v6;
    stream->m_pointer = v6 + 1;
  }
  this->m_code = v7 | (this->m_code << 8);
  v8 = stream->m_pointer;
  if ( v8 >= &stream->m_buffer[stream->m_buffer_size] )
  {
    this->m_code = -1;
  }
  else
  {
    v9 = *v8;
    stream->m_pointer = v8 + 1;
    this->m_code = v9 | (this->m_code << 8);
  }
}
