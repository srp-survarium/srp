Scaleform::GFx::AS3::LoadQueueEntryMT_LoadMovie *__thiscall Scaleform::GFx::AS3::LoadQueueEntryMT_LoadMovie::`scalar deleting destructor'(
        Scaleform::GFx::AS3::LoadQueueEntryMT_LoadMovie *this,
        char a2)
{
  Scaleform::RefCountVImpl *pObject; // ecx

  this->__vftable = (Scaleform::GFx::AS3::LoadQueueEntryMT_LoadMovie_vtbl *)&Scaleform::GFx::AS3::LoadQueueEntryMT_LoadMovie::`vftable';
  pObject = (Scaleform::RefCountVImpl *)this->pPreloadTask.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  Scaleform::GFx::LoadQueueEntryMT::~LoadQueueEntryMT(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
