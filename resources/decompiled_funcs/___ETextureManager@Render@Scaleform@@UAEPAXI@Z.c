Scaleform::Render::TextureManager *__thiscall Scaleform::Render::TextureManager::`vector deleting destructor'(
        Scaleform::Render::TextureManager *this,
        char a2)
{
  Scaleform::Render::TextureManager::~TextureManager(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
