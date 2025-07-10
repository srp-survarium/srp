BOOL __thiscall Scaleform::GFx::DrawingContext::NoLine(Scaleform::GFx::DrawingContext *this)
{
  return !this->Shapes.pObject->GetStrokeStyleCount(this->Shapes.pObject) || !this->StrokeStyle;
}
