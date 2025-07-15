char __thiscall Scaleform::Render::D3D1x::MappedTexture::Map(
        Scaleform::Render::D3D1x::MappedTexture *this,
        Scaleform::Render::Texture *ptexture,
        unsigned int mipLevel,
        unsigned int levelCount)
{
  Scaleform::Render::D3D1x::MappedTexture *v4; // esi
  Scaleform::Render::Texture *v5; // edi
  Scaleform::Render::ImageFormat v6; // eax
  Scaleform::Render::ImageFormat v7; // eax
  Scaleform::Render::TextureManager *pManager; // ebx
  Scaleform::Render::TextureManager_vtbl *v10; // eax
  volatile int RefCount; // ebx
  unsigned int *v12; // ebx
  unsigned int StartMipLevel; // esi
  Scaleform::Render::TextureManager_vtbl *v14; // edi
  volatile int v15; // edi
  int v16; // ebx
  unsigned int PlaneCount; // [esp+10h] [ebp-2B8h]
  volatile int v19; // [esp+2Ch] [ebp-29Ch]
  unsigned int plane; // [esp+30h] [ebp-298h]
  Scaleform::Render::TextureManager_vtbl *v21; // [esp+34h] [ebp-294h]
  int v22; // [esp+38h] [ebp-290h]
  int v23; // [esp+3Ch] [ebp-28Ch]
  unsigned int TextureCount; // [esp+40h] [ebp-288h]
  Scaleform::Render::ImagePlane src; // [esp+44h] [ebp-284h] BYREF
  _DWORD *v26; // [esp+58h] [ebp-270h]
  Scaleform::Render::Size<unsigned long> sz; // [esp+5Ch] [ebp-26Ch] BYREF
  _DWORD v28[3]; // [esp+64h] [ebp-264h] BYREF
  _DWORD v29[11]; // [esp+70h] [ebp-258h] BYREF
  char v30[44]; // [esp+9Ch] [ebp-22Ch] BYREF
  char v31[512]; // [esp+C8h] [ebp-200h] BYREF

  v4 = this;
  if ( levelCount > 4 )
  {
    v7 = ptexture->GetImageFormat(ptexture);
    if ( !Scaleform::Render::ImageData::Initialize(&v4->Data, v7, levelCount, 1) )
      return 0;
    v5 = ptexture;
  }
  else
  {
    v5 = ptexture;
    PlaneCount = Scaleform::Render::Texture::GetPlaneCount(ptexture);
    v6 = v5->GetImageFormat(v5);
    Scaleform::Render::ImageData::Initialize(&v4->Data, v6, levelCount, v4->Planes, PlaneCount, 1);
  }
  pManager = v5->pManagerLocks.pObject->pManager;
  v10 = pManager[1].Scaleform::RefCountBase<Scaleform::Render::TextureManager,75>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,75>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable;
  v21 = v10;
  if ( v10 )
    (*((void (__stdcall **)(Scaleform::Render::TextureManager_vtbl *))v10->~Scaleform::Render::TextureManager + 1))(v10);
  RefCount = pManager[1].RefCount;
  v19 = RefCount;
  if ( RefCount )
    (*(void (__stdcall **)(volatile int))(*(_DWORD *)RefCount + 4))(RefCount);
  plane = 0;
  v4->StartMipLevel = mipLevel;
  v4->pTexture = v5;
  v4->LevelCount = levelCount;
  TextureCount = v5->TextureCount;
  if ( !v5->TextureCount )
  {
LABEL_37:
    v4->pTexture->pMap = v4;
    if ( RefCount )
      (*(void (__stdcall **)(volatile int))(*(_DWORD *)RefCount + 8))(RefCount);
    if ( v21 )
      (*((void (__stdcall **)(Scaleform::Render::TextureManager_vtbl *))v21->~Scaleform::Render::TextureManager + 2))(v21);
    return 1;
  }
  v22 = 0;
  while ( 1 )
  {
    v12 = (unsigned int *)((char *)v5[1].__vftable + v22);
    src.Width = *v12;
    src.Height = v12[1];
    memset(&src.Pitch, 0, 12);
    if ( v4->StartMipLevel )
    {
      StartMipLevel = v4->StartMipLevel;
      do
      {
        Scaleform::Render::ImagePlane::SetNextMipSize(&src);
        --StartMipLevel;
      }
      while ( StartMipLevel );
    }
    (*(void (__stdcall **)(unsigned int, char *))(*(_DWORD *)v12[2] + 40))(v12[2], v30);
    qmemcpy(v29, v30, sizeof(v29));
    v29[9] = &_sbh_sizeHeaderList;
    v29[7] = 3;
    v29[8] = 0;
    v26 = v12 + 4;
    if ( v12[4] )
    {
      v14 = v21;
      goto LABEL_23;
    }
    vostok::sprintf<512>((char (*)[512])v31, "(StagingTexture)CreateTexture2D %dx%d", *v12, v12[1]);
    g_log_output_ptr(0, v31);
    v14 = v21;
    if ( (*((int (__stdcall **)(Scaleform::Render::TextureManager_vtbl *, _DWORD *, _DWORD, unsigned int *))v21->~Scaleform::Render::TextureManager
          + 5))(
           v21,
           v29,
           0,
           v12 + 4) < 0 )
      break;
LABEL_23:
    if ( (ptexture->Use & 0x480) != 0x480 )
      goto LABEL_30;
    if ( !checkHandleCopyResource )
    {
      canHandleCopyResource = (*((int (__stdcall **)(Scaleform::Render::TextureManager_vtbl *))v14->~Scaleform::Render::TextureManager
                               + 37))(v14) >= 40960;
      checkHandleCopyResource = 1;
    }
    if ( !warned_1 )
      warned_1 = !canHandleCopyResource;
    if ( canHandleCopyResource )
    {
      v15 = v19;
      (*(void (__stdcall **)(volatile int, unsigned int, unsigned int))(*(_DWORD *)v19 + 188))(v19, v12[4], v12[2]);
    }
    else
    {
LABEL_30:
      v15 = v19;
    }
    v16 = 0;
    if ( levelCount )
    {
      v23 = v22;
      while ( (*(int (__stdcall **)(volatile int, _DWORD, int, int, _DWORD, _DWORD *))(*(_DWORD *)v15 + 56))(
                v15,
                *v26,
                v16,
                2,
                0,
                v28) >= 0 )
      {
        src.Pitch = v28[1];
        src.pData = (unsigned __int8 *)v28[0];
        sz.Width = src.Width;
        sz.Height = src.Height;
        src.DataSize = Scaleform::Render::ImageData::GetMipLevelSize(this->Data.Format, &sz, plane);
        Scaleform::Render::ImagePlane::operator=(
          (Scaleform::Render::ImagePlane *)((char *)this->Data.pPlanes + v23),
          &src);
        Scaleform::Render::ImagePlane::SetNextMipSize(&src);
        v23 += 20 * TextureCount;
        if ( ++v16 >= levelCount )
          goto LABEL_35;
      }
      if ( v15 )
        (*(void (__stdcall **)(volatile int))(*(_DWORD *)v15 + 8))(v15);
      if ( v21 )
        goto LABEL_21;
      return 0;
    }
LABEL_35:
    ++plane;
    v22 += 20;
    v4 = this;
    if ( plane >= TextureCount )
    {
      RefCount = v19;
      goto LABEL_37;
    }
    v5 = ptexture;
  }
  if ( v19 )
    (*(void (__stdcall **)(volatile int))(*(_DWORD *)v19 + 8))(v19);
  if ( v21 )
LABEL_21:
    (*((void (__stdcall **)(Scaleform::Render::TextureManager_vtbl *))v21->~Scaleform::Render::TextureManager + 2))(v21);
  return 0;
}
