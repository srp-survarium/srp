const char *__cdecl Scaleform::GetShortFilename(const char *purl)
{
  const char *result; // eax
  unsigned int v2; // ecx
  char v3; // dl

  result = purl;
  v2 = strlen(purl);
  if ( v2 )
  {
    while ( 1 )
    {
      v3 = purl[v2];
      if ( v3 == 92 || v3 == 47 )
        break;
      if ( !--v2 )
        return result;
    }
    return &purl[v2 + 1];
  }
  return result;
}
