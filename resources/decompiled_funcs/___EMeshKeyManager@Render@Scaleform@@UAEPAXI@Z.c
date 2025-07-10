Scaleform::Render::MeshKeyManager *__thiscall Scaleform::Render::MeshKeyManager::`vector deleting destructor'(
        Scaleform::Render::MeshKeyManager *this,
        char a2)
{
  this->__vftable = (Scaleform::Render::MeshKeyManager_vtbl *)&Scaleform::Render::MeshKeyManager::`vftable';
  Scaleform::Render::MeshKeyManager::DestroyAllKeys(this);
  Scaleform::Lock::~Lock(&this->KeySetLock);
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
