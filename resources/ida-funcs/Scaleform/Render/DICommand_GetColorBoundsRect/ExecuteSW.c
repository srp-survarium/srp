void __thiscall Scaleform::Render::DICommand_GetColorBoundsRect::ExecuteSW(
        Scaleform::Render::DICommand_GetColorBoundsRect *this,
        Scaleform::Render::Color context,
        Scaleform::Render::ImageData *dest,
        Scaleform::Render::ImageData **__formal)
{
  Scaleform::Render::TextureManager *v4; // eax
  Scaleform::Render::ImageSwizzler *v5; // eax
  Scaleform::Render::ImageData *v6; // ebp
  signed int v7; // esi
  Scaleform::Render::ImagePlane *pPlanes; // eax
  char v9; // bl
  unsigned int v10; // edi
  Scaleform::Render::Rect<long> *Result; // eax
  signed int min; // [esp+1Ch] [ebp-28h]
  signed int min_4; // [esp+20h] [ebp-24h]
  int max; // [esp+24h] [ebp-20h]
  int max_4; // [esp+28h] [ebp-1Ch]
  Scaleform::Render::ImageSwizzlerContext dstSwiz; // [esp+2Ch] [ebp-18h] BYREF

  v4 = (Scaleform::Render::TextureManager *)(*(int (__thiscall **)(_DWORD))(**(_DWORD **)(*(_DWORD *)&context + 4) + 220))(*(_DWORD *)(*(_DWORD *)&context + 4));
  v5 = v4->GetImageSwizzler(v4);
  v6 = dest;
  v7 = 0;
  dstSwiz.Swizzler = v5;
  dstSwiz.pCurrentScanline = 0;
  dstSwiz.pImage = dest;
  memset(&dstSwiz.CachedBlockY, 0, 12);
  v5->Initialize(v5, &dstSwiz);
  pPlanes = v6->pPlanes;
  v9 = 0;
  v10 = 0;
  min = pPlanes->Width;
  min_4 = pPlanes->Height;
  max = 0;
  max_4 = 0;
  if ( min_4 )
  {
    while ( 1 )
    {
      dstSwiz.Swizzler->CacheScanline(dstSwiz.Swizzler, &dstSwiz, v10);
      if ( v6->pPlanes->Width )
        break;
LABEL_17:
      ++v10;
      v7 = 0;
      if ( v10 >= v6->pPlanes->Height )
        goto LABEL_18;
    }
    while ( 1 )
    {
      dstSwiz.Swizzler->GetPixelInScanline(dstSwiz.Swizzler, &context, &dstSwiz, v7);
      if ( this->FindColor )
      {
        if ( (context.Raw & this->Mask) == this->SearchColor )
          goto LABEL_7;
      }
      else if ( (context.Raw & this->Mask) != this->SearchColor )
      {
LABEL_7:
        if ( min >= v7 )
          min = v7;
        if ( min_4 >= (int)v10 )
          min_4 = v10;
        if ( v7 + 1 >= max )
          max = v7 + 1;
        if ( (int)(v10 + 1) >= max_4 )
          max_4 = v10 + 1;
        v9 = 1;
      }
      if ( ++v7 >= v6->pPlanes->Width )
        goto LABEL_17;
    }
  }
LABEL_18:
  Result = this->Result;
  if ( Result )
  {
    if ( v9 )
    {
      Result->x1 = min;
      Result->y1 = min_4;
      Result->x2 = max;
      Result->y2 = max_4;
    }
    else
    {
      Result->x1 = 0;
      Result->y1 = 0;
      Result->x2 = 0;
      Result->y2 = 0;
    }
  }
}
