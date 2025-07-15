btConvexHullInternal::Point64 *__userpurge btConvexHullInternal::Point32::cross@<eax>(
        const btConvexHullInternal::Point32 *b@<eax>,
        _QWORD *a2@<ecx>,
        btConvexHullInternal::Point32 *this)
{
  int y; // ebx
  int x; // esi
  int z; // ebp
  int v6; // edi
  int v8; // [esp+10h] [ebp-4h]
  int thisa; // [esp+18h] [ebp+4h]

  y = b->y;
  x = b->x;
  z = this->z;
  v6 = this->x;
  v8 = this->y;
  thisa = b->z;
  *a2 = thisa * v8 - y * z;
  a2[1] = z * x - thisa * v6;
  a2[2] = y * v6 - v8 * x;
  return (btConvexHullInternal::Point64 *)a2;
}


btConvexHullInternal::Point64 *__userpurge btConvexHullInternal::Point32::cross@<eax>(
        const btConvexHullInternal::Point64 *b@<eax>,
        int a2@<esi>,
        btConvexHullInternal::Point32 *this)
{
  unsigned int x; // ebx
  unsigned int x_high; // edi
  int v5; // eax
  __int64 z; // [esp+1Ch] [ebp-20h]
  __int64 y; // [esp+24h] [ebp-18h]
  __int64 v9; // [esp+2Ch] [ebp-10h]
  __int64 v10; // [esp+34h] [ebp-8h]

  z = b->z;
  y = b->y;
  v10 = this->y;
  v9 = this->z;
  x = b->x;
  x_high = HIDWORD(b->x);
  *(_DWORD *)a2 = z * v10 - y * v9;
  v5 = this->x;
  *(_DWORD *)(a2 + 4) = (unsigned __int64)(z * v10 - y * v9) >> 32;
  *(_QWORD *)(a2 + 8) = __PAIR64__(x_high, x) * v9 - v5 * z;
  *(_QWORD *)(a2 + 16) = v5 * y - __PAIR64__(x_high, x) * v10;
  return (btConvexHullInternal::Point64 *)a2;
}
