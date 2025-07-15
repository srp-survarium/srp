int __cdecl fetch_and_process_packet(OggVorbis_File *vf, ogg_packet *op_in, int readp, int spanp)
{
  int v5; // eax
  int v6; // eax
  int current_link; // [esp+8h] [ebp-7Ch]
  ogg_packet *p_op; // [esp+14h] [ebp-70h]
  int headers; // [esp+18h] [ebp-6Ch]
  int serialno; // [esp+1Ch] [ebp-68h]
  int j; // [esp+20h] [ebp-64h]
  int i; // [esp+34h] [ebp-50h]
  ogg_packet op; // [esp+3Ch] [ebp-48h] BYREF
  int result; // [esp+5Ch] [ebp-28h]
  ogg_packet *op_ptr; // [esp+60h] [ebp-24h]
  __int64 granulepos; // [esp+64h] [ebp-20h]
  int hs; // [esp+6Ch] [ebp-18h]
  int ret; // [esp+70h] [ebp-14h]
  ogg_page og; // [esp+74h] [ebp-10h] BYREF

  while ( 1 )
  {
    if ( vf->ready_state == 3 )
    {
      ret = make_decode_ready(vf);
      if ( ret < 0 )
        return ret;
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
      serialno = ogg_page_serialno(&og);
      for ( j = 0; j < vf->links && vf->serialnos[j] != serialno; ++j )
        ;
      if ( j != vf->links )
      {
        vf->current_serialno = serialno;
        vf->current_link = j;
        ogg_stream_reset_serialno(&vf->os, vf->current_serialno);
        vf->ready_state = 3;
        goto LABEL_56;
      }
    }
    else
    {
      headers = fetch_headers(vf, vf->vi, vf->vc, 0, 0, &og);
      if ( headers )
        return headers;
      vf->current_serialno = vf->os.serialno;
      ++vf->current_link;
LABEL_56:
      ogg_stream_pagein(&vf->os, &og);
    }
  }
  hs = vorbis_synthesis_halfrate_p(vf->vi);
  do
  {
    if ( op_in )
      p_op = op_in;
    else
      p_op = &op;
    op_ptr = p_op;
    result = ogg_stream_packetout(&vf->os, p_op);
    op_in = 0;
    if ( result == -1 )
      return -3;
    if ( result <= 0 )
      goto LABEL_31;
    granulepos = op_ptr->granulepos;
  }
  while ( vorbis_synthesis(&vf->vb, op_ptr) );
  if ( vorbis_synthesis_pcmout(&vf->vd, 0) )
    return -129;
  vorbis_synthesis_blockin(&vf->vd, &vf->vb);
  v5 = vorbis_synthesis_pcmout(&vf->vd, 0);
  vf->samptrack = (double)(v5 << hs) + vf->samptrack;
  vf->bittrack = (double)(8 * op_ptr->bytes) + vf->bittrack;
  if ( (HIDWORD(granulepos) & (unsigned int)granulepos) != 0xFFFFFFFF && !op_ptr->e_o_s )
  {
    if ( vf->seekable )
      current_link = vf->current_link;
    else
      current_link = 0;
    if ( vf->seekable && current_link > 0 )
      granulepos -= vf->pcmlengths[2 * current_link];
    if ( granulepos < 0 )
      granulepos = 0;
    v6 = vorbis_synthesis_pcmout(&vf->vd, 0);
    granulepos -= v6 << hs;
    for ( i = 0; i < current_link; ++i )
      granulepos += vf->pcmlengths[2 * i + 1];
    vf->pcm_offset = granulepos;
  }
  return 1;
}
