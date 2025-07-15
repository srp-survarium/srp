void __thiscall Scaleform::GFx::AS2::AvmSprite::CurveTo(
        Scaleform::GFx::AS2::AvmSprite *this,
        float cx,
        float cy,
        float ax,
        float ay)
{
  Scaleform::GFx::DrawingContext *v6; // eax
  float cya; // [esp+4h] [ebp-10h]
  float v8; // [esp+8h] [ebp-Ch]
  float aya; // [esp+Ch] [ebp-8h]
  float v10; // [esp+24h] [ebp+10h]
  float v11; // [esp+24h] [ebp+10h]
  float v12; // [esp+24h] [ebp+10h]
  float v13; // [esp+24h] [ebp+10h]

  v6 = this->pDispObj->GetDrawingContext(this->pDispObj);
  v10 = ay * 20.0;
  aya = v10;
  v11 = ax * 20.0;
  v8 = v11;
  v12 = cy * 20.0;
  cya = v12;
  v13 = 20.0 * cx;
  Scaleform::GFx::DrawingContext::CurveTo(v6, v13, cya, v8, aya);
  Scaleform::GFx::DisplayObjectBase::InvalidateHitResult(this->pDispObj);
}
