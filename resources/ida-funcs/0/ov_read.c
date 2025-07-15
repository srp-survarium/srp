int __usercall ov_read@<eax>(
        __int128 a1@<xmm0>,
        OggVorbis_File *vf,
        char *buffer,
        int length,
        int bigendianp,
        int word,
        int sgned,
        int *bitstream)
{
  return ov_read_filter(a1, vf, buffer, length, bigendianp, word, sgned, bitstream, 0, 0);
}
