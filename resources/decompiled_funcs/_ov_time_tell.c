double __cdecl ov_time_tell(OggVorbis_File *vf)
{
  int link; // [esp+10h] [ebp-14h]
  double time_total; // [esp+14h] [ebp-10h]
  __int64 pcm_total; // [esp+1Ch] [ebp-8h]

  link = 0;
  pcm_total = 0;
  time_total = 0.0;
  if ( vf->ready_state < 2 )
    return -131.0;
  if ( vf->seekable )
  {
    pcm_total = ov_pcm_total(vf, -1);
    time_total = ov_time_total(vf, -1);
    for ( link = vf->links - 1; link >= 0; --link )
    {
      pcm_total -= vf->pcmlengths[2 * link + 1];
      time_total = time_total - ov_time_total(vf, link);
      if ( vf->pcm_offset >= pcm_total )
        break;
    }
  }
  return (double)(vf->pcm_offset - pcm_total) / (double)vf->vi[link].rate + time_total;
}
