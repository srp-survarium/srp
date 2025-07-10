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
