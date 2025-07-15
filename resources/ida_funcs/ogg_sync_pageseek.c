int __cdecl ogg_sync_pageseek(ogg_sync_state *oy, ogg_page *og)
{
  int returned; // eax
  unsigned __int8 *v3; // edi
  int v4; // ebx
  int result; // eax
  int v6; // ebp
  int v7; // ebp
  int bodybytes; // ecx
  unsigned __int8 *v9; // eax
  unsigned __int8 *v10; // eax
  unsigned __int8 *v11; // ecx
  ogg_page log; // [esp+Ch] [ebp-10h] BYREF

  returned = oy->returned;
  v3 = &oy->data[returned];
  v4 = oy->fill - returned;
  if ( oy->storage < 0 )
    return 0;
  if ( !oy->headerbytes )
  {
    if ( v4 < 27 )
      return 0;
    if ( *(_DWORD *)v3 != 1399285583 )
      goto sync_fail;
    v6 = v3[26] + 27;
    result = 0;
    if ( v4 < v6 )
      return result;
    if ( v3[26] )
    {
      do
        oy->bodybytes += v3[result++ + 27];
      while ( result < v3[26] );
    }
    oy->headerbytes = v6;
  }
  if ( oy->bodybytes + oy->headerbytes > v4 )
    return 0;
  v7 = *(_DWORD *)(v3 + 22);
  *(_DWORD *)(v3 + 22) = 0;
  bodybytes = oy->bodybytes;
  log.header_len = oy->headerbytes;
  log.body = &v3[log.header_len];
  log.header = v3;
  log.body_len = bodybytes;
  ogg_page_checksum_set(&log);
  if ( v7 == *(_DWORD *)(v3 + 22) )
  {
    v9 = &oy->data[oy->returned];
    if ( og )
    {
      og->header = v9;
      og->header_len = oy->headerbytes;
      og->body = &v9[oy->headerbytes];
      og->body_len = oy->bodybytes;
    }
    result = oy->bodybytes + oy->headerbytes;
    oy->returned += result;
    oy->unsynced = 0;
    oy->headerbytes = 0;
    oy->bodybytes = 0;
    return result;
  }
  *(_DWORD *)(v3 + 22) = v7;
sync_fail:
  oy->headerbytes = 0;
  oy->bodybytes = 0;
  memchr(v3 + 1, 0x4Fu, v4 - 1);
  v11 = v10;
  if ( !v10 )
    v11 = &oy->data[oy->fill];
  oy->returned = v11 - oy->data;
  return v3 - v11;
}
