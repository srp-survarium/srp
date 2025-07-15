void __thiscall Scaleform::Render::ExternalFontWinAPI::decomposeGlyphBitmap(
        Scaleform::Render::ExternalFontWinAPI *this,
        const unsigned __int8 *data,
        int w,
        int h,
        int x,
        int y,
        Scaleform::Render::GlyphRaster *raster)
{
  unsigned int v7; // esi
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *p_Raster; // edi
  unsigned __int8 *v9; // edi
  int v11; // edx
  const unsigned __int8 *v12; // ecx
  unsigned __int8 v13; // al
  int v14; // [esp+28h] [ebp+18h]

  v7 = h * w;
  p_Raster = &raster->Raster;
  raster->Width = w;
  raster->Height = h;
  raster->OriginX = -x;
  raster->OriginY = y;
  if ( h * w >= raster->Raster.Data.Size )
  {
    if ( v7 >= raster->Raster.Data.Policy.Capacity )
      Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)p_Raster,
        p_Raster,
        v7 + (v7 >> 2));
  }
  else if ( v7 < raster->Raster.Data.Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)p_Raster,
      p_Raster,
      v7);
  }
  raster->Raster.Data.Size = v7;
  v9 = p_Raster->Data.Data;
  if ( h > 0 )
  {
    v14 = h;
    do
    {
      v11 = w;
      v12 = data;
      v13 = 0x80;
      if ( w > 0 )
      {
        do
        {
          *v9++ = -((v13 & *v12) != 0);
          v13 >>= 1;
          if ( !v13 )
          {
            ++v12;
            v13 = 0x80;
          }
          --v11;
        }
        while ( v11 );
      }
      data += ((w + 31) >> 3) & 0xFFFFFFFC;
      --v14;
    }
    while ( v14 );
  }
}
