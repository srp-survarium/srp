int __thiscall Scaleform::GFx::AS3::Instances::fl::Date::GetLocalTZA(Scaleform::GFx::AS3::Instances::fl::Date *this)
{
  int result; // eax
  DWORD TimeZoneInformation; // eax
  int Bias; // ecx
  _TIME_ZONE_INFORMATION tz; // [esp+0h] [ebp-ACh] BYREF

  result = this->LocalTZA;
  if ( this->UseDST )
  {
    TimeZoneInformation = GetTimeZoneInformation(&tz);
    Bias = tz.Bias;
    if ( TimeZoneInformation == 1 )
    {
      return -60000 * (tz.StandardBias + tz.Bias);
    }
    else
    {
      if ( TimeZoneInformation == 2 )
        Bias = tz.DaylightBias + tz.Bias;
      return -60000 * Bias;
    }
  }
  return result;
}
