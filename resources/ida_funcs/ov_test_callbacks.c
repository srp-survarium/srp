int __cdecl ov_test_callbacks(void *f, OggVorbis_File *vf, char *initial, int ibytes, ov_callbacks callbacks)
{
  return ov_open1(f, vf, initial, ibytes, callbacks);
}
