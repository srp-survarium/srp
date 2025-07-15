void __usercall Scaleform::GFx::AS3::Instances::fl::Date::GetCurrentTimeValue(
        int a1@<ebx>,
        long double *timeValue,
        int *localTZA)
{
  double v3; // st7
  int millitm; // [esp+0h] [ebp-C0h]
  timeb t; // [esp+4h] [ebp-BCh] BYREF
  _TIME_ZONE_INFORMATION tz; // [esp+14h] [ebp-ACh] BYREF

  _ftime64(a1, (__timeb64 *)&t);
  GetTimeZoneInformation(&tz);
  v3 = (double)t.time * 1000.0;
  millitm = t.millitm;
  *localTZA = -60000 * tz.Bias;
  *timeValue = v3 + (double)millitm;
}
