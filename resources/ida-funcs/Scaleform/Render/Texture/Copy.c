char __thiscall Scaleform::Render::Texture::Copy(Scaleform::Render::Texture *this, Scaleform::Render::ImageData *pdata)
{
  void (__stdcall *v3)(unsigned __int8 *, const unsigned __int8 *, unsigned int, Scaleform::Render::Palette *, void *); // esi
  Scaleform::Render::TextureManagerLocks *pObject; // eax
  Scaleform::Render::TextureManager *pManager; // ebx
  int MipLevels; // edx
  Scaleform::Render::TextureManagerLocks *v8; // eax
  Scaleform::Render::TextureManager *v9; // ecx
  int v10; // esi
  Scaleform::Render::ImageFormat v11; // eax
  Scaleform::Render::TextureManagerLocks *v12; // eax
  void (__stdcall *copyScanline)(unsigned __int8 *, const unsigned __int8 *, unsigned int, Scaleform::Render::Palette *, void *); // [esp+10h] [ebp-2Ch]
  Scaleform::Render::ImagePlane splane; // [esp+14h] [ebp-28h] BYREF
  Scaleform::Render::ImagePlane pplane; // [esp+28h] [ebp-14h] BYREF
  bool v17; // [esp+40h] [ebp+4h]

  v3 = this->pFormat->GetScanlineUncopyFn(this->pFormat);
  pObject = this->pManagerLocks.pObject;
  pManager = 0;
  copyScanline = v3;
  if ( !pObject || !pObject->pManager || this->GetFormat(this) != pdata->Format || !v3 )
    return 0;
  MipLevels = 1;
  v17 = this->pMap != 0;
  if ( (this->Use & 2) == 0 )
    MipLevels = this->MipLevels;
  if ( !this->pMap )
  {
    v8 = this->pManagerLocks.pObject;
    v9 = v8 ? v8->pManager : 0;
    if ( !v9->mapTexture(v9, this, 0, MipLevels) )
      return 0;
  }
  v10 = 0;
  if ( pdata->RawPlaneCount )
  {
    do
    {
      memset(&splane, 0, sizeof(splane));
      memset(&pplane, 0, sizeof(pplane));
      Scaleform::Render::ImageData::GetPlane(pdata, v10, &pplane);
      Scaleform::Render::ImageData::GetPlane(&this->pMap->Data, v10, &splane);
      v11 = this->GetFormat(this);
      Scaleform::Render::ConvertImagePlane(&pplane, &splane, v11, v10++, copyScanline, 0, 0);
    }
    while ( v10 < pdata->RawPlaneCount );
  }
  if ( !v17 )
  {
    v12 = this->pManagerLocks.pObject;
    if ( v12 )
      pManager = v12->pManager;
    pManager->unmapTexture(pManager, this, 1);
  }
  return 1;
}
