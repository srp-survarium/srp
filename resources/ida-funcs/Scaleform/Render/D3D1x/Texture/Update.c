char __thiscall Scaleform::Render::D3D1x::Texture::Update(
        Scaleform::Render::D3D1x::Texture *this,
        const Scaleform::Render::Texture::UpdateDesc *updates,
        unsigned int count,
        unsigned int mipLevel)
{
  Scaleform::AmpServer *Instance; // eax
  Scaleform::AmpStats *v6; // eax
  char v7; // bl
  unsigned int *p_y2; // esi
  const Scaleform::Render::TextureFormat *pFormat; // ecx
  int v11; // edx
  unsigned int v12; // eax
  unsigned int v13; // edx
  void (__stdcall *v14)(unsigned __int8 *, const unsigned __int8 *, unsigned int, Scaleform::Render::Palette *, void *); // eax
  const char *v15; // [esp+0h] [ebp-50h]
  Scaleform::AmpProfileLevel v16; // [esp+4h] [ebp-4Ch]
  Scaleform::AmpNativeFunctionId v17; // [esp+8h] [ebp-48h]
  unsigned int v18; // [esp+10h] [ebp-40h]
  Scaleform::Render::ImageFormat format; // [esp+14h] [ebp-3Ch]
  Scaleform::AmpFunctionTimer v20; // [esp+18h] [ebp-38h] BYREF
  Scaleform::Render::ImagePlane pplane; // [esp+28h] [ebp-28h] BYREF
  Scaleform::Render::ImagePlane splane; // [esp+3Ch] [ebp-14h] BYREF

  Instance = Scaleform::AmpServer::GetInstance();
  v6 = (Scaleform::AmpStats *)((int (__thiscall *)(Scaleform::AmpServer *, const char *, int, int))Instance->GetDisplayStats)(
                                Instance,
                                "Scaleform::Render::D3D1x::Texture::Update",
                                1,
                                -1);
  Scaleform::AmpFunctionTimer::AmpFunctionTimer((Scaleform::AmpFunctionTimer *)&v20.GpaTask, v6, v15, v16, v17);
  if ( this->pManagerLocks.pObject->pManager->mapTexture(this->pManagerLocks.pObject->pManager, this, mipLevel, 1) )
  {
    format = this->GetImageFormat(this);
    memset(&pplane, 0, sizeof(pplane));
    if ( count )
    {
      p_y2 = &updates->DestRect.y2;
      v18 = count;
      do
      {
        Scaleform::Render::ImagePlane::ImagePlane(&splane, (const Scaleform::Render::ImagePlane *)(p_y2 - 8));
        Scaleform::Render::ImageData::GetPlane(&this->pMap->Data, p_y2[1], &pplane);
        pFormat = this->pFormat;
        v11 = *(p_y2 - 3);
        pplane.pData += v11 * LOBYTE(pFormat[1].GetScanlineCopyFn) + pplane.Pitch * *(p_y2 - 2);
        v12 = *(p_y2 - 1) - v11;
        v13 = *p_y2 - *(p_y2 - 2);
        splane.Width = v12;
        splane.Height = v13;
        pplane.Width = v12;
        pplane.Height = v13;
        v14 = pFormat->GetScanlineCopyFn(pFormat);
        Scaleform::Render::ConvertImagePlane(&pplane, &splane, format, p_y2[1], v14, 0, 0);
        p_y2 += 10;
        --v18;
      }
      while ( v18 );
    }
    v7 = 1;
    this->pManagerLocks.pObject->pManager->unmapTexture(this->pManagerLocks.pObject->pManager, this, 1);
  }
  else
  {
    v7 = 0;
  }
  Scaleform::AmpFunctionTimer::~AmpFunctionTimer(&v20);
  return v7;
}
