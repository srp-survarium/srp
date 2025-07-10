char __thiscall Scaleform::Render::D3D1x::MappedTexture::Map(
        Scaleform::Render::D3D1x::MappedTexture *this,
        Scaleform::Render::Texture *ptexture,
        unsigned int mipLevel,
        unsigned int levelCount)
{
  Scaleform::Render::D3D1x::MappedTexture *v4; // esi
  Scaleform::Render::Texture *v5; // edi
  Scaleform::Render::ImageFormat v6; // eax
  unsigned int v7; // ebx
  Scaleform::Render::ImageData *p_Data; // esi
  Scaleform::Render::TextureManager *pManager; // ebx
  Scaleform::Render::TextureManager_vtbl *v10; // ecx
  volatile int RefCount; // ebx
  Scaleform::Render::ImageFormat v12; // ebx
  char *v13; // ebx
  unsigned int v14; // esi
  unsigned int v15; // edi
  unsigned int StartMipLevel; // eax
  bool v17; // al
  unsigned int v18; // ebx
  int MipLevelSize; // eax
  unsigned int *v20; // ecx
  unsigned int v21; // eax
  Scaleform::Render::ImageFormat Format; // [esp+364h] [ebp-DCh]
  Scaleform::Render::TextureManager_vtbl *v24; // [esp+384h] [ebp-BCh]
  unsigned int MipLevels; // [esp+38Ch] [ebp-B4h]
  unsigned int v27; // [esp+38Ch] [ebp-B4h]
  volatile int v28; // [esp+390h] [ebp-B0h]
  int v29; // [esp+394h] [ebp-ACh]
  Scaleform::Render::ImageFormat v30; // [esp+398h] [ebp-A8h]
  unsigned int TextureCount; // [esp+398h] [ebp-A8h]
  unsigned int v32; // [esp+39Ch] [ebp-A4h]
  int v33; // [esp+3A0h] [ebp-A0h]
  _DWORD *v34; // [esp+3A4h] [ebp-9Ch]
  Scaleform::Render::Size<unsigned long> sz; // [esp+3ACh] [ebp-94h] BYREF
  _DWORD v36[3]; // [esp+3B4h] [ebp-8Ch] BYREF
  __m128i v37; // [esp+3C0h] [ebp-80h] BYREF
  __m128i v38; // [esp+3D0h] [ebp-70h]
  int v39; // [esp+3E0h] [ebp-60h]
  HINSTANCE__ *v40; // [esp+3E4h] [ebp-5Ch]
  int v41; // [esp+3E8h] [ebp-58h]
  __m128i v42; // [esp+3F0h] [ebp-50h] BYREF
  __m128i v43; // [esp+400h] [ebp-40h] BYREF
  int v44; // [esp+418h] [ebp-28h]
  unsigned int v45; // [esp+43Ch] [ebp-4h]

  v4 = this;
  if ( levelCount > 4 )
  {
    v12 = ptexture->GetImageFormat(ptexture);
    Scaleform::Render::ImageData::Clear(&v4->Data);
    if ( !Scaleform::Render::ImageData::allocPlanes(&v4->Data, v12, levelCount, 1) )
      return 0;
    v5 = ptexture;
  }
  else
  {
    v5 = ptexture;
    if ( (ptexture->Use & 2) != 0 )
      MipLevels = 1;
    else
      MipLevels = ptexture->MipLevels;
    v6 = ptexture->GetFormat(ptexture);
    v7 = MipLevels * Scaleform::Render::ImageData::GetFormatPlaneCount(v6);
    p_Data = &v4->Data;
    v30 = ptexture->GetImageFormat(ptexture);
    Scaleform::Render::ImageData::Clear(p_Data);
    p_Data->Flags |= 1u;
    p_Data->Format = v30;
    p_Data->LevelCount = levelCount;
    p_Data->pPlanes = this->Planes;
    p_Data->RawPlaneCount = v7;
    if ( this != (Scaleform::Render::D3D1x::MappedTexture *)-56 && v7 == 1 )
    {
      p_Data->Plane0.Width = this->Planes[0].Width;
      p_Data->Plane0.Height = this->Planes[0].Height;
      p_Data->Plane0.Pitch = this->Planes[0].Pitch;
      p_Data->Plane0.DataSize = this->Planes[0].DataSize;
      p_Data->Plane0.pData = this->Planes[0].pData;
    }
    v4 = this;
  }
  pManager = v5->pManagerLocks.pObject->pManager;
  v10 = pManager[1].Scaleform::RefCountBase<Scaleform::Render::TextureManager,75>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,75>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable;
  v24 = v10;
  if ( v10 )
  {
    (*((void (__stdcall **)(Scaleform::Render::TextureManager_vtbl *))v10->~Scaleform::Render::TextureManager + 1))(v10);
    v10 = v24;
  }
  RefCount = pManager[1].RefCount;
  v28 = RefCount;
  if ( RefCount )
  {
    (*(void (__stdcall **)(volatile int))(*(_DWORD *)RefCount + 4))(RefCount);
    v10 = v24;
  }
  v4->StartMipLevel = mipLevel;
  v4->pTexture = v5;
  v4->LevelCount = levelCount;
  TextureCount = v5->TextureCount;
  v27 = 0;
  if ( v5->TextureCount )
  {
    v29 = 0;
    while ( 1 )
    {
      v13 = (char *)v5[1].__vftable + v29;
      v14 = *(_DWORD *)v13;
      v15 = *((_DWORD *)v13 + 1);
      if ( this->StartMipLevel )
      {
        StartMipLevel = this->StartMipLevel;
        do
        {
          v14 >>= 1;
          if ( !v14 )
            v14 = 1;
          v15 >>= 1;
          if ( !v15 )
            v15 = 1;
          --StartMipLevel;
        }
        while ( StartMipLevel );
      }
      (*(void (__stdcall **)(_DWORD, __m128i *))(**((_DWORD **)v13 + 2) + 40))(*((_DWORD *)v13 + 2), &v42);
      v37 = _mm_load_si128(&v42);
      v38 = _mm_load_si128(&v43);
      v41 = v44;
      v40 = &_sbh_sizeHeaderList;
      v38.m128i_i32[3] = 3;
      v39 = 0;
      v34 = v13 + 16;
      if ( !*((_DWORD *)v13 + 4)
        && (*((int (__stdcall **)(Scaleform::Render::TextureManager_vtbl *, __m128i *, _DWORD, char *))v24->~Scaleform::Render::TextureManager
            + 5))(
             v24,
             &v37,
             0,
             v13 + 16) < 0 )
      {
        if ( v28 )
          (*(void (__stdcall **)(volatile int))(*(_DWORD *)v28 + 8))(v28);
        if ( v24 )
          (*((void (__stdcall **)(Scaleform::Render::TextureManager_vtbl *))v24->~Scaleform::Render::TextureManager + 2))(v24);
        return 0;
      }
      if ( (ptexture->Use & 0x480) == 0x480 )
      {
        if ( checkHandleCopyResource )
        {
          v17 = canHandleCopyResource;
        }
        else
        {
          v17 = (*((int (__stdcall **)(Scaleform::Render::TextureManager_vtbl *))v24->~Scaleform::Render::TextureManager
                 + 37))(v24) >= 40960;
          canHandleCopyResource = v17;
          checkHandleCopyResource = 1;
        }
        if ( !warned_1 )
          warned_1 = !v17;
        if ( v17 )
          (*(void (__stdcall **)(volatile int, _DWORD, _DWORD))(*(_DWORD *)v28 + 188))(v28, *v34, *((_DWORD *)v13 + 2));
      }
      v32 = 0;
      if ( levelCount )
        break;
LABEL_43:
      v29 += 20;
      if ( ++v27 >= TextureCount )
      {
        RefCount = v28;
        v4 = this;
        v10 = v24;
        goto LABEL_45;
      }
      v5 = ptexture;
    }
    v33 = v29;
    while ( (*(int (__stdcall **)(volatile int, _DWORD, unsigned int, int, _DWORD, _DWORD *))(*(_DWORD *)v28 + 56))(
              v28,
              *v34,
              v32,
              2,
              0,
              v36) >= 0 )
    {
      v18 = v36[1];
      v45 = v36[0];
      Format = this->Data.Format;
      sz.Width = v14;
      sz.Height = v15;
      MipLevelSize = Scaleform::Render::ImageData::GetMipLevelSize(Format, &sz, v27);
      v20 = (unsigned int *)((char *)&this->Data.pPlanes->Width + v33);
      *v20 = v14;
      v20[3] = MipLevelSize;
      v21 = v45;
      v14 >>= 1;
      v20[1] = v15;
      v20[2] = v18;
      v20[4] = v21;
      if ( !v14 )
        v14 = 1;
      v15 >>= 1;
      if ( !v15 )
        v15 = 1;
      ++v32;
      v33 += 20 * TextureCount;
      if ( v32 >= levelCount )
        goto LABEL_43;
    }
    if ( v28 )
      (*(void (__stdcall **)(volatile int))(*(_DWORD *)v28 + 8))(v28);
    if ( v24 )
      (*((void (__stdcall **)(Scaleform::Render::TextureManager_vtbl *))v24->~Scaleform::Render::TextureManager + 2))(v24);
    return 0;
  }
  else
  {
LABEL_45:
    v4->pTexture->pMap = v4;
    if ( RefCount )
    {
      (*(void (__stdcall **)(volatile int))(*(_DWORD *)RefCount + 8))(RefCount);
      v10 = v24;
    }
    if ( v10 )
      (*((void (__stdcall **)(Scaleform::Render::TextureManager_vtbl *))v10->~Scaleform::Render::TextureManager + 2))(v10);
    return 1;
  }
}
