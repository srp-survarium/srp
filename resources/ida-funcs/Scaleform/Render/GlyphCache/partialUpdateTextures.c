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
  Scaleform::Render::Texture::UpdateDesc *Data; // edi
  int v13; // eax
  Scaleform::Render::Palette *v14; // esi
  unsigned int *p_NumGlyphsToUpdate; // [esp+14h] [ebp-64h]
  unsigned int v16; // [esp+18h] [ebp-60h]
  int v17; // [esp+1Ch] [ebp-5Ch]
  unsigned int v18; // [esp+20h] [ebp-58h]
  int v19; // [esp+24h] [ebp-54h]
  Scaleform::Render::ImageData v20; // [esp+28h] [ebp-50h] BYREF
  Scaleform::Render::ImageData v21; // [esp+50h] [ebp-28h] BYREF

  v21.pPlanes = &v21.Plane0;
  pObject = this->UpdateBuffer.pObject;
  memset(&v21, 0, 10);
  v21.RawPlaneCount = 1;
  memset(&v21.pPalette, 0, 24);
  Scaleform::Render::RawImage::GetImageData(pObject, &v21);
  v18 = 0;
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
        v17 = 0;
        v16 = 0;
        if ( this->GlyphsToUpdate.Size )
        {
          v19 = 0;
          do
          {
            v5 = &this->GlyphsToUpdate.Pages[v4 >> 6];
            v6 = v4 & 0x3F;
            if ( (*v5)[v6].TextureId == v18 )
            {
              ++v17;
              v7 = &(*v5)[v6];
              v8 = &this->RectsToUpdate.Data[v19++];
              v9 = this->UpdateBuffer.pObject;
              memset(&v20, 0, 10);
              v20.RawPlaneCount = 1;
              v20.pPlanes = &v20.Plane0;
              memset(&v20.pPalette, 0, 24);
              Scaleform::Render::RawImage::GetImageData(v9, &v20);
              v8->DestRect.x1 = v7->DstX;
              v8->DestRect.y1 = v7->DstY;
              v8->DestRect.x2 = v7->DstX + v7->w;
              v8->DestRect.y2 = v7->DstY + v7->h;
              v8->SourcePlane = *v21.pPlanes;
              v10 = &v20.pPlanes->pData[v7->SrcY * v20.pPlanes->Pitch + v7->SrcX];
              v8->PlaneIndex = 0;
              v8->SourcePlane.pData = v10;
              Scaleform::Render::ImageData::freePlanes(&v20);
              if ( v20.pPalette.pObject )
              {
                v11 = v20.pPalette.pObject;
                if ( InterlockedExchangeAdd(&v20.pPalette.pObject->RefCount.Value, -1) == 1 )
                  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v11);
              }
              v4 = v16;
            }
            v16 = ++v4;
          }
          while ( v4 < this->GlyphsToUpdate.Size );
        }
        Data = this->RectsToUpdate.Data;
        if ( *(p_NumGlyphsToUpdate - 18) == 1 )
        {
          v13 = (*(int (__thiscall **)(_DWORD, _DWORD))(*(_DWORD *)*(p_NumGlyphsToUpdate - 3) + 96))(
                  *(p_NumGlyphsToUpdate - 3),
                  *(p_NumGlyphsToUpdate - 17));
          if ( v13 )
            (*(void (__thiscall **)(int, Scaleform::Render::Texture::UpdateDesc *, int, _DWORD))(*(_DWORD *)v13 + 76))(
              v13,
              Data,
              v17,
              0);
        }
        *p_NumGlyphsToUpdate = 0;
      }
      p_NumGlyphsToUpdate += 20;
      ++v18;
    }
    while ( v18 < this->MaxNumTextures );
  }
  this->GlyphsToUpdate.Size = 0;
  this->UpdatePacker.LastX = 0;
  this->UpdatePacker.LastY = 0;
  this->UpdatePacker.LastMaxHeight = 0;
  Scaleform::Render::ImageData::freePlanes(&v21);
  if ( v21.pPalette.pObject )
  {
    v14 = v21.pPalette.pObject;
    if ( InterlockedExchangeAdd(&v21.pPalette.pObject->RefCount.Value, -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v14);
  }
}
