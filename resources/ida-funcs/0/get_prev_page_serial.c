__int64 __cdecl get_prev_page_serial(
        OggVorbis_File *vf,
        int *serial_list,
        int serial_n,
        int *serialno,
        __int64 *granpos)
{
  int v5; // eax
  int v7; // edx
  __int64 s; // [esp+Ch] [ebp-48h]
  ogg_page og; // [esp+14h] [ebp-40h] BYREF
  __int64 v10; // [esp+24h] [ebp-30h]
  __int64 next_page; // [esp+2Ch] [ebp-28h]
  __int64 v12; // [esp+34h] [ebp-20h]
  __int64 v13; // [esp+3Ch] [ebp-18h]
  __int64 v14; // [esp+44h] [ebp-10h]
  __int64 offset; // [esp+4Ch] [ebp-8h]

  offset = vf->offset;
  v12 = offset;
  v10 = -1;
  v13 = -1;
  LODWORD(s) = -1;
  v14 = -1;
LABEL_2:
  while ( (HIDWORD(v13) & (unsigned int)v13) == 0xFFFFFFFF )
  {
    offset -= (unsigned int)&_sbh_sizeHeaderList;
    if ( offset < 0 )
      offset = 0;
    v5 = seek_helper(vf, offset);
    next_page = v5;
    if ( v5 )
      return next_page;
    while ( vf->offset < v12 )
    {
      next_page = get_next_page(vf, &og, v12 - vf->offset);
      if ( next_page == -128 )
        return -128;
      if ( next_page < 0 )
        goto LABEL_2;
      s = ogg_page_serialno(&og);
      LODWORD(v14) = ogg_page_granulepos(&og);
      HIDWORD(v14) = v7;
      v13 = next_page;
      if ( s == *serialno )
      {
        v10 = next_page;
        *granpos = v14;
      }
      if ( !lookup_serialno(s, serial_list, serial_n) )
        v10 = -1;
    }
  }
  if ( v10 >= 0 )
    return v10;
  *serialno = s;
  *granpos = v14;
  return v13;
}
