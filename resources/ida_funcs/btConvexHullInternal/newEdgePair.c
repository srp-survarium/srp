btConvexHullInternal::Edge *__userpurge btConvexHullInternal::newEdgePair@<eax>(
        btConvexHullInternal *this@<ecx>,
        _DWORD *a2@<esi>,
        btConvexHullInternal::Vertex *from,
        btConvexHullInternal::Vertex *to)
{
  btConvexHullInternal::Edge *v4; // ebx
  btConvexHullInternal::Pool<btConvexHullInternal::Edge> *v5; // ecx
  btConvexHullInternal::Edge *v6; // eax
  int v7; // eax

  v4 = btConvexHullInternal::Pool<btConvexHullInternal::Edge>::newObject(
         (btConvexHullInternal::Pool<btConvexHullInternal::Edge> *)this,
         a2 + 12);
  v6 = btConvexHullInternal::Pool<btConvexHullInternal::Edge>::newObject(v5, a2 + 12);
  v4->reverse = v6;
  v6->reverse = v4;
  v4->copy = a2[25];
  v6->copy = a2[25];
  v4->target = to;
  v6->target = from;
  v4->face = 0;
  v6->face = 0;
  v7 = ++a2[29];
  if ( v7 > a2[30] )
    a2[30] = v7;
  return v4;
}
