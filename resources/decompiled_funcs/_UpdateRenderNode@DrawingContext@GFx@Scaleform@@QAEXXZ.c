void __usercall Scaleform::GFx::DrawingContext::UpdateRenderNode(
        Scaleform::GFx::DrawingContext *this@<ecx>,
        int a2@<ebx>)
{
  Scaleform::GFx::DrawingContext::PackedShape *pObject; // ecx
  unsigned int StrokeStyle; // eax
  Scaleform::GFx::DrawingContext::PackedShape *v5; // ecx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *pContainer; // ecx
  Scaleform::Render::ShapeMeshProvider *v7; // eax
  Scaleform::Render::ContextImpl::EntryData_vtbl *v8; // eax
  Scaleform::Render::ContextImpl::EntryData_vtbl *v9; // ebx
  Scaleform::Render::TreeShape *v10; // ebp
  Scaleform::Render::TreeContainer *v11; // edi
  unsigned int Size; // eax
  Scaleform::GFx::DrawingContext::PackedShape *v13; // eax
  Scaleform::GFx::DrawingContext::PackedShape *v14; // eax
  Scaleform::GFx::DrawingContext::PackedShape *v15; // edi
  Scaleform::RefCountVImpl *v16; // ecx
  bool v17; // zf
  unsigned int v18; // eax
  unsigned int v19; // eax
  unsigned __int8 val; // [esp+Fh] [ebp-9h] BYREF
  unsigned int f0; // [esp+10h] [ebp-8h]
  unsigned int s; // [esp+14h] [ebp-4h]

  pObject = this->Shapes.pObject;
  this->States &= ~0x80u;
  if ( pObject && !pObject->IsEmpty(pObject) )
  {
    StrokeStyle = this->StrokeStyle;
    f0 = this->FillStyle0;
    v5 = this->Shapes.pObject;
    s = StrokeStyle;
    if ( v5 && !v5->IsEmpty(v5) )
    {
      this->States |= 0x80u;
      if ( (this->States & 0x10) != 0 )
        Scaleform::GFx::DrawingContext::FinishPath(this);
      if ( (this->States & 8) != 0 )
      {
        Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::EndPath(this->Shapes.pObject);
        this->States &= ~8u;
      }
      this->States |= 1u;
    }
    pContainer = this->Shapes.pObject->pContainer;
    val = 0;
    Scaleform::ArrayBase<Scaleform::ArrayDataDH<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
      pContainer,
      &val);
    v7 = (Scaleform::Render::ShapeMeshProvider *)((int (__thiscall *)(Scaleform::MemoryHeap *, int, _DWORD, int))this->pHeap->Alloc)(
                                                   this->pHeap,
                                                   96,
                                                   0,
                                                   a2);
    if ( v7 )
    {
      Scaleform::Render::ShapeMeshProvider::ShapeMeshProvider(v7, this->Shapes.pObject, 0);
      v9 = v8;
    }
    else
    {
      v9 = 0;
    }
    v10 = Scaleform::Render::ContextImpl::Context::CreateEntry<Scaleform::Render::TreeShape>(this->RenContext);
    Scaleform::Render::TreeShape::SetShape(v10, v9);
    v11 = this->pTreeContainer.pObject;
    Size = Scaleform::Render::TreeContainer::GetSize(v11);
    Scaleform::Render::TreeContainer::Insert(v11, Size, v10);
    v13 = (Scaleform::GFx::DrawingContext::PackedShape *)((int (__thiscall *)(Scaleform::MemoryHeap *, int))this->pHeap->Alloc)(
                                                           this->pHeap,
                                                           68);
    if ( v13 )
    {
      Scaleform::GFx::DrawingContext::PackedShape::PackedShape(v13, this->pHeap);
      v15 = v14;
    }
    else
    {
      v15 = 0;
    }
    v16 = (Scaleform::RefCountVImpl *)this->Shapes.pObject;
    if ( v16 )
      Scaleform::RefCountImpl::Release(v16);
    v17 = f0 == 0;
    this->Shapes.pObject = v15;
    if ( !v17 )
    {
      v18 = Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::AddFillStyle(
              v15,
              &this->mFillStyle);
      v17 = (this->States & 0x10) == 0;
      this->FillStyle0 = v18;
      if ( !v17 )
      {
        Scaleform::GFx::DrawingContext::FinishPath(this);
        this->StY = 1.1754944e-38;
        this->StX = 1.1754944e-38;
        this->FillStyle1 = 0;
        this->FillStyle0 = 0;
      }
      this->States |= 0x14u;
    }
    if ( s )
    {
      v19 = Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::AddStrokeStyle(
              this->Shapes.pObject,
              &this->mLineStyle);
      this->States |= 2u;
      this->StrokeStyle = v19;
    }
    if ( v10 )
    {
      v17 = v10->RefCount-- == 1;
      if ( v17 )
        Scaleform::Render::ContextImpl::Entry::destroyHelper(v10);
    }
    if ( v9 )
      (*((void (__thiscall **)(void (__thiscall **)(Scaleform::Render::ContextImpl::EntryData *, void *)))v9->CopyTo + 2))(&v9->CopyTo);
  }
}
