Scaleform::GFx::AS2::GFxAS2LoadQueueEntryMT_LoadMovie *__thiscall Scaleform::GFx::AS2::GFxAS2LoadQueueEntryMT_LoadMovie::`vector deleting destructor'(
        Scaleform::GFx::AS2::GFxAS2LoadQueueEntryMT_LoadMovie *this,
        char a2)
{
  Scaleform::GFx::InteractiveObject *pObject; // ecx
  Scaleform::GFx::Sprite *v4; // ecx
  Scaleform::RefCountVImpl *v5; // ecx

  this->__vftable = (Scaleform::GFx::AS2::GFxAS2LoadQueueEntryMT_LoadMovie_vtbl *)&Scaleform::GFx::AS2::GFxAS2LoadQueueEntryMT_LoadMovie::`vftable';
  pObject = this->pOldChar.pObject;
  if ( pObject )
    Scaleform::RefCountNTSImpl::Release(pObject);
  v4 = this->pNewChar.pObject;
  if ( v4 )
    Scaleform::RefCountNTSImpl::Release(v4);
  v5 = (Scaleform::RefCountVImpl *)this->pPreloadTask.pObject;
  if ( v5 )
    Scaleform::RefCountImpl::Release(v5);
  Scaleform::GFx::LoadQueueEntryMT::~LoadQueueEntryMT(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
