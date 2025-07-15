int __cdecl ov_read(OggVorbis_File *vf, char *buffer, int length, int bigendianp, int word, int sgned, int *bitstream)
{
  return ov_read_filter(vf, buffer, length, bigendianp, word, sgned, bitstream, 0, 0);
}
