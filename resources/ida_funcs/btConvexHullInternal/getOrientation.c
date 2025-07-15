int __usercall btConvexHullInternal::getOrientation@<eax>(
        const btConvexHullInternal::Edge *next@<ecx>,
        btConvexHullInternal::Point32 *t@<eax>,
        const btConvexHullInternal::Edge *prev,
        const btConvexHullInternal::Point32 *s)
{
  btConvexHullInternal::Vertex *target; // eax
  btConvexHullInternal::Vertex *v6; // ecx
  int v7; // edx
  int v8; // edx
  btConvexHullInternal::Vertex *v9; // ecx
  int v10; // esi
  btConvexHullInternal::Vertex *v11; // esi
  int v12; // ecx
  int v13; // esi
  btConvexHullInternal::Point32 v15; // [esp+8h] [ebp-54h] BYREF
  btConvexHullInternal::Point32 b; // [esp+18h] [ebp-44h] BYREF
  btConvexHullInternal::Point64 m; // [esp+28h] [ebp-34h] BYREF
  btConvexHullInternal::Point64 n; // [esp+40h] [ebp-1Ch] BYREF

  if ( prev->next != next )
    return prev->prev == next;
  if ( prev->prev == next )
  {
    btConvexHullInternal::Point32::cross(s, &n, t);
    target = next->reverse->target;
    v6 = next->target;
    v7 = v6->point.x - target->point.x;
    v6 = (btConvexHullInternal::Vertex *)((char *)v6 + 88);
    b.x = v7;
    v8 = (int)v6->prev - target->point.y;
    b.z = (int)v6->edges - target->point.z;
    v9 = prev->target;
    v10 = v9->point.x - target->point.x;
    v9 = (btConvexHullInternal::Vertex *)((char *)v9 + 88);
    v15.x = v10;
    v11 = v9->prev;
    v12 = (int)v9->edges - target->point.z;
    v13 = (int)v11 - target->point.y;
    b.y = v8;
    b.index = -1;
    v15.index = -1;
    v15.z = v12;
    v15.y = v13;
    btConvexHullInternal::Point32::cross(&b, &m, &v15);
    if ( btConvexHullInternal::Point64::dot(&n, &m) <= 0 )
      return 1;
  }
  return 2;
}
