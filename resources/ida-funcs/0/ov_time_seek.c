int __cdecl ov_time_seek(OggVorbis_File *vf, double a2)
{
  double v3; // [esp+Ch] [ebp-20h]
  int i; // [esp+18h] [ebp-14h]
  double v5; // [esp+1Ch] [ebp-10h]
  __int64 v6; // [esp+24h] [ebp-8h]

  v6 = 0;
  v5 = 0.0;
  if ( vf->ready_state < 2 )
    return -131;
  if ( !vf->seekable )
    return -138;
  if ( a2 < 0.0 )
    return -131;
  for ( i = 0; i < vf->links; ++i )
  {
    v3 = ov_time_total(vf, i);
    if ( v5 + v3 > a2 )
      break;
    v5 = v5 + v3;
    v6 += vf->pcmlengths[2 * i + 1];
  }
  if ( i == vf->links )
    return -131;
  else
    return ov_pcm_seek(vf, (unsigned __int64)((double)v6 + (a2 - v5) * (double)vf->vi[i].rate));
}
