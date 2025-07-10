void __thiscall Scaleform::GFx::DrawingContext::NewPath(Scaleform::GFx::DrawingContext *this, float x, float y)
{
  Scaleform::GFx::DrawingContext::PackedShape *pObject; // eax
  bool v5; // zf
  unsigned __int8 States; // al
  unsigned int FillStyle1; // [esp-8h] [ebp-1Ch]
  unsigned int StrokeStyle; // [esp-4h] [ebp-18h]
  Scaleform::Render::ShapeDataPackedEncoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> > v9; // [esp+Ch] [ebp-8h] BYREF

  Scaleform::GFx::DrawingContext::AcquirePath(this, this->States & 1);
  pObject = this->Shapes.pObject;
  v5 = (this->States & 1) == 0;
  v9.Multiplier = pObject->Multiplier;
  StrokeStyle = this->StrokeStyle;
  FillStyle1 = this->FillStyle1;
  v9.Encoder.Data = pObject->pContainer;
  if ( v5 )
    Scaleform::Render::ShapeDataPackedEncoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::StartPath(
      &v9,
      &this->PosInfo,
      Shape_NewPath,
      this->FillStyle0,
      FillStyle1,
      StrokeStyle,
      x,
      y);
  else
    Scaleform::Render::ShapeDataPackedEncoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::StartPath(
      &v9,
      &this->PosInfo,
      Shape_NewLayer,
      this->FillStyle0,
      FillStyle1,
      StrokeStyle,
      x,
      y);
  States = this->States;
  this->Ex = x;
  this->Ey = y;
  this->States = States & 0x76 | 0x88;
}
