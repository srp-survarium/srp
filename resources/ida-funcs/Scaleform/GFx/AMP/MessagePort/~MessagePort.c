void __thiscall Scaleform::GFx::AMP::MessagePort::~MessagePort(Scaleform::GFx::AMP::MessagePort *this)
{
  volatile LONG *v2; // esi
  volatile LONG *v3; // esi
  volatile LONG *v4; // esi

  v2 = (volatile LONG *)(this->FileName.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(v2 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v2);
  v3 = (volatile LONG *)(this->AppName.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(v3 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v3);
  v4 = (volatile LONG *)(this->PeerName.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(v4 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v4);
  this->__vftable = (Scaleform::GFx::AMP::MessagePort_vtbl *)&Scaleform::GFx::AMP::Message::`vftable';
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}
