void __thiscall Scaleform::GFx::AS3::Instances::fl_display::Graphics::moveTo(
        Scaleform::GFx::AS3::Instances::fl_display::Graphics *this,
        const Scaleform::GFx::AS3::Value *result,
        long double x,
        long double y)
{
  float v5; // [esp+4h] [ebp-8h]
  float ya; // [esp+1Ch] [ebp+10h]
  float yb; // [esp+1Ch] [ebp+10h]

  Scaleform::Render::JPEG::JPEGRwSource::TermSource((Scaleform::GFx::AS3::RefCountBaseGC<328> *)this->pDispObj);
  Scaleform::GFx::DisplayObjectBase::InvalidateHitResult(this->pDispObj);
  Scaleform::GFx::DrawingContext::AcquirePath(this->pDrawing.pObject, 0);
  ya = y * 20.0;
  v5 = ya;
  yb = 20.0 * x;
  Scaleform::GFx::DrawingContext::MoveTo(this->pDrawing.pObject, yb, v5);
  Scaleform::GFx::DisplayObjectBase::InvalidateHitResult(this->pDispObj);
}
