void __thiscall Scaleform::GFx::AS3::Instances::fl_display::Bitmap::bitmapDataSet(
        Scaleform::GFx::AS3::Instances::fl_display::Bitmap *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *value)
{
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::BitmapData> *p_pBitmapData; // edi
  Scaleform::GFx::AS3::AvmBitmap *pObject; // ecx
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *v6; // edi
  Scaleform::GFx::AS3::AvmBitmap *v7; // ecx

  p_pBitmapData = &this->pBitmapData;
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&this->pBitmapData,
    (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)value);
  pObject = (Scaleform::GFx::AS3::AvmBitmap *)this->pDispObj.pObject;
  if ( pObject )
  {
    v6 = p_pBitmapData->pObject;
    if ( v6 )
      Scaleform::GFx::AS3::AvmBitmap::SetResourceMovieDef(pObject, v6->pDefImpl.pObject);
    else
      Scaleform::GFx::AS3::AvmBitmap::SetResourceMovieDef(pObject, 0);
  }
  v7 = (Scaleform::GFx::AS3::AvmBitmap *)this->pDispObj.pObject;
  if ( v7 )
    Scaleform::GFx::AS3::AvmBitmap::RecreateRenderNode(v7);
}
