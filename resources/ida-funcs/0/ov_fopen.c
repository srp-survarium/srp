int __cdecl ov_fopen(char *path, OggVorbis_File *vf)
{
  int v3; // [esp+0h] [ebp-8h]
  _iobuf *stream; // [esp+4h] [ebp-4h]

  stream = fopen(path, aRb_1);
  if ( !stream )
    return -1;
  v3 = ov_open(stream, vf, 0, 0);
  if ( v3 )
    fclose(stream);
  return v3;
}
