int __cdecl ov_raw_seek(OggVorbis_File *vf, __int64 pos)
{
  int j; // [esp+28h] [ebp-1DCh]
  int serialno; // [esp+2Ch] [ebp-1D8h]
  int link; // [esp+30h] [ebp-1D4h]
  __int64 granulepos; // [esp+34h] [ebp-1D0h]
  int i; // [esp+3Ch] [ebp-1C8h]
  ogg_packet op; // [esp+44h] [ebp-1C0h] BYREF
  int lastblock; // [esp+64h] [ebp-1A0h]
  ogg_page og; // [esp+68h] [ebp-19Ch] BYREF
  int firstflag; // [esp+78h] [ebp-18Ch]
  int thisblock; // [esp+7Ch] [ebp-188h]
  int lastflag; // [esp+80h] [ebp-184h]
  __int64 pagepos; // [esp+84h] [ebp-180h]
  int accblock; // [esp+8Ch] [ebp-178h]
  ogg_stream_state work_os; // [esp+94h] [ebp-170h] BYREF

  if ( vf->ready_state < 2 )
    return -131;
  if ( !vf->seekable )
    return -138;
  if ( pos < 0 || pos > vf->end )
    return -131;
  if ( vf->ready_state >= 3 && (pos < vf->offsets[vf->current_link] || pos >= vf->offsets[vf->current_link + 1]) )
    decode_clear(vf);
  vf->pcm_offset = -1;
  ogg_stream_reset_serialno(&vf->os, vf->current_serialno);
  vorbis_synthesis_restart(&vf->vd);
  if ( seek_helper(vf, pos) )
  {
    vf->pcm_offset = -1;
    ogg_stream_clear(&work_os);
    decode_clear(vf);
    return -137;
  }
  lastblock = 0;
  accblock = 0;
  thisblock = 0;
  lastflag = 0;
  firstflag = 0;
  pagepos = -1;
  ogg_stream_init(&work_os, vf->current_serialno);
  ogg_stream_reset(&work_os);
  while ( 1 )
  {
    while ( 1 )
    {
      if ( vf->ready_state < 3 || ogg_stream_packetout(&work_os, &op) <= 0 )
        goto LABEL_34;
      if ( vf->vi[vf->current_link].codec_setup )
        break;
      ogg_stream_packetout(&vf->os, 0);
LABEL_34:
      if ( lastblock )
      {
        vf->pcm_offset = -1;
        goto LABEL_50;
      }
      pagepos = get_next_page(vf, &og, -1);
      if ( pagepos < 0 )
      {
        vf->pcm_offset = ov_pcm_total(vf, -1);
        goto LABEL_50;
      }
      if ( vf->ready_state >= 3 && vf->current_serialno != ogg_page_serialno(&og) && ogg_page_bos(&og) )
      {
        decode_clear(vf);
        ogg_stream_clear(&work_os);
      }
      if ( vf->ready_state >= 3 )
      {
LABEL_49:
        ogg_stream_pagein(&vf->os, &og);
        ogg_stream_pagein(&work_os, &og);
        lastflag = ogg_page_eos(&og);
      }
      else
      {
        serialno = ogg_page_serialno(&og);
        for ( j = 0; j < vf->links && vf->serialnos[j] != serialno; ++j )
          ;
        if ( j != vf->links )
        {
          vf->current_link = j;
          vf->current_serialno = serialno;
          ogg_stream_reset_serialno(&vf->os, serialno);
          ogg_stream_reset_serialno(&work_os, serialno);
          vf->ready_state = 3;
          firstflag = pagepos <= vf->dataoffsets[j];
          goto LABEL_49;
        }
      }
    }
    thisblock = vorbis_packet_blocksize(&vf->vi[vf->current_link], &op);
    if ( thisblock >= 0 )
    {
      if ( !lastflag || firstflag )
      {
        if ( lastblock )
          accblock += (thisblock + lastblock) >> 2;
      }
      else
      {
        ogg_stream_packetout(&vf->os, 0);
      }
    }
    else
    {
      ogg_stream_packetout(&vf->os, 0);
      thisblock = 0;
    }
    if ( (HIDWORD(op.granulepos) & op.granulepos) != -1 )
      break;
    lastblock = thisblock;
  }
  link = vf->current_link;
  granulepos = op.granulepos - vf->pcmlengths[2 * link];
  if ( granulepos < 0 )
    granulepos = 0;
  for ( i = 0; i < link; ++i )
    granulepos += vf->pcmlengths[2 * i + 1];
  vf->pcm_offset = granulepos - accblock;
  if ( vf->pcm_offset < 0 )
    vf->pcm_offset = 0;
LABEL_50:
  ogg_stream_clear(&work_os);
  vf->bittrack = 0.0;
  vf->samptrack = 0.0;
  return 0;
}
