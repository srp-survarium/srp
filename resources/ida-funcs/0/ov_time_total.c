double __cdecl ov_time_total(OggVorbis_File *vf, int i)
{
  double v3; // [esp+0h] [ebp-10h]
  int ia; // [esp+Ch] [ebp-4h]

  if ( vf->ready_state < 2 )
    return -131.0;
  if ( !vf->seekable || i >= vf->links )
    return -131.0;
  if ( i >= 0 )
    return (double)vf->pcmlengths[2 * i + 1] / (double)vf->vi[i].rate;
  v3 = 0.0;
  for ( ia = 0; ia < vf->links; ++ia )
    v3 = ov_time_total(vf, ia) + v3;
  return v3;
}
