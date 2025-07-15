int __cdecl ov_bitrate_instant(OggVorbis_File *vf)
{
  int current_link; // [esp+0h] [ebp-Ch]
  int ret; // [esp+8h] [ebp-4h]

  if ( vf->seekable )
    current_link = vf->current_link;
  else
    current_link = 0;
  if ( vf->ready_state < 2 )
    return -131;
  if ( 0.0 == vf->samptrack )
    return -1;
  ret = (int)(vf->bittrack / vf->samptrack * (double)vf->vi[current_link].rate + 0.5);
  vf->bittrack = 0.0;
  vf->samptrack = 0.0;
  return ret;
}
