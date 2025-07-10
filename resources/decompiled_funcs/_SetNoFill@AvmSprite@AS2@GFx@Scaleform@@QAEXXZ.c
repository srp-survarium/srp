void __thiscall Scaleform::GFx::AS2::AvmSprite::SetNoFill(Scaleform::GFx::AS2::AvmSprite *this)
{
  Scaleform::GFx::DrawingContext *v2; // edi
  Scaleform::GFx::DrawingContext *v3; // ebx

  v2 = this->pDispObj->GetDrawingContext(this->pDispObj);
  v3 = this->pDispObj->GetDrawingContext(this->pDispObj);
  Scaleform::Render::JPEG::JPEGRwSource::TermSource((Scaleform::GFx::AS3::RefCountBaseGC<328> *)this->pDispObj);
  Scaleform::GFx::DisplayObjectBase::InvalidateHitResult(this->pDispObj);
  Scaleform::GFx::DrawingContext::AcquirePath(v3, 1);
  Scaleform::GFx::DrawingContext::SetNoFill(v2);
}
