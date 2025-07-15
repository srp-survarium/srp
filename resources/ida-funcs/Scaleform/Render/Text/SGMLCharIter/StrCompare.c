unsigned int __cdecl Scaleform::Render::Text::SGMLCharIter<wchar_t>::StrCompare(
        const wchar_t *dst,
        unsigned int dstlen,
        const wchar_t *src,
        unsigned int srclen)
{
  unsigned int v4; // ebp
  int v7; // ebx
  int v8; // eax
  unsigned int v10; // [esp+4h] [ebp-4h]

  v4 = dstlen;
  if ( !dstlen )
    return -srclen;
  v10 = srclen;
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
    return dstlen - v10;
  return v7 - v8;
}


unsigned int __cdecl Scaleform::Render::Text::SGMLCharIter<wchar_t>::StrCompare(
        const wchar_t *wstr,
        const char *str,
        unsigned int len)
{
  unsigned int v3; // ebp
  const char *v4; // esi
  int v6; // ebx
  int v7; // eax

  v3 = len;
  if ( !len )
    return -strlen(str);
  v4 = str;
  do
  {
    v6 = Scaleform::SFtowlower(*wstr++);
    v7 = Scaleform::SFtowlower(*v4++);
    if ( !--v3 || !v6 )
      break;
    if ( v6 != v7 )
      return v6 - v7;
  }
  while ( *v4 );
  if ( v6 == v7 && (v3 || *v4) )
    return len - strlen(str);
  return v6 - v7;
}
