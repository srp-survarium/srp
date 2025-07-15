btConvexHullInternal::Int128 *__userpurge btConvexHullInternal::Int128::operator*@<eax>(
        btConvexHullInternal::Int128 *this@<ecx>,
        btConvexHullInternal::Int128 *a2@<eax>,
        btConvexHullInternal::Int128 *result,
        __int64 b)
{
  btConvexHullInternal::Int128 *p_resulta; // edi
  int high_high; // eax
  int high; // edx
  unsigned int low; // esi
  unsigned int low_high; // ecx
  BOOL v9; // edi
  bool v10; // bl
  int v11; // edx
  int v12; // esi
  unsigned __int64 v13; // xmm0_8
  unsigned int v14; // edi
  unsigned __int64 v15; // kr08_8
  btConvexHullInternal::Int128 *p_a; // ecx
  btConvexHullInternal::Int128 *v17; // eax
  btConvexHullInternal::Int128 resulta; // [esp+10h] [ebp-20h] BYREF
  btConvexHullInternal::Int128 a; // [esp+20h] [ebp-10h] BYREF

  p_resulta = a2;
  high_high = HIDWORD(a2->high);
  high = p_resulta->high;
  if ( high_high < 0 )
  {
    low = p_resulta->low;
    low_high = HIDWORD(p_resulta->low);
    v10 = 1;
    v9 = p_resulta->low == 0;
    v11 = ~high;
    resulta.low = -__SPAIR64__(low_high, low);
    LODWORD(resulta.high) = v9 + v11;
    HIDWORD(resulta.high) = __CFADD__(v9, v11) + ~high_high;
    p_resulta = &resulta;
  }
  else
  {
    v10 = 0;
  }
  v12 = b;
  a.low = p_resulta->low;
  v13 = p_resulta->high;
  v14 = HIDWORD(b);
  a.high = v13;
  if ( b < 0 )
  {
    v10 = !v10;
    v12 = -(int)b;
    v14 = (unsigned __int64)-b >> 32;
  }
  btConvexHullInternal::DMul<unsigned __int64,unsigned int>::mul(
    a.low,
    __PAIR64__(v14, v12),
    &resulta.low,
    &resulta.high);
  v15 = a.high * __PAIR64__(v14, v12) + resulta.high;
  resulta.high = v15;
  if ( v10 )
  {
    a.low = -resulta.low;
    a.high = (resulta.low == 0) + ~v15;
    p_a = &a;
  }
  else
  {
    p_a = &resulta;
  }
  v17 = result;
  *result = *p_a;
  return v17;
}


btConvexHullInternal::Int128 *__userpurge btConvexHullInternal::Int128::operator-@<eax>(
        btConvexHullInternal::Int128 *this@<ecx>,
        int a2@<eax>,
        btConvexHullInternal::Int128 *result,
        const btConvexHullInternal::Int128 *b)
{
  __int64 v4; // rdi
  unsigned __int64 v5; // kr10_8
  unsigned __int64 v6; // kr18_8
  BOOL v7; // ebp
  unsigned int v8; // edi
  unsigned int v9; // ebx

  v5 = ~this->high + (this->low == 0);
  HIDWORD(v4) = HIDWORD(v5);
  v6 = *(_QWORD *)a2 - this->low;
  v7 = *(_QWORD *)a2 >= this->low;
  HIDWORD(result->low) = HIDWORD(v6);
  v8 = *(_DWORD *)(a2 + 8);
  LODWORD(result->low) = v6;
  v9 = (__PAIR64__(*(_DWORD *)(a2 + 12), v7) + v8) >> 32;
  LODWORD(v4) = v7 + v8;
  result->high = __PAIR64__(v9, v5) + v4;
  return result;
}


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
