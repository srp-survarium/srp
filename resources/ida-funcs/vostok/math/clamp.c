void __cdecl vostok::math::clamp<int>(int min)
{
  int *value_and_result; // ecx
  int v2; // eax

  v2 = *value_and_result;
  if ( *value_and_result > 0 )
  {
    if ( v2 > min )
      v2 = min;
  }
  else
  {
    v2 = 0;
  }
  *value_and_result = v2;
}


void __cdecl vostok::math::clamp<unsigned int>(unsigned int min, unsigned int max)
{
  unsigned int *value_and_result; // ecx
  unsigned int v3; // eax

  v3 = *value_and_result;
  if ( *value_and_result > min )
  {
    if ( v3 > max )
      v3 = max;
  }
  else
  {
    v3 = min;
  }
  *value_and_result = v3;
}
