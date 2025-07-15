void __userpurge ppmd_compressor_impl::rcDecNormalize(
        ppmd_compressor_impl *this@<ecx>,
        _DWORD *a2@<esi>,
        compression::ppmd::stream *stream)
{
  int v3; // eax
  unsigned int v4; // ecx
  int v5; // eax
  int v6; // ecx

  while ( 1 )
  {
    v3 = a2[1904];
    v4 = a2[1906];
    if ( (v3 ^ (v3 + v4)) < (unsigned int)&s_ui_commands_allocator.m_buffer[2035360] )
      goto LABEL_4;
    if ( v4 >= 0x8000 )
      break;
    a2[1906] = -v3 & 0x7FFF;
LABEL_4:
    v5 = compression::ppmd::stream::get_char(stream);
    v6 = a2[1905];
    a2[1906] <<= 8;
    a2[1904] <<= 8;
    a2[1905] = (v6 << 8) | v5;
  }
}
