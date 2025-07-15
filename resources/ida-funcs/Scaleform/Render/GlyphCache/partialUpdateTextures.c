void __thiscall Scaleform::Render::GlyphCache::partialUpdateTextures(Scaleform::Render::GlyphCache *this)
{
  Scaleform::Render::RawImage *pObject; // ecx
  unsigned int v3; // esi
  unsigned int v4; // esi
  Scaleform::Render::GlyphCache::UpdateRect **v5; // edx
  int v6; // eax
  Scaleform::Render::GlyphCache::UpdateRect *v7; // edi
  Scaleform::Render::Texture::UpdateDesc *v8; // esi
  Scaleform::Render::RawImage *v9; // ecx
  unsigned __int8 *v10; // ecx
  Scaleform::Render::Palette *v11; // esi
  Scaleform::Render::Texture::UpdateDesc *v12; // edi
  int v13; // eax
  Scaleform::Render::Palette *v14; // esi
  unsigned int *p_NumGlyphsToUpdate; // [esp+14h] [ebp-64h]
  unsigned int j; // [esp+18h] [ebp-60h]
  unsigned int numRects; // [esp+1Ch] [ebp-5Ch]
  unsigned int i; // [esp+20h] [ebp-58h]
  int v19; // [esp+24h] [ebp-54h]
  Scaleform::Render::ImageData data; // [esp+28h] [ebp-50h] BYREF
  Scaleform::Render::ImageData d; // [esp+50h] [ebp-28h] BYREF

  d.pPlanes = &d.Plane0;
  pObject = this->UpdateBuffer.pObject;
  memset(&d, 0, 10);
  d.RawPlaneCount = 1;
  memset(&d.pPalette, 0, 24);
  Scaleform::Render::RawImage::GetImageData(pObject, &d);
  i = 0;
  if ( this->MaxNumTextures )
  {
    p_NumGlyphsToUpdate = &this->Textures[0].NumGlyphsToUpdate;
    do
    {
      v3 = *p_NumGlyphsToUpdate;
      if ( *p_NumGlyphsToUpdate )
      {
        Scaleform::ArrayUnsafeBase<Scaleform::Render::Texture::UpdateDesc,Scaleform::AllocatorLH_POD<Scaleform::Render::Texture::UpdateDesc,2>>::Reserve(
          &this->RectsToUpdate,
          v3,
          0x20u);
        this->RectsToUpdate.Size = v3;
        v4 = 0;
        numRects = 0;
        j = 0;
        if ( this->GlyphsToUpdate.Size )
        {
          v19 = 0;
          do
          {
            v5 = &this->GlyphsToUpdate.Pages[v4 >> 6];
            v6 = v4 & 0x3F;
            if ( (*v5)[v6].TextureId == i )
            {
              ++numRects;
              v7 = &(*v5)[v6];
              v8 = &this->RectsToUpdate.Data[v19++];
              v9 = this->UpdateBuffer.pObject;
              memset(&data, 0, 10);
              data.RawPlaneCount = 1;
              data.pPlanes = &data.Plane0;
              memset(&data.pPalette, 0, 24);
              Scaleform::Render::RawImage::GetImageData(v9, &data);
              v8->DestRect.x1 = v7->DstX;
              v8->DestRect.y1 = v7->DstY;
              v8->DestRect.x2 = v7->DstX + v7->w;
              v8->DestRect.y2 = v7->DstY + v7->h;
              v8->SourcePlane = *d.pPlanes;
              v10 = &data.pPlanes->pData[v7->SrcY * data.pPlanes->Pitch + v7->SrcX];
              v8->PlaneIndex = 0;
              v8->SourcePlane.pData = v10;
              Scaleform::Render::ImageData::freePlanes(&data);
              if ( data.pPalette.pObject )
              {
                v11 = data.pPalette.pObject;
                if ( InterlockedExchangeAdd(&data.pPalette.pObject->RefCount.Value, -1) == 1 )
                  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v11);
              }
              v4 = j;
            }
            j = ++v4;
          }
          while ( v4 < this->GlyphsToUpdate.Size );
        }
        v12 = this->RectsToUpdate.Data;
        if ( *(p_NumGlyphsToUpdate - 18) == 1 )
        {
          v13 = (*(int (__thiscall **)(_DWORD, _DWORD))(*(_DWORD *)*(p_NumGlyphsToUpdate - 3) + 84))(
                  *(p_NumGlyphsToUpdate - 3),
                  *(p_NumGlyphsToUpdate - 17));
          if ( v13 )
            (*(void (__thiscall **)(int, Scaleform::Render::Texture::UpdateDesc *, unsigned int, _DWORD))(*(_DWORD *)v13 + 72))(
              v13,
              v12,
              numRects,
              0);
        }
        *p_NumGlyphsToUpdate = 0;
      }
      p_NumGlyphsToUpdate += 20;
      ++i;
    }
    while ( i < this->MaxNumTextures );
  }
  this->GlyphsToUpdate.Size = 0;
  this->UpdatePacker.LastX = 0;
  this->UpdatePacker.LastY = 0;
  this->UpdatePacker.LastMaxHeight = 0;
  Scaleform::Render::ImageData::freePlanes(&d);
  if ( d.pPalette.pObject )
  {
    v14 = d.pPalette.pObject;
    if ( InterlockedExchangeAdd(&d.pPalette.pObject->RefCount.Value, -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v14);
  }
}
