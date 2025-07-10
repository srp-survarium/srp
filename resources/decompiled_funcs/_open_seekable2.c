int __cdecl open_seekable2(OggVorbis_File *vf)
{
  __int64 *offsets; // eax
  __int64 *pcmlengths; // ecx
  int endserial; // [esp+8h] [ebp-2Ch] BYREF
  __int64 pcmoffset; // [esp+Ch] [ebp-28h]
  __int64 dataoffset; // [esp+14h] [ebp-20h]
  __int64 end; // [esp+1Ch] [ebp-18h]
  __int64 endgran; // [esp+24h] [ebp-10h] BYREF
  int serialno; // [esp+30h] [ebp-4h]

  dataoffset = *vf->dataoffsets;
  endgran = -1;
  endserial = vf->os.serialno;
  serialno = vf->os.serialno;
  pcmoffset = initial_pcmoffset(vf, vf->vi);
  if ( vf->callbacks.seek_func && vf->callbacks.tell_func )
  {
    ((void (__cdecl *)(void *, _DWORD, _DWORD, int))vf->callbacks.seek_func)(vf->datasource, 0, 0, 2);
    vf->end = vf->callbacks.tell_func(vf->datasource);
    vf->offset = vf->end;
  }
  else
  {
    vf->end = -1;
    vf->offset = -1;
  }
  if ( (HIDWORD(vf->end) & vf->end) == -1 )
    return -131;
  end = get_prev_page_serial(vf, vf->serialnos + 2, vf->serialnos[1], &endserial, &endgran);
  if ( end < 0 )
    return end;
  if ( bisect_forward_serialno(
         vf,
         0,
         dataoffset,
         vf->offset,
         endgran,
         endserial,
         vf->serialnos + 2,
         vf->serialnos[1],
         0) < 0 )
    return -128;
  offsets = vf->offsets;
  *(_DWORD *)offsets = 0;
  *((_DWORD *)offsets + 1) = 0;
  *vf->serialnos = serialno;
  *vf->dataoffsets = dataoffset;
  *vf->pcmlengths = pcmoffset;
  vf->pcmlengths[1] -= pcmoffset;
  if ( *((int *)vf->pcmlengths + 3) < 0 )
  {
    pcmlengths = vf->pcmlengths;
    *((_DWORD *)pcmlengths + 2) = 0;
    *((_DWORD *)pcmlengths + 3) = 0;
  }
  return ov_raw_seek(vf, dataoffset);
}
