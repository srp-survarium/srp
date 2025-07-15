int __cdecl ogg_stream_pagein(ogg_stream_state *os, ogg_page *og)
{
  unsigned __int8 *header; // edi
  unsigned __int8 v3; // al
  int v4; // edx
  int v5; // ebx
  int body_returned; // ecx
  int lacing_returned; // eax
  bool v9; // zf
  int v10; // edx
  int lacing_packet; // eax
  int *v12; // ecx
  int lacing_fill; // eax
  int v14; // eax
  int v15; // edx
  __int64 *granule_vals; // eax
  int v17; // ecx
  int *v18; // eax
  int v19; // ecx
  __int64 *v20; // eax
  int v21; // eax
  int *v22; // eax
  int v23; // [esp+10h] [ebp-30h]
  unsigned int needed; // [esp+14h] [ebp-2Ch]
  int v25; // [esp+18h] [ebp-28h]
  int v26; // [esp+1Ch] [ebp-24h]
  unsigned __int8 *src; // [esp+20h] [ebp-20h]
  int srca; // [esp+20h] [ebp-20h]
  int v29; // [esp+24h] [ebp-1Ch]
  int v30; // [esp+28h] [ebp-18h]
  int v31; // [esp+2Ch] [ebp-14h]
  int v32; // [esp+30h] [ebp-10h]
  int v33; // [esp+34h] [ebp-Ch]
  int v34; // [esp+38h] [ebp-8h]
  int v35; // [esp+3Ch] [ebp-4h]

  v23 = 0;
  src = og->body;
  header = og->header;
  needed = og->body_len;
  v31 = og->header[4];
  v3 = og->header[5];
  v32 = v3 & 1;
  v29 = v3 & 2;
  v33 = v3 & 4;
  v34 = ogg_page_granulepos(og);
  v35 = v4;
  v30 = ogg_page_serialno(og);
  v5 = header[18] | ((header[19] | ((header[20] | (header[21] << 8)) << 8)) << 8);
  v25 = header[26];
  if ( ogg_stream_check(os) )
    return -1;
  body_returned = os->body_returned;
  lacing_returned = os->lacing_returned;
  v26 = lacing_returned;
  if ( body_returned )
  {
    v9 = os->body_fill == body_returned;
    os->body_fill -= body_returned;
    if ( !v9 )
    {
      memmove(os->body_data, &os->body_data[body_returned], os->body_fill);
      lacing_returned = v26;
    }
    os->body_returned = 0;
  }
  if ( lacing_returned )
  {
    v10 = os->lacing_fill - lacing_returned;
    if ( v10 )
    {
      memmove((unsigned __int8 *)os->lacing_vals, (unsigned __int8 *)&os->lacing_vals[lacing_returned], 4 * v10);
      memmove(
        (unsigned __int8 *)os->granule_vals,
        (unsigned __int8 *)&os->granule_vals[v26],
        8 * (os->lacing_fill - v26));
      lacing_returned = v26;
    }
    os->lacing_fill -= lacing_returned;
    os->lacing_packet -= lacing_returned;
    os->lacing_returned = 0;
  }
  if ( v30 != os->serialno || v31 > 0 || os_lacing_expand(os, v25 + 1) )
    return -1;
  if ( v5 != os->pageno )
  {
    lacing_packet = os->lacing_packet;
    if ( lacing_packet < os->lacing_fill )
    {
      v12 = &os->lacing_vals[lacing_packet];
      do
      {
        os->body_fill -= (unsigned __int8)*v12;
        ++lacing_packet;
        ++v12;
      }
      while ( lacing_packet < os->lacing_fill );
      lacing_packet = os->lacing_packet;
    }
    v9 = os->pageno == -1;
    os->lacing_fill = lacing_packet;
    if ( !v9 )
    {
      os->lacing_vals[lacing_packet] = 1024;
      ++os->lacing_fill;
      ++os->lacing_packet;
    }
  }
  if ( v32 )
  {
    lacing_fill = os->lacing_fill;
    if ( lacing_fill < 1 || os->lacing_vals[lacing_fill - 1] == 1024 )
    {
      v29 = 0;
      if ( v25 > 0 )
      {
        do
        {
          v14 = header[v23 + 27];
          src += v14;
          needed -= v14;
          ++v23;
        }
        while ( v14 >= 255 && v23 < v25 );
      }
    }
  }
  if ( !needed )
    goto LABEL_30;
  if ( os_body_expand(os, needed) )
    return -1;
  memcpy(&os->body_data[os->body_fill], src, needed);
  os->body_fill += needed;
LABEL_30:
  srca = -1;
  if ( v23 < v25 )
  {
    do
    {
      v15 = header[v23 + 27];
      os->lacing_vals[os->lacing_fill] = v15;
      granule_vals = os->granule_vals;
      v17 = os->lacing_fill;
      LODWORD(granule_vals[v17]) = -1;
      HIDWORD(granule_vals[v17]) = -1;
      if ( v29 )
      {
        v18 = &os->lacing_vals[os->lacing_fill];
        *v18 |= 0x100u;
        v29 = 0;
      }
      if ( v15 >= 255 )
      {
        v19 = srca;
      }
      else
      {
        v19 = os->lacing_fill;
        srca = v19;
      }
      ++os->lacing_fill;
      ++v23;
      if ( v15 < 255 )
        os->lacing_packet = os->lacing_fill;
    }
    while ( v23 < v25 );
    if ( v19 != -1 )
    {
      v20 = os->granule_vals;
      LODWORD(v20[v19]) = v34;
      HIDWORD(v20[v19]) = v35;
    }
  }
  if ( v33 )
  {
    v21 = os->lacing_fill;
    os->e_o_s = 1;
    if ( v21 > 0 )
    {
      v22 = &os->lacing_vals[v21 - 1];
      *v22 |= 0x200u;
    }
  }
  os->pageno = v5 + 1;
  return 0;
}
