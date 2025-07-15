Scaleform::GFx::LoadUpdateSync *__thiscall Scaleform::GFx::LoadUpdateSync::`scalar deleting destructor'(
        Scaleform::GFx::LoadUpdateSync *this,
        char a2)
{
  this->__vftable = (Scaleform::GFx::LoadUpdateSync_vtbl *)&Scaleform::GFx::LoadUpdateSync::`vftable';
  Scaleform::WaitCondition::~WaitCondition(&this->WC);
  Scaleform::Mutex::~Mutex(&this->mMutex);
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
