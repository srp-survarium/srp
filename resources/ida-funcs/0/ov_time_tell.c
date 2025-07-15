double __cdecl ov_time_tell(OggVorbis_File *vf)
{
  int i; // [esp+10h] [ebp-14h]
  double v3; // [esp+14h] [ebp-10h]
  __int64 v4; // [esp+1Ch] [ebp-8h]

  i = 0;
  v4 = 0;
  v3 = 0.0;
  if ( vf->ready_state < 2 )
    return -131.0;
  if ( vf->seekable )
  {
    v4 = ov_pcm_total(vf, -1);
    v3 = ov_time_total(vf, -1);
    for ( i = vf->links - 1; i >= 0; --i )
    {
      v4 -= vf->pcmlengths[2 * i + 1];
      v3 = v3 - ov_time_total(vf, i);
      if ( vf->pcm_offset >= v4 )
        break;
    }
  }
  return (double)(vf->pcm_offset - v4) / (double)vf->vi[i].rate + v3;
}
