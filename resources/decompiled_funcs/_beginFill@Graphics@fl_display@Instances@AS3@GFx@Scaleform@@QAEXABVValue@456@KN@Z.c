void __thiscall Scaleform::GFx::AS3::Instances::fl_display::Graphics::beginFill(
        Scaleform::GFx::AS3::Instances::fl_display::Graphics *this,
        const Scaleform::GFx::AS3::Value *result,
        unsigned int color,
        long double alpha)
{
  Scaleform::Render::JPEG::JPEGRwSource::TermSource((Scaleform::GFx::AS3::RefCountBaseGC<328> *)this->pDispObj);
  Scaleform::GFx::DisplayObjectBase::InvalidateHitResult(this->pDispObj);
  Scaleform::GFx::DrawingContext::AcquirePath(this->pDrawing.pObject, 1);
  Scaleform::GFx::DrawingContext::BeginSolidFill(
    this->pDrawing.pObject,
    color | ((unsigned int)(__int64)(alpha * 255.0) << 24));
}
