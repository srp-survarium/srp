void __thiscall Scaleform::GFx::AS2::AvmSprite::LineTo(Scaleform::GFx::AS2::AvmSprite *this, float x, float y)
{
  Scaleform::GFx::DrawingContext *v4; // eax
  float ya; // [esp+4h] [ebp-8h]
  float v6; // [esp+14h] [ebp+8h]
  float v7; // [esp+14h] [ebp+8h]

  v4 = this->pDispObj->GetDrawingContext(this->pDispObj);
  v6 = y * 20.0;
  ya = v6;
  v7 = 20.0 * x;
  Scaleform::GFx::DrawingContext::LineTo(v4, v7, ya);
  Scaleform::GFx::DisplayObjectBase::InvalidateHitResult(this->pDispObj);
}
