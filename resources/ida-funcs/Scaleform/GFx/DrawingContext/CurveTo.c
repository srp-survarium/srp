void __thiscall Scaleform::GFx::DrawingContext::CurveTo(
        Scaleform::GFx::DrawingContext *this,
        float cx,
        float cy,
        float ax,
        float ay)
{
  Scaleform::GFx::DrawingContext::PackedShape *pObject; // eax
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *pContainer; // ecx
  unsigned __int8 States; // al
  Scaleform::Render::ShapeDataPackedEncoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> > v9; // [esp+14h] [ebp-8h] BYREF

  if ( (this->States & 8) == 0 )
    Scaleform::GFx::DrawingContext::NewPath(this, this->Ex, this->Ey);
  pObject = this->Shapes.pObject;
  pContainer = pObject->pContainer;
  v9.Multiplier = pObject->Multiplier;
  v9.Encoder.Data = pContainer;
  Scaleform::Render::ShapeDataPackedEncoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::QuadTo(
    &v9,
    &this->PosInfo,
    cx,
    cy,
    ax,
    ay);
  States = this->States;
  this->Ex = ax;
  this->Ey = ay;
  this->States = States & 0x7D | 0x80;
}
