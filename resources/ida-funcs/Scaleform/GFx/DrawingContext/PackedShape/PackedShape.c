void __thiscall Scaleform::GFx::DrawingContext::PackedShape::PackedShape(
        Scaleform::GFx::DrawingContext::PackedShape *this,
        Scaleform::MemoryHeap *pHeap)
{
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *p_Container; // ecx

  this->__vftable = (Scaleform::GFx::DrawingContext::PackedShape_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  p_Container = &this->Container;
  this->pContainer = p_Container;
  this->Decoder.OneOverMultiplier = 1.0;
  this->Decoder.Decoder.Data = p_Container;
  this->Multiplier = 1.0;
  this->StartingPos = 0;
  this->FillStyles.Data.Data = 0;
  this->FillStyles.Data.Size = 0;
  this->FillStyles.Data.Policy.Capacity = 0;
  this->StrokeStyles.Data.Data = 0;
  this->StrokeStyles.Data.Size = 0;
  this->StrokeStyles.Data.Policy.Capacity = 0;
  this->__vftable = (Scaleform::GFx::DrawingContext::PackedShape_vtbl *)&Scaleform::GFx::DrawingContext::PackedShape::`vftable';
  p_Container->Data.Data = 0;
  p_Container->Data.Size = 0;
  p_Container->Data.Policy.Capacity = 0;
  p_Container->Data.pHeap = pHeap;
}
