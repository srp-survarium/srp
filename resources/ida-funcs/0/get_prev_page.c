__int64 __cdecl get_prev_page(OggVorbis_File *vf, ogg_page *og)
{
  __int64 result; // rax
  __int64 next_page; // [esp+4h] [ebp-20h]
  __int64 v4; // [esp+Ch] [ebp-18h]
  __int64 v5; // [esp+14h] [ebp-10h]
  __int64 offset; // [esp+1Ch] [ebp-8h]

  offset = vf->offset;
  v4 = offset;
  v5 = -1;
LABEL_2:
  while ( (HIDWORD(v5) & (unsigned int)v5) == 0xFFFFFFFF )
  {
    offset -= (unsigned int)&_sbh_sizeHeaderList;
    if ( offset < 0 )
      offset = 0;
    LODWORD(result) = seek_helper(vf, offset);
    if ( (_DWORD)result )
      return (int)result;
    while ( vf->offset < v4 )
    {
      memset((int)og, 0, sizeof(ogg_page));
      next_page = get_next_page(vf, og, v4 - vf->offset);
      if ( next_page == -128 )
        return -128;
      if ( next_page < 0 )
        goto LABEL_2;
      v5 = next_page;
    }
  }
  if ( og->header_len )
    return v5;
  LODWORD(result) = seek_helper(vf, v5);
  if ( (_DWORD)result )
    return (int)result;
  if ( (((unsigned __int64)get_next_page(vf, og, (unsigned int)&_sbh_sizeHeaderList) >> 32) & 0x80000000) == 0LL )
    return v5;
  else
    return -129;
}
