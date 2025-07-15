int __cdecl ov_raw_seek_lap(OggVorbis_File *vf, __int64 pos)
{
  return ov_64_seek_lap(vf, pos, ov_raw_seek);
}
