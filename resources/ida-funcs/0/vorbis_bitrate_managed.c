BOOL __usercall vorbis_bitrate_managed@<eax>(vorbis_block *vb@<eax>)
{
  _DWORD *v1; // eax

  v1 = (char *)vb->vd->backend_state + 80;
  return v1 && *v1;
}
