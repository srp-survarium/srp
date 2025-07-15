double __cdecl Scaleform::GFx::AS3::Instances::fl::Date::YearFromTime(double time)
{
  int v1; // edi
  int v2; // esi
  bool v3; // cc
  int v4; // eax
  int v5; // ebx
  int low; // [esp+34h] [ebp-14h]
  double middle; // [esp+38h] [ebp-10h]
  double v9; // [esp+40h] [ebp-8h]
  double v10; // [esp+40h] [ebp-8h]

  v1 = (int)floor(time / 3.1536e10) + 1970;
  v2 = (int)floor(time / 3.16224e10) + 1970;
  v3 = v1 <= v2;
  low = v2;
  if ( v1 < v2 )
  {
    v4 = v1;
    v1 = v2;
    v2 = v4;
    low = v4;
    v3 = v1 <= v4;
  }
  if ( v3 )
    return (double)low;
  while ( 1 )
  {
    v5 = (v2 + v1) / 2;
    middle = (double)v5;
    v9 = floor((middle - 1969.0) * 0.25) + (middle - 1970.0) * 365.0;
    v10 = (v9 - floor((middle - 1901.0) / 100.0)) * 86400000.0;
    if ( floor((middle - 1601.0) / 400.0) * 86400000.0 + v10 <= time )
      break;
    v1 = v5 - 1;
LABEL_7:
    if ( v1 <= v2 )
      return (double)low;
  }
  v2 = v5 + 1;
  low = v5 + 1;
  if ( Scaleform::GFx::AS3::Instances::fl::Date::DayFromYear((double)(v5 + 1)) * 86400000.0 <= time )
    goto LABEL_7;
  return (double)v5;
}
