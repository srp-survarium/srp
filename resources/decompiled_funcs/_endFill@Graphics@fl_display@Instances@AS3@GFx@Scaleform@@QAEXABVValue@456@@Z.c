void __thiscall Scaleform::GFx::AS3::Instances::fl_display::Graphics::endFill(
        Scaleform::GFx::AS3::Instances::fl_display::Graphics *this,
        const Scaleform::GFx::AS3::Value *result)
{
  Scaleform::Render::JPEG::JPEGRwSource::TermSource((Scaleform::GFx::AS3::RefCountBaseGC<328> *)this->pDispObj);
  Scaleform::GFx::DisplayObjectBase::InvalidateHitResult(this->pDispObj);
  Scaleform::GFx::DrawingContext::AcquirePath(this->pDrawing.pObject, 1);
  Scaleform::GFx::DrawingContext::EndFill(this->pDrawing.pObject);
}
