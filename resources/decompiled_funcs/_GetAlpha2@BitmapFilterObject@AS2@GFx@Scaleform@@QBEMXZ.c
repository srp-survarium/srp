double __thiscall Scaleform::GFx::AS2::BitmapFilterObject::GetAlpha2(Scaleform::GFx::AS2::BitmapFilterObject *this)
{
  unsigned __int8 Alpha; // al

  Alpha = Scaleform::GFx::AS2::BitmapFilterObject::readonlyFilterParams(this)->Colors[1].Channels.Alpha;
  if ( !Alpha )
    return (float)0.0;
  return (float)((double)Alpha / 255.0);
}
