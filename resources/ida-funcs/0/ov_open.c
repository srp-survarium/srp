int __cdecl ov_open(_iobuf *f, OggVorbis_File *vf, char *initial, int ibytes)
{
  ov_callbacks v5; // [esp-10h] [ebp-20h]

  v5.read_func = (unsigned int (__cdecl *)(void *, unsigned int, unsigned int, void *))fread;
  v5.seek_func = (int (__cdecl *)(void *, __int64, int))fseek64_wrap;
  v5.close_func = (int (__cdecl *)(void *))fclose;
  v5.tell_func = (int (__cdecl *)(void *))ftell;
  return ov_open_callbacks(f, vf, initial, ibytes, v5);
}
