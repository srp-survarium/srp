__int64 __cdecl get_prev_page(OggVorbis_File *vf, ogg_page *og)
{
  __int64 result; // rax
  __int64 ret; // [esp+4h] [ebp-20h]
  __int64 end; // [esp+Ch] [ebp-18h]
  __int64 offset; // [esp+14h] [ebp-10h]
  __int64 begin; // [esp+1Ch] [ebp-8h]

  begin = vf->offset;
  end = begin;
  offset = -1;
LABEL_2:
  while ( (HIDWORD(offset) & (unsigned int)offset) == 0xFFFFFFFF )
  {
    begin -= (unsigned int)&_sbh_sizeHeaderList;
    if ( begin < 0 )
      begin = 0;
    LODWORD(result) = seek_helper(vf, begin);
    if ( (_DWORD)result )
      return (int)result;
    while ( vf->offset < end )
    {
      memset((unsigned __int8 *)og, 0, sizeof(ogg_page));
      ret = get_next_page(vf, og, end - vf->offset);
      if ( ret == -128 )
        return -128;
      if ( ret < 0 )
        goto LABEL_2;
      offset = ret;
    }
  }
  if ( og->header_len )
    return offset;
  LODWORD(result) = seek_helper(vf, offset);
  if ( (_DWORD)result )
    return (int)result;
  if ( (((unsigned __int64)get_next_page(vf, og, (unsigned int)&_sbh_sizeHeaderList) >> 32) & 0x80000000) == 0LL )
    return offset;
  else
    return -129;
}
