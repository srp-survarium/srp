int __usercall ov_pcm_seek_page_lap@<eax>(__int128 a1@<xmm0>, OggVorbis_File *vf, __int64 pos)
{
  return ov_64_seek_lap(a1, vf, pos, ov_pcm_seek_page);
}
