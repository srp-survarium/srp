int __usercall fetch_and_process_packet@<eax>(
        __int128 a1@<xmm0>,
        OggVorbis_File *vf,
        ogg_packet *op_in,
        int readp,
        int spanp)
{
  int v6; // eax
  int v7; // eax
  int current_link; // [esp+8h] [ebp-7Ch]
  ogg_packet *v9; // [esp+14h] [ebp-70h]
  int headers; // [esp+18h] [ebp-6Ch]
  int v11; // [esp+1Ch] [ebp-68h]
  int i; // [esp+20h] [ebp-64h]
  int j; // [esp+34h] [ebp-50h]
  char v14; // [esp+3Ch] [ebp-48h] BYREF
  int v15; // [esp+5Ch] [ebp-28h]
  ogg_packet *op; // [esp+60h] [ebp-24h]
  __int64 granulepos; // [esp+64h] [ebp-20h]
  int v18; // [esp+6Ch] [ebp-18h]
  int decode_ready; // [esp+70h] [ebp-14h]
  ogg_page og; // [esp+74h] [ebp-10h] BYREF

  while ( 1 )
  {
    if ( vf->ready_state == 3 )
    {
      decode_ready = make_decode_ready(a1, vf);
      if ( decode_ready < 0 )
        return decode_ready;
    }
    if ( vf->ready_state == 4 )
      break;
LABEL_31:
    if ( vf->ready_state >= 2 )
    {
      do
      {
        if ( !readp )
          return 0;
        if ( (((unsigned __int64)get_next_page(vf, &og, -1) >> 32) & 0x80000000) != 0LL )
          return -2;
        vf->bittrack = (double)(8 * og.header_len) + vf->bittrack;
        if ( vf->ready_state != 4 || vf->current_serialno == ogg_page_serialno(&og) )
          goto LABEL_45;
      }
      while ( !ogg_page_bos(&og) );
      if ( !spanp )
        return -2;
      decode_clear(vf);
      if ( !vf->seekable )
      {
        vorbis_info_clear(vf->vi);
        vorbis_comment_clear(vf->vc);
      }
    }
LABEL_45:
    if ( vf->ready_state > 2 )
      goto LABEL_56;
    if ( vf->seekable )
    {
      v11 = ogg_page_serialno(&og);
      for ( i = 0; i < vf->links && vf->serialnos[i] != v11; ++i )
        ;
      if ( i != vf->links )
      {
        vf->current_serialno = v11;
        vf->current_link = i;
        ogg_stream_reset_serialno(&vf->os, vf->current_serialno);
        vf->ready_state = 3;
        goto LABEL_56;
      }
    }
    else
    {
      headers = fetch_headers(a1, vf, vf->vi, vf->vc, 0, 0, &og);
      if ( headers )
        return headers;
      vf->current_serialno = vf->os.serialno;
      ++vf->current_link;
LABEL_56:
      ogg_stream_pagein(&vf->os, &og);
    }
  }
  v18 = vorbis_synthesis_halfrate_p(vf->vi);
  do
  {
    if ( op_in )
      v9 = op_in;
    else
      v9 = (ogg_packet *)&v14;
    op = v9;
    v15 = ogg_stream_packetout(&vf->os, v9);
    op_in = 0;
    if ( v15 == -1 )
      return -3;
    if ( v15 <= 0 )
      goto LABEL_31;
    granulepos = op->granulepos;
  }
  while ( vorbis_synthesis(&vf->vb, op) );
  if ( vorbis_synthesis_pcmout(&vf->vd, 0) )
    return -129;
  vorbis_synthesis_blockin(&vf->vd, &vf->vb);
  v6 = vorbis_synthesis_pcmout(&vf->vd, 0);
  vf->samptrack = (double)(v6 << v18) + vf->samptrack;
  vf->bittrack = (double)(8 * op->bytes) + vf->bittrack;
  if ( (HIDWORD(granulepos) & (unsigned int)granulepos) != 0xFFFFFFFF && !op->e_o_s )
  {
    if ( vf->seekable )
      current_link = vf->current_link;
    else
      current_link = 0;
    if ( vf->seekable && current_link > 0 )
      granulepos -= vf->pcmlengths[2 * current_link];
    if ( granulepos < 0 )
      granulepos = 0;
    v7 = vorbis_synthesis_pcmout(&vf->vd, 0);
    granulepos -= v7 << v18;
    for ( j = 0; j < current_link; ++j )
      granulepos += vf->pcmlengths[2 * j + 1];
    vf->pcm_offset = granulepos;
  }
  return 1;
}
