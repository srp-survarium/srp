void __thiscall Scaleform::GFx::AS3::Instances::fl_display::Graphics::clear(
        Scaleform::GFx::AS3::Instances::fl_display::Graphics *this,
        const Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::DrawingContext::Clear(this->pDrawing.pObject);
  Scaleform::GFx::DisplayObjectBase::InvalidateHitResult(this->pDispObj);
  Scaleform::Render::JPEG::JPEGRwSource::TermSource((Scaleform::GFx::AS3::RefCountBaseGC<328> *)this->pDispObj);
}
