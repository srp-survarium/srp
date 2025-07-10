unsigned int __cdecl Scaleform::Render::Text::SGMLCharIter<wchar_t>::StrCompare(
        const wchar_t *wstr,
        const char *str,
        const char *len)
{
  unsigned int v3; // ebp
  const char *v4; // esi
  int v6; // ebx
  int v7; // eax

  v3 = (unsigned int)len;
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
    return (unsigned int)&len[-strlen(str)];
  return v6 - v7;
}
