Scaleform::Render::FontCacheHandleManager *__thiscall Scaleform::Render::FontCacheHandleManager::`vector deleting destructor'(
        Scaleform::Render::FontCacheHandleManager *this,
        char a2)
{
  this->__vftable = (Scaleform::Render::FontCacheHandleManager_vtbl *)&Scaleform::Render::FontCacheHandleManager::`vftable';
  Scaleform::Render::FontCacheHandleManager::DestroyAllFonts(this);
  Scaleform::Lock::~Lock(&this->FontLock);
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
