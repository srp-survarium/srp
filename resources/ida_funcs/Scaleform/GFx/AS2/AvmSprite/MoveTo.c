void __thiscall Scaleform::GFx::AS2::AvmSprite::MoveTo(Scaleform::GFx::AS2::AvmSprite *this, float x, float y)
{
  Scaleform::GFx::DrawingContext *v4; // edi
  float v5; // [esp+4h] [ebp-Ch]
  float ya; // [esp+18h] [ebp+8h]
  float yb; // [esp+18h] [ebp+8h]

  v4 = this->pDispObj->GetDrawingContext(this->pDispObj);
  Scaleform::Render::JPEG::JPEGRwSource::TermSource((Scaleform::GFx::AS3::RefCountBaseGC<328> *)this->pDispObj);
  Scaleform::GFx::DisplayObjectBase::InvalidateHitResult(this->pDispObj);
  Scaleform::GFx::DrawingContext::AcquirePath(v4, 0);
  ya = y * 20.0;
  v5 = ya;
  yb = 20.0 * x;
  Scaleform::GFx::DrawingContext::MoveTo(v4, yb, v5);
  Scaleform::GFx::DisplayObjectBase::InvalidateHitResult(this->pDispObj);
}
