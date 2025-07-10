btConvexHullInternal::Int128 *__usercall btConvexHullInternal::Int128::operator+@<eax>(
        btConvexHullInternal::Int128 *this@<edi>,
        const btConvexHullInternal::Int128 *b@<esi>,
        btConvexHullInternal::Int128 *result@<eax>)
{
  unsigned __int64 v3; // kr08_8
  BOOL v4; // ebx
  unsigned int high; // ecx
  unsigned int v6; // kr00_4

  v3 = this->low + b->low;
  v4 = v3 < this->low;
  HIDWORD(result->low) = HIDWORD(v3);
  high = b->high;
  v6 = this->high;
  LODWORD(result->low) = v3;
  result->high = v4 + __PAIR64__(HIDWORD(b->high), v6) + __PAIR64__(HIDWORD(this->high), high);
  return result;
}
