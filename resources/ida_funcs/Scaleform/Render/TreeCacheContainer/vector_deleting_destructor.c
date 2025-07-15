Scaleform::Render::TreeCacheContainer *__thiscall Scaleform::Render::TreeCacheContainer::`vector deleting destructor'(
        Scaleform::Render::TreeCacheContainer *this,
        char a2)
{
  Scaleform::Render::TreeCacheContainer::~TreeCacheContainer(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
