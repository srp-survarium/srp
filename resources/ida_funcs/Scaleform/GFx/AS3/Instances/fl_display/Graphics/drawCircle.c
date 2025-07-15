void __thiscall Scaleform::GFx::AS3::Instances::fl_display::Graphics::drawCircle(
        Scaleform::GFx::AS3::Instances::fl_display::Graphics *this,
        const Scaleform::GFx::AS3::Value *result,
        long double x,
        long double y,
        long double radius)
{
  float v6; // [esp+14h] [ebp-38h]
  float v7; // [esp+18h] [ebp-34h]
  float v8; // [esp+1Ch] [ebp-30h]
  float v9; // [esp+20h] [ebp-2Ch]
  float v10; // [esp+20h] [ebp-2Ch]
  float v11; // [esp+20h] [ebp-2Ch]
  float cy; // [esp+24h] [ebp-28h]
  float v13; // [esp+24h] [ebp-28h]
  float v14; // [esp+24h] [ebp-28h]
  float v15; // [esp+28h] [ebp-24h]
  float v16; // [esp+2Ch] [ebp-20h]
  float v17; // [esp+30h] [ebp-1Ch]
  float v18; // [esp+30h] [ebp-1Ch]
  float v19; // [esp+30h] [ebp-1Ch]
  float v20; // [esp+34h] [ebp-18h]
  float v21; // [esp+38h] [ebp-14h]
  float v22; // [esp+38h] [ebp-14h]
  float v23; // [esp+38h] [ebp-14h]
  float v24; // [esp+38h] [ebp-14h]
  float v25; // [esp+38h] [ebp-14h]
  float v26; // [esp+38h] [ebp-14h]
  float v27; // [esp+38h] [ebp-14h]
  double v28; // [esp+3Ch] [ebp-10h]
  double v29; // [esp+44h] [ebp-8h]
  float fx; // [esp+54h] [ebp+8h]
  float fxa; // [esp+54h] [ebp+8h]
  float fxb; // [esp+54h] [ebp+8h]
  float fxc; // [esp+54h] [ebp+8h]
  float fxd; // [esp+54h] [ebp+8h]
  float fy; // [esp+5Ch] [ebp+10h]
  float fradius; // [esp+64h] [ebp+18h]

  fx = x;
  fy = y;
  fradius = radius;
  v6 = fy * 20.0;
  v21 = fradius + fx;
  v7 = 20.0 * v21;
  Scaleform::GFx::DrawingContext::MoveTo(this->pDrawing.pObject, v7, v6);
  v29 = 0.7071067690849304 * fradius;
  v22 = fy + v29;
  v8 = v22 * 20.0;
  v23 = v29 + fx;
  v20 = v23 * 20.0;
  v28 = fradius * 0.4142135679721832;
  v24 = fy + v28;
  cy = 20.0 * v24;
  Scaleform::GFx::DrawingContext::CurveTo(this->pDrawing.pObject, v7, cy, v20, v8);
  v25 = fradius + fy;
  v9 = v25 * 20.0;
  v16 = fx * 20.0;
  v26 = fx + v28;
  v27 = 20.0 * v26;
  Scaleform::GFx::DrawingContext::CurveTo(this->pDrawing.pObject, v27, v9, v16, v9);
  v17 = fx - v29;
  v15 = v17 * 20.0;
  v18 = fx - v28;
  v19 = 20.0 * v18;
  Scaleform::GFx::DrawingContext::CurveTo(this->pDrawing.pObject, v19, v9, v15, v8);
  fxa = fx - fradius;
  fxb = fxa * 20.0;
  Scaleform::GFx::DrawingContext::CurveTo(this->pDrawing.pObject, fxb, cy, fxb, v6);
  v13 = fy - v29;
  v14 = v13 * 20.0;
  v10 = fy - v28;
  v11 = 20.0 * v10;
  Scaleform::GFx::DrawingContext::CurveTo(this->pDrawing.pObject, fxb, v11, v15, v14);
  fxc = fy - fradius;
  fxd = fxc * 20.0;
  Scaleform::GFx::DrawingContext::CurveTo(this->pDrawing.pObject, v19, fxd, v16, fxd);
  Scaleform::GFx::DrawingContext::CurveTo(this->pDrawing.pObject, v27, fxd, v20, v14);
  Scaleform::GFx::DrawingContext::CurveTo(this->pDrawing.pObject, v7, v11, v7, v6);
  Scaleform::GFx::DisplayObjectBase::InvalidateHitResult(this->pDispObj);
}
