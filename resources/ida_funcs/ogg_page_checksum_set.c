void __usercall ogg_page_checksum_set(ogg_page *og@<eax>)
{
  int v2; // edx
  unsigned __int8 *header; // ecx
  int header_len; // esi
  unsigned int v5; // eax
  int body_len; // esi
  unsigned __int8 *body; // edi

  v2 = 0;
  if ( og )
  {
    header = og->header;
    header[22] = 0;
    header_len = og->header_len;
    header[23] = 0;
    v5 = 0;
    header[24] = 0;
    header[25] = 0;
    if ( header_len > 0 )
    {
      do
        v5 = crc_lookup[HIBYTE(v5) ^ header[v2++]] ^ (v5 << 8);
      while ( v2 < header_len );
      v2 = 0;
    }
    body_len = og->body_len;
    if ( body_len > 0 )
    {
      body = og->body;
      do
        v5 = crc_lookup[HIBYTE(v5) ^ body[v2++]] ^ (v5 << 8);
      while ( v2 < body_len );
    }
    *(_DWORD *)(header + 22) = v5;
  }
}
