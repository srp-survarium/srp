void __thiscall Scaleform::GFx::DrawingContext::LineTo(Scaleform::GFx::DrawingContext *this, float x, float y)
{
  Scaleform::GFx::DrawingContext::PackedShape *pObject; // eax
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *pContainer; // ecx
  unsigned __int8 States; // al
  Scaleform::Render::ShapeDataPackedEncoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> > v7; // [esp+Ch] [ebp-8h] BYREF

  if ( (this->States & 8) == 0 )
    Scaleform::GFx::DrawingContext::NewPath(this, this->Ex, this->Ey);
  pObject = this->Shapes.pObject;
  pContainer = pObject->pContainer;
  v7.Multiplier = pObject->Multiplier;
  v7.Encoder.Data = pContainer;
  Scaleform::Render::ShapeDataPackedEncoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::LineTo(
    &v7,
    &this->PosInfo,
    x,
    y);
  States = this->States;
  this->Ex = x;
  this->Ey = y;
  this->States = States & 0x7D | 0x80;
}
