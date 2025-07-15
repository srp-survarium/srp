void __thiscall Scaleform::GFx::AS3::Instances::fl_display::Graphics::drawEllipse(
        Scaleform::GFx::AS3::Instances::fl_display::Graphics *this,
        const Scaleform::GFx::AS3::Value *result,
        long double x,
        long double y,
        long double width,
        long double height)
{
  float fxradius; // [esp+14h] [ebp-44h]
  float fyradius; // [esp+18h] [ebp-40h]
  float ay; // [esp+1Ch] [ebp-3Ch]
  float v10; // [esp+20h] [ebp-38h]
  float v11; // [esp+20h] [ebp-38h]
  float v12; // [esp+20h] [ebp-38h]
  float cy; // [esp+24h] [ebp-34h]
  float v14; // [esp+24h] [ebp-34h]
  float v15; // [esp+24h] [ebp-34h]
  float v16; // [esp+28h] [ebp-30h]
  float v17; // [esp+2Ch] [ebp-2Ch]
  double v18; // [esp+30h] [ebp-28h]
  float v19; // [esp+38h] [ebp-20h]
  float v20; // [esp+3Ch] [ebp-1Ch]
  float v21; // [esp+3Ch] [ebp-1Ch]
  float v22; // [esp+3Ch] [ebp-1Ch]
  float v23; // [esp+3Ch] [ebp-1Ch]
  float v24; // [esp+3Ch] [ebp-1Ch]
  float v25; // [esp+3Ch] [ebp-1Ch]
  double v26; // [esp+40h] [ebp-18h]
  double v27; // [esp+48h] [ebp-10h]
  double v28; // [esp+50h] [ebp-8h]
  float xa; // [esp+60h] [ebp+8h]
  float ya; // [esp+68h] [ebp+10h]
  float yb; // [esp+68h] [ebp+10h]
  float fx; // [esp+70h] [ebp+18h]
  float fxa; // [esp+70h] [ebp+18h]
  float fxb; // [esp+70h] [ebp+18h]
  float fxc; // [esp+70h] [ebp+18h]
  float fxd; // [esp+70h] [ebp+18h]
  float fxe; // [esp+70h] [ebp+18h]
  float fxf; // [esp+70h] [ebp+18h]
  float fxg; // [esp+70h] [ebp+18h]
  float fy; // [esp+78h] [ebp+20h]
  float fya; // [esp+78h] [ebp+20h]

  fx = width;
  fxradius = fx * 0.5;
  fxa = height;
  fyradius = 0.5 * fxa;
  fxb = x;
  fxc = fxb + fxradius;
  fy = y;
  fya = fy + fyradius;
  xa = fya * 20.0;
  ya = fxradius + fxc;
  yb = 20.0 * ya;
  Scaleform::GFx::DrawingContext::MoveTo(this->pDrawing.pObject, yb, xa);
  v27 = fyradius * 0.7071067690849304;
  v20 = v27 + fya;
  ay = v20 * 20.0;
  v18 = 0.7071067690849304 * fxradius;
  v21 = v18 + fxc;
  v19 = v21 * 20.0;
  v28 = fyradius * 0.4142135679721832;
  v22 = fya + v28;
  cy = 20.0 * v22;
  Scaleform::GFx::DrawingContext::CurveTo(this->pDrawing.pObject, yb, cy, v19, ay);
  v23 = fyradius + fya;
  v10 = v23 * 20.0;
  v17 = fxc * 20.0;
  v26 = fxradius * 0.4142135679721832;
  v24 = fxc + v26;
  v25 = 20.0 * v24;
  Scaleform::GFx::DrawingContext::CurveTo(this->pDrawing.pObject, v25, v10, v17, v10);
  *(float *)&v18 = fxc - v18;
  v16 = *(float *)&v18 * 20.0;
  *(float *)&v18 = fxc - v26;
  *(float *)&v18 = 20.0 * *(float *)&v18;
  Scaleform::GFx::DrawingContext::CurveTo(this->pDrawing.pObject, *(float *)&v18, v10, v16, ay);
  fxd = fxc - fxradius;
  fxe = fxd * 20.0;
  Scaleform::GFx::DrawingContext::CurveTo(this->pDrawing.pObject, fxe, cy, fxe, xa);
  v14 = fya - v27;
  v15 = v14 * 20.0;
  v11 = fya - v28;
  v12 = 20.0 * v11;
  Scaleform::GFx::DrawingContext::CurveTo(this->pDrawing.pObject, fxe, v12, v16, v15);
  fxf = fya - fyradius;
  fxg = fxf * 20.0;
  Scaleform::GFx::DrawingContext::CurveTo(this->pDrawing.pObject, *(float *)&v18, fxg, v17, fxg);
  Scaleform::GFx::DrawingContext::CurveTo(this->pDrawing.pObject, v25, fxg, v19, v15);
  Scaleform::GFx::DrawingContext::CurveTo(this->pDrawing.pObject, yb, v12, yb, xa);
  Scaleform::GFx::DisplayObjectBase::InvalidateHitResult(this->pDispObj);
}
