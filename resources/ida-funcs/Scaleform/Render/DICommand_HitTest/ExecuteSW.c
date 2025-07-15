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
  int v11; // ebx
  int x1; // eax
  int v13; // eax
  int v14; // edi
  bool *v15; // esi
  Scaleform::Render::TextureManager *v16; // eax
  Scaleform::Render::TextureManager *v17; // eax
  Scaleform::Render::ImageData *v18; // edi
  Scaleform::Render::Image *pObject; // edi
  unsigned int Height; // ebp
  unsigned int v21; // eax
  unsigned int Width; // ebx
  unsigned int v23; // eax
  int y; // ecx
  int v25; // eax
  int i; // ebx
  signed int v27; // edi
  int x; // ecx
  int v29; // eax
  int v30; // edi
  signed int v31; // ebp
  bool *v32; // esi
  bool *v33; // esi
  unsigned int v34; // [esp+2Ch] [ebp-44h] BYREF
  Scaleform::Render::Size<unsigned long> v35; // [esp+30h] [ebp-40h] BYREF
  Scaleform::Render::Color result; // [esp+38h] [ebp-38h] BYREF
  int v37; // [esp+40h] [ebp-30h] BYREF
  int v38; // [esp+44h] [ebp-2Ch]
  Scaleform::Render::ImageData *v39; // [esp+48h] [ebp-28h]
  int v40; // [esp+4Ch] [ebp-24h]
  int v41; // [esp+50h] [ebp-20h]
  int v42; // [esp+54h] [ebp-1Ch]
  Scaleform::Render::ImageSwizzlerContext v43; // [esp+58h] [ebp-18h] BYREF
  int v44; // [esp+74h] [ebp+4h]
  unsigned int v45; // [esp+74h] [ebp+4h]
  int v46; // [esp+7Ch] [ebp+Ch]

  if ( this->SecondImage.pObject )
  {
    v16 = context->pHAL->GetTextureManager(context->pHAL);
    v37 = (int)v16->GetImageSwizzler(v16);
    v38 = 0;
    v39 = dest;
    v40 = 0;
    v41 = 0;
    v42 = 0;
    (*(void (__thiscall **)(int, int *))(*(_DWORD *)v37 + 4))(v37, &v37);
    v17 = context->pHAL->GetTextureManager(context->pHAL);
    v18 = *psrc;
    v43.Swizzler = v17->GetImageSwizzler(v17);
    v43.pCurrentScanline = 0;
    v43.pImage = v18;
    memset(&v43.CachedBlockY, 0, 12);
    v43.Swizzler->Initialize(v43.Swizzler, &v43);
    pObject = this->SecondImage.pObject;
    Height = dest->pPlanes->Height;
    v21 = pObject->GetSize(pObject, (Scaleform::Render::Size<unsigned long> *)&result)->Height;
    v34 = Height;
    if ( Height >= v21 )
      v34 = v21;
    Width = dest->pPlanes->Width;
    v23 = pObject->GetSize(pObject, &v35)->Width;
    v45 = Width;
    if ( Width >= v23 )
      v45 = v23;
    y = this->SecondPoint.y;
    v25 = this->FirstPoint.y;
    for ( i = (y - v25) & ((y - v25 < 0) - 1); i < (int)(v34 + y - v25); ++i )
    {
      v27 = i + v25 - y;
      if ( i < 0 || i >= (signed int)dest->pPlanes->Height || v27 < 0 || v27 >= (signed int)(*psrc)->pPlanes->Height )
        break;
      (*(void (__thiscall **)(int, int *, int))(*(_DWORD *)v37 + 8))(v37, &v37, i);
      v43.Swizzler->CacheScanline(v43.Swizzler, &v43, v27);
      x = this->SecondPoint.x;
      v29 = this->FirstPoint.x;
      v30 = (x - v29) & ((x - v29 < 0) - 1);
      if ( v30 < (int)(v45 + x - v29) )
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
          (*(void (__thiscall **)(int, Scaleform::Render::Size<unsigned long> *, int *, int))(*(_DWORD *)v37 + 20))(
            v37,
            &v35,
            &v37,
            v30);
          if ( HIBYTE(v35.Width) >= this->FirstThreshold )
          {
            Scaleform::Render::ImageSwizzlerContext::GetPixelInScanline(&v43, &result, v31);
            if ( result.Channels.Alpha >= this->SecondThreshold )
            {
              v33 = this->Result;
              if ( v33 )
                *v33 = 1;
              return;
            }
          }
          x = this->SecondPoint.x;
          v29 = this->FirstPoint.x;
        }
        while ( ++v30 < (int)(v45 + x - v29) );
      }
      y = this->SecondPoint.y;
      v25 = this->FirstPoint.y;
    }
  }
  else
  {
    v5 = context->pHAL->GetTextureManager(context->pHAL);
    v6 = dest;
    v37 = (int)v5->GetImageSwizzler(v5);
    v38 = 0;
    v39 = dest;
    v40 = 0;
    v41 = 0;
    v42 = 0;
    (*(void (__thiscall **)(int, int *))(*(_DWORD *)v37 + 4))(v37, &v37);
    pPlanes = dest->pPlanes;
    v44 = pPlanes->Height;
    if ( v44 >= this->SecondArea.y2 - this->SecondArea.y1 )
      v44 = this->SecondArea.y2 - this->SecondArea.y1;
    v46 = pPlanes->Width;
    if ( (signed int)pPlanes->Width >= this->SecondArea.x2 - this->SecondArea.x1 )
      v46 = this->SecondArea.x2 - this->SecondArea.x1;
    y1 = this->SecondArea.y1;
    v9 = y1 - this->FirstPoint.y < 0;
    v10 = y1 - this->FirstPoint.y;
    v11 = v9 ? 0 : v10;
    if ( v11 < v44 + v10 )
    {
      while ( v11 >= 0 && v11 < (signed int)v6->pPlanes->Height )
      {
        (*(void (__thiscall **)(int, int *, int))(*(_DWORD *)v37 + 8))(v37, &v37, v11);
        x1 = this->SecondArea.x1;
        v9 = x1 - this->FirstPoint.x < 0;
        v13 = x1 - this->FirstPoint.x;
        v14 = v9 ? 0 : v13;
        if ( v14 < v46 + v13 )
        {
          while ( v14 >= 0 && v14 < (signed int)dest->pPlanes->Width )
          {
            (*(void (__thiscall **)(int, unsigned int *, int *, int))(*(_DWORD *)v37 + 20))(v37, &v34, &v37, v14);
            if ( HIBYTE(v34) >= this->FirstThreshold )
            {
              v15 = this->Result;
              if ( v15 )
                *v15 = 1;
              return;
            }
            if ( ++v14 >= v46 + this->SecondArea.x1 - this->FirstPoint.x )
              break;
          }
        }
        if ( ++v11 >= v44 + this->SecondArea.y1 - this->FirstPoint.y )
          break;
        v6 = dest;
      }
    }
  }
  v32 = this->Result;
  if ( v32 )
    *v32 = 0;
}
