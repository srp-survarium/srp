void __thiscall Scaleform::GFx::AS3::Instances::fl::Date::AS3getSeconds(
        Scaleform::GFx::AS3::Instances::fl::Date *this,
        long double *result)
{
  double v3; // st7
  double TimeValue; // [esp+Ch] [ebp-8h]
  int LocalTZA; // [esp+Ch] [ebp-8h]

  TimeValue = this->TimeValue;
  if ( (HIDWORD(TimeValue) & 0x7FF00000) == 0x7FF00000 && HIDWORD(TimeValue) & 0xFFFFF | LODWORD(TimeValue) )
  {
    *result = this->TimeValue;
  }
  else
  {
    LocalTZA = Scaleform::GFx::AS3::Instances::fl::Date::GetLocalTZA(this);
    v3 = fmod(floor(((double)LocalTZA + this->TimeValue) / 1000.0), 60.0);
    if ( v3 < 0.0 )
      v3 = v3 + 60.0;
    *result = v3;
  }
}
