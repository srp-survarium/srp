void __thiscall Scaleform::Render::DICommand_Compare::ExecuteSW(
        Scaleform::Render::DICommand_Compare *this,
        Scaleform::Render::DICommandContext *context,
        Scaleform::Render::ImageData *dest,
        Scaleform::Render::ImageData **psrc)
{
  Scaleform::Render::ImageData *v4; // ebp
  Scaleform::Render::ImageData *v5; // edi
  Scaleform::Render::TextureManager *v7; // eax
  Scaleform::Render::ImageSwizzler *v8; // eax
  Scaleform::Render::TextureManager *v9; // eax
  Scaleform::Render::ImageSwizzler *v10; // eax
  Scaleform::Render::TextureManager *v11; // eax
  Scaleform::Render::ImageData *v12; // esi
  unsigned int i; // edi
  unsigned int j; // esi
  char v15; // al
  char v16; // cl
  char v17; // dl
  unsigned __int8 s0Alpha; // [esp+3Ch] [ebp-9Ah]
  unsigned __int8 s1Alpha; // [esp+3Dh] [ebp-99h]
  Scaleform::Render::ImageData *dCol; // [esp+3Eh] [ebp-98h]
  unsigned int dCola; // [esp+3Eh] [ebp-98h]
  char delta_1; // [esp+43h] [ebp-93h]
  Scaleform::Render::Color s1Col; // [esp+46h] [ebp-90h] BYREF
  Scaleform::Render::Color s0Col; // [esp+4Ah] [ebp-8Ch] BYREF
  Scaleform::Render::DICommand_Compare *v25; // [esp+4Eh] [ebp-88h]
  Scaleform::Render::ImageSwizzlerContext src0Swiz; // [esp+52h] [ebp-84h] BYREF
  Scaleform::Render::ImageSwizzlerContext dstSwiz; // [esp+6Ah] [ebp-6Ch] BYREF
  Scaleform::Render::ImageSwizzlerContext src1Swiz; // [esp+82h] [ebp-54h] BYREF
  Scaleform::Render::ImagePlane d; // [esp+9Ah] [ebp-3Ch] BYREF
  Scaleform::Render::ImagePlane s[2]; // [esp+AEh] [ebp-28h] BYREF

  v4 = *psrc;
  v5 = psrc[1];
  v25 = this;
  memset(&d, 0, sizeof(d));
  memset(s, 0, sizeof(s));
  Scaleform::Render::ImageData::GetPlane(dest, 0, &d);
  Scaleform::Render::ImageData::GetPlane(v4, 0, s);
  Scaleform::Render::ImageData::GetPlane(v5, 0, &s[1]);
  v7 = context->pHAL->GetTextureManager(context->pHAL);
  v8 = v7->GetImageSwizzler(v7);
  dstSwiz.pImage = dest;
  dstSwiz.Swizzler = v8;
  dstSwiz.pCurrentScanline = 0;
  memset(&dstSwiz.CachedBlockY, 0, 12);
  v8->Initialize(v8, &dstSwiz);
  v9 = context->pHAL->GetTextureManager(context->pHAL);
  dCol = *psrc;
  v10 = v9->GetImageSwizzler(v9);
  src0Swiz.pImage = dCol;
  src0Swiz.Swizzler = v10;
  src0Swiz.pCurrentScanline = 0;
  memset(&src0Swiz.CachedBlockY, 0, 12);
  v10->Initialize(v10, &src0Swiz);
  v11 = context->pHAL->GetTextureManager(context->pHAL);
  v12 = psrc[1];
  src1Swiz.Swizzler = v11->GetImageSwizzler(v11);
  src1Swiz.pCurrentScanline = 0;
  src1Swiz.pImage = v12;
  memset(&src1Swiz.CachedBlockY, 0, 12);
  src1Swiz.Swizzler->Initialize(src1Swiz.Swizzler, &src1Swiz);
  for ( i = 0; i < v4->pPlanes->Height; ++i )
  {
    dstSwiz.Swizzler->CacheScanline(dstSwiz.Swizzler, &dstSwiz, i);
    src0Swiz.Swizzler->CacheScanline(src0Swiz.Swizzler, &src0Swiz, i);
    src1Swiz.Swizzler->CacheScanline(src1Swiz.Swizzler, &src1Swiz, i);
    for ( j = 0; j < v4->pPlanes->Width; ++j )
    {
      src0Swiz.Swizzler->GetPixelInScanline(src0Swiz.Swizzler, &s0Col, &src0Swiz, j);
      src1Swiz.Swizzler->GetPixelInScanline(src1Swiz.Swizzler, &s1Col, &src1Swiz, j);
      if ( v25->pSource.pObject->Transparent )
        s0Alpha = s0Col.Channels.Alpha;
      else
        s0Alpha = -1;
      if ( v25->pImageCompare1.pObject->Transparent )
        s1Alpha = s1Col.Channels.Alpha;
      else
        s1Alpha = -1;
      v15 = s0Col.Channels.Red - s1Col.Channels.Red;
      delta_1 = s0Col.Channels.Green - s1Col.Channels.Green;
      v16 = s0Alpha - s1Alpha;
      if ( s0Col.Channels.Red == s1Col.Channels.Red && !delta_1 && s0Col.Channels.Blue == s1Col.Channels.Blue && v16 )
      {
        v15 = -1;
        delta_1 = -1;
        v17 = -1;
      }
      else
      {
        v17 = s0Col.Channels.Blue - s1Col.Channels.Blue;
        v16 = -1;
      }
      BYTE2(dCola) = v15;
      LOBYTE(dCola) = v17;
      BYTE1(dCola) = delta_1;
      HIBYTE(dCola) = v16;
      dstSwiz.Swizzler->SetPixelInScanline(dstSwiz.Swizzler, &dstSwiz, j, dCola);
    }
  }
}
