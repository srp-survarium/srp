void __thiscall Scaleform::Render::DICommand_HitTest::ExecuteSW(
        Scaleform::Render::DICommand_HitTest *this,
        Scaleform::Render::DICommandContext *context,
        Scaleform::Render::ImageData *dest,
        Scaleform::Render::ImageData **psrc)
{
  Scaleform::Render::TextureManager *v5; // eax
  Scaleform::Render::ImageData *v6; // edi
  Scaleform::Render::ImagePlane *pPlanes; // ecx
  int y1; // eax
  bool v9; // sf
  int v10; // eax
  signed int v11; // ebx
  int x1; // eax
  int v13; // eax
  signed int v14; // edi
  bool *v15; // esi
  Scaleform::Render::TextureManager *v16; // eax
  Scaleform::Render::TextureManager *v17; // eax
  Scaleform::Render::ImageData *v18; // edi
  Scaleform::Render::Image *pObject; // edi
  unsigned int Height; // ebp
  Scaleform::Render::Color v21; // eax
  unsigned int Width; // ebx
  Scaleform::Render::DICommandContext *v23; // eax
  int y; // ecx
  int v25; // eax
  signed int i; // ebx
  signed int v27; // edi
  int x; // ecx
  int v29; // eax
  signed int v30; // edi
  signed int v31; // ebp
  bool *v32; // esi
  bool *Result; // esi
  Scaleform::Render::Color c0; // [esp+2Ch] [ebp-44h] BYREF
  Scaleform::Render::Size<unsigned long> v35; // [esp+30h] [ebp-40h] BYREF
  Scaleform::Render::Color c1; // [esp+38h] [ebp-38h] BYREF
  Scaleform::Render::ImageSwizzlerContext img0Swiz; // [esp+40h] [ebp-30h] BYREF
  Scaleform::Render::ImageSwizzlerContext img1Swiz; // [esp+58h] [ebp-18h] BYREF
  Scaleform::Render::DICommandContext *contexta; // [esp+74h] [ebp+4h]
  Scaleform::Render::DICommandContext *contextb; // [esp+74h] [ebp+4h]
  Scaleform::Render::ImageData **psrca; // [esp+7Ch] [ebp+Ch]

  if ( this->SecondImage.pObject )
  {
    v16 = context->pHAL->GetTextureManager(context->pHAL);
    img0Swiz.Swizzler = v16->GetImageSwizzler(v16);
    img0Swiz.pCurrentScanline = 0;
    img0Swiz.pImage = dest;
    memset(&img0Swiz.CachedBlockY, 0, 12);
    img0Swiz.Swizzler->Initialize(img0Swiz.Swizzler, &img0Swiz);
    v17 = context->pHAL->GetTextureManager(context->pHAL);
    v18 = *psrc;
    img1Swiz.Swizzler = v17->GetImageSwizzler(v17);
    img1Swiz.pCurrentScanline = 0;
    img1Swiz.pImage = v18;
    memset(&img1Swiz.CachedBlockY, 0, 12);
    img1Swiz.Swizzler->Initialize(img1Swiz.Swizzler, &img1Swiz);
    pObject = this->SecondImage.pObject;
    Height = dest->pPlanes->Height;
    v21 = (Scaleform::Render::Color)pObject->GetSize(pObject, (Scaleform::Render::Size<unsigned long> *)&c1)->Height;
    c0 = (Scaleform::Render::Color)Height;
    if ( Height >= v21.Raw )
      c0 = v21;
    Width = dest->pPlanes->Width;
    v23 = (Scaleform::Render::DICommandContext *)pObject->GetSize(pObject, &v35)->Width;
    contextb = (Scaleform::Render::DICommandContext *)Width;
    if ( Width >= (unsigned int)v23 )
      contextb = v23;
    y = this->SecondPoint.y;
    v25 = this->FirstPoint.y;
    for ( i = (y - v25) & ((y - v25 < 0) - 1); i < *(_DWORD *)&c0 + y - v25; ++i )
    {
      v27 = i + v25 - y;
      if ( i < 0 || i >= (signed int)dest->pPlanes->Height || v27 < 0 || v27 >= (signed int)(*psrc)->pPlanes->Height )
        break;
      img0Swiz.Swizzler->CacheScanline(img0Swiz.Swizzler, &img0Swiz, i);
      img1Swiz.Swizzler->CacheScanline(img1Swiz.Swizzler, &img1Swiz, v27);
      x = this->SecondPoint.x;
      v29 = this->FirstPoint.x;
      v30 = (x - v29) & ((x - v29 < 0) - 1);
      if ( v30 < (int)contextb + x - v29 )
      {
        do
        {
          v31 = v30 + v29 - x;
          if ( v30 < 0
            || v30 >= (signed int)dest->pPlanes->Width
            || v31 < 0
            || v31 >= (signed int)(*psrc)->pPlanes->Width )
          {
            break;
          }
          img0Swiz.Swizzler->GetPixelInScanline(img0Swiz.Swizzler, (Scaleform::Render::Color *)&v35, &img0Swiz, v30);
          if ( HIBYTE(v35.Width) >= this->FirstThreshold )
          {
            Scaleform::Render::ImageSwizzlerContext::GetPixelInScanline(&img1Swiz, &c1, v31);
            if ( c1.Channels.Alpha >= this->SecondThreshold )
            {
              Result = this->Result;
              if ( Result )
                *Result = 1;
              return;
            }
          }
          x = this->SecondPoint.x;
          v29 = this->FirstPoint.x;
        }
        while ( ++v30 < (int)contextb + x - v29 );
      }
      y = this->SecondPoint.y;
      v25 = this->FirstPoint.y;
    }
  }
  else
  {
    v5 = context->pHAL->GetTextureManager(context->pHAL);
    v6 = dest;
    img0Swiz.Swizzler = v5->GetImageSwizzler(v5);
    img0Swiz.pCurrentScanline = 0;
    img0Swiz.pImage = dest;
    memset(&img0Swiz.CachedBlockY, 0, 12);
    img0Swiz.Swizzler->Initialize(img0Swiz.Swizzler, &img0Swiz);
    pPlanes = dest->pPlanes;
    contexta = (Scaleform::Render::DICommandContext *)pPlanes->Height;
    if ( (int)contexta >= this->SecondArea.y2 - this->SecondArea.y1 )
      contexta = (Scaleform::Render::DICommandContext *)(this->SecondArea.y2 - this->SecondArea.y1);
    psrca = (Scaleform::Render::ImageData **)pPlanes->Width;
    if ( (signed int)pPlanes->Width >= this->SecondArea.x2 - this->SecondArea.x1 )
      psrca = (Scaleform::Render::ImageData **)(this->SecondArea.x2 - this->SecondArea.x1);
    y1 = this->SecondArea.y1;
    v9 = y1 - this->FirstPoint.y < 0;
    v10 = y1 - this->FirstPoint.y;
    v11 = v9 ? 0 : v10;
    if ( v11 < (int)contexta + v10 )
    {
      while ( v11 >= 0 && v11 < (signed int)v6->pPlanes->Height )
      {
        img0Swiz.Swizzler->CacheScanline(img0Swiz.Swizzler, &img0Swiz, v11);
        x1 = this->SecondArea.x1;
        v9 = x1 - this->FirstPoint.x < 0;
        v13 = x1 - this->FirstPoint.x;
        v14 = v9 ? 0 : v13;
        if ( v14 < (int)psrca + v13 )
        {
          while ( v14 >= 0 && v14 < (signed int)dest->pPlanes->Width )
          {
            img0Swiz.Swizzler->GetPixelInScanline(img0Swiz.Swizzler, &c0, &img0Swiz, v14);
            if ( c0.Channels.Alpha >= this->FirstThreshold )
            {
              v15 = this->Result;
              if ( v15 )
                *v15 = 1;
              return;
            }
            if ( ++v14 >= (int)psrca + this->SecondArea.x1 - this->FirstPoint.x )
              break;
          }
        }
        if ( ++v11 >= (int)contexta + this->SecondArea.y1 - this->FirstPoint.y )
          break;
        v6 = dest;
      }
    }
  }
  v32 = this->Result;
  if ( v32 )
    *v32 = 0;
}
