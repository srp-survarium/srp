void __usercall vostok::math::clamp<unsigned int>(
        unsigned int *value_and_result@<ecx>,
        unsigned int min@<edx>,
        unsigned int max@<esi>)
{
  unsigned int v3; // eax

  v3 = *value_and_result;
  if ( *value_and_result > min )
  {
    if ( v3 > max )
      *value_and_result = max;
    else
      *value_and_result = v3;
  }
  else
  {
    *value_and_result = min;
  }
}
