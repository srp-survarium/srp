void __thiscall Scaleform::GFx::AS3::Instances::fl::Date::AS3getUTCDay(
        Scaleform::GFx::AS3::Instances::fl::Date *this,
        long double *result)
{
  int v2; // eax
  double TimeValue; // [esp+8h] [ebp-8h]

  TimeValue = this->TimeValue;
  if ( (HIDWORD(TimeValue) & 0x7FF00000) == 0x7FF00000 && HIDWORD(TimeValue) & 0xFFFFF | LODWORD(TimeValue) )
  {
    *result = this->TimeValue;
  }
  else
  {
    v2 = (int)fmod(floor(this->TimeValue / 86400000.0) + 4.0, 7.0);
    *result = (double)(v2 + (v2 < 0 ? 7 : 0));
  }
}
