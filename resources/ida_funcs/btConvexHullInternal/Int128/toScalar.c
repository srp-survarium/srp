double __thiscall btConvexHullInternal::Int128::toScalar(btConvexHullInternal::Int128 *this)
{
  int high_high; // eax
  int high; // edx
  unsigned __int64 v3; // kr00_8
  unsigned int v4; // eax
  unsigned int v5; // ecx
  unsigned int low; // esi
  unsigned int low_high; // ecx
  btConvexHullInternal::Int128 v9; // [esp+10h] [ebp-14h] BYREF

  high_high = HIDWORD(this->high);
  high = this->high;
  if ( high_high < 0 )
  {
    low = this->low;
    low_high = HIDWORD(this->low);
    v9.low = -__SPAIR64__(low_high, low);
    v9.high = __PAIR64__(~high_high, (low_high | low) == 0) + (unsigned int)~high;
    return -btConvexHullInternal::Int128::toScalar(&v9);
  }
  else
  {
    LODWORD(v9.low) = this->high;
    HIDWORD(v9.low) = high_high & 0x7FFFFFFF;
    v3 = __PAIR64__(high_high, v9.low);
    v4 = this->low;
    v5 = HIDWORD(this->low);
    v9.low = __PAIR64__(v5 & 0x80000000, 0);
    return (double)v3 * 1.8446744e19 + (double)__PAIR64__(v5, v4);
  }
}
