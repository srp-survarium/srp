int __usercall ov_time_seek_page_lap@<eax>(__int128 a1@<xmm0>, OggVorbis_File *vf, long double pos)
{
  return ov_d_seek_lap(a1, vf, pos, (int (__cdecl *)(OggVorbis_File *, long double))ov_time_seek_page);
}
