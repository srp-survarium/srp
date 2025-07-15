BOOL __cdecl pointCmp(const btConvexHullInternal::Point32 *a1, const btConvexHullInternal::Point32 *a2)
{
  int y; // edx
  int v3; // esi

  y = a1->y;
  v3 = a2->y;
  return y < v3 || y == v3 && (a1->x < a2->x || a1->x == a2->x && a1->z < a2->z);
}
