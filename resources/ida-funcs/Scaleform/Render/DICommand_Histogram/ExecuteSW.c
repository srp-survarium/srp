void __thiscall Scaleform::Render::DICommand_Histogram::ExecuteSW(
        Scaleform::Render::DICommand_Histogram *this,
        Scaleform::Render::Color context,
        Scaleform::Render::ImageData *dst,
        Scaleform::Render::ImageData **__formal)
{
  Scaleform::Render::TextureManager *v5; // eax
  Scaleform::Render::ImageSwizzler *v6; // eax
  Scaleform::Render::ImageData *v7; // ebx
  signed int i; // ebp
  Scaleform::Render::ImagePlane *pPlanes; // edx
  int y2; // eax
  signed int j; // edi
  int Width; // eax
  unsigned int Raw; // eax
  Scaleform::Render::ImageSwizzlerContext mappedSwizzler; // [esp+10h] [ebp-18h] BYREF

  v5 = (Scaleform::Render::TextureManager *)(*(int (__thiscall **)(_DWORD))(**(_DWORD **)(*(_DWORD *)&context + 4) + 220))(*(_DWORD *)(*(_DWORD *)&context + 4));
  v6 = v5->GetImageSwizzler(v5);
  v7 = dst;
  mappedSwizzler.Swizzler = v6;
  mappedSwizzler.pCurrentScanline = 0;
  mappedSwizzler.pImage = dst;
  memset(&mappedSwizzler.CachedBlockY, 0, 12);
  v6->Initialize(v6, &mappedSwizzler);
  for ( i = this->SourceRect.y1 < 0 ? 0 : this->SourceRect.y1; ; ++i )
  {
    pPlanes = v7->pPlanes;
    y2 = this->SourceRect.y2;
    if ( (signed int)pPlanes->Height < y2 )
      y2 = pPlanes->Height;
    if ( i >= y2 )
      break;
    mappedSwizzler.Swizzler->CacheScanline(mappedSwizzler.Swizzler, &mappedSwizzler, i);
    for ( j = this->SourceRect.x1 < 0 ? 0 : this->SourceRect.x1; ; ++j )
    {
      Width = v7->pPlanes->Width;
      if ( Width >= this->SourceRect.x2 )
        Width = this->SourceRect.x2;
      if ( j >= Width )
        break;
      mappedSwizzler.Swizzler->GetPixelInScanline(mappedSwizzler.Swizzler, &context, &mappedSwizzler, j);
      Raw = context.Raw;
      ++this->Result[context.Channels.Blue + 512];
      Raw >>= 8;
      ++this->Result[(unsigned __int8)Raw + 256];
      Raw >>= 8;
      ++this->Result[(unsigned __int8)Raw];
      ++this->Result[BYTE1(Raw) + 768];
    }
  }
}
