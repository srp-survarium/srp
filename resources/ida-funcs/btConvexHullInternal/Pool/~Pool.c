void __usercall btConvexHullInternal::Pool<btConvexHullInternal::Face>::~Pool<btConvexHullInternal::Face>(
        btConvexHullInternal::Pool<btConvexHullInternal::Vertex> *this@<ecx>,
        void ***a2@<esi>)
{
  void **v2; // edi

  while ( *a2 )
  {
    v2 = *a2;
    *a2 = (void **)(*a2)[2];
    btAlignedFreeInternal(*v2);
    btAlignedFreeInternal(v2);
  }
}
