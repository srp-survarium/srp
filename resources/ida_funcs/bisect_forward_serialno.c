int __cdecl bisect_forward_serialno(
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
  int v9; // eax
  int v11; // eax
  int headers; // eax
  int v13; // edx
  __int64 *pcmlengths; // ecx
  __int64 v15; // [esp+20h] [ebp-9Ch]
  int testserial; // [esp+28h] [ebp-94h] BYREF
  __int64 bisect; // [esp+2Ch] [ebp-90h]
  int next_serialnos; // [esp+34h] [ebp-88h] BYREF
  vorbis_comment vc; // [esp+38h] [ebp-84h] BYREF
  int *next_serialno_list; // [esp+48h] [ebp-74h] BYREF
  vorbis_info vi; // [esp+4Ch] [ebp-70h] BYREF
  __int64 searchgran; // [esp+6Ch] [ebp-50h] BYREF
  __int64 pcmoffset; // [esp+74h] [ebp-48h]
  ogg_page og; // [esp+7Ch] [ebp-40h] BYREF
  __int64 dataoffset; // [esp+8Ch] [ebp-30h]
  __int64 ret; // [esp+94h] [ebp-28h]
  __int64 next; // [esp+9Ch] [ebp-20h]
  __int64 last; // [esp+A4h] [ebp-18h]
  __int64 endsearched; // [esp+ACh] [ebp-10h]
  int serialno; // [esp+B8h] [ebp-4h]

  dataoffset = searched;
  endsearched = end;
  next = end;
  searchgran = -1;
  serialno = vf->os.serialno;
  if ( lookup_serialno(endserial, currentno_list, currentnos) )
  {
    while ( endserial != serialno )
    {
      endserial = serialno;
      vf->offset = get_prev_page_serial(vf, currentno_list, currentnos, &endserial, &endgran);
    }
    vf->links = m + 1;
    if ( vf->offsets )
      free(vf->offsets);
    if ( vf->serialnos )
      free(vf->serialnos);
    if ( vf->dataoffsets )
      free(vf->dataoffsets);
    vf->offsets = (__int64 *)malloc(8 * vf->links + 8);
    vf->vi = (vorbis_info *)realloc(vf->vi, 32 * vf->links);
    vf->vc = (vorbis_comment *)realloc(vf->vc, 16 * vf->links);
    vf->serialnos = (int *)malloc(4 * vf->links);
    vf->dataoffsets = (__int64 *)malloc(8 * vf->links);
    vf->pcmlengths = (__int64 *)malloc(16 * vf->links);
    vf->offsets[m + 1] = end;
    vf->offsets[m] = begin;
    if ( endgran < 0 )
      v15 = 0;
    else
      v15 = endgran;
    vf->pcmlengths[2 * m + 1] = v15;
  }
  else
  {
    next_serialno_list = 0;
    next_serialnos = 0;
    while ( searched < endsearched )
    {
      if ( endsearched - searched >= (unsigned int)&_sbh_sizeHeaderList )
        bisect = (endsearched + searched) / 2;
      else
        bisect = searched;
      if ( bisect != vf->offset )
      {
        v9 = seek_helper(vf, bisect);
        ret = v9;
        if ( v9 )
          return ret;
      }
      last = get_next_page(vf, &og, -1);
      if ( last == -128 )
        return -128;
      if ( last >= 0 && lookup_page_serialno(&og, currentno_list, currentnos) )
      {
        searched = vf->offset;
      }
      else
      {
        endsearched = bisect;
        if ( last >= 0 )
          next = last;
      }
    }
    testserial = serialno + 1;
    vf->offset = next;
    while ( testserial != serialno )
    {
      testserial = serialno;
      vf->offset = get_prev_page_serial(vf, currentno_list, currentnos, &testserial, &searchgran);
    }
    if ( vf->offset != next )
    {
      v11 = seek_helper(vf, next);
      ret = v11;
      if ( v11 )
        return ret;
    }
    headers = fetch_headers(vf, &vi, &vc, (void **)&next_serialno_list, &next_serialnos, 0);
    ret = headers;
    if ( headers )
      return ret;
    serialno = vf->os.serialno;
    dataoffset = vf->offset;
    pcmoffset = initial_pcmoffset(vf, &vi);
    ret = bisect_forward_serialno(
            vf,
            next,
            vf->offset,
            end,
            endgran,
            endserial,
            next_serialno_list,
            next_serialnos,
            m + 1);
    if ( (_DWORD)ret )
      return ret;
    if ( next_serialno_list )
      free(next_serialno_list);
    vf->offsets[m + 1] = next;
    vf->serialnos[m + 1] = serialno;
    vf->dataoffsets[m + 1] = dataoffset;
    qmemcpy(&vf->vi[m + 1], &vi, sizeof(vf->vi[m + 1]));
    vf->vc[m + 1] = vc;
    vf->pcmlengths[2 * m + 1] = searchgran;
    vf->pcmlengths[2 * m + 2] = pcmoffset;
    vf->pcmlengths[2 * m + 3] -= pcmoffset;
    if ( vf->pcmlengths[2 * m + 3] < 0 )
    {
      v13 = 2 * m;
      pcmlengths = vf->pcmlengths;
      LODWORD(pcmlengths[v13 + 3]) = 0;
      HIDWORD(pcmlengths[v13 + 3]) = 0;
    }
  }
  return 0;
}
