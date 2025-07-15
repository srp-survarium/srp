void __thiscall Scaleform::Render::ShapeDataFloat::ShapeDataFloat(Scaleform::Render::ShapeDataFloat *this)
{
  Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> *p_Container; // ecx

  this->__vftable = (Scaleform::Render::ShapeDataFloat_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->Status = Status_Clean;
  this->Fills.Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> >::Data.Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> >::Data = 0;
  this->Fills.Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> >::Data.Size = 0;
  this->Fills.Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> >::Data.Policy.Capacity = 0;
  this->Strokes.Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> >::Data.Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> >::Data = 0;
  this->Strokes.Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> >::Data.Size = 0;
  this->Strokes.Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> >::Data.Policy.Capacity = 0;
  this->StartX = 0.0;
  this->StartY = 0.0;
  p_Container = &this->Container;
  this->LastX = 0.0;
  this->Data = p_Container;
  this->LastY = 0.0;
  this->StartingPos = 0;
  this->__vftable = (Scaleform::Render::ShapeDataFloat_vtbl *)&Scaleform::Render::ShapeDataFloat::`vftable';
  p_Container->Data.Data = 0;
  p_Container->Data.Size = 0;
  p_Container->Data.Policy.Capacity = 0;
}
