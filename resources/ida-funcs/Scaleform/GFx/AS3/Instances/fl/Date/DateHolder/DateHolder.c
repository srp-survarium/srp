void __thiscall Scaleform::GFx::AS3::Instances::fl::Date::DateHolder::DateHolder(
        Scaleform::GFx::AS3::Instances::fl::Date::DateHolder *this,
        long double time,
        long double tza)
{
  long double v4; // st7
  int X_4; // [esp+4h] [ebp-44h]
  double v6; // [esp+30h] [ebp-18h]
  long double t; // [esp+38h] [ebp-10h]
  double v8; // [esp+40h] [ebp-8h]

  this->TZA = tza;
  t = tza + time;
  v6 = Scaleform::GFx::AS3::Instances::fl::Date::YearFromTime(t);
  this->Entries[0] = v6;
  v8 = floor(t / 86400000.0);
  X_4 = (int)(v8 - Scaleform::GFx::AS3::Instances::fl::Date::DayFromYear(v6));
  this->Entries[1] = (double)Scaleform::GFx::AS3::Instances::fl::Date::MonthFromYearDay((int)v6, X_4);
  this->Entries[2] = (double)Scaleform::GFx::AS3::Instances::fl::Date::DateFromTime(t);
  v4 = fmod(t, 86400000.0);
  if ( v4 < 0.0 )
    v4 = v4 + 86400000.0;
  this->TimeInDay = v4;
}
