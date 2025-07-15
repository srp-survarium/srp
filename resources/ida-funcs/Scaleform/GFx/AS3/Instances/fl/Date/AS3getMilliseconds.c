void __thiscall Scaleform::GFx::AS3::Instances::fl::Date::AS3getMilliseconds(
        Scaleform::GFx::AS3::Instances::fl::Date *this,
        long double *result)
{
  double v2; // st7
  double TimeValue; // [esp+4h] [ebp-8h]

  TimeValue = this->TimeValue;
  if ( (HIDWORD(TimeValue) & 0x7FF00000) == 0x7FF00000 && HIDWORD(TimeValue) & 0xFFFFF | LODWORD(TimeValue) )
  {
    *result = this->TimeValue;
  }
  else
  {
    v2 = fmod((double)Scaleform::GFx::AS3::Instances::fl::Date::GetLocalTZA(this) + this->TimeValue, 1000.0);
    if ( v2 < 0.0 )
      v2 = v2 + 1000.0;
    *result = v2;
  }
}
