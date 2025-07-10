void __thiscall Scaleform::GFx::AS2::AvmSprite::SetNoLine(Scaleform::GFx::AS2::AvmSprite *this)
{
  Scaleform::GFx::DrawingContext *v2; // edi
  Scaleform::GFx::DrawingContext *v3; // ebx

  v2 = this->pDispObj->GetDrawingContext(this->pDispObj);
  if ( !Scaleform::GFx::DrawingContext::NoLine(v2) )
  {
    v3 = this->pDispObj->GetDrawingContext(this->pDispObj);
    Scaleform::Render::JPEG::JPEGRwSource::TermSource((Scaleform::GFx::AS3::RefCountBaseGC<328> *)this->pDispObj);
    Scaleform::GFx::DisplayObjectBase::InvalidateHitResult(this->pDispObj);
    Scaleform::GFx::DrawingContext::AcquirePath(v3, 0);
    Scaleform::GFx::DrawingContext::SetNoLine(v2);
  }
}
