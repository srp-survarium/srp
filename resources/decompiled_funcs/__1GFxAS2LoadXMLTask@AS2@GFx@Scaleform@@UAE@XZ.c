void __thiscall Scaleform::GFx::AS2::GFxAS2LoadXMLTask::~GFxAS2LoadXMLTask(
        Scaleform::GFx::AS2::GFxAS2LoadCSSTask *this)
{
  Scaleform::RefCountVImpl *pObject; // ecx
  volatile LONG *v3; // esi
  volatile LONG *v4; // esi
  Scaleform::RefCountVImpl *v5; // ecx

  pObject = (Scaleform::RefCountVImpl *)this->pLoader.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  v3 = (volatile LONG *)(this->Url.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(v3 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v3);
  v4 = (volatile LONG *)(this->Level0Path.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(v4 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v4);
  v5 = (Scaleform::RefCountVImpl *)this->pLoadStates.pObject;
  if ( v5 )
    Scaleform::RefCountImpl::Release(v5);
  this->__vftable = (Scaleform::GFx::AS2::GFxAS2LoadCSSTask_vtbl *)&Scaleform::GFx::Task::`vftable';
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}
