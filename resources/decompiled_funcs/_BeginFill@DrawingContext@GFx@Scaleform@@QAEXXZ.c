void __thiscall Scaleform::GFx::DrawingContext::BeginFill(Scaleform::GFx::DrawingContext *this)
{
  if ( (this->States & 0x10) != 0 )
  {
    Scaleform::GFx::DrawingContext::FinishPath(this);
    this->StY = 1.1754944e-38;
    this->StX = 1.1754944e-38;
    this->FillStyle1 = 0;
    this->FillStyle0 = 0;
  }
  this->States |= 0x14u;
}
