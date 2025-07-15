void __usercall GIM_ShapeRetriever::~GIM_ShapeRetriever(GIM_ShapeRetriever *this@<ecx>, int a2@<esi>)
{
  *(_DWORD *)(a2 + 368) = &GIM_ShapeRetriever::ChildShapeRetriever::`vftable';
  *(_DWORD *)(a2 + 360) = &GIM_ShapeRetriever::ChildShapeRetriever::`vftable';
  *(_DWORD *)(a2 + 352) = &GIM_ShapeRetriever::ChildShapeRetriever::`vftable';
  btPolyhedralConvexShape::~btPolyhedralConvexShape((btPolyhedralConvexShape *)(a2 + 144));
  btPolyhedralConvexShape::~btPolyhedralConvexShape((btPolyhedralConvexShape *)(a2 + 16));
}
