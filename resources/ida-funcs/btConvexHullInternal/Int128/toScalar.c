double __thiscall btConvexHullInternal::Int128::toScalar(btConvexHullInternal::Int128 *this)
{
  unsigned __int64 high; // rax
  unsigned int low; // esi
  unsigned int low_high; // ecx
  btConvexHullInternal::Int128 *v5; // eax
  btConvexHullInternal::Int128 v6; // [esp+10h] [ebp-10h] BYREF

  high = this->high;
  if ( (high & 0x8000000000000000uLL) != 0LL )
  {
    v5 = btConvexHullInternal::Int128::operator-(this, &v6, this);
    return -btConvexHullInternal::Int128::toScalar(v5);
  }
  else
  {
    low = this->low;
    low_high = HIDWORD(this->low);
    v6.low = __PAIR64__(low_high & 0x7FFFFFFF, low);
    return (double)high * 1.8446744e19 + (double)__PAIR64__(low_high, low);
  }
}
