int __cdecl ov_open2(OggVorbis_File *vf)
{
  int ret; // [esp+0h] [ebp-4h]

  if ( vf->ready_state != 1 )
    return -131;
  vf->ready_state = 2;
  if ( vf->seekable )
  {
    ret = open_seekable2(vf);
    if ( ret )
    {
      vf->datasource = 0;
      ov_clear(vf);
    }
    return ret;
  }
  else
  {
    vf->ready_state = 3;
    return 0;
  }
}
