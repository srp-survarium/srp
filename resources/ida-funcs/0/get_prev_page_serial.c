__int64 __cdecl get_prev_page_serial(
        OggVorbis_File *vf,
        int *serial_list,
        int serial_n,
        int *serialno,
        __int64 *granpos)
{
  int v5; // eax
  __int64 ret_serialno; // [esp+Ch] [ebp-48h]
  ogg_page og; // [esp+14h] [ebp-40h] BYREF
  __int64 prefoffset; // [esp+24h] [ebp-30h]
  __int64 ret; // [esp+2Ch] [ebp-28h]
  __int64 end; // [esp+34h] [ebp-20h]
  __int64 offset; // [esp+3Ch] [ebp-18h]
  __int64 ret_gran; // [esp+44h] [ebp-10h]
  __int64 begin; // [esp+4Ch] [ebp-8h]

  begin = vf->offset;
  end = begin;
  prefoffset = -1;
  offset = -1;
  LODWORD(ret_serialno) = -1;
  ret_gran = -1;
LABEL_2:
  while ( (HIDWORD(offset) & (unsigned int)offset) == 0xFFFFFFFF )
  {
    begin -= (unsigned int)&_sbh_sizeHeaderList;
    if ( begin < 0 )
      begin = 0;
    v5 = seek_helper(vf, begin);
    ret = v5;
    if ( v5 )
      return ret;
    while ( vf->offset < end )
    {
      ret = get_next_page(vf, &og, end - vf->offset);
      if ( ret == -128 )
        return -128;
      if ( ret < 0 )
        goto LABEL_2;
      ret_serialno = ogg_page_serialno(&og);
      ret_gran = ogg_page_granulepos(&og);
      offset = ret;
      if ( ret_serialno == *serialno )
      {
        prefoffset = ret;
        *granpos = ret_gran;
      }
      if ( !lookup_serialno(ret_serialno, serial_list, serial_n) )
        prefoffset = -1;
    }
  }
  if ( prefoffset >= 0 )
    return prefoffset;
  *serialno = ret_serialno;
  *granpos = ret_gran;
  return offset;
}
