void __thiscall Scaleform::Render::Primitive::Remove(
        Scaleform::Render::Primitive *this,
        unsigned int index,
        unsigned int count)
{
  unsigned int v3; // ebp
  Scaleform::Render::Primitive *v4; // eax
  Scaleform::Render::Primitive *pNext; // esi
  unsigned int v6; // edi
  int v7; // ebx
  unsigned int Size; // ecx
  volatile int *p_RefCount; // ecx
  _DWORD *v10; // eax
  unsigned int v11; // eax
  bool v12; // zf

  v3 = index;
  v4 = this;
  pNext = (Scaleform::Render::Primitive *)this->Batches.Root.pNext;
  v6 = count;
  v7 = 0;
  while ( 1 )
  {
    Size = pNext->Meshes.Data.Size;
    if ( v3 - v7 < Size )
      break;
    v7 += Size;
LABEL_15:
    pNext = (Scaleform::Render::Primitive *)pNext->RefCount;
LABEL_16:
    v4 = this;
    if ( !v6 || pNext == (Scaleform::Render::Primitive *)&this->Batches )
      goto LABEL_22;
  }
  if ( v3 != v7 )
  {
    v11 = Size - v3 + v7;
    if ( v6 <= v11 )
      v11 = v6;
    v12 = pNext->Batches.Root.pPrev == (Scaleform::Render::PrimitiveBatch *)2;
    pNext->Meshes.Data.Size = Size - v11;
    if ( !v12 )
    {
      pNext->Batches.Root.pPrev = (Scaleform::Render::PrimitiveBatch *)3;
      if ( pNext->pFill.pObject )
      {
        pNext->Prepare = (Scaleform::Render::RenderQueueItem::QIPrepareResult (__thiscall *)(Scaleform::Render::RenderQueueItem::Interface *, Scaleform::Render::RenderQueueItem *, Scaleform::Render::RenderQueueProcessor *, bool))pNext->pHAL;
        pNext->pHAL->__vftable = (Scaleform::Render::HAL_vtbl *)pNext->Scaleform::Render::RenderQueueItem::Interface::__vftable;
        pNext->pFill.pObject = 0;
      }
    }
    v6 -= v11;
    v7 += pNext->Meshes.Data.Size;
    goto LABEL_15;
  }
  if ( v6 >= Size )
  {
    v6 -= Size;
    p_RefCount = &pNext->RefCount;
    v10 = &pNext->Scaleform::RefCountBase<Scaleform::Render::Primitive,68>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,68>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable;
    pNext = (Scaleform::Render::Primitive *)pNext->RefCount;
    *(_DWORD *)(*v10 + 4) = pNext;
    **(_DWORD **)p_RefCount = *v10;
    if ( v10[4] )
    {
      *(_DWORD *)(v10[2] + 4) = v10[3];
      *(_DWORD *)v10[3] = v10[2];
      v10[4] = 0;
    }
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v10);
    v3 = index;
    goto LABEL_16;
  }
  pNext->Meshes.Data.Size -= v6;
  if ( pNext->Batches.Root.pPrev != (Scaleform::Render::PrimitiveBatch *)2 )
  {
    pNext->Batches.Root.pPrev = (Scaleform::Render::PrimitiveBatch *)3;
    if ( pNext->pFill.pObject )
    {
      pNext->Prepare = (Scaleform::Render::RenderQueueItem::QIPrepareResult (__thiscall *)(Scaleform::Render::RenderQueueItem::Interface *, Scaleform::Render::RenderQueueItem *, Scaleform::Render::RenderQueueProcessor *, bool))pNext->pHAL;
      pNext->pHAL->__vftable = (Scaleform::Render::HAL_vtbl *)pNext->Scaleform::Render::RenderQueueItem::Interface::__vftable;
      pNext->pFill.pObject = 0;
    }
  }
LABEL_22:
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::ComplexPrimitiveBundle::InstanceEntry,Scaleform::AllocatorLH<Scaleform::Render::ComplexPrimitiveBundle::InstanceEntry,2>,Scaleform::ArrayDefaultPolicy>>::RemoveMultipleAt(
    (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::ComplexPrimitiveBundle::InstanceEntry,Scaleform::AllocatorLH<Scaleform::Render::ComplexPrimitiveBundle::InstanceEntry,2>,Scaleform::ArrayDefaultPolicy> > *)&v4->Meshes,
    v3,
    count);
  if ( v3 < this->ModifyIndex )
    this->ModifyIndex = v3;
}
