double __cdecl Scaleform::GFx::AS3::Instances::fl::Date::MakeTime(double hour, double minute, double sec, double ms)
{
  double v5; // st7
  double v6; // st7
  double v7; // st7
  double v8; // st7
  double v9; // [esp+30h] [ebp-18h]
  double v10; // [esp+38h] [ebp-10h]
  long double v11; // [esp+40h] [ebp-8h]
  double v12; // [esp+40h] [ebp-8h]

  v11 = minute + hour + sec + ms;
  if ( (HIDWORD(v11) & 0x7FF00000) == 0x7FF00000 )
    return Scaleform::GFx::NumberUtil::NaN();
  if ( hour <= 0.0 )
    v5 = -floor(-hour);
  else
    v5 = floor(hour);
  v10 = v5;
  if ( minute <= 0.0 )
    v6 = -floor(-minute);
  else
    v6 = floor(minute);
  v9 = v6;
  if ( sec <= 0.0 )
    v7 = -floor(-sec);
  else
    v7 = floor(sec);
  v12 = v7;
  if ( ms <= 0.0 )
    v8 = -floor(-ms);
  else
    v8 = floor(ms);
  return v8 + v9 * 60000.0 + v10 * 3600000.0 + v12 * 1000.0;
}
