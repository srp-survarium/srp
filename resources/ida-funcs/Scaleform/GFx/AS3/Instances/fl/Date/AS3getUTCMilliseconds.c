void __thiscall Scaleform::GFx::AS3::Instances::fl::Date::AS3getUTCMilliseconds(
        Scaleform::GFx::AS3::Instances::fl::Date *this,
        long double *result)
{
  double v2; // st7
  double TimeValue; // [esp+4h] [ebp-8h]

  TimeValue = this->TimeValue;
  if ( (HIDWORD(TimeValue) & 0x7FF00000) == 0x7FF00000
    && (unsigned int)&loc_FFFFF & HIDWORD(TimeValue) | LODWORD(TimeValue) )
  {
    *result = this->TimeValue;
  }
  else
  {
    v2 = fmod(this->TimeValue, 1000.0);
    if ( v2 < 0.0 )
      v2 = v2 + 1000.0;
    *result = v2;
  }
}
