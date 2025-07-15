int __userpurge btConvexHullInternal::Rational64::compare@<eax>(
        const btConvexHullInternal::Rational64 *b@<edi>,
        btConvexHullInternal::Rational64 *this)
{
  int sign; // ecx
  int result; // eax
  btConvexHullInternal::Int128 *v5; // eax
  btConvexHullInternal::Int128 *v6; // eax
  int v7; // eax
  __int128 v8; // [esp-1Ch] [ebp-50h]
  __int128 v9; // [esp-Ch] [ebp-40h]
  unsigned __int64 v10; // [esp+8h] [ebp-2Ch] BYREF
  unsigned __int64 v11; // [esp+18h] [ebp-1Ch] BYREF
  int v12; // [esp+2Ch] [ebp-8h]
  const btConvexHullInternal::Int128 *v13; // [esp+3Ch] [ebp+8h]

  sign = b->sign;
  result = this->sign;
  v12 = result;
  if ( result == sign )
  {
    if ( result )
    {
      *(_QWORD *)((char *)&v9 + 4) = b->numerator;
      LODWORD(v9) = HIDWORD(this->denominator);
      v5 = btConvexHullInternal::Int128::mul(
             &v11,
             (btConvexHullInternal::Int128 *)this->denominator,
             v9,
             *((unsigned __int64 *)&v9 + 1));
      *(_QWORD *)((char *)&v8 + 4) = b->denominator;
      v13 = v5;
      LODWORD(v8) = HIDWORD(this->numerator);
      v6 = btConvexHullInternal::Int128::mul(
             &v10,
             (btConvexHullInternal::Int128 *)this->numerator,
             v8,
             *((unsigned __int64 *)&v8 + 1));
      v7 = btConvexHullInternal::Int128::ucmp(v6, v13);
      return v12 * v7;
    }
  }
  else
  {
    result -= sign;
  }
  return result;
}
