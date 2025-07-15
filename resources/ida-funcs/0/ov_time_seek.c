int __cdecl ov_time_seek(OggVorbis_File *vf, double seconds)
{
  double addsec; // [esp+Ch] [ebp-20h]
  int link; // [esp+18h] [ebp-14h]
  double time_total; // [esp+1Ch] [ebp-10h]
  __int64 pcm_total; // [esp+24h] [ebp-8h]

  pcm_total = 0;
  time_total = 0.0;
  if ( vf->ready_state < 2 )
    return -131;
  if ( !vf->seekable )
    return -138;
  if ( seconds < 0.0 )
    return -131;
  for ( link = 0; link < vf->links; ++link )
  {
    addsec = ov_time_total(vf, link);
    if ( time_total + addsec > seconds )
      break;
    time_total = time_total + addsec;
    pcm_total += vf->pcmlengths[2 * link + 1];
  }
  if ( link == vf->links )
    return -131;
  else
    return ov_pcm_seek(vf, (unsigned __int64)((double)pcm_total + (seconds - time_total) * (double)vf->vi[link].rate));
}
