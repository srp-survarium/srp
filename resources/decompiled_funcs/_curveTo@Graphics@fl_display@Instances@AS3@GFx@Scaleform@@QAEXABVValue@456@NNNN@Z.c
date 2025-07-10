void __thiscall Scaleform::GFx::AS3::Instances::fl_display::Graphics::curveTo(
        Scaleform::GFx::AS3::Instances::fl_display::Graphics *this,
        const Scaleform::GFx::AS3::Value *result,
        long double controlX,
        long double controlY,
        long double anchorX,
        long double anchorY)
{
  float cy; // [esp+4h] [ebp-10h]
  float v8; // [esp+8h] [ebp-Ch]
  float ay; // [esp+Ch] [ebp-8h]
  float anchorYa; // [esp+34h] [ebp+20h]
  float anchorYb; // [esp+34h] [ebp+20h]
  float anchorYc; // [esp+34h] [ebp+20h]
  float anchorYd; // [esp+34h] [ebp+20h]
  float anchorYe; // [esp+34h] [ebp+20h]
  float anchorYf; // [esp+34h] [ebp+20h]
  float anchorYg; // [esp+34h] [ebp+20h]
  float anchorYh; // [esp+34h] [ebp+20h]

  anchorYa = anchorY;
  anchorYb = anchorYa * 20.0;
  ay = anchorYb;
  anchorYc = anchorX;
  anchorYd = anchorYc * 20.0;
  v8 = anchorYd;
  anchorYe = controlY;
  anchorYf = anchorYe * 20.0;
  cy = anchorYf;
  anchorYg = controlX;
  anchorYh = 20.0 * anchorYg;
  Scaleform::GFx::DrawingContext::CurveTo(this->pDrawing.pObject, anchorYh, cy, v8, ay);
  Scaleform::GFx::DisplayObjectBase::InvalidateHitResult(this->pDispObj);
}
