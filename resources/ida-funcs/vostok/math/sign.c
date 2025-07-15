char __usercall vostok::math::sign@<al>(float a1@<xmm0>)
{
  if ( a1 > 0.0 )
    return 1;
  if ( a1 >= 0.0 )
    return 0;
  return -1;
}
