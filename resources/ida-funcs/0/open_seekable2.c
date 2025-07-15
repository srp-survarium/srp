int __cdecl open_seekable2(OggVorbis_File *vf)
{
  __int64 *offsets; // eax
  __int64 *pcmlengths; // ecx
  int serialno; // [esp+8h] [ebp-2Ch] BYREF
  __int64 v5; // [esp+Ch] [ebp-28h]
  __int64 searched; // [esp+14h] [ebp-20h]
  __int64 prev_page_serial; // [esp+1Ch] [ebp-18h]
  __int64 granpos; // [esp+24h] [ebp-10h] BYREF
  int v9; // [esp+30h] [ebp-4h]

  searched = *vf->dataoffsets;
  granpos = -1;
  serialno = vf->os.serialno;
  v9 = vf->os.serialno;
  v5 = initial_pcmoffset(vf, vf->vi);
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
  prev_page_serial = get_prev_page_serial(vf, vf->serialnos + 2, vf->serialnos[1], &serialno, &granpos);
  if ( prev_page_serial < 0 )
    return prev_page_serial;
  if ( bisect_forward_serialno(vf, 0, searched, vf->offset, granpos, serialno, vf->serialnos + 2, vf->serialnos[1], 0) < 0 )
    return -128;
  offsets = vf->offsets;
  *(_DWORD *)offsets = 0;
  *((_DWORD *)offsets + 1) = 0;
  *vf->serialnos = v9;
  *vf->dataoffsets = searched;
  *vf->pcmlengths = v5;
  vf->pcmlengths[1] -= v5;
  if ( *((int *)vf->pcmlengths + 3) < 0 )
  {
    pcmlengths = vf->pcmlengths;
    *((_DWORD *)pcmlengths + 2) = 0;
    *((_DWORD *)pcmlengths + 3) = 0;
  }
  return ov_raw_seek(vf, searched);
}
