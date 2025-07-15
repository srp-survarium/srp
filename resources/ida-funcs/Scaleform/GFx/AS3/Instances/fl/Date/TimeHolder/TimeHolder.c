void __thiscall Scaleform::GFx::AS3::Instances::fl::Date::TimeHolder::TimeHolder(
        Scaleform::GFx::AS3::Instances::fl::Date::TimeHolder *this,
        long double time,
        long double tza)
{
  double v4; // st7
  double v5; // st7
  double v6; // st7
  double v7; // st5
  double t; // [esp+40h] [ebp-8h]

  this->TZA = tza;
  t = tza + time;
  v4 = fmod(floor(t / 3600000.0), 24.0);
  if ( v4 < 0.0 )
    v4 = v4 + 24.0;
  this->Entries[0] = v4;
  v5 = fmod(floor(t / 60000.0), 60.0);
  if ( v5 < 0.0 )
    v5 = v5 + 60.0;
  this->Entries[1] = v5;
  v6 = fmod(floor(t / 1000.0), 60.0);
  v7 = v6;
  if ( v6 < 0.0 )
    v7 = v6 + 60.0;
  this->Entries[2] = v7;
  if ( v6 < 0.0 )
    v6 = v6 + 60.0;
  this->Entries[3] = v6;
  this->Day = floor(t / 86400000.0);
}
