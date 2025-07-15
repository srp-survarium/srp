btConvexHullInternal::Int128 *__usercall btConvexHullInternal::Int128::operator-@<eax>(
        btConvexHullInternal::Int128 *this@<ecx>,
        btConvexHullInternal::Int128 *a2@<eax>,
        _DWORD *a3@<esi>)
{
  int v3; // edi
  int v4; // edx
  int v5; // ecx

  if ( *(_QWORD *)a3 )
    v3 = 0;
  else
    v3 = (a3[1] | *a3) + 1;
  v4 = -*a3;
  HIDWORD(a2->low) = -*(_QWORD *)a3 >> 32;
  v5 = a3[2];
  LODWORD(a2->low) = v4;
  a2->high = __PAIR64__(~a3[3], v3) + (unsigned int)~v5;
  return a2;
}
