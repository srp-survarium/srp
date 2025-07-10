char __thiscall Scaleform::Render::Primitive::Insert(
        Scaleform::Render::Primitive *this,
        void (__thiscall *index)(struct Scaleform::Render::Primitive *this),
        Scaleform::Render::Mesh *pmesh,
        const Scaleform::Render::MatrixPoolImpl::HMatrix *m)
{
  Scaleform::Render::Primitive *pNext; // esi
  Scaleform::Render::Primitive *v6; // ebx
  void (__thiscall *v7)(struct Scaleform::Render::Primitive *); // edi
  Scaleform::Render::MeshCache *v8; // eax
  unsigned int v9; // edx
  unsigned int Size; // ecx
  Scaleform::Render::Primitive_vtbl *v11; // eax
  Scaleform::Render::MatrixPoolImpl::EntryHandle *pHandle; // eax
  const Scaleform::Render::MeshCacheParams *params; // [esp+10h] [ebp-8h] BYREF
  Scaleform::RefCountVImpl *v15; // [esp+14h] [ebp-4h]

  pNext = (Scaleform::Render::Primitive *)this->Batches.Root.pNext;
  v6 = 0;
  v7 = 0;
  v8 = this->pHAL->GetMeshCache(this->pHAL);
  params = v8->GetParams(&v8->Scaleform::Render::MeshCacheConfig);
  while ( 1 )
  {
    v9 = (unsigned int)index;
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
        v9 = (unsigned int)index;
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
    || this->Meshes.Data.Data[(_DWORD)v7].pMesh.pObject != pmesh
    || pNext->Meshes.Data.Size > params->MaxBatchInstances )
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
  params = (const Scaleform::Render::MeshCacheParams *)pHandle;
  if ( pHandle != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
    ++pHandle->pHeader->RefCount;
  if ( pmesh )
  {
    Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)pmesh);
    v9 = (unsigned int)index;
  }
  v15 = (Scaleform::RefCountVImpl *)pmesh;
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Primitive::MeshEntry,Scaleform::AllocatorLH<Scaleform::Render::Primitive::MeshEntry,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
    (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::ComplexPrimitiveBundle::InstanceEntry,Scaleform::AllocatorLH<Scaleform::Render::ComplexPrimitiveBundle::InstanceEntry,2>,Scaleform::ArrayDefaultPolicy> > *)&this->Meshes,
    v9,
    (const Scaleform::Render::ComplexPrimitiveBundle::InstanceEntry *)&params);
  if ( (unsigned int)index < this->ModifyIndex )
    this->ModifyIndex = (unsigned int)index;
  ++Primitive_Insert;
  if ( v15 )
    Scaleform::RefCountImpl::Release(v15);
  if ( params != (const Scaleform::Render::MeshCacheParams *)&Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
    Scaleform::Render::MatrixPoolImpl::DataHeader::Release((Scaleform::Render::MatrixPoolImpl::DataHeader *)params->MemReserve);
  return 1;
}
