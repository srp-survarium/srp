int __cdecl ov_fopen(const char *path, OggVorbis_File *vf)
{
  int ret; // [esp+0h] [ebp-8h]
  _iobuf *f; // [esp+4h] [ebp-4h]

  f = fopen(path, mode);
  if ( !f )
    return -1;
  ret = ov_open(f, vf, 0, 0);
  if ( ret )
    fclose(f);
  return ret;
}
