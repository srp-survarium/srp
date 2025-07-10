// local variable allocation has failed, the output may be wrong!
int __usercall btConvexHullInternal::Rational128::compare@<eax>(
        btConvexHullInternal::Rational128 *this@<esi>,
        const btConvexHullInternal::Rational128 *b@<edi>)
{
  int sign; // ecx
  int v3; // ebx
  int v5; // eax
  btConvexHullInternal::Int128 v6; // [esp-28h] [ebp-74h]
  btConvexHullInternal::Int128 *p_dbnLow; // [esp-28h] [ebp-74h]
  btConvexHullInternal::Int128 *p_dbnHigh; // [esp-24h] [ebp-70h]
  btConvexHullInternal::Int128 denominator; // [esp-20h] [ebp-6Ch] OVERLAPPED
  btConvexHullInternal::Int128 v10; // [esp-18h] [ebp-64h]
  unsigned __int64 low; // [esp-10h] [ebp-5Ch] OVERLAPPED
  btConvexHullInternal::Int128 dbnHigh; // [esp+8h] [ebp-44h] BYREF
  btConvexHullInternal::Int128 nbdHigh; // [esp+18h] [ebp-34h] BYREF
  btConvexHullInternal::Int128 dbnLow; // [esp+28h] [ebp-24h] BYREF
  btConvexHullInternal::Int128 nbdLow; // [esp+38h] [ebp-14h] BYREF

  sign = b->sign;
  v3 = this->sign;
  if ( v3 != sign )
    return v3 - sign;
  if ( !v3 )
    return 0;
  if ( this->isInt64 )
    return -btConvexHullInternal::Rational128::compare(
              (btConvexHullInternal::Rational128 *)this->numerator.low,
              (int)b,
              v3 * this->numerator.low);
  v10.high = b->denominator.low;
  v6.high = this->numerator.low;
  v10.low = this->numerator.high;
  HIDWORD(v6.low) = &nbdHigh;
  LODWORD(v6.low) = &nbdLow;
  btConvexHullInternal::DMul<btConvexHullInternal::Int128,unsigned __int64>::mul(v6, v10, b->denominator.high);
  low = b->numerator.low;
  denominator = this->denominator;
  p_dbnHigh = &dbnHigh;
  p_dbnLow = &dbnLow;
  btConvexHullInternal::DMul<btConvexHullInternal::Int128,unsigned __int64>::mul(
    *(btConvexHullInternal::Int128 *)((char *)&denominator - 8),
    *(btConvexHullInternal::Int128 *)(&low - 1),
    b->numerator.high);
  v5 = btConvexHullInternal::Int128::ucmp(&nbdHigh, &dbnHigh);
  if ( v5 )
    return v5 * v3;
  else
    return v3 * btConvexHullInternal::Int128::ucmp(&nbdLow, &dbnLow);
}
