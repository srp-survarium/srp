void __thiscall Scaleform::GFx::AS2::BitmapFilterObject::SetAlpha2(
        Scaleform::GFx::AS2::BitmapFilterObject *this,
        float a)
{
  Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams(this)->Colors[1].Channels.Alpha = (int)(a * 255.0);
}
