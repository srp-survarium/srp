void __thiscall Scaleform::GFx::DrawingContext::EndFill(Scaleform::GFx::DrawingContext *this)
{
  Scaleform::GFx::DrawingContext::FinishPath(this);
  this->StY = 1.1754944e-38;
  this->StX = 1.1754944e-38;
  this->FillStyle1 = 0;
  this->FillStyle0 = 0;
}
