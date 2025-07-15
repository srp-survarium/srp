int __cdecl ov_time_seek_lap(OggVorbis_File *vf, long double pos)
{
  return ov_d_seek_lap(vf, pos, (int (__cdecl *)(OggVorbis_File *, long double))ov_time_seek);
}
