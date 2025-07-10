void __usercall btConvexHullInternal::Pool<btConvexHullInternal::Face>::~Pool<btConvexHullInternal::Face>(
        btConvexHullInternal::Pool<btConvexHullInternal::Vertex> *this@<ecx>,
        void ***a2@<edi>)
{
  void **v2; // esi
  void *v3; // eax

  while ( *a2 )
  {
    v2 = *a2;
    *a2 = (void **)(*a2)[2];
    v3 = *v2;
    if ( *v2 )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(v3);
    }
    ++gNumAlignedFree;
    sAlignedFreeFunc(v2);
  }
}
