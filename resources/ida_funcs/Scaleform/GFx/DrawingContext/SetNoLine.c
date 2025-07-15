void __thiscall Scaleform::GFx::DrawingContext::SetNoLine(Scaleform::GFx::DrawingContext *this)
{
  this->States &= ~2u;
  this->StrokeStyle = 0;
}
