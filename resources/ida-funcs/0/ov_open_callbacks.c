int __cdecl ov_open_callbacks(void *f, OggVorbis_File *vf, char *initial, int ibytes, ov_callbacks callbacks)
{
  int v6; // [esp+10h] [ebp-4h]

  v6 = ov_open1(f, vf, initial, ibytes, callbacks);
  if ( v6 )
    return v6;
  else
    return ov_open2(vf);
}
