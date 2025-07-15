void __cdecl decode_clear(OggVorbis_File *vf)
{
  vorbis_dsp_clear(&vf->vd);
  vorbis_block_clear(&vf->vb);
  vf->ready_state = 2;
}
