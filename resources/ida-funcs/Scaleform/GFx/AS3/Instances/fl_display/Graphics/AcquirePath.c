void __thiscall Scaleform::GFx::AS3::Instances::fl_display::Graphics::AcquirePath(
        Scaleform::GFx::AS3::Instances::fl_display::Graphics *this,
        bool newShapeFlag)
{
  Scaleform::Render::JPEG::JPEGRwSource::TermSource((Scaleform::GFx::AS3::RefCountBaseGC<328> *)this->pDispObj);
  Scaleform::GFx::DisplayObjectBase::InvalidateHitResult(this->pDispObj);
  Scaleform::GFx::DrawingContext::AcquirePath(this->pDrawing.pObject, newShapeFlag);
}
