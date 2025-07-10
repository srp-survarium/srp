Scaleform::Render::TextureManagerLocks *__thiscall Scaleform::Render::TextureManagerLocks::`vector deleting destructor'(
        Scaleform::Render::TextureManagerLocks *this,
        char a2)
{
  this->__vftable = (Scaleform::Render::TextureManagerLocks_vtbl *)&Scaleform::Render::TextureManagerLocks::`vftable';
  Scaleform::WaitCondition::~WaitCondition(&this->TextureInitWC);
  Scaleform::Mutex::~Mutex(&this->TextureMutex);
  Scaleform::Lock::~Lock(&this->ImageLock);
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
