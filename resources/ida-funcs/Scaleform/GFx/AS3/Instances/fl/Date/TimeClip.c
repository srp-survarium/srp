double __cdecl Scaleform::GFx::AS3::Instances::fl::Date::TimeClip(double time)
{
  if ( (HIDWORD(time) & 0x7FF00000) == 0x7FF00000 || fabs(time) > 8.64e15 )
    return Scaleform::GFx::NumberUtil::NaN();
  if ( time <= 0.0 )
    return ceil(time);
  return floor(time);
}
