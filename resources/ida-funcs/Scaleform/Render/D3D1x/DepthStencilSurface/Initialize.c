BOOL __thiscall Scaleform::Render::D3D1x::DepthStencilSurface::Initialize(
        Scaleform::Render::D3D1x::DepthStencilSurface *this)
{
  Scaleform::Render::TextureManager *v2; // ebx
  unsigned int Height; // ecx
  unsigned int Width; // eax
  char v6[512]; // [esp+Ch] [ebp-22Ch] BYREF
  unsigned __int8 dst[44]; // [esp+20Ch] [ebp-2Ch] BYREF

  v2 = this->GetTextureManager(this);
  memset((int)dst, 0, sizeof(dst));
  Height = this->Size.Height;
  Width = this->Size.Width;
  *(_DWORD *)&dst[28] = 0;
  *(_DWORD *)&dst[36] = 0;
  *(_DWORD *)dst = Width;
  *(_DWORD *)&dst[4] = Height;
  *(_DWORD *)&dst[8] = 1;
  *(_DWORD *)&dst[12] = 1;
  *(_DWORD *)&dst[16] = 45;
  *(_DWORD *)&dst[32] = 64;
  *(_DWORD *)&dst[20] = 1;
  vostok::sprintf<512>((char (*)[512])v6, "(DepthStencilSurface)CreateTexture2D %dx%d", Width, Height);
  g_log_output_ptr(0, v6);
  if ( (*((int (__stdcall **)(Scaleform::Render::TextureManager_vtbl *, unsigned __int8 *, _DWORD, ID3D11Texture2D **))v2[1].~Scaleform::Render::TextureManager
        + 5))(
         v2[1].Scaleform::RefCountBase<Scaleform::Render::TextureManager,75>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,75>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable,
         dst,
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
  }
  else
  {
    this->State = State_Dead;
  }
  return this->State == State_Dead;
}
