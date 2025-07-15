void __thiscall Scaleform::Render::Primitive::~Primitive(Scaleform::Render::Primitive *this)
{
  Scaleform::List<Scaleform::Render::PrimitiveBatch,Scaleform::Render::PrimitiveBatch> *p_Batches; // edi
  Scaleform::Render::PrimitiveBatch *pNext; // eax
  Scaleform::Render::PrimitiveFill *pObject; // ecx

  --Primitive_Total;
  p_Batches = &this->Batches;
  this->Scaleform::RefCountBase<Scaleform::Render::Primitive,68>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,68>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable = (Scaleform::Render::Primitive_vtbl *)&Scaleform::Render::Primitive::`vftable'{for `Scaleform::RefCountBase<Scaleform::Render::Primitive,68>'};
  this->Scaleform::Render::RenderQueueItem::Interface::__vftable = (Scaleform::Render::RenderQueueItem::Interface_vtbl *)&Scaleform::Render::Primitive::`vftable'{for `Scaleform::Render::RenderQueueItem::Interface'};
  if ( (Scaleform::List<Scaleform::Render::PrimitiveBatch,Scaleform::Render::PrimitiveBatch> *)this->Batches.Root.pNext != &this->Batches )
  {
    do
    {
      pNext = this->Batches.Root.pNext;
      pNext->pPrev->pNext = pNext->pNext;
      pNext->pNext->Scaleform::ListNode<Scaleform::Render::PrimitiveBatch>::$C512BB809886916B7F681A9EBDF58E11::pPrev = pNext->pPrev;
      if ( pNext->MeshNode.pMeshItem )
      {
        pNext->MeshNode.pPrev->pNext = pNext->MeshNode.pNext;
        pNext->MeshNode.pNext->pPrev = pNext->MeshNode.pPrev;
        pNext->MeshNode.pMeshItem = 0;
      }
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pNext);
    }
    while ( (Scaleform::List<Scaleform::Render::PrimitiveBatch,Scaleform::Render::PrimitiveBatch> *)p_Batches->Root.pNext != p_Batches );
  }
  Scaleform::ConstructorMov<Scaleform::Render::ComplexPrimitiveBundle::InstanceEntry>::DestructArray(
    (Scaleform::Render::ComplexPrimitiveBundle::InstanceEntry *)this->Meshes.Data.Data,
    this->Meshes.Data.Size);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Meshes.Data.Data);
  pObject = this->pFill.pObject;
  if ( pObject )
    Scaleform::RefCountNTSImpl::Release(pObject);
  this->Scaleform::Render::RenderQueueItem::Interface::__vftable = (Scaleform::Render::RenderQueueItem::Interface_vtbl *)&Scaleform::Render::RenderQueueItem::Interface::`vftable';
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}
