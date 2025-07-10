Scaleform::Render::TreeCacheRoot *__thiscall Scaleform::Render::TreeCacheRoot::`vector deleting destructor'(
        Scaleform::Render::TreeCacheRoot *this,
        char a2)
{
  Scaleform::Render::TreeCacheRoot::~TreeCacheRoot(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
