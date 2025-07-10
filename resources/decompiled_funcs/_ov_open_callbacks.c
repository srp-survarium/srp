int __cdecl ov_open_callbacks(void *f, OggVorbis_File *vf, const char *initial, int ibytes, ov_callbacks callbacks)
{
  int ret; // [esp+10h] [ebp-4h]

  ret = ov_open1(f, vf, initial, ibytes, callbacks);
  if ( ret )
    return ret;
  else
    return ov_open2(vf);
}
