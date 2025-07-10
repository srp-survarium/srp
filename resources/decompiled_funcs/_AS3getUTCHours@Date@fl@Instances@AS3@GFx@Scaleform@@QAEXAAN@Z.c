void __thiscall Scaleform::GFx::AS3::Instances::fl::Date::AS3getUTCHours(
        Scaleform::GFx::AS3::Instances::fl::Date *this,
        long double *result)
{
  double v2; // st7
  double TimeValue; // [esp+8h] [ebp-8h]

  TimeValue = this->TimeValue;
  if ( (HIDWORD(TimeValue) & 0x7FF00000) == 0x7FF00000
    && (unsigned int)&loc_FFFFF & HIDWORD(TimeValue) | LODWORD(TimeValue) )
  {
    *result = this->TimeValue;
  }
  else
  {
    v2 = fmod(floor(this->TimeValue / 3600000.0), 24.0);
    if ( v2 < 0.0 )
      v2 = v2 + 24.0;
    *result = v2;
  }
}
