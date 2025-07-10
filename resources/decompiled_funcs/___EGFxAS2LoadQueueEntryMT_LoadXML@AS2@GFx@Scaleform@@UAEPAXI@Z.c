Scaleform::GFx::AS2::GFxAS2LoadQueueEntryMT_LoadXML *__thiscall Scaleform::GFx::AS2::GFxAS2LoadQueueEntryMT_LoadXML::`vector deleting destructor'(
        Scaleform::GFx::AS2::GFxAS2LoadQueueEntryMT_LoadXML *this,
        char a2)
{
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::RefCountVImpl *v4; // ecx

  this->__vftable = (Scaleform::GFx::AS2::GFxAS2LoadQueueEntryMT_LoadXML_vtbl *)&Scaleform::GFx::AS2::GFxAS2LoadQueueEntryMT_LoadXML::`vftable';
  pObject = (Scaleform::RefCountVImpl *)this->pLoadStates.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  v4 = (Scaleform::RefCountVImpl *)this->pTask.pObject;
  if ( v4 )
    Scaleform::RefCountImpl::Release(v4);
  Scaleform::GFx::LoadQueueEntryMT::~LoadQueueEntryMT(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
