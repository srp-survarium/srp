void __thiscall Scaleform::GFx::AS3::Instances::fl_display::Bitmap::SetBitmapData(
        Scaleform::GFx::AS3::Instances::fl_display::Bitmap *this,
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *b)
{
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::BitmapData> *p_pBitmapData; // edi
  Scaleform::GFx::AS3::AvmBitmap *pObject; // ecx
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *v5; // edi
  Scaleform::GFx::AS3::AvmBitmap *v6; // ecx
  Scaleform::GFx::AS3::Value r; // [esp+8h] [ebp-10h]

  p_pBitmapData = &this->pBitmapData;
  r.Flags = 0;
  r.Bonus.pWeakProxy = 0;
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&this->pBitmapData,
    (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)b);
  pObject = (Scaleform::GFx::AS3::AvmBitmap *)this->pDispObj.pObject;
  if ( pObject )
  {
    v5 = p_pBitmapData->pObject;
    if ( v5 )
      Scaleform::GFx::AS3::AvmBitmap::SetResourceMovieDef(pObject, v5->pDefImpl.pObject);
    else
      Scaleform::GFx::AS3::AvmBitmap::SetResourceMovieDef(pObject, 0);
  }
  v6 = (Scaleform::GFx::AS3::AvmBitmap *)this->pDispObj.pObject;
  if ( v6 )
    Scaleform::GFx::AS3::AvmBitmap::RecreateRenderNode(v6);
}
