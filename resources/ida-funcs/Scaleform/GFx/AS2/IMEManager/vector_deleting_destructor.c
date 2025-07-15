Scaleform::GFx::AS2::IMEManager *__thiscall Scaleform::GFx::AS2::IMEManager::`vector deleting destructor'(
        Scaleform::GFx::AS2::IMEManager *this,
        char a2)
{
  volatile LONG *v3; // edi

  v3 = (volatile LONG *)(this->CandListPath.HeapTypeBits & 0xFFFFFFFC);
  this->__vftable = (Scaleform::GFx::AS2::IMEManager_vtbl *)&Scaleform::GFx::AS2::IMEManager::`vftable';
  if ( InterlockedExchangeAdd(v3 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v3);
  Scaleform::GFx::ASIMEManager::~ASIMEManager(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
