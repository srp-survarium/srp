void __fastcall ogg_page_checksum_set(int a1, ogg_page *og)
{
  unsigned __int8 *header; // eax
  int header_len; // esi
  unsigned int v4; // ecx
  int v5; // esi
  unsigned __int8 *body; // edx
  int i; // [esp+4h] [ebp-4h]
  int body_len; // [esp+4h] [ebp-4h]

  if ( og )
  {
    header = og->header;
    header_len = og->header_len;
    header[22] = 0;
    header[23] = 0;
    v4 = 0;
    header[24] = 0;
    header[25] = 0;
    for ( i = 0; i < header_len; ++i )
      v4 = crc_lookup[HIBYTE(v4) ^ header[i]] ^ (v4 << 8);
    v5 = 0;
    body_len = og->body_len;
    if ( body_len > 0 )
    {
      body = og->body;
      do
        v4 = crc_lookup[HIBYTE(v4) ^ body[v5++]] ^ (v4 << 8);
      while ( v5 < body_len );
    }
    *(_DWORD *)(header + 22) = v4;
  }
}
