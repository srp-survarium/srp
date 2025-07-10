char __thiscall Scaleform::Render::D3D1x::Texture::Update(
        Scaleform::Render::D3D1x::Texture *this,
        const Scaleform::Render::Texture::UpdateDesc *updates,
        unsigned int count,
        unsigned int mipLevel)
{
  Scaleform::Render::D3D1x::Texture *v4; // edi
  unsigned int *p_y2; // esi
  unsigned int v7; // eax
  unsigned int v8; // edx
  unsigned __int8 *v9; // ecx
  unsigned int v10; // eax
  Scaleform::Render::MappedTextureBase *pMap; // ecx
  const Scaleform::Render::TextureFormat *pFormat; // ecx
  int v13; // edx
  unsigned __int8 *v14; // ebx
  unsigned int v15; // eax
  unsigned int v16; // edx
  void (__stdcall *v17)(unsigned __int8 *, const unsigned __int8 *, unsigned int, Scaleform::Render::Palette *, void *); // eax
  unsigned int v18; // [esp+Ch] [ebp-34h]
  Scaleform::Render::ImageFormat format; // [esp+14h] [ebp-2Ch]
  Scaleform::Render::ImagePlane dplane; // [esp+18h] [ebp-28h] BYREF
  Scaleform::Render::ImagePlane splane; // [esp+2Ch] [ebp-14h] BYREF

  v4 = this;
  if ( !this->pManagerLocks.pObject->pManager->mapTexture(this->pManagerLocks.pObject->pManager, this, mipLevel, 1) )
    return 0;
  format = v4->GetImageFormat(v4);
  memset(&dplane, 0, sizeof(dplane));
  if ( count )
  {
    p_y2 = &updates->DestRect.y2;
    v18 = count;
    do
    {
      v7 = *(p_y2 - 8);
      v8 = *(p_y2 - 6);
      splane.Height = *(p_y2 - 7);
      v9 = (unsigned __int8 *)*(p_y2 - 4);
      splane.Width = v7;
      v10 = *(p_y2 - 5);
      splane.Pitch = v8;
      splane.pData = v9;
      pMap = v4->pMap;
      splane.DataSize = v10;
      Scaleform::Render::ImageData::GetPlane(&pMap->Data, p_y2[1], &dplane);
      pFormat = v4->pFormat;
      v13 = *(p_y2 - 3);
      v14 = &dplane.pData[dplane.Pitch * *(p_y2 - 2) + v13 * LOBYTE(pFormat[1].GetScanlineCopyFn)];
      v15 = *(p_y2 - 1) - v13;
      v16 = *p_y2 - *(p_y2 - 2);
      splane.Width = v15;
      dplane.Width = v15;
      dplane.pData = v14;
      splane.Height = v16;
      dplane.Height = v16;
      v17 = pFormat->GetScanlineCopyFn(pFormat);
      Scaleform::Render::ConvertImagePlane(&dplane, &splane, format, p_y2[1], v17, 0, 0);
      v4 = this;
      p_y2 += 10;
      --v18;
    }
    while ( v18 );
  }
  v4->pManagerLocks.pObject->pManager->unmapTexture(v4->pManagerLocks.pObject->pManager, v4, 1);
  return 1;
}
