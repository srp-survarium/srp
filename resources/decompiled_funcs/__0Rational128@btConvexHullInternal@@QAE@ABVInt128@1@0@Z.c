void __userpurge btConvexHullInternal::Rational128::Rational128(
        btConvexHullInternal::Rational128 *this@<eax>,
        const btConvexHullInternal::Int128 *numerator@<edx>,
        const btConvexHullInternal::Int128 *denominator)
{
  int v3; // edi
  unsigned __int64 high; // xmm0_8
  unsigned __int64 v5; // xmm0_8
  int v6; // edx
  unsigned __int64 v7; // kr08_8
  unsigned __int64 v8; // [esp+20h] [ebp-8h]

  if ( (numerator->high & 0x8000000000000000uLL) == 0LL )
    v3 = numerator->high || numerator->low;
  else
    v3 = -1;
  this->sign = v3;
  if ( v3 < 0 )
  {
    v8 = (numerator->low == 0) + ~numerator->high;
    this->numerator.low = -numerator->low;
    high = v8;
  }
  else
  {
    this->numerator.low = numerator->low;
    high = numerator->high;
  }
  this->numerator.high = high;
  if ( (denominator->high & 0x8000000000000000uLL) != 0LL )
  {
    this->sign = -v3;
    v7 = (denominator->low == 0) + ~denominator->high;
    v6 = HIDWORD(v7);
    LODWORD(v8) = v7;
    this->denominator.low = -denominator->low;
    HIDWORD(v8) = v6;
    v5 = v8;
  }
  else
  {
    this->denominator.low = denominator->low;
    v5 = denominator->high;
  }
  this->isInt64 = 0;
  this->denominator.high = v5;
}
