Scaleform::Render::Font *__thiscall Scaleform::Render::Font::`vector deleting destructor'(
        Scaleform::Render::Font *this,
        char a2)
{
  this->__vftable = (Scaleform::Render::Font_vtbl *)&Scaleform::Render::Font::`vftable';
  Scaleform::Render::FontCacheHandleRef::releaseFont(&this->hRef);
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
