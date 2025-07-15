char __thiscall Scaleform::Render::Primitive::Insert(
        Scaleform::Render::Primitive *this,
        void (__thiscall *index)(struct Scaleform::Render::Primitive *this),
        Scaleform::GFx::Resource *pmesh,
        const Scaleform::Render::MatrixPoolImpl::HMatrix *m)
{
  Scaleform::Render::Primitive *pNext; // esi
  Scaleform::Render::Primitive *v6; // ebx
  void (__thiscall *v7)(struct Scaleform::Render::Primitive *); // edi
  Scaleform::Render::MeshCache *v8; // eax
  void (__thiscall *v9)(struct Scaleform::Render::Primitive *); // edx
  unsigned int Size; // ecx
  Scaleform::Render::Primitive_vtbl *v11; // eax
  Scaleform::Render::MatrixPoolImpl::EntryHandle *pHandle; // eax
  Scaleform::Render::ComplexPrimitiveBundle::InstanceEntry val; // [esp+10h] [ebp-8h] BYREF

  pNext = (Scaleform::Render::Primitive *)this->Batches.Root.pNext;
  v6 = 0;
  v7 = 0;
  v8 = this->pHAL->GetMeshCache(this->pHAL);
  val.M.pHandle = (Scaleform::Render::MatrixPoolImpl::EntryHandle *)v8->GetParams(&v8->Scaleform::Render::MeshCacheConfig);
  while ( 1 )
  {
    v9 = index;
    if ( v7 == index )
    {
      if ( v6 && v6->Batches.Root.pPrev == (Scaleform::Render::PrimitiveBatch *)3 )
      {
        ++v6->Meshes.Data.Size;
        goto LABEL_17;
      }
      if ( pNext == (Scaleform::Render::Primitive *)&this->Batches
        || pNext->Batches.Root.pPrev != (Scaleform::Render::PrimitiveBatch *)3 )
      {
        v11 = (Scaleform::Render::Primitive_vtbl *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                     Scaleform::Memory::pGlobalHeap,
                                                     this,
                                                     44,
                                                     0);
        v11[4].~Scaleform::Render::Primitive = 0;
        v11[5].~Scaleform::Render::Primitive = (void (__thiscall *)(struct Scaleform::Render::Primitive *))3;
        v11[6].~Scaleform::Render::Primitive = 0;
        LOBYTE(v11[7].~Scaleform::Render::Primitive) = 0;
        v11[8].~Scaleform::Render::Primitive = (void (__thiscall *)(struct Scaleform::Render::Primitive *))this;
        v11[9].~Scaleform::Render::Primitive = (void (__thiscall *)(struct Scaleform::Render::Primitive *))1;
        v11[10].~Scaleform::Render::Primitive = v7;
        v11[1].~Scaleform::Render::Primitive = *(void (__thiscall **)(struct Scaleform::Render::Primitive *))pNext->RefCount;
        v11->~Scaleform::Render::Primitive = (void (__thiscall *)(struct Scaleform::Render::Primitive *))pNext->Scaleform::RefCountBase<Scaleform::Render::Primitive,68>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,68>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable;
        pNext->Scaleform::RefCountBase<Scaleform::Render::Primitive,68>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,68>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable[1].~Scaleform::Render::Primitive = (void (__thiscall *)(struct Scaleform::Render::Primitive *))v11;
        v9 = index;
        pNext->Scaleform::RefCountBase<Scaleform::Render::Primitive,68>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,68>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable = v11;
        goto LABEL_17;
      }
    }
    if ( pNext == (Scaleform::Render::Primitive *)&this->Batches )
      goto LABEL_17;
    Size = pNext->Meshes.Data.Size;
    if ( (char *)index - (char *)v7 < Size )
      break;
    v6 = pNext;
    pNext = (Scaleform::Render::Primitive *)pNext->RefCount;
    v7 = (void (__thiscall *)(struct Scaleform::Render::Primitive *))((char *)v7 + Size);
  }
  ++pNext->Meshes.Data.Size;
  if ( pNext->Batches.Root.pPrev != (Scaleform::Render::PrimitiveBatch *)2
    || (Scaleform::GFx::Resource *)this->Meshes.Data.Data[(_DWORD)v7].pMesh.pObject != pmesh
    || (Scaleform::Render::MatrixPoolImpl::DataHeader *)pNext->Meshes.Data.Size > val.M.pHandle[6].pHeader )
  {
    pNext->Batches.Root.pPrev = (Scaleform::Render::PrimitiveBatch *)3;
    if ( pNext->pFill.pObject )
    {
      pNext->Prepare = (Scaleform::Render::RenderQueueItem::QIPrepareResult (__thiscall *)(Scaleform::Render::RenderQueueItem::Interface *, Scaleform::Render::RenderQueueItem *, Scaleform::Render::RenderQueueProcessor *, bool))pNext->pHAL;
      pNext->pHAL->__vftable = (Scaleform::Render::HAL_vtbl *)pNext->Scaleform::Render::RenderQueueItem::Interface::__vftable;
      pNext->pFill.pObject = 0;
    }
  }
LABEL_17:
  pHandle = m->pHandle;
  val.M.pHandle = pHandle;
  if ( pHandle != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
    ++pHandle->pHeader->RefCount;
  if ( pmesh )
  {
    Scaleform::RefCountImpl::AddRef(pmesh);
    v9 = index;
  }
  val.pMesh.pObject = (Scaleform::Render::ComplexMesh *)pmesh;
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Primitive::MeshEntry,Scaleform::AllocatorLH<Scaleform::Render::Primitive::MeshEntry,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
    (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::ComplexPrimitiveBundle::InstanceEntry,Scaleform::AllocatorLH<Scaleform::Render::ComplexPrimitiveBundle::InstanceEntry,2>,Scaleform::ArrayDefaultPolicy> > *)&this->Meshes,
    (unsigned int)v9,
    &val);
  if ( (unsigned int)index < this->ModifyIndex )
    this->ModifyIndex = (unsigned int)index;
  ++Primitive_Insert;
  if ( val.pMesh.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)val.pMesh.pObject);
  if ( val.M.pHandle != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
    Scaleform::Render::MatrixPoolImpl::DataHeader::Release(val.M.pHandle->pHeader);
  return 1;
}
