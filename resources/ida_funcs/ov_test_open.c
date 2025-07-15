int __cdecl ov_test_open(OggVorbis_File *vf)
{
  if ( vf->ready_state == 1 )
    return ov_open2(vf);
  else
    return -131;
}
