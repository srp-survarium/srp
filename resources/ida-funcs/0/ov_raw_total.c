__int64 __cdecl ov_raw_total(OggVorbis_File *vf, int i)
{
  __int64 v3; // [esp+8h] [ebp-10h]
  int ia; // [esp+14h] [ebp-4h]

  if ( vf->ready_state < 2 )
    return -131;
  if ( !vf->seekable || i >= vf->links )
    return -131;
  if ( i >= 0 )
    return vf->offsets[i + 1] - vf->offsets[i];
  v3 = 0;
  for ( ia = 0; ia < vf->links; ++ia )
    v3 += ov_raw_total(vf, ia);
  return v3;
}
