void __thiscall Scaleform::Render::DICommand_Clear::ExecuteSW(
        Scaleform::Render::DICommand_Clear *this,
        Scaleform::Render::DICommandContext *context,
        Scaleform::Render::ImageData *dest,
        Scaleform::Render::ImageData **__formal)
{
  Scaleform::Render::TextureManager *v5; // eax
  unsigned int v6; // esi
  unsigned int Raw; // ebp
  unsigned int v8; // ebx
  Scaleform::Render::ImageSwizzlerContext dstSwiz; // [esp+10h] [ebp-18h] BYREF

  v5 = context->pHAL->GetTextureManager(context->pHAL);
  v6 = 0;
  dstSwiz.Swizzler = v5->GetImageSwizzler(v5);
  dstSwiz.pCurrentScanline = 0;
  dstSwiz.pImage = dest;
  memset(&dstSwiz.CachedBlockY, 0, 12);
  dstSwiz.Swizzler->Initialize(dstSwiz.Swizzler, &dstSwiz);
  Raw = this->FillColor.Raw;
  v8 = 0;
  if ( dest->pPlanes->Height )
  {
    while ( 1 )
    {
      dstSwiz.Swizzler->CacheScanline(dstSwiz.Swizzler, &dstSwiz, v8);
      if ( dest->pPlanes->Width )
      {
        do
          dstSwiz.Swizzler->SetPixelInScanline(dstSwiz.Swizzler, &dstSwiz, v6++, Raw);
        while ( v6 < dest->pPlanes->Width );
      }
      if ( ++v8 >= dest->pPlanes->Height )
        break;
      v6 = 0;
    }
  }
}
