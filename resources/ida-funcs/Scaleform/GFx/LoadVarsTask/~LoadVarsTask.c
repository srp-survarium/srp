void __thiscall Scaleform::GFx::LoadVarsTask::~LoadVarsTask(Scaleform::GFx::LoadVarsTask *this)
{
  volatile LONG *v2; // esi
  volatile LONG *v3; // esi
  volatile LONG *v4; // esi
  Scaleform::RefCountVImpl *pObject; // ecx

  v2 = (volatile LONG *)(this->Data.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(v2 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v2);
  v3 = (volatile LONG *)(this->Url.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(v3 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v3);
  v4 = (volatile LONG *)(this->Level0Path.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(v4 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v4);
  pObject = (Scaleform::RefCountVImpl *)this->pLoadStates.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->__vftable = (Scaleform::GFx::LoadVarsTask_vtbl *)&Scaleform::GFx::Task::`vftable';
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}
