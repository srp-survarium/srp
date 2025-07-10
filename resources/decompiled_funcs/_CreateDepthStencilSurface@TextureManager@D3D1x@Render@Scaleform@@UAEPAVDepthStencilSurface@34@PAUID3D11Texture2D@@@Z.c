void __thiscall Scaleform::Render::D3D1x::TextureManager::CreateDepthStencilSurface(
        Scaleform::Render::D3D1x::TextureManager *this,
        ID3D11Texture2D *psurface)
{
  ID3D11Texture2D *v2; // ebx
  void *(__thiscall *AllocAutoHeap)(Scaleform::MemoryHeap *, const void *, unsigned int, const Scaleform::AllocInfo *); // edx
  Scaleform::Render::D3D1x::DepthStencilSurface *v5; // eax
  Scaleform::GFx::Resource *pObject; // esi
  int v7; // eax
  Scaleform::Render::Size<unsigned long> size; // [esp+18h] [ebp-34h] BYREF
  D3D11_TEXTURE2D_DESC desc; // [esp+20h] [ebp-2Ch] BYREF

  v2 = psurface;
  if ( psurface )
  {
    psurface->AddRef(psurface);
    v2->GetDesc(v2, &desc);
    AllocAutoHeap = Scaleform::Memory::pGlobalHeap->AllocAutoHeap;
    psurface = (ID3D11Texture2D *)75;
    v5 = (Scaleform::Render::D3D1x::DepthStencilSurface *)AllocAutoHeap(
                                                            Scaleform::Memory::pGlobalHeap,
                                                            this,
                                                            40u,
                                                            (const Scaleform::AllocInfo *)&psurface);
    if ( v5 )
    {
      pObject = (Scaleform::GFx::Resource *)this->pLocks.pObject;
      size.Width = desc.Width;
      size.Height = desc.Height;
      Scaleform::Render::D3D1x::DepthStencilSurface::DepthStencilSurface(v5, pObject, &size);
      *(_DWORD *)(v7 + 32) = v2;
      *(_DWORD *)(v7 + 20) = 2;
    }
    else
    {
      MEMORY[0x20] = v2;
      MEMORY[0x14] = 2;
    }
  }
}
