void __thiscall Scaleform::GFx::MovieDefImpl::BindTaskData::BindTaskData(
        Scaleform::GFx::MovieDefImpl::BindTaskData *this,
        Scaleform::MemoryHeap *pheap,
        Scaleform::GFx::MovieDataDef *pdataDef,
        Scaleform::GFx::MovieDefImpl *pdefImpl,
        unsigned int loadFlags,
        bool fullyLoaded)
{
  void *v7; // edi
  Scaleform::GFx::LoadUpdateSync *v8; // eax
  Scaleform::GFx::LoadUpdateSync *v9; // edi
  Scaleform::RefCountVImpl *pObject; // ecx
  volatile unsigned int v11; // eax
  Scaleform::GFx::MovieDataDef *v12; // ecx
  char v13; // [esp+10h] [ebp-8h]
  Scaleform::String v14; // [esp+14h] [ebp-4h] BYREF
  char pheapa; // [esp+1Ch] [ebp+4h]

  this->__vftable = (Scaleform::GFx::MovieDefImpl::BindTaskData_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  v13 = 0;
  this->RefCount = 1;
  this->__vftable = (Scaleform::GFx::MovieDefImpl::BindTaskData_vtbl *)&Scaleform::GFx::MovieDefImpl::BindTaskData::`vftable';
  this->pHeap = pheap;
  if ( pdataDef )
    Scaleform::RefCountImpl::AddRef(pdataDef);
  this->pDataDef.pObject = pdataDef;
  this->pDefImpl_Unsafe = pdefImpl;
  Scaleform::GFx::ResourceBinding::ResourceBinding(&this->ResourceBinding, pheap);
  this->ImportSourceMovies.Data.Data = 0;
  this->ImportSourceMovies.Data.Size = 0;
  this->ImportSourceMovies.Data.Policy.Capacity = 0;
  Scaleform::Lock::Lock(&this->ImportSourceLock, 0);
  this->ResourceImports.Data.Data = 0;
  this->ResourceImports.Data.Size = 0;
  this->ResourceImports.Data.Policy.Capacity = 0;
  this->BoundShapeMeshProviders.mHash.pTable = 0;
  this->pBindUpdate.pObject = 0;
  EnterCriticalSection(&this->ResourceBinding.ResourceLock.cs);
  this->ResourceBinding.pOwnerDefRes = pdefImpl;
  LeaveCriticalSection(&this->ResourceBinding.ResourceLock.cs);
  this->LoadFlags = loadFlags;
  this->BindingCanceled = 0;
  this->BindingFrame = 0;
  this->BytesLoaded = 0;
  this->BindState = 0;
  if ( pdataDef->MovieType != MT_Image
    || (Scaleform::String::String(
          &v14,
          (const __m128i *)((pdataDef->pData.pObject->FileURL.HeapTypeBits & 0xFFFFFFFC) + 8)),
        v13 = 1,
        pheapa = 0,
        !Scaleform::GFx::LoaderImpl::IsProtocolImage(&v14, 0, 0)) )
  {
    pheapa = 1;
  }
  if ( (v13 & 1) != 0 )
  {
    v7 = (void *)(v14.HeapTypeBits & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd((volatile LONG *)((v14.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v7);
  }
  if ( pheapa )
  {
    v8 = (Scaleform::GFx::LoadUpdateSync *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 36, 0);
    v9 = v8;
    if ( v8 )
    {
      v8->__vftable = (Scaleform::GFx::LoadUpdateSync_vtbl *)&Scaleform::RefCountImplCore::`vftable';
      v8->RefCount = 1;
      v8->__vftable = (Scaleform::GFx::LoadUpdateSync_vtbl *)&Scaleform::GFx::LoadUpdateSync::`vftable';
      Scaleform::Mutex::Mutex(&v8->mMutex, 1, 0);
      Scaleform::WaitCondition::WaitCondition(&v9->WC);
      v9->LoadFinished = 0;
    }
    else
    {
      v9 = 0;
    }
    pObject = (Scaleform::RefCountVImpl *)this->pBindUpdate.pObject;
    if ( pObject )
      Scaleform::RefCountImpl::Release(pObject);
    this->pBindUpdate.pObject = v9;
  }
  if ( fullyLoaded )
  {
    v11 = this->pDataDef.pObject->GetLoadingFrame(this->pDataDef.pObject);
    v12 = this->pDataDef.pObject;
    this->BindingFrame = v11;
    this->BytesLoaded = v12->pData.pObject->Header.FileLength;
  }
}
