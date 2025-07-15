void __stdcall Scaleform::UTF8Util::EncodeString(char *pbuff, wchar_t *pchar, int length)
{
  int v3; // esi
  wchar_t v4; // ax
  int pindex; // [esp+Ch] [ebp-4h] BYREF

  v3 = 0;
  pindex = 0;
  if ( length == -1 )
  {
    v4 = *pchar;
    if ( *pchar )
    {
      do
      {
        Scaleform::UTF8Util::EncodeChar(pbuff, &pindex, v4);
        v4 = pchar[++v3];
      }
      while ( v4 );
      pbuff[pindex] = 0;
    }
    else
    {
      *pbuff = 0;
    }
  }
  else if ( length <= 0 )
  {
    *pbuff = 0;
  }
  else
  {
    do
      Scaleform::UTF8Util::EncodeChar(pbuff, &pindex, pchar[v3++]);
    while ( v3 < length );
    pbuff[pindex] = 0;
  }
}
