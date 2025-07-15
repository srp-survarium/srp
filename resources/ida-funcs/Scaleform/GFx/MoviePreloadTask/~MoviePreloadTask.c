void __thiscall Scaleform::GFx::MoviePreloadTask::~MoviePreloadTask(Scaleform::GFx::MoviePreloadTask *this)
{
  Scaleform::GFx::MovieDefImpl *pObject; // ecx
  volatile LONG *v3; // esi
  volatile LONG *v4; // esi
  volatile LONG *v5; // esi
  Scaleform::RefCountVImpl *v6; // ecx

  pObject = this->pDefImpl.pObject;
  if ( pObject )
    Scaleform::GFx::Resource::Release(pObject);
  v3 = (volatile LONG *)(this->UrlStrGfx.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(v3 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v3);
  v4 = (volatile LONG *)(this->Url.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(v4 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v4);
  v5 = (volatile LONG *)(this->Level0Path.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(v5 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v5);
  v6 = (Scaleform::RefCountVImpl *)this->pLoadStates.pObject;
  if ( v6 )
    Scaleform::RefCountImpl::Release(v6);
  this->__vftable = (Scaleform::GFx::MoviePreloadTask_vtbl *)&Scaleform::GFx::Task::`vftable';
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}
