BOOL __usercall vostok::math::is_zero<float>@<eax>(const float *value@<eax>, const float *epsilon@<edx>)
{
  return *epsilon > COERCE_FLOAT(*(_DWORD *)value & 0x7FFFFFFF);
}
