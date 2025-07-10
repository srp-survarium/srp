unsigned int __cdecl Scaleform::Render::Text::ImageSubstCmp::StrCompare(
        const wchar_t *dst,
        int dstlen,
        const wchar_t *src,
        unsigned int srclen,
        bool insertion)
{
  unsigned int v5; // edi
  unsigned int v8; // ebx
  int v9; // eax
  int v10; // esi

  v5 = dstlen;
  if ( !dstlen )
    return -srclen;
  v8 = srclen;
  do
  {
    v9 = *dst;
    v10 = *src;
    ++dst;
    ++src;
    if ( !--v5 || !v9 )
      break;
    if ( v9 != v10 )
      return v9 - v10;
    --v8;
  }
  while ( v8 );
  if ( v9 == v10 && v8 && (!insertion || v5) )
    return dstlen - srclen;
  return v9 - v10;
}
