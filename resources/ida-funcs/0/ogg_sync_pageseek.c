int __cdecl ogg_sync_pageseek(ogg_sync_state *oy, ogg_page *og)
{
  int returned; // ecx
  int v4; // eax
  unsigned __int8 *v5; // ebx
  bool v6; // sf
  int result; // eax
  int v8; // edi
  int v9; // edx
  int v10; // ecx
  int bodybytes; // eax
  unsigned __int8 *v12; // eax
  unsigned __int8 *v13; // ecx
  unsigned __int8 *v14; // eax
  ogg_page v15; // [esp+8h] [ebp-14h] BYREF
  int v16; // [esp+18h] [ebp-4h]
  int v17; // [esp+24h] [ebp+8h]

  returned = oy->returned;
  v4 = oy->fill - returned;
  v5 = &oy->data[returned];
  v6 = oy->storage < 0;
  v16 = v4;
  if ( v6 )
    return 0;
  if ( !oy->headerbytes )
  {
    if ( v4 < 27 )
      return 0;
    if ( *(_DWORD *)v5 != *(_DWORD *)"OggS" )
    {
sync_fail:
      oy->headerbytes = 0;
      oy->bodybytes = 0;
      memchr(v5 + 1, 0x4Fu, v4 - 1);
      v13 = v12;
      if ( !v12 )
        v13 = &oy->data[oy->fill];
      oy->returned = v13 - oy->data;
      return v5 - v13;
    }
    v8 = v5[26] + 27;
    if ( v4 < v8 )
      return 0;
    v9 = 0;
    if ( v5[26] )
    {
      do
        oy->bodybytes += v5[v9++ + 27];
      while ( v9 < v5[26] );
    }
    oy->headerbytes = v8;
  }
  v10 = oy->bodybytes + oy->headerbytes;
  if ( v10 > v4 )
    return 0;
  v17 = *(_DWORD *)(v5 + 22);
  *(_DWORD *)(v5 + 22) = 0;
  v15.header_len = oy->headerbytes;
  v15.body = &v5[v15.header_len];
  bodybytes = oy->bodybytes;
  v15.header = v5;
  v15.body_len = bodybytes;
  ogg_page_checksum_set(v10, &v15);
  if ( v17 != *(_DWORD *)(v5 + 22) )
  {
    *(_DWORD *)(v5 + 22) = v17;
    v4 = v16;
    goto sync_fail;
  }
  v14 = &oy->data[oy->returned];
  if ( og )
  {
    og->header = v14;
    og->header_len = oy->headerbytes;
    og->body = &v14[oy->headerbytes];
    og->body_len = oy->bodybytes;
  }
  result = oy->bodybytes + oy->headerbytes;
  oy->unsynced = 0;
  oy->returned += result;
  oy->headerbytes = 0;
  oy->bodybytes = 0;
  return result;
}
