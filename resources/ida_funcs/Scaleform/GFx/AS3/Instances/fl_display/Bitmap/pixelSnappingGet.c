void __thiscall Scaleform::GFx::AS3::Instances::fl_display::Bitmap::pixelSnappingGet(
        Scaleform::GFx::AS3::Instances::fl_display::Bitmap *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::AS3::Instances::fl_display::Bitmap::PixelSnappingType PixelSnapping; // eax
  __int32 v3; // eax

  PixelSnapping = this->PixelSnapping;
  if ( PixelSnapping )
  {
    v3 = PixelSnapping - 1;
    if ( v3 )
    {
      if ( v3 == 1 )
        Scaleform::GFx::ASString::operator=(result, "auto");
    }
    else
    {
      Scaleform::GFx::ASString::operator=(result, "always");
    }
  }
  else
  {
    Scaleform::GFx::ASString::operator=(result, "never");
  }
}
