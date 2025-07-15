btConvexHullInternal::Point64 *__userpurge btConvexHullInternal::Point32::cross@<eax>(
        const btConvexHullInternal::Point32 *b@<eax>,
        _QWORD *a2@<ecx>,
        btConvexHullInternal::Point32 *this)
{
  int z; // edx
  int y; // ebx
  int x; // esi
  int v7; // eax
  int v8; // edi
  int v10; // [esp+1Ch] [ebp+8h]

  z = b->z;
  y = b->y;
  x = b->x;
  v10 = this->z;
  v7 = this->y;
  v8 = this->x;
  *a2 = z * v7 - y * v10;
  a2[1] = v10 * x - z * v8;
  a2[2] = y * v8 - v7 * x;
  return (btConvexHullInternal::Point64 *)a2;
}


btConvexHullInternal::Point64 *__userpurge btConvexHullInternal::Point32::cross@<eax>(
        btConvexHullInternal::Point32 *this@<ecx>,
        int a2@<esi>,
        btConvexHullInternal::Point64 *result,
        const btConvexHullInternal::Point64 *b)
{
  unsigned int x; // ecx
  unsigned int v5; // edi
  int v6; // eax
  __int64 y; // [esp+10h] [ebp-28h]
  __int64 z; // [esp+18h] [ebp-20h]
  __int64 y_low; // [esp+20h] [ebp-18h]
  __int64 x_high; // [esp+28h] [ebp-10h]

  x_high = SHIDWORD(result->x);
  z = b->z;
  y_low = SLODWORD(result->y);
  y = b->y;
  *(_DWORD *)a2 = z * x_high - y * y_low;
  x = b->x;
  v5 = HIDWORD(b->x);
  v6 = result->x;
  *(_DWORD *)(a2 + 4) = (unsigned __int64)(z * x_high - y * y_low) >> 32;
  *(_QWORD *)(a2 + 8) = __PAIR64__(v5, x) * y_low - v6 * z;
  *(_QWORD *)(a2 + 16) = v6 * y - __PAIR64__(v5, x) * x_high;
  return (btConvexHullInternal::Point64 *)a2;
}
