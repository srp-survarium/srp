__int64 __cdecl ov_raw_total(OggVorbis_File *vf, int i)
{
  __int64 acc; // [esp+8h] [ebp-10h]
  int j; // [esp+14h] [ebp-4h]

  if ( vf->ready_state < 2 )
    return -131;
  if ( !vf->seekable || i >= vf->links )
    return -131;
  if ( i >= 0 )
    return vf->offsets[i + 1] - vf->offsets[i];
  acc = 0;
  for ( j = 0; j < vf->links; ++j )
    acc += ov_raw_total(vf, j);
  return acc;
}
