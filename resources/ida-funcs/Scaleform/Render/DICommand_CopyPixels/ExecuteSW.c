void __thiscall Scaleform::Render::DICommand_CopyPixels::ExecuteSW(
        Scaleform::Render::DICommand_CopyPixels *this,
        Scaleform::Render::DICommandContext *context,
        Scaleform::Render::ImageData *dest,
        Scaleform::Render::ImageData **psrc)
{
  Scaleform::Render::ImageData *v5; // ecx
  Scaleform::Render::ImagePlane *pPlanes; // eax
  int Height; // edx
  int *v8; // eax
  int v9; // ecx
  int v10; // edx
  int v11; // eax
  int v12; // ecx
  int x; // edi
  int v14; // eax
  Scaleform::Render::TextureManager *v15; // eax
  Scaleform::Render::TextureManager *v16; // eax
  Scaleform::Render::ImageData *v17; // ebx
  unsigned int v18; // ebx
  Scaleform::Render::TextureManager *v19; // eax
  int y1; // ebx
  int v21; // esi
  int v22; // edi
  int x1; // esi
  int v24; // edi
  int v25; // eax
  Scaleform::Render::ImageData **v26; // eax
  int v27; // eax
  int v28; // ecx
  unsigned __int8 v29; // bl
  Scaleform::Render::ImageData *v30; // [esp+50h] [ebp-A0h]
  float v31; // [esp+50h] [ebp-A0h]
  unsigned int Raw; // [esp+50h] [ebp-A0h]
  float f; // [esp+54h] [ebp-9Ch]
  bool v34; // [esp+5Bh] [ebp-95h]
  Scaleform::Render::ImageData *v35; // [esp+5Ch] [ebp-94h] BYREF
  Scaleform::Render::Point<long> v36; // [esp+60h] [ebp-90h] BYREF
  int v37; // [esp+68h] [ebp-88h]
  int v38; // [esp+6Ch] [ebp-84h]
  Scaleform::Render::Color v39; // [esp+70h] [ebp-80h] BYREF
  Scaleform::Render::Rect<long> v40; // [esp+74h] [ebp-7Ch] BYREF
  Scaleform::Render::Point<long> v41; // [esp+84h] [ebp-6Ch] BYREF
  Scaleform::Render::Rect<long> result; // [esp+8Ch] [ebp-64h] BYREF
  Scaleform::Render::Color c2; // [esp+9Ch] [ebp-54h] BYREF
  int v44; // [esp+A0h] [ebp-50h]
  Scaleform::Render::ImageData *v45; // [esp+A4h] [ebp-4Ch]
  int v46; // [esp+A8h] [ebp-48h]
  int v47; // [esp+ACh] [ebp-44h]
  int v48; // [esp+B0h] [ebp-40h]
  _BYTE v49[4]; // [esp+B4h] [ebp-3Ch] BYREF
  int i; // [esp+B8h] [ebp-38h]
  int j; // [esp+BCh] [ebp-34h]
  _DWORD v52[6]; // [esp+C0h] [ebp-30h] BYREF
  _DWORD v53[6]; // [esp+D8h] [ebp-18h] BYREF

  v5 = *psrc;
  pPlanes = dest->pPlanes;
  Height = pPlanes->Height;
  v36.x = pPlanes->Width;
  v8 = (int *)v5->pPlanes;
  v9 = v8[1];
  v36.y = Height;
  v10 = *v8;
  result.y1 = v9;
  result.x1 = v10;
  memset(&v40, 0, sizeof(v40));
  if ( Scaleform::Render::DICommand_SourceRect::CalculateDestClippedRect(
         this,
         (const Scaleform::Render::Size<unsigned long> *)&result,
         (const Scaleform::Render::Size<unsigned long> *)&v36,
         &this->SourceRect,
         &v40,
         &v41) )
  {
    v34 = this->pAlphaSource.pObject != 0;
    if ( this->pAlphaSource.pObject )
    {
      v11 = this->SourceRect.y2 - this->SourceRect.y1;
      v12 = this->SourceRect.x2 - this->SourceRect.x1;
      x = this->AlphaPoint.x;
      v35 = psrc[1];
      v14 = this->AlphaPoint.y + v11;
      result.y1 = this->AlphaPoint.y;
      result.y2 = v14;
      result.x2 = x + v12;
      result.x1 = x;
      if ( !Scaleform::Render::DICommand_SourceRect::CalculateDestClippedRect(this, v35, dest, &result, &v40, &v36) )
        return;
    }
    else
    {
      v35 = *psrc;
      v36 = v41;
    }
    v15 = context->pHAL->GetTextureManager(context->pHAL);
    c2 = (Scaleform::Render::Color)v15->GetImageSwizzler(v15);
    v44 = 0;
    v45 = dest;
    v46 = 0;
    v47 = 0;
    v48 = 0;
    (*(void (__thiscall **)(Scaleform::Render::Color, Scaleform::Render::Color *))(*(_DWORD *)c2.Raw + 4))(c2, &c2);
    v16 = context->pHAL->GetTextureManager(context->pHAL);
    v17 = *psrc;
    v52[0] = v16->GetImageSwizzler(v16);
    v52[1] = 0;
    v52[2] = v17;
    memset(&v52[3], 0, 12);
    (*(void (__thiscall **)(_DWORD, _DWORD *))(*(_DWORD *)v52[0] + 4))(v52[0], v52);
    if ( v34 )
      v18 = (unsigned int)v35;
    else
      v18 = (unsigned int)*psrc;
    v19 = context->pHAL->GetTextureManager(context->pHAL);
    v53[0] = v19->GetImageSwizzler(v19);
    v53[1] = 0;
    v53[2] = v18;
    memset(&v53[3], 0, 12);
    (*(void (__thiscall **)(_DWORD, _DWORD *))(*(_DWORD *)v53[0] + 4))(v53[0], v53);
    y1 = v40.y1;
    v38 = v40.y1;
    if ( v40.y1 < v40.y2 )
    {
      v21 = v36.y - v41.y;
      v22 = v40.y1 - v36.y;
      v37 = v40.y1 - v36.y;
      for ( i = v36.y - v41.y; ; v21 = i )
      {
        (*(void (__thiscall **)(Scaleform::Render::Color, Scaleform::Render::Color *, int))(*(_DWORD *)c2.Raw + 8))(
          c2,
          &c2,
          y1);
        (*(void (__thiscall **)(_DWORD, _DWORD *, int))(*(_DWORD *)v52[0] + 8))(v52[0], v52, v22 + v21);
        (*(void (__thiscall **)(_DWORD, _DWORD *, int))(*(_DWORD *)v53[0] + 8))(v53[0], v53, v22);
        x1 = v40.x1;
        if ( v40.x1 < v40.x2 )
        {
          v24 = v40.x1 - v36.x;
          v25 = v36.x - v41.x;
          for ( j = v36.x - v41.x; ; v25 = j )
          {
            (*(void (__thiscall **)(_DWORD, Scaleform::Render::ImageData **, _DWORD *, int))(*(_DWORD *)v52[0] + 20))(
              v52[0],
              &v35,
              v52,
              v24 + v25);
            if ( !this->pSource.pObject->Transparent )
              HIBYTE(v35) = -1;
            if ( v34 )
            {
              (*(void (__thiscall **)(_DWORD, _BYTE *, _DWORD *, int))(*(_DWORD *)v53[0] + 20))(v53[0], v49, v53, v24);
              v26 = (Scaleform::Render::ImageData **)v49;
            }
            else
            {
              v26 = &v35;
            }
            v30 = *v26;
            (*(void (__thiscall **)(Scaleform::Render::Color, Scaleform::Render::Color *, Scaleform::Render::Color *, int))(*(_DWORD *)c2.Raw + 20))(
              c2,
              &v39,
              &c2,
              x1);
            if ( v34 )
              v27 = HIBYTE(v30) + 1;
            else
              v27 = 256;
            v28 = (v27 * HIBYTE(v35)) >> 8;
            v29 = (unsigned __int16)(v27 * HIBYTE(v35)) >> 8;
            if ( this->MergeAlpha )
            {
              v31 = (double)v39.Channels.Alpha / 255.0;
              v29 = (int)(v31 * (double)(255 - (unsigned __int8)v28) + (double)(unsigned __int8)v28);
            }
            if ( !this->pImage.pObject->Transparent )
              v29 = -1;
            f = (double)(unsigned __int8)v28 / (double)v29;
            Raw = Scaleform::Render::Color::Blend(
                    (Scaleform::Render::Color *)&result,
                    v39,
                    (Scaleform::Render::Color)v35,
                    f)->Raw;
            HIBYTE(Raw) = v29;
            (*(void (__thiscall **)(Scaleform::Render::Color, Scaleform::Render::Color *, int, unsigned int))(*(_DWORD *)c2.Raw + 12))(
              c2,
              &c2,
              x1++,
              Raw);
            ++v24;
            if ( x1 >= v40.x2 )
              break;
          }
          y1 = v38;
          v22 = v37;
        }
        ++y1;
        ++v22;
        v38 = y1;
        v37 = v22;
        if ( y1 >= v40.y2 )
          break;
      }
    }
  }
}
