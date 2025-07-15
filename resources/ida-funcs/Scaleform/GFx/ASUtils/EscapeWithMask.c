void __cdecl Scaleform::GFx::ASUtils::EscapeWithMask(
        const char *psrc,
        unsigned int length,
        Scaleform::String *pescapedStr,
        const unsigned int *escapeMask)
{
  unsigned int v4; // edi
  __m128i *i; // esi
  int v6; // ebx
  char *v7; // esi
  __m128i v8[15]; // [esp+Ch] [ebp-100h] BYREF
  char v9; // [esp+10Bh] [ebp-1h] BYREF

  v4 = 0;
  for ( i = v8; v4 < length; i = (__m128i *)((char *)i + 1) )
  {
    v6 = (unsigned __int8)psrc[v4];
    if ( (char *)i->m128i_i64 + 4 >= &v9 )
    {
      i->m128i_i8[0] = 0;
      Scaleform::String::AppendString(pescapedStr, v8, 0xFFFFFFFF);
      i = v8;
    }
    if ( v6 < 128 && ((1 << (v6 & 0x1F)) & escapeMask[v6 / 32]) != 0 )
    {
      i->m128i_i8[0] = v6;
    }
    else
    {
      v7 = &i->m128i_i8[1];
      *(v7 - 1) = 37;
      *v7 = v6 / 16 + (v6 / 16 > 9 ? 55 : 48);
      i = (__m128i *)(v7 + 1);
      i->m128i_i8[0] = (v6 & 0xF) + ((int)(v6 & 0x8000000F) > 9 ? 55 : 48);
    }
    ++v4;
  }
  i->m128i_i8[0] = 0;
  Scaleform::String::AppendString(pescapedStr, v8, 0xFFFFFFFF);
}
