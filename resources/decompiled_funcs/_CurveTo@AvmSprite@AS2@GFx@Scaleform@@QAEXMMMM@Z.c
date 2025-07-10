void __thiscall Scaleform::GFx::AS2::AvmSprite::CurveTo(
        Scaleform::GFx::AS2::AvmSprite *this,
        float cx,
        float cy,
        float ax,
        float ay)
{
  Scaleform::GFx::DrawingContext *v6; // eax
  float v7; // [esp+4h] [ebp-10h]
  float v8; // [esp+8h] [ebp-Ch]
  float v9; // [esp+Ch] [ebp-8h]
  float aya; // [esp+24h] [ebp+10h]
  float ayb; // [esp+24h] [ebp+10h]
  float ayc; // [esp+24h] [ebp+10h]
  float ayd; // [esp+24h] [ebp+10h]

  v6 = this->pDispObj->GetDrawingContext(this->pDispObj);
  aya = ay * 20.0;
  v9 = aya;
  ayb = ax * 20.0;
  v8 = ayb;
  ayc = cy * 20.0;
  v7 = ayc;
  ayd = 20.0 * cx;
  Scaleform::GFx::DrawingContext::CurveTo(v6, ayd, v7, v8, v9);
  Scaleform::GFx::DisplayObjectBase::InvalidateHitResult(this->pDispObj);
}
