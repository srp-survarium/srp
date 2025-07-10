void __stdcall Scaleform::UTF8Util::EncodeString(char *pbuff, wchar_t *pchar, int length)
{
  int v3; // esi
  wchar_t v4; // ax
  int ofs; // [esp+Ch] [ebp-4h] BYREF

  v3 = 0;
  ofs = 0;
  if ( length == -1 )
  {
    v4 = *pchar;
    if ( *pchar )
    {
      do
      {
        Scaleform::UTF8Util::EncodeChar(pbuff, &ofs, v4);
        v4 = pchar[++v3];
      }
      while ( v4 );
      pbuff[ofs] = 0;
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
      Scaleform::UTF8Util::EncodeChar(pbuff, &ofs, pchar[v3++]);
    while ( v3 < length );
    pbuff[ofs] = 0;
  }
}
