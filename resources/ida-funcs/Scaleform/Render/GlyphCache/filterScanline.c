void __thiscall Scaleform::Render::GlyphCache::filterScanline(
        Scaleform::Render::GlyphCache *this,
        unsigned __int8 *sl,
        unsigned int w)
{
  unsigned int v3; // edi
  char *v4; // eax
  int v5; // esi
  int v6; // ecx
  unsigned __int8 v7; // bl
  unsigned __int8 *v8; // ecx
  char v9; // dl
  __m128i src[16]; // [esp+Ch] [ebp-100h] BYREF

  v3 = w;
  if ( w > 0x100 )
    v3 = 256;
  memset((int)src, 0, v3);
  if ( v3 > 4 )
  {
    v4 = &src[0].m128i_i8[1];
    v5 = 4 - ((_DWORD)src[0].m128i_i32 + 1);
    do
    {
      v6 = sl[v5 - 2 + (_DWORD)v4];
      v7 = this->ScanlineFilter.Secondary[v6];
      *v4 += v7;
      v4[2] += v7;
      v8 = &this->ScanlineFilter.Primary[v6];
      v9 = v8[512];
      *(v4 - 1) += v9;
      LOBYTE(v8) = *v8;
      v4[3] += v9;
      *++v4 += (char)v8;
    }
    while ( (unsigned int)&v4[v5] < v3 );
  }
  memcpy((int)sl, src, v3);
}
