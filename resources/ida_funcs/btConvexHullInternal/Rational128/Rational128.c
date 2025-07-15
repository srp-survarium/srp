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


void __userpurge btConvexHullInternal::Rational128::Rational128(
        btConvexHullInternal::Rational128 *this@<ecx>,
        int a2@<eax>,
        __int64 value)
{
  __int64 v3; // [esp+8h] [ebp-14h]
  __int64 v4; // [esp+10h] [ebp-Ch]

  if ( value >= 0 )
  {
    if ( value > 0 )
    {
      *(_DWORD *)(a2 + 32) = 1;
      v3 = value;
LABEL_8:
      v4 = 0;
      goto LABEL_9;
    }
    if ( value >= 0 )
    {
      *(_DWORD *)(a2 + 32) = 0;
      v3 = 0;
      goto LABEL_8;
    }
  }
  *(_DWORD *)(a2 + 32) = -1;
  v3 = -value;
  if ( (((unsigned __int64)-value >> 32) & 0x80000000) == 0LL )
    goto LABEL_8;
  v4 = -1;
LABEL_9:
  *(_QWORD *)a2 = v3;
  *(_QWORD *)(a2 + 8) = v4;
  *(_QWORD *)(a2 + 16) = 1;
  *(_QWORD *)(a2 + 24) = 0;
  *(_BYTE *)(a2 + 36) = 1;
}
