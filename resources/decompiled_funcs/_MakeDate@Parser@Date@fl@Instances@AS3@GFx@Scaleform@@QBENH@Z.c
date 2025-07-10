double __thiscall Scaleform::GFx::AS3::Instances::fl::Date::Parser::MakeDate(
        Scaleform::GFx::AS3::Instances::fl::Date::Parser *this,
        int localTZA)
{
  double Time; // st7
  double Day; // [esp+58h] [ebp-8h]

  if ( !this->Valid )
    return Scaleform::GFx::NumberUtil::NaN();
  if ( this->HasTZA )
    localTZA = this->TZA;
  Day = Scaleform::GFx::AS3::Instances::fl::Date::MakeDay((double)this->Year, (double)this->Month, (double)this->Day);
  Time = Scaleform::GFx::AS3::Instances::fl::Date::MakeTime(
           (double)this->Hour,
           (double)this->Minute,
           (double)this->Sec,
           0.0);
  return Scaleform::GFx::AS3::Instances::fl::Date::TimeClip(Time + Day * 86400000.0 - (double)localTZA);
}
