__int64 __cdecl ov_pcm_total(OggVorbis_File *vf, int i)
{
  __int64 v3; // [esp+0h] [ebp-10h]
  int ia; // [esp+Ch] [ebp-4h]

  if ( vf->ready_state < 2 )
    return -131;
  if ( !vf->seekable || i >= vf->links )
    return -131;
  if ( i >= 0 )
    return vf->pcmlengths[2 * i + 1];
  v3 = 0;
  for ( ia = 0; ia < vf->links; ++ia )
    v3 += ov_pcm_total(vf, ia);
  return v3;
}
