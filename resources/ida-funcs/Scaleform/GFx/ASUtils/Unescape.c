void __cdecl Scaleform::GFx::ASUtils::Unescape(const char *psrc, unsigned int length, Scaleform::String *punescapedStr)
{
  const char *v3; // esi
  __m128i *v4; // edi
  int v5; // ebx
  int v6; // eax
  int v7; // ecx
  const char *v8; // esi
  int v9; // edx
  int v10; // eax
  int v11; // edx
  __m128i v12[15]; // [esp+Ch] [ebp-100h] BYREF
  char v13; // [esp+10Bh] [ebp-1h] BYREF

  v3 = psrc;
  v4 = v12;
  while ( v3 < &psrc[length] )
  {
    v5 = *(unsigned __int8 *)v3++;
    if ( &v4->m128i_i8[1] >= &v13 )
    {
      v4->m128i_i8[0] = 0;
      Scaleform::String::AppendString(punescapedStr, v12, 0xFFFFFFFF);
      v4 = v12;
    }
    if ( v5 == 37 )
    {
      v6 = *(unsigned __int8 *)v3;
      if ( (unsigned int)(v6 - 97) <= 0x19 )
        v6 -= 32;
      v7 = *((unsigned __int8 *)v3 + 1);
      v8 = v3 + 1;
      v9 = v7 - 32;
      if ( (unsigned int)(v7 - 97) > 0x19 )
        v9 = v7;
      v3 = v8 + 1;
      if ( v6 - 48 <= 9 )
        v10 = v6 - 48;
      else
        v10 = v6 - 55;
      if ( v9 - 48 <= 9 )
        v11 = v9 - 48;
      else
        v11 = v9 - 55;
      if ( v10 >= 16 || v11 >= 16 )
        continue;
      v4->m128i_i8[0] = v11 + 16 * v10;
    }
    else
    {
      v4->m128i_i8[0] = v5;
    }
    v4 = (__m128i *)((char *)v4 + 1);
  }
  v4->m128i_i8[0] = 0;
  Scaleform::String::AppendString(punescapedStr, v12, 0xFFFFFFFF);
}
