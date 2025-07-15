Scaleform::GFx::LoadQueueEntryMT_LoadVars *__thiscall Scaleform::GFx::LoadQueueEntryMT_LoadVars::`scalar deleting destructor'(
        Scaleform::GFx::LoadQueueEntryMT_LoadVars *this,
        char a2)
{
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::RefCountVImpl *v4; // ecx
  Scaleform::GFx::LoadQueueEntry *pQueueEntry; // ecx

  this->__vftable = (Scaleform::GFx::LoadQueueEntryMT_LoadVars_vtbl *)&Scaleform::GFx::LoadQueueEntryMT_LoadVars::`vftable';
  pObject = (Scaleform::RefCountVImpl *)this->pLoadStates.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  v4 = (Scaleform::RefCountVImpl *)this->pTask.pObject;
  if ( v4 )
    Scaleform::RefCountImpl::Release(v4);
  pQueueEntry = this->pQueueEntry;
  this->__vftable = (Scaleform::GFx::LoadQueueEntryMT_LoadVars_vtbl *)&Scaleform::GFx::LoadQueueEntryMT::`vftable';
  if ( pQueueEntry )
    ((void (__thiscall *)(Scaleform::GFx::LoadQueueEntry *, int))pQueueEntry->~Scaleform::GFx::LoadQueueEntry)(
      pQueueEntry,
      1);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
