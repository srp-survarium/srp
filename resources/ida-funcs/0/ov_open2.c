int __cdecl ov_open2(OggVorbis_File *vf)
{
  int v2; // [esp+0h] [ebp-4h]

  if ( vf->ready_state != 1 )
    return -131;
  vf->ready_state = 2;
  if ( vf->seekable )
  {
    v2 = open_seekable2(vf);
    if ( v2 )
    {
      vf->datasource = 0;
      ov_clear(vf);
    }
    return v2;
  }
  else
  {
    vf->ready_state = 3;
    return 0;
  }
}
