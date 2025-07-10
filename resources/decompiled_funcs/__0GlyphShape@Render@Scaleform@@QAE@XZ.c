void __thiscall Scaleform::Render::GlyphShape::GlyphShape(Scaleform::Render::GlyphShape *this)
{
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *p_Data; // ecx

  this->__vftable = (Scaleform::Render::GlyphShape_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  p_Data = &this->Data;
  this->pContainer = p_Data;
  this->Decoder.OneOverMultiplier = 1.0;
  this->Decoder.Decoder.Scaleform::Render::ShapeDataPacked<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> >::Data = p_Data;
  this->Multiplier = 1.0;
  this->StartingPos = 0;
  this->FillStyles.Scaleform::Render::ShapeDataPacked<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> >::Data.Scaleform::Render::ShapeDataPacked<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> >::Data = 0;
  this->FillStyles.Scaleform::Render::ShapeDataPacked<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> >::Data.Size = 0;
  this->FillStyles.Scaleform::Render::ShapeDataPacked<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> >::Data.Policy.Capacity = 0;
  this->StrokeStyles.Scaleform::Render::ShapeDataPacked<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> >::Data.Scaleform::Render::ShapeDataPacked<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> >::Data = 0;
  this->StrokeStyles.Scaleform::Render::ShapeDataPacked<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> >::Data.Size = 0;
  this->StrokeStyles.Scaleform::Render::ShapeDataPacked<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> >::Data.Policy.Capacity = 0;
  this->__vftable = (Scaleform::Render::GlyphShape_vtbl *)&Scaleform::Render::GlyphShape::`vftable';
  p_Data->Data.Data = 0;
  p_Data->Data.Size = 0;
  p_Data->Data.Policy.Capacity = 0;
  this->HintedSize = 0;
  this->Bounds.x1 = 0.0;
  this->Bounds.y1 = 0.0;
  this->Bounds.x2 = 0.0;
  this->Bounds.y2 = 0.0;
}
