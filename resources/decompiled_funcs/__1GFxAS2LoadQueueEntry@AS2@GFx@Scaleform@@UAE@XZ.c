void __thiscall Scaleform::GFx::AS2::GFxAS2LoadQueueEntry::~GFxAS2LoadQueueEntry(
        Scaleform::GFx::AS2::GFxAS2LoadQueueEntry *this)
{
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::RefCountVImpl *v3; // ecx
  Scaleform::GFx::CharacterHandle *v4; // esi
  volatile LONG *v5; // edi

  pObject = (Scaleform::RefCountVImpl *)this->CSSHolder.Loader.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  if ( this->CSSHolder.ASObj.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&this->CSSHolder.ASObj);
  v3 = (Scaleform::RefCountVImpl *)this->XMLHolder.Loader.pObject;
  if ( v3 )
    Scaleform::RefCountImpl::Release(v3);
  if ( this->XMLHolder.ASObj.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&this->XMLHolder.ASObj);
  if ( this->LoadVarsHolder.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&this->LoadVarsHolder);
  if ( this->MovieClipLoaderHolder.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&this->MovieClipLoaderHolder);
  v4 = this->pCharacter.pObject;
  if ( v4 )
  {
    if ( --v4->RefCount <= 0 )
    {
      Scaleform::GFx::CharacterHandle::~CharacterHandle(v4);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v4);
    }
  }
  this->__vftable = (Scaleform::GFx::AS2::GFxAS2LoadQueueEntry_vtbl *)&Scaleform::GFx::LoadQueueEntry::`vftable';
  v5 = (volatile LONG *)(this->URL.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(v5 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v5);
}
