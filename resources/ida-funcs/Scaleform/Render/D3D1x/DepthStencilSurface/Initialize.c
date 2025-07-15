BOOL __thiscall Scaleform::Render::D3D1x::DepthStencilSurface::Initialize(
        Scaleform::Render::D3D1x::DepthStencilSurface *this)
{
  Scaleform::Render::TextureManager *v2; // edi
  unsigned int Height; // edx
  unsigned int Width; // ecx
  D3D11_TEXTURE2D_DESC desc; // [esp+10h] [ebp-2Ch] BYREF

  v2 = this->GetTextureManager(this);
  memset((int)&desc, 0, sizeof(desc));
  Height = this->Size.Height;
  Width = this->Size.Width;
  desc.Usage = D3D11_USAGE_DEFAULT;
  desc.CPUAccessFlags = 0;
  desc.Height = Height;
  desc.Width = Width;
  desc.MipLevels = 1;
  desc.ArraySize = 1;
  desc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
  desc.BindFlags = 64;
  desc.SampleDesc.Count = 1;
  if ( (*((int (__stdcall **)(Scaleform::Render::TextureManager_vtbl *, D3D11_TEXTURE2D_DESC *, _DWORD, ID3D11Texture2D **))v2[1].~Scaleform::Render::TextureManager
        + 5))(
         v2[1].Scaleform::RefCountBase<Scaleform::Render::TextureManager,75>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,75>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable,
         &desc,
         0,
         &this->pDepthStencilSurface) < 0
    || (*((int (__stdcall **)(Scaleform::Render::TextureManager_vtbl *, ID3D11Texture2D *, _DWORD, ID3D11DepthStencilView **))v2[1].~Scaleform::Render::TextureManager
        + 10))(
         v2[1].Scaleform::RefCountBase<Scaleform::Render::TextureManager,75>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,75>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable,
         this->pDepthStencilSurface,
         0,
         &this->pDepthStencilSurfaceView) < 0 )
  {
    this->State = State_Valid;
    return 0;
  }
  else
  {
    this->State = State_Dead;
    return this->State == State_Dead;
  }
}
