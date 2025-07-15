void __thiscall Scaleform::Render::D3D1x::TextureManager::createMappedTexture(
        Scaleform::Render::D3D1x::TextureManager *this)
{
  void *v1; // eax
  Scaleform::Render::D3D1x::MappedTexture *v2; // [esp-4h] [ebp-4h]

  v1 = Scaleform::NewOverrideBase<75>::operator new(0x88u, (Scaleform::MemAddressStub *)this);
  if ( v1 )
    Scaleform::Render::D3D1x::MappedTexture::MappedTexture(v2, (int)v1);
}
