void __thiscall Scaleform::GFx::AS2::AvmSprite::BeginBitmapFill(
        Scaleform::GFx::AS2::AvmSprite *this,
        Scaleform::GFx::FillType fillType,
        Scaleform::GFx::ImageResource *pimageRes,
        const Scaleform::Render::Matrix2x4<float> *mtx)
{
  Scaleform::GFx::DrawingContext *v5; // edi

  v5 = this->pDispObj->GetDrawingContext(this->pDispObj);
  Scaleform::Render::JPEG::JPEGRwSource::TermSource((Scaleform::GFx::AS3::RefCountBaseGC<328> *)this->pDispObj);
  Scaleform::GFx::DisplayObjectBase::InvalidateHitResult(this->pDispObj);
  Scaleform::GFx::DrawingContext::AcquirePath(v5, 1);
  Scaleform::GFx::DrawingContext::BeginBitmapFill(v5, fillType, pimageRes, mtx);
}
