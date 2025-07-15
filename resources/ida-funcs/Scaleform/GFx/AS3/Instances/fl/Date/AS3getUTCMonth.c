void __thiscall Scaleform::GFx::AS3::Instances::fl::Date::AS3getUTCMonth(
        Scaleform::GFx::AS3::Instances::fl::Date *this,
        long double *result)
{
  double TimeValue; // [esp+8h] [ebp-8h]

  TimeValue = this->TimeValue;
  if ( (HIDWORD(TimeValue) & 0x7FF00000) == 0x7FF00000 && HIDWORD(TimeValue) & 0xFFFFF | LODWORD(TimeValue) )
    *result = this->TimeValue;
  else
    *result = (double)Scaleform::GFx::AS3::Instances::fl::Date::MonthFromTime(this->TimeValue);
}
