void __thiscall Scaleform::GFx::AS2::BitmapFilterObject::SetAlpha(
        Scaleform::GFx::AS2::BitmapFilterObject *this,
        float a)
{
  Scaleform::GFx::AS2::BitmapFilterObject::writableFilterParams(this)->Colors[0].Channels.Alpha = (int)(a * 255.0);
}
