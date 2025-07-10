__int64 __cdecl ov_pcm_total(OggVorbis_File *vf, int i)
{
  __int64 acc; // [esp+0h] [ebp-10h]
  int j; // [esp+Ch] [ebp-4h]

  if ( vf->ready_state < 2 )
    return -131;
  if ( !vf->seekable || i >= vf->links )
    return -131;
  if ( i >= 0 )
    return vf->pcmlengths[2 * i + 1];
  acc = 0;
  for ( j = 0; j < vf->links; ++j )
    acc += ov_pcm_total(vf, j);
  return acc;
}
