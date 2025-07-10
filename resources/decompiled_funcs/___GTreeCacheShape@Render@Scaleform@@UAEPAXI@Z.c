Scaleform::Render::TreeCacheShape *__thiscall Scaleform::Render::TreeCacheShape::`scalar deleting destructor'(
        Scaleform::Render::TreeCacheShape *this,
        char a2)
{
  Scaleform::Render::TreeCacheShape::~TreeCacheShape(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
