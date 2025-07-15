int __usercall Clamp_float_@<xmm0>(const float *x@<eax>, const float *h@<ecx>)
{
  int result; // xmm0_4

  result = *(_DWORD *)x;
  if ( *x > *h )
    return *(_DWORD *)h;
  return result;
}
