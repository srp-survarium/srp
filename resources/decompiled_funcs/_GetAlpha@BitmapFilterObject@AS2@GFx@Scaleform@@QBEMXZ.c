double __thiscall Scaleform::GFx::AS2::BitmapFilterObject::GetAlpha(Scaleform::GFx::AS2::BitmapFilterObject *this)
{
  unsigned __int8 Alpha; // al

  Alpha = Scaleform::GFx::AS2::BitmapFilterObject::readonlyFilterParams(this)->Colors[0].Channels.Alpha;
  if ( !Alpha )
    return (float)0.0;
  return (float)((double)Alpha / 255.0);
}
