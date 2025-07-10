int __cdecl ov_pcm_seek_page(OggVorbis_File *vf, __int64 pos)
{
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  __int64 v8; // rax
  ogg_packet op; // [esp+64h] [ebp-98h] BYREF
  ogg_page v10; // [esp+84h] [ebp-78h] BYREF
  __int64 granulepos; // [esp+94h] [ebp-68h]
  __int64 bisect; // [esp+9Ch] [ebp-60h]
  __int64 endtime; // [esp+A4h] [ebp-58h]
  ogg_page og; // [esp+ACh] [ebp-50h] BYREF
  __int64 target; // [esp+BCh] [ebp-40h]
  __int64 end; // [esp+C4h] [ebp-38h]
  __int64 begintime; // [esp+CCh] [ebp-30h]
  __int64 best; // [esp+D4h] [ebp-28h]
  __int64 begin; // [esp+DCh] [ebp-20h]
  __int64 result; // [esp+E4h] [ebp-18h]
  int link; // [esp+F0h] [ebp-Ch]
  __int64 total; // [esp+F4h] [ebp-8h]

  link = -1;
  result = 0;
  total = ov_pcm_total(vf, -1);
  if ( vf->ready_state < 2 )
    return -131;
  if ( !vf->seekable )
    return -138;
  if ( pos < 0 || pos > total )
    return -131;
  for ( link = vf->links - 1; link >= 0; --link )
  {
    total -= vf->pcmlengths[2 * link + 1];
    if ( pos >= total )
      break;
  }
  end = vf->offsets[link + 1];
  begin = vf->offsets[link];
  begintime = vf->pcmlengths[2 * link];
  endtime = begintime + vf->pcmlengths[2 * link + 1];
  target = begintime + pos - total;
  best = begin;
LABEL_13:
  while ( begin < end )
  {
    if ( end - begin >= (unsigned int)&_sbh_sizeHeaderList )
    {
      bisect = begin
             + (unsigned __int64)((double)(target - begintime) * (double)(end - begin) / (double)(endtime - begintime))
             - (unsigned int)&_sbh_sizeHeaderList;
      if ( bisect < (int)((int)&_sbh_sizeHeaderList + begin) )
        bisect = begin;
    }
    else
    {
      bisect = begin;
    }
    if ( bisect != vf->offset )
    {
      v3 = seek_helper(vf, bisect);
      result = v3;
      if ( v3 )
        goto seek_error_0;
    }
    while ( begin < end )
    {
      result = get_next_page(vf, &og, end - vf->offset);
      if ( result == -128 )
        goto seek_error_0;
      if ( result >= 0 )
      {
        v5 = ogg_page_serialno(&og);
        if ( v5 == vf->serialnos[link] )
        {
          granulepos = ogg_page_granulepos(&og);
          if ( (HIDWORD(granulepos) & (unsigned int)granulepos) != 0xFFFFFFFF )
          {
            if ( granulepos >= target )
            {
              if ( bisect > begin + 1 )
              {
                if ( end != vf->offset )
                {
                  end = bisect;
                  endtime = granulepos;
                  goto LABEL_13;
                }
                end = result;
                bisect -= (unsigned int)&_sbh_sizeHeaderList;
                if ( bisect <= begin )
                  bisect = begin + 1;
                v6 = seek_helper(vf, bisect);
                result = v6;
                if ( v6 )
                  goto seek_error_0;
              }
              else
              {
                end = begin;
              }
            }
            else
            {
              best = result;
              begin = vf->offset;
              begintime = granulepos;
              if ( target - granulepos > 44100 )
                goto LABEL_13;
              bisect = begin;
            }
          }
        }
      }
      else if ( bisect > begin + 1 )
      {
        if ( !bisect )
          goto seek_error_0;
        bisect -= (unsigned int)&_sbh_sizeHeaderList;
        if ( bisect <= begin )
          bisect = begin + 1;
        v4 = seek_helper(vf, bisect);
        result = v4;
        if ( v4 )
          goto seek_error_0;
      }
      else
      {
        end = begin;
      }
    }
  }
  result = seek_helper(vf, best);
  vf->pcm_offset = -1;
  if ( result || (result = get_next_page(vf, &v10, -1), result < 0) )
  {
seek_error_0:
    vf->pcm_offset = -1;
    decode_clear(vf);
    return result;
  }
  if ( link == vf->current_link )
  {
    vorbis_synthesis_restart(&vf->vd);
  }
  else
  {
    decode_clear(vf);
    vf->current_link = link;
    vf->current_serialno = vf->serialnos[link];
    vf->ready_state = 3;
  }
  ogg_stream_reset_serialno(&vf->os, vf->current_serialno);
  ogg_stream_pagein(&vf->os, &v10);
  while ( 1 )
  {
    v7 = ogg_stream_packetpeek(&vf->os, &op);
    result = v7;
    if ( !v7 )
    {
      v8 = seek_helper(vf, best);
      result = v8;
      if ( (int)v8 >> 31 >= 0 && (int)v8 < 0 || (int)v8 >> 31 >= 0 )
      {
        while ( 1 )
        {
          result = get_prev_page(vf, &v10);
          if ( result < 0 )
            break;
          if ( ogg_page_serialno(&v10) == vf->current_serialno
            && ((int)((unsigned __int64)ogg_page_granulepos(&v10) >> 32) > -1 || !ogg_page_continued(&v10)) )
          {
            return ov_raw_seek(vf, result);
          }
          vf->offset = result;
        }
      }
      goto seek_error_0;
    }
    if ( result < 0 )
    {
      result = -136;
      goto seek_error_0;
    }
    if ( (HIDWORD(op.granulepos) & op.granulepos) != -1 )
      break;
    result = ogg_stream_packetout(&vf->os, 0);
  }
  vf->pcm_offset = op.granulepos - vf->pcmlengths[2 * vf->current_link];
  if ( vf->pcm_offset < 0 )
    vf->pcm_offset = 0;
  vf->pcm_offset += total;
  if ( vf->pcm_offset > pos || pos > ov_pcm_total(vf, -1) )
  {
    result = -129;
    goto seek_error_0;
  }
  vf->bittrack = 0.0;
  vf->samptrack = 0.0;
  return 0;
}
