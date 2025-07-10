BOOL __cdecl pointCmp(const btConvexHullInternal::Point32 *p, const btConvexHullInternal::Point32 *q)
{
  int y; // eax
  int v3; // ecx

  y = p->y;
  v3 = q->y;
  return y < v3 || y == v3 && (p->x < q->x || p->x == q->x && p->z < q->z);
}
