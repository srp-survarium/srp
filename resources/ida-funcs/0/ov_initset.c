int __usercall ov_initset@<eax>(__int128 a1@<xmm0>, OggVorbis_File *vf)
{
  int v3; // [esp+0h] [ebp-4h]

  while ( vf->ready_state != 4 )
  {
    v3 = fetch_and_process_packet(a1, vf, 0, 1, 0);
    if ( v3 < 0 && v3 != -3 )
      return v3;
  }
  return 0;
}
