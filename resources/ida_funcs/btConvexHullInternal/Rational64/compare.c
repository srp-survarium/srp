int __usercall btConvexHullInternal::Rational64::compare@<eax>(
        btConvexHullInternal::Rational64 *this@<edi>,
        const btConvexHullInternal::Rational64 *b@<esi>)
{
  int sign; // ecx
  int v3; // ebx
  btConvexHullInternal::Int128 resLow; // [esp+8h] [ebp-24h] BYREF
  btConvexHullInternal::Int128 v6; // [esp+18h] [ebp-14h] BYREF

  sign = b->sign;
  v3 = this->sign;
  if ( v3 != sign )
    return v3 - sign;
  if ( !v3 )
    return 0;
  btConvexHullInternal::DMul<unsigned __int64,unsigned int>::mul(
    this->denominator,
    b->numerator,
    &resLow.low,
    &resLow.high);
  btConvexHullInternal::DMul<unsigned __int64,unsigned int>::mul(this->numerator, b->denominator, &v6.low, &v6.high);
  return v3 * btConvexHullInternal::Int128::ucmp(&v6, &resLow);
}
