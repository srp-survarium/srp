unsigned int __cdecl Scaleform::Render::Text::SGMLCharIter<wchar_t>::StrCompare(
        const wchar_t *dst,
        int dstlen,
        const wchar_t *src,
        unsigned int srclen)
{
  unsigned int v4; // ebp
  int v7; // ebx
  int v8; // eax
  int slen; // [esp+4h] [ebp-4h]

  v4 = dstlen;
  if ( !dstlen )
    return -srclen;
  slen = srclen;
  do
  {
    v7 = Scaleform::SFtowlower(*dst++);
    v8 = Scaleform::SFtowlower(*src++);
    if ( !--v4 || !v7 )
      break;
    if ( v7 != v8 )
      return v7 - v8;
    --srclen;
  }
  while ( srclen );
  if ( v7 == v8 && (v4 || srclen) )
    return dstlen - slen;
  return v7 - v8;
}
