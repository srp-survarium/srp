void __thiscall Scaleform::Render::DICommand_SetPixels::ExecuteSW(
        Scaleform::Render::DICommand_SetPixels *this,
        Scaleform::Render::DICommandContext *context,
        Scaleform::Render::ImageData *dest,
        Scaleform::Render::ImageData **__formal)
{
  Scaleform::Render::TextureManager *v5; // eax
  Scaleform::Render::ImageSwizzler *v6; // eax
  unsigned int v7; // ebp
  signed int y1; // ebx
  signed int x1; // edi
  unsigned int v10; // eax
  bool *Result; // esi
  bool *v12; // esi
  Scaleform::Render::ImageSwizzlerContext imgSwiz; // [esp+10h] [ebp-18h] BYREF

  v5 = context->pHAL->GetTextureManager(context->pHAL);
  v6 = v5->GetImageSwizzler(v5);
  v7 = 0;
  imgSwiz.pImage = dest;
  imgSwiz.Swizzler = v6;
  imgSwiz.pCurrentScanline = 0;
  memset(&imgSwiz.CachedBlockY, 0, 12);
  v6->Initialize(v6, &imgSwiz);
  y1 = this->DestRect.y1;
  if ( y1 >= this->DestRect.y2 )
  {
LABEL_6:
    Result = this->Result;
    if ( Result )
      *Result = 1;
  }
  else
  {
    while ( 1 )
    {
      imgSwiz.Swizzler->CacheScanline(imgSwiz.Swizzler, &imgSwiz, y1);
      x1 = this->DestRect.x1;
      if ( x1 < this->DestRect.x2 )
        break;
LABEL_5:
      if ( ++y1 >= this->DestRect.y2 )
        goto LABEL_6;
    }
    while ( v7 < this->Provider->GetLength(this->Provider) )
    {
      v10 = this->Provider->ReadNextPixel(this->Provider);
      imgSwiz.Swizzler->SetPixelInScanline(imgSwiz.Swizzler, &imgSwiz, x1++, v10);
      ++v7;
      if ( x1 >= this->DestRect.x2 )
        goto LABEL_5;
    }
    v12 = this->Result;
    if ( v12 )
      *v12 = 0;
  }
}
