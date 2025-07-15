int __cdecl ov_pcm_seek(OggVorbis_File *vf, __int64 pos)
{
  int v3; // eax
  __int64 v4; // [esp+34h] [ebp-60h]
  int n; // [esp+40h] [ebp-54h]
  char v6; // [esp+44h] [ebp-50h]
  int i; // [esp+48h] [ebp-4Ch]
  int serialno; // [esp+4Ch] [ebp-48h]
  int j; // [esp+50h] [ebp-44h]
  ogg_packet op; // [esp+54h] [ebp-40h] BYREF
  ogg_page og; // [esp+74h] [ebp-20h] BYREF
  int v12; // [esp+84h] [ebp-10h]
  int v13; // [esp+88h] [ebp-Ch]
  int v14; // [esp+8Ch] [ebp-8h]
  int decode_ready; // [esp+90h] [ebp-4h]

  v13 = 0;
  decode_ready = ov_pcm_seek_page(vf, pos);
  if ( decode_ready < 0 )
    return decode_ready;
  decode_ready = make_decode_ready(vf);
  if ( decode_ready )
    return decode_ready;
  while ( 1 )
  {
    while ( 1 )
    {
      while ( 1 )
      {
        v12 = ogg_stream_packetpeek(&vf->os, &op);
        if ( v12 > 0 )
          break;
        if ( v12 < 0 && v12 != -3 || (((unsigned __int64)get_next_page(vf, &og, -1) >> 32) & 0x80000000) != 0LL )
          goto LABEL_33;
        if ( ogg_page_bos(&og) )
          decode_clear(vf);
        if ( vf->ready_state >= 3 )
        {
LABEL_32:
          ogg_stream_pagein(&vf->os, &og);
        }
        else
        {
          serialno = ogg_page_serialno(&og);
          for ( i = 0; i < vf->links && vf->serialnos[i] != serialno; ++i )
            ;
          if ( i != vf->links )
          {
            vf->current_link = i;
            vf->ready_state = 3;
            vf->current_serialno = ogg_page_serialno(&og);
            ogg_stream_reset_serialno(&vf->os, serialno);
            v12 = make_decode_ready(vf);
            if ( v12 )
              return v12;
            v13 = 0;
            goto LABEL_32;
          }
        }
      }
      v14 = vorbis_packet_blocksize(&vf->vi[vf->current_link], &op);
      if ( v14 >= 0 )
        break;
      ogg_stream_packetout(&vf->os, 0);
    }
    if ( v13 )
      vf->pcm_offset += (v14 + v13) >> 2;
    v3 = vorbis_info_blocksize(vf->vi, 1);
    if ( vf->pcm_offset + ((v14 + v3) >> 2) >= pos )
      break;
    ogg_stream_packetout(&vf->os, 0);
    vorbis_synthesis_trackonly(&vf->vb, &op);
    vorbis_synthesis_blockin(&vf->vd, &vf->vb);
    if ( op.granulepos >= 0 )
    {
      vf->pcm_offset = op.granulepos - vf->pcmlengths[2 * vf->current_link];
      if ( vf->pcm_offset < 0 )
        vf->pcm_offset = 0;
      for ( j = 0; j < vf->current_link; ++j )
        vf->pcm_offset += vf->pcmlengths[2 * j + 1];
    }
    v13 = v14;
  }
LABEL_33:
  vf->bittrack = 0.0;
  vf->samptrack = 0.0;
  v6 = vorbis_synthesis_halfrate_p(vf->vi);
  while ( vf->pcm_offset < pos >> v6 << v6 )
  {
    v4 = (pos - vf->pcm_offset) >> v6;
    n = vorbis_synthesis_pcmout(&vf->vd, 0);
    if ( n > v4 )
      n = v4;
    vorbis_synthesis_read(&vf->vd, n);
    vf->pcm_offset += n << v6;
    if ( n < v4 && fetch_and_process_packet(vf, 0, 1, 1) <= 0 )
      vf->pcm_offset = ov_pcm_total(vf, -1);
  }
  return 0;
}
