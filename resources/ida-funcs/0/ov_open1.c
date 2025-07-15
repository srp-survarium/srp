int __cdecl ov_open1(void *f, OggVorbis_File *vf, char *initial, int ibytes, ov_callbacks callbacks)
{
  unsigned __int8 *v5; // eax
  __int64 *offsets; // eax
  int v8; // [esp+0h] [ebp-18h]
  int headers; // [esp+8h] [ebp-10h]
  int *serialno_list; // [esp+Ch] [ebp-Ch] BYREF
  int v11; // [esp+10h] [ebp-8h]
  int serialno_n; // [esp+14h] [ebp-4h] BYREF

  if ( f && callbacks.seek_func )
    v8 = ((int (__cdecl *)(void *, _DWORD, _DWORD, int))callbacks.seek_func)(f, 0, 0, 1);
  else
    v8 = -1;
  v11 = v8;
  serialno_list = 0;
  serialno_n = 0;
  memset((int)vf, 0, sizeof(OggVorbis_File));
  vf->datasource = f;
  vf->callbacks = callbacks;
  ogg_sync_init(&vf->oy);
  if ( initial )
  {
    v5 = (unsigned __int8 *)ogg_sync_buffer(&vf->oy, ibytes);
    memcpy(v5, (unsigned __int8 *)initial, ibytes);
    ogg_sync_wrote(&vf->oy, ibytes);
  }
  if ( v11 != -1 )
    vf->seekable = 1;
  vf->links = 1;
  vf->vi = (vorbis_info *)ogg_calloc_impl(vf->links, 0x20u);
  vf->vc = (vorbis_comment *)ogg_calloc_impl(vf->links, 0x10u);
  ogg_stream_init(&vf->os, -1);
  headers = fetch_headers(vf, vf->vi, vf->vc, (void **)&serialno_list, &serialno_n, 0);
  if ( headers >= 0 )
  {
    vf->serialnos = (int *)ogg_calloc_impl(serialno_n + 2, 4u);
    vf->current_serialno = vf->os.serialno;
    *vf->serialnos = vf->current_serialno;
    vf->serialnos[1] = serialno_n;
    memcpy((unsigned __int8 *)vf->serialnos + 8, (unsigned __int8 *)serialno_list, 4 * serialno_n);
    vf->offsets = (__int64 *)ogg_calloc_impl(1u, 8u);
    vf->dataoffsets = (__int64 *)ogg_calloc_impl(1u, 8u);
    offsets = vf->offsets;
    *(_DWORD *)offsets = 0;
    *((_DWORD *)offsets + 1) = 0;
    *vf->dataoffsets = vf->offset;
    vf->ready_state = 1;
  }
  else
  {
    vf->datasource = 0;
    ov_clear(vf);
  }
  if ( serialno_list )
    ogg_free_impl(serialno_list);
  return headers;
}
