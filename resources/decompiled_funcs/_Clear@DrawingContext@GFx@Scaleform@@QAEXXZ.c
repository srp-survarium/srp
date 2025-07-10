void __thiscall Scaleform::GFx::DrawingContext::Clear(Scaleform::GFx::DrawingContext *this)
{
  Scaleform::GFx::DrawingContext::PackedShape *v2; // eax
  Scaleform::MemoryHeap *pHeap; // edx
  Scaleform::GFx::DrawingContext::PackedShape *v4; // ebp
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::Render::TreeContainer *v6; // ebx
  unsigned int Size; // eax

  v2 = (Scaleform::GFx::DrawingContext::PackedShape *)this->pHeap->Alloc(this->pHeap, 68, 0);
  if ( v2 )
  {
    pHeap = this->pHeap;
    v2->__vftable = (Scaleform::GFx::DrawingContext::PackedShape_vtbl *)&Scaleform::RefCountImplCore::`vftable';
    v2->RefCount = 1;
    v2->pContainer = &v2->Container;
    v2->Decoder.OneOverMultiplier = 1.0;
    v2->Decoder.Decoder.Data = &v2->Container;
    v2->Multiplier = 1.0;
    v2->StartingPos = 0;
    v2->FillStyles.Data.Data = 0;
    v2->FillStyles.Data.Size = 0;
    v2->FillStyles.Data.Policy.Capacity = 0;
    v2->StrokeStyles.Data.Data = 0;
    v2->StrokeStyles.Data.Size = 0;
    v2->StrokeStyles.Data.Policy.Capacity = 0;
    v2->__vftable = (Scaleform::GFx::DrawingContext::PackedShape_vtbl *)&Scaleform::GFx::DrawingContext::PackedShape::`vftable';
    v2->Container.Data.Data = 0;
    v2->Container.Data.Size = 0;
    v2->Container.Data.Policy.Capacity = 0;
    v2->Container.Data.pHeap = pHeap;
    v4 = v2;
  }
  else
  {
    v4 = 0;
  }
  pObject = (Scaleform::RefCountVImpl *)this->Shapes.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->Shapes.pObject = v4;
  this->Ey = 0.0;
  this->States = 1;
  v6 = this->pTreeContainer.pObject;
  this->Ex = 0.0;
  this->StY = 1.1754944e-38;
  this->StrokeStyle = 0;
  this->StX = 1.1754944e-38;
  this->FillStyle1 = 0;
  this->FillStyle0 = 0;
  Size = Scaleform::Render::TreeContainer::GetSize(v6);
  Scaleform::Render::TreeContainer::Remove(v6, 0, Size);
  this->States |= 0x80u;
}
