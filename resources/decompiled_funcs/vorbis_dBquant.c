int __usercall vorbis_dBquant@<eax>(const float *x@<eax>)
{
  int v1; // eax

  v1 = (int)(*x * 7.314285755157471 + 1023.5);
  if ( v1 <= 1023 )
    return v1 < 0 ? 0 : v1;
  else
    return 1023;
}
