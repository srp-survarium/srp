void __thiscall Scaleform::GFx::LoadBinaryTask::~LoadBinaryTask(Scaleform::GFx::LoadBinaryTask *this)
{
  unsigned __int8 *Data; // eax
  volatile LONG *v3; // esi
  volatile LONG *v4; // esi
  Scaleform::RefCountVImpl *pObject; // ecx

  Data = this->Data.Data.Data;
  if ( Data )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, Data);
  v3 = (volatile LONG *)(this->Url.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(v3 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v3);
  v4 = (volatile LONG *)(this->Level0Path.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(v4 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v4);
  pObject = (Scaleform::RefCountVImpl *)this->pLoadStates.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->__vftable = (Scaleform::GFx::LoadBinaryTask_vtbl *)&Scaleform::GFx::Task::`vftable';
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}
