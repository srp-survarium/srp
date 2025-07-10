void __thiscall Scaleform::GFx::AS3::Instances::fl_display::Bitmap::smoothingSet(
        Scaleform::GFx::AS3::Instances::fl_display::Bitmap *this,
        const Scaleform::GFx::AS3::Value *result,
        bool value)
{
  Scaleform::GFx::AS3::AvmBitmap *pObject; // ecx

  this->Smoothing = value;
  pObject = (Scaleform::GFx::AS3::AvmBitmap *)this->pDispObj.pObject;
  if ( pObject )
    Scaleform::GFx::AS3::AvmBitmap::RecreateRenderNode(pObject);
}
