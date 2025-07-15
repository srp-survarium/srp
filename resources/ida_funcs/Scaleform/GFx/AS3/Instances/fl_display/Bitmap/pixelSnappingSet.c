void __thiscall Scaleform::GFx::AS3::Instances::fl_display::Bitmap::pixelSnappingSet(
        Scaleform::GFx::AS3::Instances::fl_display::Bitmap *this,
        const Scaleform::GFx::AS3::Value *result,
        const Scaleform::GFx::ASString *value)
{
  Scaleform::GFx::AS3::Instances::fl_display::Bitmap::PixelSnappingType v4; // eax
  Scaleform::GFx::AS3::AvmBitmap *pObject; // ecx

  v4 = Scaleform::GFx::AS3::Instances::fl_display::Bitmap::String2PixelSnapping(this, value->pNode->pData);
  pObject = (Scaleform::GFx::AS3::AvmBitmap *)this->pDispObj.pObject;
  this->PixelSnapping = v4;
  if ( pObject )
    Scaleform::GFx::AS3::AvmBitmap::RecreateRenderNode(pObject);
}
