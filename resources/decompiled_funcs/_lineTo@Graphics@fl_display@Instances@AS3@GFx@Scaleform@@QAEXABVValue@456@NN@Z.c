void __thiscall Scaleform::GFx::AS3::Instances::fl_display::Graphics::lineTo(
        Scaleform::GFx::AS3::Instances::fl_display::Graphics *this,
        const Scaleform::GFx::AS3::Value *result,
        long double x,
        long double y)
{
  float v5; // [esp+4h] [ebp-8h]
  float ya; // [esp+1Ch] [ebp+10h]
  float yb; // [esp+1Ch] [ebp+10h]

  ya = y * 20.0;
  v5 = ya;
  yb = 20.0 * x;
  Scaleform::GFx::DrawingContext::LineTo(this->pDrawing.pObject, yb, v5);
  Scaleform::GFx::DisplayObjectBase::InvalidateHitResult(this->pDispObj);
}
