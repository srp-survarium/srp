void __thiscall Scaleform::GFx::AMP::MessageLog::~MessageLog(Scaleform::GFx::AMP::MessageLog *this)
{
  volatile LONG *v2; // esi
  volatile LONG *v3; // esi

  v2 = (volatile LONG *)(this->TimeStamp.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(v2 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v2);
  v3 = (volatile LONG *)(this->LogText.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(v3 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v3);
  this->__vftable = (Scaleform::GFx::AMP::MessageLog_vtbl *)&Scaleform::GFx::AMP::Message::`vftable';
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}
