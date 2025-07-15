void __userpurge btConvexHullInternal::Face::init(
        btConvexHullInternal::Vertex *a@<eax>,
        btConvexHullInternal::Vertex *c@<edx>,
        btConvexHullInternal::Face *this,
        btConvexHullInternal::Vertex *b)
{
  int v4; // esi
  int v5; // edi
  int v6; // edx
  btConvexHullInternal::Face *lastNearbyFace; // edx
  __int64 v8; // [esp+0h] [ebp-14h]

  this->nearbyVertex = a;
  this->origin = a->point;
  LODWORD(v8) = b->point.x - a->point.x;
  v4 = b->point.z - a->point.z;
  HIDWORD(v8) = b->point.y - a->point.y;
  *(_QWORD *)&this->dir0.x = v8;
  *(_QWORD *)&this->dir0.z = (unsigned int)v4 | 0xFFFFFFFF00000000uLL;
  LODWORD(v8) = c->point.x - a->point.x;
  v5 = c->point.y - a->point.y;
  v6 = c->point.z - a->point.z;
  HIDWORD(v8) = v5;
  *(_QWORD *)&this->dir1.x = v8;
  *(_QWORD *)&this->dir1.z = (unsigned int)v6 | 0xFFFFFFFF00000000uLL;
  lastNearbyFace = a->lastNearbyFace;
  if ( lastNearbyFace )
    lastNearbyFace->nextWithSameNearbyVertex = this;
  else
    a->firstNearbyFace = this;
  a->lastNearbyFace = this;
}
