Scaleform::Render::D3D1x::TextureManager *__thiscall Scaleform::Render::D3D1x::TextureManager::`scalar deleting destructor'(
        Scaleform::Render::D3D1x::TextureManager *this,
        char a2)
{
  Scaleform::Render::D3D1x::TextureManager::~TextureManager(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
