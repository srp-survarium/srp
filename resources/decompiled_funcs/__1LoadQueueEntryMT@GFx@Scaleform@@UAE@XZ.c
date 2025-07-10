void __thiscall Scaleform::GFx::LoadQueueEntryMT::~LoadQueueEntryMT(Scaleform::GFx::LoadQueueEntryMT *this)
{
  Scaleform::GFx::LoadQueueEntry *pQueueEntry; // ecx

  this->__vftable = (Scaleform::GFx::LoadQueueEntryMT_vtbl *)&Scaleform::GFx::LoadQueueEntryMT::`vftable';
  pQueueEntry = this->pQueueEntry;
  if ( pQueueEntry )
    ((void (__thiscall *)(Scaleform::GFx::LoadQueueEntry *, int))pQueueEntry->~Scaleform::GFx::LoadQueueEntry)(
      pQueueEntry,
      1);
}
