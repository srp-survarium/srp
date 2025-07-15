Scaleform::Render::MappedTextureBase *__thiscall Scaleform::Render::D3D1x::TextureManager::createMappedTexture(
        Scaleform::Render::D3D1x::TextureManager *this)
{
  void *(__thiscall *AllocAutoHeap)(Scaleform::MemoryHeap *, const void *, unsigned int, const Scaleform::AllocInfo *); // eax
  Scaleform::Render::MappedTextureBase *v2; // ecx
  _DWORD *v3; // esi
  int v5; // [esp+4h] [ebp-4h] BYREF

  AllocAutoHeap = Scaleform::Memory::pGlobalHeap->AllocAutoHeap;
  v5 = 75;
  v3 = (_DWORD *)AllocAutoHeap(Scaleform::Memory::pGlobalHeap, this, 136u, (const Scaleform::AllocInfo *)&v5);
  if ( !v3 )
    return 0;
  Scaleform::Render::MappedTextureBase::MappedTextureBase(v2);
  *v3 = &Scaleform::Render::D3D1x::MappedTexture::`vftable';
  return (Scaleform::Render::MappedTextureBase *)v3;
}
