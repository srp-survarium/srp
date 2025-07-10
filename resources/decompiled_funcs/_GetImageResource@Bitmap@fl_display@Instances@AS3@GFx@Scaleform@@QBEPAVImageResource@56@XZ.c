Scaleform::GFx::ImageResource *__thiscall Scaleform::GFx::AS3::Instances::fl_display::Bitmap::GetImageResource(
        Scaleform::GFx::AS3::Instances::fl_display::Bitmap *this)
{
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *pObject; // ecx

  pObject = this->pBitmapData.pObject;
  if ( pObject )
    return Scaleform::GFx::AS3::Instances::fl_display::BitmapData::GetImageResource(pObject);
  else
    return 0;
}
