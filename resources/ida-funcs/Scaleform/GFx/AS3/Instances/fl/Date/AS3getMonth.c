void __thiscall Scaleform::GFx::AS3::Instances::fl::Date::AS3getMonth(
        Scaleform::GFx::AS3::Instances::fl::Date *this,
        long double *result)
{
  int LocalTZA; // eax
  double TimeValue; // [esp+Ch] [ebp-8h]

  TimeValue = this->TimeValue;
  if ( (HIDWORD(TimeValue) & 0x7FF00000) == 0x7FF00000
    && (unsigned int)&loc_FFFFF & HIDWORD(TimeValue) | LODWORD(TimeValue) )
  {
    *result = this->TimeValue;
  }
  else
  {
    LocalTZA = Scaleform::GFx::AS3::Instances::fl::Date::GetLocalTZA(this);
    *result = (double)Scaleform::GFx::AS3::Instances::fl::Date::MonthFromTime((double)LocalTZA + this->TimeValue);
  }
}
