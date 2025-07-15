int __cdecl ogg_stream_pagein(ogg_stream_state *os, ogg_page *og)
{
  unsigned __int8 *header; // edi
  unsigned __int8 v3; // al
  __int64 v4; // rax
  int v5; // ebx
  int body_returned; // ecx
  int lacing_returned; // eax
  bool v9; // zf
  int v10; // edx
  int v11; // edx
  int lacing_packet; // eax
  int *v13; // ecx
  int lacing_fill; // eax
  int v15; // ecx
  int v16; // eax
  int v17; // ebx
  int v18; // edx
  __int64 *granule_vals; // eax
  int v20; // ecx
  int v21; // ecx
  int v22; // eax
  unsigned int bodysize; // [esp+10h] [ebp-30h]
  int segments; // [esp+14h] [ebp-2Ch]
  int segptr; // [esp+18h] [ebp-28h]
  int lr; // [esp+1Ch] [ebp-24h]
  unsigned __int8 *saved; // [esp+20h] [ebp-20h]
  int saveda; // [esp+20h] [ebp-20h]
  int bos; // [esp+24h] [ebp-1Ch]
  int pageno; // [esp+28h] [ebp-18h]
  int version; // [esp+2Ch] [ebp-14h]
  int continued; // [esp+30h] [ebp-10h]
  int eos; // [esp+34h] [ebp-Ch]
  __int64 granulepos; // [esp+38h] [ebp-8h]

  header = og->header;
  saved = og->body;
  version = og->header[4];
  v3 = og->header[5];
  bodysize = og->body_len;
  continued = v3 & 1;
  segptr = 0;
  bos = v3 & 2;
  eos = v3 & 4;
  LODWORD(v4) = ogg_page_granulepos(og);
  granulepos = v4;
  v5 = header[14] | ((header[15] | (*((unsigned __int16 *)header + 8) << 8)) << 8);
  pageno = header[18] | ((header[19] | ((header[20] | (header[21] << 8)) << 8)) << 8);
  segments = header[26];
  if ( !os || !os->body_data )
    return -1;
  body_returned = os->body_returned;
  lacing_returned = os->lacing_returned;
  lr = lacing_returned;
  if ( body_returned )
  {
    v9 = os->body_fill == body_returned;
    os->body_fill -= body_returned;
    if ( !v9 )
    {
      memmove(os->body_data, &os->body_data[body_returned], os->body_fill);
      lacing_returned = lr;
    }
    os->body_returned = 0;
  }
  if ( lacing_returned )
  {
    v10 = os->lacing_fill - lacing_returned;
    if ( v10 )
    {
      memmove((unsigned __int8 *)os->lacing_vals, (unsigned __int8 *)&os->lacing_vals[lacing_returned], 4 * v10);
      memmove((unsigned __int8 *)os->granule_vals, (unsigned __int8 *)&os->granule_vals[lr], 8 * (os->lacing_fill - lr));
      lacing_returned = lr;
    }
    os->lacing_fill -= lacing_returned;
    os->lacing_packet -= lacing_returned;
    os->lacing_returned = 0;
  }
  if ( v5 != os->serialno || version > 0 || os_lacing_expand(os, segments + 1) )
    return -1;
  v11 = os->pageno;
  if ( pageno != v11 )
  {
    lacing_packet = os->lacing_packet;
    if ( lacing_packet < os->lacing_fill )
    {
      v13 = &os->lacing_vals[lacing_packet];
      do
      {
        os->body_fill -= (unsigned __int8)*v13;
        ++lacing_packet;
        ++v13;
      }
      while ( lacing_packet < os->lacing_fill );
      lacing_packet = os->lacing_packet;
    }
    os->lacing_fill = lacing_packet;
    if ( v11 != -1 )
    {
      os->lacing_vals[lacing_packet] = 1024;
      ++os->lacing_fill;
      ++os->lacing_packet;
    }
  }
  if ( !continued || (lacing_fill = os->lacing_fill, lacing_fill >= 1) && os->lacing_vals[lacing_fill - 1] != 1024 )
  {
    v15 = segments;
    goto LABEL_30;
  }
  v15 = segments;
  bos = 0;
  if ( segments <= 0 )
  {
LABEL_30:
    v17 = 0;
    goto LABEL_31;
  }
  do
  {
    v16 = header[segptr + 27];
    saved += v16;
    bodysize -= v16;
    v17 = segptr + 1;
    if ( v16 != 255 )
      break;
    ++segptr;
  }
  while ( v17 < segments );
LABEL_31:
  if ( bodysize )
  {
    if ( !os_body_expand(os, bodysize) )
    {
      memcpy(&os->body_data[os->body_fill], saved, bodysize);
      v15 = segments;
      os->body_fill += bodysize;
      goto LABEL_34;
    }
    return -1;
  }
LABEL_34:
  saveda = -1;
  if ( v17 < v15 )
  {
    do
    {
      v18 = header[v17 + 27];
      os->lacing_vals[os->lacing_fill] = v18;
      granule_vals = os->granule_vals;
      v20 = os->lacing_fill;
      LODWORD(granule_vals[v20]) = -1;
      HIDWORD(granule_vals[v20]) = -1;
      if ( bos )
      {
        os->lacing_vals[os->lacing_fill] |= 0x100u;
        bos = 0;
      }
      if ( v18 >= 255 )
      {
        v21 = saveda;
      }
      else
      {
        v21 = os->lacing_fill;
        saveda = v21;
      }
      ++os->lacing_fill;
      ++v17;
      if ( v18 < 255 )
        os->lacing_packet = os->lacing_fill;
    }
    while ( v17 < segments );
    if ( v21 != -1 )
      os->granule_vals[v21] = granulepos;
  }
  if ( eos )
  {
    v22 = os->lacing_fill;
    os->e_o_s = 1;
    if ( v22 > 0 )
      os->lacing_vals[v22 - 1] |= 0x200u;
  }
  os->pageno = pageno + 1;
  return 0;
}
