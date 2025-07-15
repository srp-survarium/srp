int __usercall btConvexHullInternal::Int128::ucmp@<eax>(
        btConvexHullInternal::Int128 *this@<ecx>,
        const btConvexHullInternal::Int128 *b@<eax>)
{
  unsigned int high_high; // edx
  unsigned int high; // ebx
  unsigned int v4; // esi
  unsigned int v5; // edi
  unsigned int low; // edx
  unsigned int v8; // esi
  unsigned int low_high; // ecx
  unsigned int v10; // eax

  high_high = HIDWORD(this->high);
  high = b->high;
  v4 = HIDWORD(b->high);
  v5 = this->high;
  if ( high_high > v4 )
    return 1;
  if ( high_high < v4 || v5 < high )
    return -1;
  if ( __PAIR64__(high_high, v5) > __PAIR64__(v4, high) )
    return 1;
  low = this->low;
  v8 = b->low;
  low_high = HIDWORD(this->low);
  v10 = HIDWORD(b->low);
  if ( low_high > v10 )
    return 1;
  if ( low_high < v10 || low < v8 )
    return -1;
  return __PAIR64__(low_high, low) > __PAIR64__(v10, v8);
}
