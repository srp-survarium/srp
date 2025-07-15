Scaleform::Render::DepthStencilSurface *__thiscall Scaleform::Render::D3D1x::TextureManager::CreateDepthStencilSurface(
        Scaleform::Render::D3D1x::TextureManager *this,
        const Scaleform::Render::Size<unsigned long> *size,
        struct Scaleform::Render::MemoryManager *manager)
{
  Scaleform::Render::D3D1x::DepthStencilSurface *v5; // eax
  Scaleform::Render::DepthStencilSurface *v6; // eax

  if ( !this->pDevice )
    return 0;
  v5 = (Scaleform::Render::D3D1x::DepthStencilSurface *)Scaleform::NewOverrideBase<75>::operator new(
                                                          0x28u,
                                                          (Scaleform::MemAddressStub *)this);
  if ( v5 )
    Scaleform::Render::D3D1x::DepthStencilSurface::DepthStencilSurface(
      v5,
      size,
      (Scaleform::GFx::Resource *)this->pLocks.pObject);
  else
    v6 = 0;
  return Scaleform::Render::TextureManager::postCreateDepthStencilSurface(this, v6);
}


void __thiscall Scaleform::Render::D3D1x::TextureManager::CreateDepthStencilSurface(
        Scaleform::Render::D3D1x::TextureManager *this,
        ID3D11Texture2D *psurface)
{
  Scaleform::Render::D3D1x::DepthStencilSurface *v3; // eax
  int v4; // eax
  Scaleform::Render::TextureManagerLocks *pObject; // [esp-8h] [ebp-44h]
  Scaleform::Render::Size<unsigned long> v6; // [esp+8h] [ebp-34h] BYREF
  Scaleform::Render::Size<unsigned long> v7; // [esp+34h] [ebp-8h] BYREF

  if ( psurface )
  {
    psurface->AddRef(psurface);
    psurface->GetDesc(psurface, (D3D11_TEXTURE2D_DESC *)&v6);
    v3 = (Scaleform::Render::D3D1x::DepthStencilSurface *)Scaleform::NewOverrideBase<75>::operator new(
                                                            0x28u,
                                                            (Scaleform::MemAddressStub *)this);
    if ( v3 )
    {
      pObject = this->pLocks.pObject;
      v7 = v6;
      Scaleform::Render::D3D1x::DepthStencilSurface::DepthStencilSurface(v3, &v7, (Scaleform::GFx::Resource *)pObject);
    }
    else
    {
      v4 = 0;
    }
    *(_DWORD *)(v4 + 32) = psurface;
    *(_DWORD *)(v4 + 20) = 2;
  }
}
