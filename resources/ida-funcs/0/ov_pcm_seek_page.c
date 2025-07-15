int __cdecl ov_pcm_seek_page(OggVorbis_File *vf, __int64 pos)
{
  int v3; // eax
  int v4; // eax
  int v5; // eax
  __int64 v6; // rax
  int v7; // eax
  int v8; // eax
  __int64 v9; // rax
  int v10; // edx
  ogg_packet op; // [esp+64h] [ebp-98h] BYREF
  ogg_page v12; // [esp+84h] [ebp-78h] BYREF
  __int64 v13; // [esp+94h] [ebp-68h]
  __int64 offset; // [esp+9Ch] [ebp-60h]
  __int64 v15; // [esp+A4h] [ebp-58h]
  ogg_page og; // [esp+ACh] [ebp-50h] BYREF
  __int64 v17; // [esp+BCh] [ebp-40h]
  __int64 v18; // [esp+C4h] [ebp-38h]
  __int64 v19; // [esp+CCh] [ebp-30h]
  __int64 v20; // [esp+D4h] [ebp-28h]
  __int64 v21; // [esp+DCh] [ebp-20h]
  __int64 posa; // [esp+E4h] [ebp-18h]
  int i; // [esp+F0h] [ebp-Ch]
  __int64 v24; // [esp+F4h] [ebp-8h]

  i = -1;
  posa = 0;
  v24 = ov_pcm_total(vf, -1);
  if ( vf->ready_state < 2 )
    return -131;
  if ( !vf->seekable )
    return -138;
  if ( pos < 0 || pos > v24 )
    return -131;
  for ( i = vf->links - 1; i >= 0; --i )
  {
    v24 -= vf->pcmlengths[2 * i + 1];
    if ( pos >= v24 )
      break;
  }
  v18 = vf->offsets[i + 1];
  v21 = vf->offsets[i];
  v19 = vf->pcmlengths[2 * i];
  v15 = v19 + vf->pcmlengths[2 * i + 1];
  v17 = v19 + pos - v24;
  v20 = v21;
LABEL_13:
  while ( v21 < v18 )
  {
    if ( v18 - v21 >= (unsigned int)&_sbh_sizeHeaderList )
    {
      offset = v21
             + (unsigned __int64)((double)(v17 - v19) * (double)(v18 - v21) / (double)(v15 - v19))
             - (unsigned int)&_sbh_sizeHeaderList;
      if ( offset < (int)((int)&_sbh_sizeHeaderList + v21) )
        offset = v21;
    }
    else
    {
      offset = v21;
    }
    if ( offset != vf->offset )
    {
      v3 = seek_helper(vf, offset);
      posa = v3;
      if ( v3 )
        goto seek_error_0;
    }
    while ( v21 < v18 )
    {
      posa = get_next_page(vf, &og, v18 - vf->offset);
      if ( posa == -128 )
        goto seek_error_0;
      if ( posa >= 0 )
      {
        v5 = ogg_page_serialno(&og);
        if ( v5 == vf->serialnos[i] )
        {
          LODWORD(v6) = ogg_page_granulepos(&og);
          v13 = v6;
          if ( (HIDWORD(v6) & (unsigned int)v6) != 0xFFFFFFFF )
          {
            if ( v13 >= v17 )
            {
              if ( offset > v21 + 1 )
              {
                if ( v18 != vf->offset )
                {
                  v18 = offset;
                  v15 = v13;
                  goto LABEL_13;
                }
                v18 = posa;
                offset -= (unsigned int)&_sbh_sizeHeaderList;
                if ( offset <= v21 )
                  offset = v21 + 1;
                v7 = seek_helper(vf, offset);
                posa = v7;
                if ( v7 )
                  goto seek_error_0;
              }
              else
              {
                v18 = v21;
              }
            }
            else
            {
              v20 = posa;
              v21 = vf->offset;
              v19 = v13;
              if ( v17 - v13 > 44100 )
                goto LABEL_13;
              offset = v21;
            }
          }
        }
      }
      else if ( offset > v21 + 1 )
      {
        if ( !offset )
          goto seek_error_0;
        offset -= (unsigned int)&_sbh_sizeHeaderList;
        if ( offset <= v21 )
          offset = v21 + 1;
        v4 = seek_helper(vf, offset);
        posa = v4;
        if ( v4 )
          goto seek_error_0;
      }
      else
      {
        v18 = v21;
      }
    }
  }
  posa = seek_helper(vf, v20);
  vf->pcm_offset = -1;
  if ( posa || (posa = get_next_page(vf, &v12, -1), posa < 0) )
  {
seek_error_0:
    vf->pcm_offset = -1;
    decode_clear(vf);
    return posa;
  }
  if ( i == vf->current_link )
  {
    vorbis_synthesis_restart(&vf->vd);
  }
  else
  {
    decode_clear(vf);
    vf->current_link = i;
    vf->current_serialno = vf->serialnos[i];
    vf->ready_state = 3;
  }
  ogg_stream_reset_serialno(&vf->os, vf->current_serialno);
  ogg_stream_pagein(&vf->os, &v12);
  while ( 1 )
  {
    v8 = ogg_stream_packetpeek(&vf->os, &op);
    posa = v8;
    if ( !v8 )
    {
      v9 = seek_helper(vf, v20);
      posa = v9;
      if ( (int)v9 >> 31 >= 0 && (int)v9 < 0 || (int)v9 >> 31 >= 0 )
      {
        while ( 1 )
        {
          posa = get_prev_page(vf, &v12);
          if ( posa < 0 )
            break;
          if ( ogg_page_serialno(&v12) == vf->current_serialno )
          {
            ogg_page_granulepos(&v12);
            if ( v10 > -1 || !ogg_page_continued(&v12) )
              return ov_raw_seek(vf, posa);
          }
          vf->offset = posa;
        }
      }
      goto seek_error_0;
    }
    if ( posa < 0 )
    {
      posa = -136;
      goto seek_error_0;
    }
    if ( (HIDWORD(op.granulepos) & op.granulepos) != -1 )
      break;
    posa = ogg_stream_packetout(&vf->os, 0);
  }
  vf->pcm_offset = op.granulepos - vf->pcmlengths[2 * vf->current_link];
  if ( vf->pcm_offset < 0 )
    vf->pcm_offset = 0;
  vf->pcm_offset += v24;
  if ( vf->pcm_offset > pos || pos > ov_pcm_total(vf, -1) )
  {
    posa = -129;
    goto seek_error_0;
  }
  vf->bittrack = 0.0;
  vf->samptrack = 0.0;
  return 0;
}
