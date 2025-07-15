int __cdecl ov_raw_seek(OggVorbis_File *vf, __int64 pos)
{
  int i; // [esp+28h] [ebp-1DCh]
  int serialno; // [esp+2Ch] [ebp-1D8h]
  int current_link; // [esp+30h] [ebp-1D4h]
  __int64 v6; // [esp+34h] [ebp-1D0h]
  int j; // [esp+3Ch] [ebp-1C8h]
  ogg_packet op; // [esp+44h] [ebp-1C0h] BYREF
  int v9; // [esp+64h] [ebp-1A0h]
  ogg_page og; // [esp+68h] [ebp-19Ch] BYREF
  BOOL v11; // [esp+78h] [ebp-18Ch]
  int v12; // [esp+7Ch] [ebp-188h]
  int v13; // [esp+80h] [ebp-184h]
  __int64 next_page; // [esp+84h] [ebp-180h]
  int v15; // [esp+8Ch] [ebp-178h]
  ogg_stream_state os; // [esp+94h] [ebp-170h] BYREF

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
    ogg_stream_clear(&os);
    decode_clear(vf);
    return -137;
  }
  v9 = 0;
  v15 = 0;
  v12 = 0;
  v13 = 0;
  v11 = 0;
  next_page = -1;
  ogg_stream_init(&os, vf->current_serialno);
  ogg_stream_reset(&os);
  while ( 1 )
  {
    while ( 1 )
    {
      if ( vf->ready_state < 3 || ogg_stream_packetout(&os, &op) <= 0 )
        goto LABEL_34;
      if ( vf->vi[vf->current_link].codec_setup )
        break;
      ogg_stream_packetout(&vf->os, 0);
LABEL_34:
      if ( v9 )
      {
        vf->pcm_offset = -1;
        goto LABEL_50;
      }
      next_page = get_next_page(vf, &og, -1);
      if ( next_page < 0 )
      {
        vf->pcm_offset = ov_pcm_total(vf, -1);
        goto LABEL_50;
      }
      if ( vf->ready_state >= 3 && vf->current_serialno != ogg_page_serialno(&og) && ogg_page_bos(&og) )
      {
        decode_clear(vf);
        ogg_stream_clear(&os);
      }
      if ( vf->ready_state >= 3 )
      {
LABEL_49:
        ogg_stream_pagein(&vf->os, &og);
        ogg_stream_pagein(&os, &og);
        v13 = ogg_page_eos(&og);
      }
      else
      {
        serialno = ogg_page_serialno(&og);
        for ( i = 0; i < vf->links && vf->serialnos[i] != serialno; ++i )
          ;
        if ( i != vf->links )
        {
          vf->current_link = i;
          vf->current_serialno = serialno;
          ogg_stream_reset_serialno(&vf->os, serialno);
          ogg_stream_reset_serialno(&os, serialno);
          vf->ready_state = 3;
          v11 = next_page <= vf->dataoffsets[i];
          goto LABEL_49;
        }
      }
    }
    v12 = vorbis_packet_blocksize(&vf->vi[vf->current_link], &op);
    if ( v12 >= 0 )
    {
      if ( !v13 || v11 )
      {
        if ( v9 )
          v15 += (v12 + v9) >> 2;
      }
      else
      {
        ogg_stream_packetout(&vf->os, 0);
      }
    }
    else
    {
      ogg_stream_packetout(&vf->os, 0);
      v12 = 0;
    }
    if ( (HIDWORD(op.granulepos) & op.granulepos) != -1 )
      break;
    v9 = v12;
  }
  current_link = vf->current_link;
  v6 = op.granulepos - vf->pcmlengths[2 * current_link];
  if ( v6 < 0 )
    v6 = 0;
  for ( j = 0; j < current_link; ++j )
    v6 += vf->pcmlengths[2 * j + 1];
  vf->pcm_offset = v6 - v15;
  if ( vf->pcm_offset < 0 )
    vf->pcm_offset = 0;
LABEL_50:
  ogg_stream_clear(&os);
  vf->bittrack = 0.0;
  vf->samptrack = 0.0;
  return 0;
}
