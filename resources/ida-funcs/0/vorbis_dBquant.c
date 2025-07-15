int __usercall vorbis_dBquant@<eax>(const float *x@<eax>)
{
  int result; // eax

  result = (int)(float)((float)(*x * 7.3142858) + 1023.5);
  if ( result > 1023 )
    return 1023;
  if ( result < 0 )
    return 0;
  return result;
}
