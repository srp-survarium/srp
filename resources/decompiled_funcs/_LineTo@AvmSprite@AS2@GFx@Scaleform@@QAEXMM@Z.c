void __thiscall Scaleform::GFx::AS2::AvmSprite::LineTo(Scaleform::GFx::AS2::AvmSprite *this, float x, float y)
{
  Scaleform::GFx::DrawingContext *v4; // eax
  float v5; // [esp+4h] [ebp-8h]
  float ya; // [esp+14h] [ebp+8h]
  float yb; // [esp+14h] [ebp+8h]

  v4 = this->pDispObj->GetDrawingContext(this->pDispObj);
  ya = y * 20.0;
  v5 = ya;
  yb = 20.0 * x;
  Scaleform::GFx::DrawingContext::LineTo(v4, yb, v5);
  Scaleform::GFx::DisplayObjectBase::InvalidateHitResult(this->pDispObj);
}
