void __thiscall Scaleform::GFx::AS2::AvmSprite::BeginFill(Scaleform::GFx::AS2::AvmSprite *this, unsigned int rgba)
{
  Scaleform::GFx::DrawingContext *v3; // edi

  v3 = this->pDispObj->GetDrawingContext(this->pDispObj);
  Scaleform::Render::JPEG::JPEGRwSource::TermSource((Scaleform::GFx::AS3::RefCountBaseGC<328> *)this->pDispObj);
  Scaleform::GFx::DisplayObjectBase::InvalidateHitResult(this->pDispObj);
  Scaleform::GFx::DrawingContext::AcquirePath(v3, 1);
  Scaleform::GFx::DrawingContext::BeginSolidFill(v3, rgba);
}
