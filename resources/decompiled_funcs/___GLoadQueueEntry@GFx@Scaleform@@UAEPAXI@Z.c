Scaleform::GFx::LoadQueueEntry *__thiscall Scaleform::GFx::LoadQueueEntry::`scalar deleting destructor'(
        Scaleform::GFx::LoadQueueEntry *this,
        char a2)
{
  volatile LONG *v3; // esi

  v3 = (volatile LONG *)(this->URL.HeapTypeBits & 0xFFFFFFFC);
  this->__vftable = (Scaleform::GFx::LoadQueueEntry_vtbl *)&Scaleform::GFx::LoadQueueEntry::`vftable';
  if ( InterlockedExchangeAdd(v3 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v3);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
