double __cdecl ov_time_total(OggVorbis_File *vf, int i)
{
  double acc; // [esp+0h] [ebp-10h]
  int j; // [esp+Ch] [ebp-4h]

  if ( vf->ready_state < 2 )
    return -131.0;
  if ( !vf->seekable || i >= vf->links )
    return -131.0;
  if ( i >= 0 )
    return (double)vf->pcmlengths[2 * i + 1] / (double)vf->vi[i].rate;
  acc = 0.0;
  for ( j = 0; j < vf->links; ++j )
    acc = ov_time_total(vf, j) + acc;
  return acc;
}
