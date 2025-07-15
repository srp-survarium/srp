int __usercall bisect_forward_serialno@<eax>(
        __int128 a1@<xmm0>,
        OggVorbis_File *vf,
        __int64 begin,
        __int64 searched,
        __int64 end,
        __int64 endgran,
        int endserial,
        int *currentno_list,
        int currentnos,
        int m)
{
  int v10; // eax
  int v12; // eax
  int headers; // eax
  int v14; // edx
  __int64 *pcmlengths; // ecx
  __int64 v16; // [esp+20h] [ebp-9Ch]
  int serialno; // [esp+28h] [ebp-94h] BYREF
  __int64 offset; // [esp+2Ch] [ebp-90h]
  int currentnosa; // [esp+34h] [ebp-88h] BYREF
  vorbis_comment v20; // [esp+38h] [ebp-84h] BYREF
  int *currentno_lista; // [esp+48h] [ebp-74h] BYREF
  vorbis_info vi; // [esp+4Ch] [ebp-70h] BYREF
  __int64 v23; // [esp+6Ch] [ebp-50h] BYREF
  __int64 v24; // [esp+74h] [ebp-48h]
  ogg_page og; // [esp+7Ch] [ebp-40h] BYREF
  __int64 v26; // [esp+8Ch] [ebp-30h]
  __int64 v27; // [esp+94h] [ebp-28h]
  __int64 begina; // [esp+9Ch] [ebp-20h]
  __int64 next_page; // [esp+A4h] [ebp-18h]
  __int64 v30; // [esp+ACh] [ebp-10h]
  int v31; // [esp+B8h] [ebp-4h]

  v26 = searched;
  v30 = end;
  begina = end;
  v23 = -1;
  v31 = vf->os.serialno;
  if ( lookup_serialno(endserial, currentno_list, currentnos) )
  {
    while ( endserial != v31 )
    {
      endserial = v31;
      vf->offset = get_prev_page_serial(vf, currentno_list, currentnos, &endserial, &endgran);
    }
    vf->links = m + 1;
    if ( vf->offsets )
      ogg_free_impl(vf->offsets);
    if ( vf->serialnos )
      ogg_free_impl(vf->serialnos);
    if ( vf->dataoffsets )
      ogg_free_impl(vf->dataoffsets);
    vf->offsets = (__int64 *)ogg_malloc_impl(8 * vf->links + 8);
    vf->vi = (vorbis_info *)ogg_realloc_impl(vf->vi, 32 * vf->links);
    vf->vc = (vorbis_comment *)ogg_realloc_impl(vf->vc, 16 * vf->links);
    vf->serialnos = (int *)ogg_malloc_impl(4 * vf->links);
    vf->dataoffsets = (__int64 *)ogg_malloc_impl(8 * vf->links);
    vf->pcmlengths = (__int64 *)ogg_malloc_impl(16 * vf->links);
    vf->offsets[m + 1] = end;
    vf->offsets[m] = begin;
    if ( endgran < 0 )
      v16 = 0;
    else
      v16 = endgran;
    vf->pcmlengths[2 * m + 1] = v16;
  }
  else
  {
    currentno_lista = 0;
    currentnosa = 0;
    while ( searched < v30 )
    {
      if ( v30 - searched >= (unsigned int)&_sbh_sizeHeaderList )
        offset = (v30 + searched) / 2;
      else
        offset = searched;
      if ( offset != vf->offset )
      {
        v10 = seek_helper(vf, offset);
        v27 = v10;
        if ( v10 )
          return v27;
      }
      next_page = get_next_page(vf, &og, -1);
      if ( next_page == -128 )
        return -128;
      if ( next_page >= 0 && lookup_page_serialno(&og, currentno_list, currentnos) )
      {
        searched = vf->offset;
      }
      else
      {
        v30 = offset;
        if ( next_page >= 0 )
          begina = next_page;
      }
    }
    serialno = v31 + 1;
    vf->offset = begina;
    while ( serialno != v31 )
    {
      serialno = v31;
      vf->offset = get_prev_page_serial(vf, currentno_list, currentnos, &serialno, &v23);
    }
    if ( vf->offset != begina )
    {
      v12 = seek_helper(vf, begina);
      v27 = v12;
      if ( v12 )
        return v27;
    }
    headers = fetch_headers(a1, vf, &vi, &v20, (void **)&currentno_lista, &currentnosa, 0);
    v27 = headers;
    if ( headers )
      return v27;
    v31 = vf->os.serialno;
    v26 = vf->offset;
    v24 = initial_pcmoffset(vf, &vi);
    v27 = bisect_forward_serialno(vf, begina, vf->offset, end, endgran, endserial, currentno_lista, currentnosa, m + 1);
    if ( (_DWORD)v27 )
      return v27;
    if ( currentno_lista )
      ogg_free_impl(currentno_lista);
    vf->offsets[m + 1] = begina;
    vf->serialnos[m + 1] = v31;
    vf->dataoffsets[m + 1] = v26;
    qmemcpy(&vf->vi[m + 1], &vi, sizeof(vf->vi[m + 1]));
    vf->vc[m + 1] = v20;
    vf->pcmlengths[2 * m + 1] = v23;
    vf->pcmlengths[2 * m + 2] = v24;
    vf->pcmlengths[2 * m + 3] -= v24;
    if ( vf->pcmlengths[2 * m + 3] < 0 )
    {
      v14 = 2 * m;
      pcmlengths = vf->pcmlengths;
      LODWORD(pcmlengths[v14 + 3]) = 0;
      HIDWORD(pcmlengths[v14 + 3]) = 0;
    }
  }
  return 0;
}
