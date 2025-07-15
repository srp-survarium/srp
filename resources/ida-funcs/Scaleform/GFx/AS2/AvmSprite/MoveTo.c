void __thiscall Scaleform::GFx::AS2::AvmSprite::MoveTo(Scaleform::GFx::AS2::AvmSprite *this, float x, float y)
{
  Scaleform::GFx::DrawingContext *v4; // edi
  float ya; // [esp+4h] [ebp-Ch]
  float v6; // [esp+18h] [ebp+8h]
  float v7; // [esp+18h] [ebp+8h]

  v4 = this->pDispObj->GetDrawingContext(this->pDispObj);
  Scaleform::Render::JPEG::JPEGRwSource::TermSource((Scaleform::GFx::AS3::RefCountBaseGC<328> *)this->pDispObj);
  Scaleform::GFx::DisplayObjectBase::InvalidateHitResult(this->pDispObj);
  Scaleform::GFx::DrawingContext::AcquirePath(v4, 0);
  v6 = y * 20.0;
  ya = v6;
  v7 = 20.0 * x;
  Scaleform::GFx::DrawingContext::MoveTo(v4, v7, ya);
  Scaleform::GFx::DisplayObjectBase::InvalidateHitResult(this->pDispObj);
}
