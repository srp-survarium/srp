void __usercall GIM_ShapeRetriever::~GIM_ShapeRetriever(GIM_ShapeRetriever *this@<ecx>, _DWORD *a2@<esi>)
{
  void *v2; // eax
  void *v3; // eax

  a2[92] = &GIM_ShapeRetriever::ChildShapeRetriever::`vftable';
  a2[90] = &GIM_ShapeRetriever::ChildShapeRetriever::`vftable';
  a2[88] = &GIM_ShapeRetriever::ChildShapeRetriever::`vftable';
  v2 = (void *)a2[52];
  a2[36] = &btPolyhedralConvexShape::`vftable';
  if ( v2 )
  {
    ++gNumAlignedFree;
    sAlignedFreeFunc(v2);
  }
  a2[36] = &btCollisionShape::`vftable';
  v3 = (void *)a2[20];
  a2[4] = &btPolyhedralConvexShape::`vftable';
  if ( v3 )
  {
    ++gNumAlignedFree;
    sAlignedFreeFunc(v3);
  }
  a2[4] = &btCollisionShape::`vftable';
}
