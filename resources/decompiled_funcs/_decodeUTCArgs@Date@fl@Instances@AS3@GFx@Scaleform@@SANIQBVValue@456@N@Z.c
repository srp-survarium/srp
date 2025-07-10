double __cdecl Scaleform::GFx::AS3::Instances::fl::Date::decodeUTCArgs(
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv,
        long double tza)
{
  long double v4; // st7
  double Time; // st7
  Scaleform::GFx::AS3::CheckResult result; // [esp+5Bh] [ebp-45h] BYREF
  int v7; // [esp+5Ch] [ebp-44h]
  double ms; // [esp+60h] [ebp-40h] BYREF
  double seconds; // [esp+68h] [ebp-38h] BYREF
  double minutes; // [esp+70h] [ebp-30h] BYREF
  double hours; // [esp+78h] [ebp-28h] BYREF
  long double date; // [esp+80h] [ebp-20h] BYREF
  long double year; // [esp+88h] [ebp-18h]
  long double yearArg; // [esp+90h] [ebp-10h] BYREF
  long double month; // [esp+98h] [ebp-8h] BYREF

  if ( !Scaleform::GFx::AS3::Value::Convert2Number(argv, &result, &yearArg)->Result )
    return 0.0;
  v4 = yearArg;
  if ( (unsigned int)(int)yearArg < 0x64 )
    v4 = yearArg + 1900.0;
  year = v4;
  if ( !Scaleform::GFx::AS3::Value::Convert2Number(argv + 1, &result, &month)->Result )
    return 0.0;
  date = 1.0;
  hours = 0.0;
  minutes = 0.0;
  seconds = 0.0;
  ms = 0.0;
  if ( argc >= 3 && !Scaleform::GFx::AS3::Value::Convert2Number(argv + 2, &result, &date)->Result )
    return 0.0;
  if ( argc >= 4 )
  {
    if ( !Scaleform::GFx::AS3::Value::Convert2Number(argv + 3, &result, &hours)->Result )
      return 0.0;
    v7 = (int)hours;
    hours = (double)(int)hours;
  }
  if ( argc >= 5 )
  {
    if ( !Scaleform::GFx::AS3::Value::Convert2Number(argv + 4, &result, &minutes)->Result )
      return 0.0;
    v7 = (int)minutes;
    minutes = (double)(int)minutes;
  }
  if ( argc >= 6 )
  {
    if ( !Scaleform::GFx::AS3::Value::Convert2Number(argv + 5, &result, &seconds)->Result )
      return 0.0;
    v7 = (int)seconds;
    seconds = (double)(int)seconds;
  }
  if ( argc >= 7 )
  {
    if ( Scaleform::GFx::AS3::Value::Convert2Number(argv + 6, &result, &ms)->Result )
    {
      v7 = (int)ms;
      ms = (double)(int)ms;
      goto LABEL_20;
    }
    return 0.0;
  }
LABEL_20:
  year = Scaleform::GFx::AS3::Instances::fl::Date::MakeDay(year, month, date);
  Time = Scaleform::GFx::AS3::Instances::fl::Date::MakeTime(hours, minutes, seconds, ms);
  return Scaleform::GFx::AS3::Instances::fl::Date::TimeClip(Time + year * 86400000.0 - tza);
}
