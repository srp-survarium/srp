GIM_ShapeRetriever::TriangleShapeRetriever *__thiscall GIM_ShapeRetriever::ChildShapeRetriever::`scalar deleting destructor'(
        GIM_ShapeRetriever::TriangleShapeRetriever *this,
        char a2)
{
  this->__vftable = (GIM_ShapeRetriever::TriangleShapeRetriever_vtbl *)&GIM_ShapeRetriever::ChildShapeRetriever::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
