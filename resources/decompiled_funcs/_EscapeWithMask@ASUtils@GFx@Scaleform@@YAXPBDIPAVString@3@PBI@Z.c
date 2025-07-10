void __cdecl Scaleform::GFx::ASUtils::EscapeWithMask(
        const char *psrc,
        unsigned int length,
        Scaleform::String *pescapedStr,
        const unsigned int *escapeMask)
{
  unsigned int v4; // edi
  char *i; // esi
  int v6; // ebx
  _BYTE *v7; // esi
  char buf[256]; // [esp+Ch] [ebp-100h] BYREF

  v4 = 0;
  for ( i = buf; v4 < length; ++i )
  {
    v6 = (unsigned __int8)psrc[v4];
    if ( i + 4 >= &buf[255] )
    {
      *i = 0;
      Scaleform::String::AppendString(pescapedStr, buf, 0xFFFFFFFF);
      i = buf;
    }
    if ( v6 < 128 && ((1 << (v6 & 0x1F)) & escapeMask[v6 / 32]) != 0 )
    {
      *i = v6;
    }
    else
    {
      v7 = i + 1;
      *(v7 - 1) = 37;
      *v7 = v6 / 16 + (v6 / 16 > 9 ? 55 : 48);
      i = v7 + 1;
      *i = (v6 & 0xF) + ((int)(v6 & 0x8000000F) > 9 ? 55 : 48);
    }
    ++v4;
  }
  *i = 0;
  Scaleform::String::AppendString(pescapedStr, buf, 0xFFFFFFFF);
}
