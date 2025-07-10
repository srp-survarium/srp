int __cdecl ov_pcm_seek(OggVorbis_File *vf, __int64 pos)
{
  int v3; // eax
  __int64 target; // [esp+34h] [ebp-60h]
  int samples; // [esp+40h] [ebp-54h]
  char hs; // [esp+44h] [ebp-50h]
  int link; // [esp+48h] [ebp-4Ch]
  int serialno; // [esp+4Ch] [ebp-48h]
  int i; // [esp+50h] [ebp-44h]
  ogg_packet op; // [esp+54h] [ebp-40h] BYREF
  ogg_page og; // [esp+74h] [ebp-20h] BYREF
  int decode_ready; // [esp+84h] [ebp-10h]
  int lastblock; // [esp+88h] [ebp-Ch]
  int thisblock; // [esp+8Ch] [ebp-8h]
  int ret; // [esp+90h] [ebp-4h]

  lastblock = 0;
  ret = ov_pcm_seek_page(vf, pos);
  if ( ret < 0 )
    return ret;
  ret = make_decode_ready(vf);
  if ( ret )
    return ret;
  while ( 1 )
  {
    while ( 1 )
    {
      while ( 1 )
      {
        decode_ready = ogg_stream_packetpeek(&vf->os, &op);
        if ( decode_ready > 0 )
          break;
        if ( decode_ready < 0 && decode_ready != -3
          || (((unsigned __int64)get_next_page(vf, &og, -1) >> 32) & 0x80000000) != 0LL )
        {
          goto LABEL_33;
        }
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
          for ( link = 0; link < vf->links && vf->serialnos[link] != serialno; ++link )
            ;
          if ( link != vf->links )
          {
            vf->current_link = link;
            vf->ready_state = 3;
            vf->current_serialno = ogg_page_serialno(&og);
            ogg_stream_reset_serialno(&vf->os, serialno);
            decode_ready = make_decode_ready(vf);
            if ( decode_ready )
              return decode_ready;
            lastblock = 0;
            goto LABEL_32;
          }
        }
      }
      thisblock = vorbis_packet_blocksize(&vf->vi[vf->current_link], &op);
      if ( thisblock >= 0 )
        break;
      ogg_stream_packetout(&vf->os, 0);
    }
    if ( lastblock )
      vf->pcm_offset += (thisblock + lastblock) >> 2;
    v3 = vorbis_info_blocksize(vf->vi, 1);
    if ( vf->pcm_offset + ((thisblock + v3) >> 2) >= pos )
      break;
    ogg_stream_packetout(&vf->os, 0);
    vorbis_synthesis_trackonly(&vf->vb, &op);
    vorbis_synthesis_blockin(&vf->vd, &vf->vb);
    if ( op.granulepos >= 0 )
    {
      vf->pcm_offset = op.granulepos - vf->pcmlengths[2 * vf->current_link];
      if ( vf->pcm_offset < 0 )
        vf->pcm_offset = 0;
      for ( i = 0; i < vf->current_link; ++i )
        vf->pcm_offset += vf->pcmlengths[2 * i + 1];
    }
    lastblock = thisblock;
  }
LABEL_33:
  vf->bittrack = 0.0;
  vf->samptrack = 0.0;
  hs = vorbis_synthesis_halfrate_p(vf->vi);
  while ( vf->pcm_offset < pos >> hs << hs )
  {
    target = (pos - vf->pcm_offset) >> hs;
    samples = vorbis_synthesis_pcmout(&vf->vd, 0);
    if ( samples > target )
      samples = target;
    vorbis_synthesis_read(&vf->vd, samples);
    vf->pcm_offset += samples << hs;
    if ( samples < target && fetch_and_process_packet(vf, 0, 1, 1) <= 0 )
      vf->pcm_offset = ov_pcm_total(vf, -1);
  }
  return 0;
}
