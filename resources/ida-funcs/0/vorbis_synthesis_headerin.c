int __usercall vorbis_synthesis_headerin@<eax>(__int128 a1@<xmm0>, vorbis_info *vi, vorbis_comment *vc, ogg_packet *op)
{
  unsigned __int8 *packet; // ecx
  int v6; // ecx
  const char *v7; // edi
  int *v8; // esi
  bool v9; // zf
  oggpack_buffer b; // [esp+8h] [ebp-1Ch] BYREF
  int v12; // [esp+1Ch] [ebp-8h] BYREF
  __int16 v13; // [esp+20h] [ebp-4h]
  unsigned int v14; // [esp+34h] [ebp+10h]

  if ( op )
  {
    packet = op->packet;
    memset(&b, 0, sizeof(b));
    b.storage = op->bytes;
    b.ptr = packet;
    b.buffer = packet;
    v14 = oggpack_read(&b, 8u);
    v12 = 0;
    v13 = 0;
    v_readstring((char *)&v12, &b, 6);
    v6 = 3;
    v7 = "vorbis";
    v8 = &v12;
    v9 = 1;
    do
    {
      if ( !v6 )
        break;
      v9 = *(_WORD *)v8 == *(_WORD *)v7;
      v8 = (int *)((char *)v8 + 2);
      v7 += 2;
      --v6;
    }
    while ( v9 );
    if ( !v9 )
      return -132;
    if ( v14 == 1 )
    {
      if ( op->b_o_s && !vi->rate )
        return vorbis_unpack_info(vi, &b);
    }
    else if ( v14 == 3 )
    {
      if ( vi->rate )
        return vorbis_unpack_comment(vc, &b);
    }
    else if ( v14 == 5 && vi->rate && vc->vendor )
    {
      return vorbis_unpack_books(&b, a1, vi);
    }
  }
  return -133;
}
