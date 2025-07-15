Scaleform::GFx::LoadQueueEntryMT *__thiscall Scaleform::GFx::LoadQueueEntryMT::`scalar deleting destructor'(
        Scaleform::GFx::LoadQueueEntryMT *this,
        char a2)
{
  Scaleform::GFx::LoadQueueEntry *pQueueEntry; // ecx

  pQueueEntry = this->pQueueEntry;
  this->__vftable = (Scaleform::GFx::LoadQueueEntryMT_vtbl *)&Scaleform::GFx::LoadQueueEntryMT::`vftable';
  if ( pQueueEntry )
    ((void (__thiscall *)(Scaleform::GFx::LoadQueueEntry *, int))pQueueEntry->~Scaleform::GFx::LoadQueueEntry)(
      pQueueEntry,
      1);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
