btConvexHullInternal::Rational128 *__userpurge btConvexHullInternal::Vertex::dot@<eax>(
        btConvexHullInternal::Vertex *this@<ecx>,
        int a2@<eax>,
        btConvexHullInternal::Rational128 *result,
        const btConvexHullInternal::Point64 *b)
{
  __int64 v4; // rax
  btConvexHullInternal::Rational128 *v5; // ecx
  btConvexHullInternal::Rational128 *v6; // eax
  const btConvexHullInternal::Int128 *v7; // esi
  btConvexHullInternal::Int128 *v8; // eax
  btConvexHullInternal::Int128 *v9; // eax
  btConvexHullInternal::Int128 *v10; // eax
  const btConvexHullInternal::Int128 *v12; // [esp-4h] [ebp-C0h]
  btConvexHullInternal::Int128 *v13; // [esp+14h] [ebp-A8h]
  btConvexHullInternal::Int128 v14; // [esp+18h] [ebp-A4h] BYREF
  btConvexHullInternal::Int128 v15; // [esp+28h] [ebp-94h] BYREF
  btConvexHullInternal::Int128 v16; // [esp+38h] [ebp-84h] BYREF
  btConvexHullInternal::Int128 v17; // [esp+48h] [ebp-74h] BYREF
  btConvexHullInternal::Int128 v18; // [esp+58h] [ebp-64h] BYREF
  _BYTE v19[40]; // [esp+68h] [ebp-54h] BYREF
  btConvexHullInternal::Rational128 v20; // [esp+90h] [ebp-2Ch] BYREF

  if ( *(int *)(a2 + 100) < 0 )
  {
    v12 = (const btConvexHullInternal::Int128 *)(a2 + 72);
    v13 = btConvexHullInternal::Int128::operator*((btConvexHullInternal::Int128 *)HIDWORD(b->z), &v17, b->z);
    v7 = btConvexHullInternal::Int128::operator*(&v18, &v18, b->y);
    v8 = btConvexHullInternal::Int128::operator*(&v14, &v14, b->x);
    v9 = btConvexHullInternal::Int128::operator+(v8, v7, &v15);
    v10 = btConvexHullInternal::Int128::operator+(v9, v13, &v16);
    btConvexHullInternal::Rational128::Rational128(&v20, v10, v12);
  }
  else
  {
    v4 = btConvexHullInternal::Point32::dot((btConvexHullInternal::Point32 *)(a2 + 88), b);
    btConvexHullInternal::Rational128::Rational128(v5, (int)v19, v4);
  }
  *result = *v6;
  return result;
}
